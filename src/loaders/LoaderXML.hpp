#ifndef LOADER_XML_H
#define LOADER_XML_H

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>

#include <string>
#include <iostream>

#include "../core/resources/loader/Loader.hpp"

using namespace std;
using namespace boost::property_tree;

namespace Ballistic {
    namespace Loaders {

        class LoaderXML : public Ballistic::Core::Resources::Loader {
        protected:
            void toShape(ptree &geom, ptree &shape_xml, void *s);
        public:
            virtual Ballistic::Core::Resources::extensionsSet getFileExtensions();
            virtual std::string getType();
            virtual void *loadFromData(char *data, size_t size);
        };
    }
}


#endif