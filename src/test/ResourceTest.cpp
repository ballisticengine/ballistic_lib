#include <limits.h>
#include <gtest/gtest.h>
#include <iostream>

#include "../core/resources/ResourceManager.hpp"
#include "../core/resources/storage/FilesystemStorageHandler.hpp"

using Ballistic::Core::Resources::Storage::FilesystemStorageHandler;
using Ballistic::Core::Resources::Storage::FileData;
using Ballistic::Core::Resources::ResourceManager;
using Ballistic::Core::Resources::ResourceHandle;
using Ballistic::Core::Resources::Loader;
using Ballistic::Core::Resources::extensionsSet;

class TestLoader : public Loader {
public:

    virtual extensionsSet getFileExtensions() {

    }

    virtual std::string getType() {
        return "text";
    }

    virtual void *loadFromData(char *data, size_t size) {
        return (void *)data;
    }
};

TEST(ResourceTest, FSLoader) {
    FilesystemStorageHandler fsh;
    fsh.setWD("../src/test/data");
    FileData fd = fsh.getResource("text.txt");
    ASSERT_EQ(10, fd.size);

    std::cout << fd.data << std::endl; //TODO: make actual test here

    delete fd.data;
}

TEST(ResourceTest, ManagerStatic) {
    FilesystemStorageHandler fsh;
    fsh.setWD("../src/test/data");
    ResourceManager resMan(&fsh);
    TestLoader *testLoader = new TestLoader();
    resMan.getLoader().registerStaticPlugin("testLoader", testLoader);
    ResourceHandle resHandle = resMan.get("text.txt", "text");
   // std::cout << "Res: " << (char *)resHandle.getData() << std::endl;

}