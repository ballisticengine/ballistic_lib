#include "./LoaderOBJ.hpp"

#include "../core/builders/mesh/TriMeshBuilder.hpp"
#include "../core/builders/material/TextureMaterialBuilder.hpp"

#include "../core/types/spatial/Vector3d.hpp"
#include "../core/resources/loader/Results.hpp"
#include <cstring>
#include <string>
#include <boost/algorithm/string/replace.hpp>

namespace Ballistic {
    namespace Loaders {
        using namespace Ballistic::Core::Builders;
        using Ballistic::Core::Types::scalar_t;
        using Ballistic::Core::Types::Spatial::Vector3d;
        using Ballistic::Core::Resources::MeshAndMaterialResult;
        using Ballistic::Core::Types::Graphics::Texture;
        using namespace std;

        Ballistic::Core::Resources::extensionsSet LoaderOBJ::getFileExtensions() {
            Ballistic::Core::Resources::extensionsSet exts;
            exts.insert("obj");
            return exts;
        }

        Ballistic::Core::Resources::ResourceType LoaderOBJ::getType() {
            return Ballistic::Core::Resources::RESOURCE_MESH_MATERIAL_TEXTURE;
        }

        int * LoaderOBJ::splitFace(char *faceStr) {
            int *fs = new int[3];
            sscanf(faceStr, "%i/%i/%i", &fs[0], &fs[1], &fs[2]);


            return fs;
        }

        void * LoaderOBJ::loadFromData(char *data, size_t size) {
            TriMeshBuilder builder;
            TextureMaterialBuilder materialBuilder;
            
            std::vector<std::string> lines = this->makeLines(data);

            for (auto i : lines) {
                char prefix[16], rest[128];

                sscanf(i.c_str(), "%s %s", prefix, rest);
                string prefixS(prefix);

                if (prefixS == "#") {
                    continue;
                } else if (prefixS == "v" || prefixS == "vn") {
                    scalar_t x, y, z;
                    sscanf(rest, "%f %f %f", &x, &y, &z);

                    if (prefixS == "v") {
                        builder.addIndexableVertex(Vector3d(x, y, z));
                    } else if (prefixS == "vn") {
                        builder.addIndexableNormal(Vector3d(x, y, z));
                    }
                } else if (prefixS == "f") {
                    char a[16], b[16], c[16];
                    sscanf(i.c_str(), "%s %s %s %s", prefix, a, b, c);
                    int *af = this->splitFace(a);
                    int *bf = this->splitFace(b);
                    int *cf = this->splitFace(c);

                    builder.addPolyVertex(af[0]);
                    builder.addPolyVertex(bf[0]);
                    builder.addPolyVertex(cf[0]);
                    builder.addPolyNormal(af[2]);
                    builder.addPolyNormal(bf[2]);
                    builder.addPolyNormal(cf[2]);
                      // materialBuilder.setPolyTexture("tex.png");
                    //

                    delete af;
                    delete bf;
                    delete cf;
                }

                // cout << i << endl;
            }

            
            
            
            MeshAndMaterialResult *res = new MeshAndMaterialResult();

            res->mesh = builder.build();
            res->material = materialBuilder.build();

            return res;
            
            

        }

        std::vector<std::string> LoaderOBJ::makeLines(char *data) {
            std::vector<std::string> lines;

            string line; // = boost::replace_all_copy<string>(line);

            for (size_t i = 0; i < strlen(data); i++) {
                if (data[i] == '\n') {
                    lines.push_back(line);
                    line = "";
                    continue;
                }

                line += data[i];
            }

            return lines;
        }

    }
}