#ifndef LOADER_XML_H
#define LOADER_XML_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include <string>
#include <iostream>

#include "../core/types/graphics/Mesh.hpp"
#include "../core/types/graphics/Texture.hpp"
#include "../core/types/graphics/materials/Material.hpp"
#include "../core/resources/loader/Loader.hpp"

namespace Ballistic {
    namespace Loaders {

        struct LoaderXMLResult {
            Ballistic::Core::Types::Graphics::Mesh *mesh;
            Ballistic::Core::Types::Graphics::Materials::Material *material;
        };
        
        class LoaderXML : public Ballistic::Core::Resources::Loader {

        public:
            virtual Ballistic::Core::Resources::extensionsSet getFileExtensions();
            virtual std::string getType();
            //TODO: below function should return struct with mesh, mtl and texture
            virtual void *loadFromData(char *data, size_t size);
        };
    }
}


#endif