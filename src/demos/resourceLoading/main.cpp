#include <iostream>

#include "../../core/resources/ResourceManager.hpp"
#include "../../core/resources/ResourceHandle.hpp"
#include "../../core/resources/storage/FilesystemStorageHandler.hpp"
#include "../../loaders/LoaderXML.hpp"

using namespace std;
using namespace Ballistic::Core::Resources;
using namespace Ballistic::Core::Resources::Storage;
using namespace Ballistic::Loaders;

int main() {
    FilesystemStorageHandler fs;
    fs.setWD("../src/test/data");
    ResourceManager resMan(&fs);
    
    LoaderXML loaderXML;
    
    resMan.getLoader().registerStaticPlugin("loaderXML", &loaderXML);
    
    //resMan.get("untitled.xml", "mesh");
    
    return 0;
}