#include "LoaderXML.hpp"

#include "../core/builders/mesh/TriMeshBuilder.hpp"
#include "../core/builders/material/TextureMaterialBuilder.hpp"
#include "../core/types/common.hpp"
#include "../core/types/spatial/Vector3d.hpp"
#include "../core/resources/loader/Results.hpp"

#include <sstream>


namespace Ballistic {
    namespace Loaders {

        using namespace std;
        using namespace boost::property_tree;

        Ballistic::Core::Resources::extensionsSet LoaderXML::getFileExtensions() {
            Ballistic::Core::Resources::extensionsSet exts;
            exts.insert("xml");
            return exts;
        }

      Ballistic::Core::Resources::ResourceType LoaderXML::getType() {
            return Ballistic::Core::Resources::RESOURCE_MESH_AND_MATERIAL;
        }

        void *LoaderXML::loadFromData(char *data, size_t size) {

            using namespace Ballistic::Core::Builders;
            using Ballistic::Core::Types::scalar_t;
            using Ballistic::Core::Types::Spatial::Vector3d;
            using Ballistic::Core::Resources::MeshAndMaterialResult;
            using Ballistic::Core::Types::Graphics::Texture;
            
            TriMeshBuilder builder;
            TextureMaterialBuilder materialBuilder;

            stringstream ss;
            ss << data;
            ptree pt;
            read_xml(ss, pt);

            ptree shp = pt.get_child("shape"),
                    geom = shp.get_child("geom"),
                    verts = geom.get_child("vertices"),
                    faces = geom.get_child("faces"),
                    uvs = geom.get_child("uvs")
                    ;

            size_t
            v_count = verts.size(),
                    f_count = faces.size(),
                    uv_count = uvs.size(),
                    vpf = 3
                    ;

            BOOST_FOREACH(const ptree::value_type &vx, verts) {
                ptree
                coords = vx.second.get_child("coords"),
                        normal = vx.second.get_child("normal"),
                        uv = vx.second.get_child("normal")
                        ;

                scalar_t
                x = coords.get<scalar_t>("x"),
                        y = coords.get<scalar_t>("y"),
                        z = coords.get<scalar_t>("z"),
                        nx = normal.get<scalar_t>("x"),
                        ny = normal.get<scalar_t>("y"),
                        nz = normal.get<scalar_t>("z"),
                        uvx = uv.get<scalar_t>("x"),
                        uvy = uv.get<scalar_t>("y")
                        ;
                builder.addIndexableVertex(Vector3d(x, y, z));
                builder.addIndexableNormal(Vector3d(nx, ny, nz));
                materialBuilder.addIndexableUV(Vector3d(uvx, uvy, 0));
            }
            std::string textureId = "";
            static Texture *tex=0; //TODO: makeshift, get rid of that
            BOOST_FOREACH(const ptree::value_type &face, faces) {
                builder.startPolygon();
                materialBuilder.startPolygon();
                ptree f_verts = face.second.get_child("vertices");

                BOOST_FOREACH(const ptree::value_type &f_vx, f_verts) {
                    size_t index = f_vx.second.get<size_t>("i");
                    builder.addPolyVertex(index);
                    builder.addPolyNormal(index);
                    materialBuilder.addPolyUV(index);
                    materialBuilder.setPolyTexture(tex);

                }

                try {
                    
                    if(textureId=="") {
                        textureId = face.second.get<string>("texture");
                        this->addDependency(textureId, Ballistic::Core::Resources::RESOURCE_TEXTURE, (void **)&tex);
                    }
                                       
                } catch (std::exception e) {

                }

                builder.endPolygon();
                materialBuilder.endPolygon();
            }

            MeshAndMaterialResult *res = new MeshAndMaterialResult();

            res->mesh = builder.build();
            res->material = materialBuilder.build();

            return res;
        }

        
    }
}

