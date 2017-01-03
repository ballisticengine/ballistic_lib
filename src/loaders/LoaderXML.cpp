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

        std::string LoaderXML::getType() {
            return "meshAndMaterial";
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
                        this->addDependency(textureId, "texture", (void **)&tex);
                    }
                                       
                } catch (std::exception e) {

                }

                builder.endPolygon();
                materialBuilder.startPolygon();
            }

            MeshAndMaterialResult *res = new MeshAndMaterialResult();

            res->mesh = builder.build();
            res->material = materialBuilder.build();

            return res;
        }

        //        void LoaderXML::toShape(ptree &geom, ptree &shape_xml, void *s) {

        //            ptree
        //            verts = geom.get_child("vertices"),
        //                    faces = geom.get_child("faces"),
        //                    uvs = geom.get_child("uvs")
        //                    ;
        //            size_t
        //            v_count = verts.size(),
        //                    f_count = faces.size(),
        //                    uv_count = uvs.size(),
        //                    vpf = 3
        //                    ;
        //
        //
        //            string type;
        //            try {
        //                type = shape_xml.get<string>("type");
        //            } catch (std::exception e) {
        //                type = "level";
        //            }
        //
        //
        //
        //            s->f_count = f_count;
        //            s->v_count = v_count;
        //            s->v_per_poly = vpf;
        //            s->uv_count = uv_count;
        //            s->vertices = new v_type[v_count];
        //            s->normals = new n_type[v_count];
        //            s->faces = new Face[f_count];
        //            //s->uvs = new uv[uv_count];
        //            s->textures = new Ballistic::Types::Texture*[f_count];
        //            s->materials = new Material*[f_count];
        //            s->frame_count = 0;
        //            int i;
        //
        //            i = 0;
        //
        //            BOOST_FOREACH(const ptree::value_type &vx, verts) {
        //                ptree
        //                coords = vx.second.get_child("coords"),
        //                        normal = vx.second.get_child("normal")
        //                        ;
        //                scalar_t
        //                x = coords.get<scalar_t>("x"),
        //                        y = coords.get<scalar_t>("y"),
        //                        z = coords.get<scalar_t>("z"),
        //                        nx = normal.get<scalar_t>("x"),
        //                        ny = normal.get<scalar_t>("y"),
        //                        nz = normal.get<scalar_t>("z")
        //                        ;
        //                s->vertices[i].x = x;
        //                s->vertices[i].y = y;
        //                s->vertices[i].z = z;
        //                s->normals[i].x = nx;
        //                s->normals[i].y = ny;
        //                s->normals[i].z = nz;
        //
        //                Vector3d norm;
        //
        //                i++;
        //            }
        //
        //            i = 0;
        //
        //            int n = 0, uvc = 0;
        //
        //            BOOST_FOREACH(const ptree::value_type &face, faces) {
        //                ptree f_verts = face.second.get_child("vertices");
        //                s->faces[i].index = new unsigned int[vpf];
        //                s->faces[i].uvs = new UV[vpf];
        //                s->faces[i].normals = new Vector3d[vpf];
        //
        //                try {
        //
        //
        //                    string texname = face.second.get<string>("texture");
        //
        //                    //Texture *t = (Texture *) TextureFactory::getInstance()->get(texname, this->force_common);
        //                    //  Texture *t;
        //                    //s->textures[i] = t;
        //                    this->addDependency(texname, (void **) &s->textures[i]);
        //                    //s->textures[i] = 0;
        //                } catch (std::exception e) {
        //                    s->textures[i] = 0;
        //
        //                }
        //
        //                try {
        //                    ptree material = face.second.get_child("material");
        //                    ColorRGBA sc, dc;
        //
        //                    sc.r = material.get<scalar_t>("specular.r");
        //                    sc.g = material.get<scalar_t>("specular.g");
        //                    sc.b = material.get<scalar_t>("specular.b");
        //                    dc.r = material.get<scalar_t>("diffuse.r");
        //                    dc.g = material.get<scalar_t>("diffuse.g");
        //                    dc.b = material.get<scalar_t>("diffuse.b");
        //                    scalar_t shin = material.get<scalar_t>("shining"),
        //                            emit = material.get<scalar_t>("emit")
        //                            ;
        //                    Material *m = new Material();
        //                    m->setShininess(shin);
        //                    m->setEmission(emit);
        //                    m->setDiffuse(dc);
        //                    m->setSpecular(sc);
        //                    s->materials[i] = m;
        //                } catch (std::exception e) {
        //                    s->materials[i] = 0;
        //                }
        //
        //                n = 0;
        //
        //                BOOST_FOREACH(const ptree::value_type &f_vx, f_verts) {
        //                    size_t index = f_vx.second.get<size_t>("i");
        //                    s->faces[i].index[n] = index;
        //                    ptree uv = f_vx.second.get_child("uv");
        //                    s->faces[i].uvs[n].u = uv.get<scalar_t>("u");
        //                    s->faces[i].uvs[n].v = uv.get<scalar_t>("v");
        //                    s->faces[i].normals[n] = s->normals[index];
        //                    uvc++;
        //                    n++;
        //
        //                }
        //                i++;
        //            }
        //
        //
        //            if (type == "animation") {
        //                ptree frames = shape_xml.get_child("frames");
        //                size_t frame_count = shape_xml.get<size_t>("frame_count");
        //                s->frame_count = frame_count;
        //                s->frames = new Frame[frame_count];
        //                s->frame_times = new scalar_t[frame_count];
        //                size_t frame_i = 0, vert_i;
        //
        //                BOOST_FOREACH(const ptree::value_type &frame, frames) {
        //                    ptree frame_verts = frame.second.get_child("vertices");
        //                    s->frames[frame_i].verts = new v_type[v_count];
        //                    s->frames[frame_i].fnum = frame.second.get<scalar_t>("fnum");
        //                    s->frames[frame_i].fval = frame.second.get<scalar_t>("fval");
        //                    s->frame_times[frame_i] = frame.second.get<scalar_t>("ftime");
        //                    vert_i = 0;
        //
        //                    BOOST_FOREACH(const ptree::value_type &vert, frame_verts) {
        //                        scalar_t
        //                        x = vert.second.get<scalar_t>("x"),
        //                                y = vert.second.get<scalar_t>("y"),
        //                                z = vert.second.get<scalar_t>("z")
        //                                ;
        //                        s->frames[frame_i].verts[vert_i].x = x;
        //                        s->frames[frame_i].verts[vert_i].y = y;
        //                        s->frames[frame_i].verts[vert_i].z = z;
        //                        vert_i++;
        //
        //                    }
        //                    frame_i++;
        //
        //                }
        //            }
        //
        //
        //            scalar_t slocx = 0, slocy = 0, slocz = 0;
        //
        //            try {
        //                slocx = shape_xml.get<scalar_t>("loc.x");
        //                slocy = shape_xml.get<scalar_t>("loc.y");
        //                slocz = shape_xml.get<scalar_t>("loc.z");
        //            } catch (std::exception e) {
        //                cout << "No loc for " << type;
        //            }

        //        }
    }
}

