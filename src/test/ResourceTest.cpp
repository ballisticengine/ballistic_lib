#include <limits.h>
#include <gtest/gtest.h>
#include <iostream>

#include "../core/resources/ResourceManager.hpp"
#include "../core/resources/storage/FilesystemStorageHandler.hpp"
#include "../loaders/TextureLoader.hpp"
#include "types/graphics/Texture.hpp"

using Ballistic::Core::Resources::Storage::FilesystemStorageHandler;
using Ballistic::Core::Resources::Storage::FileData;
using Ballistic::Core::Resources::ResourceManager;
using Ballistic::Core::Resources::ResourceHandle;
using Ballistic::Core::Resources::Loader;
using Ballistic::Core::Resources::extensionsSet;
using Ballistic::Core::Types::Graphics::Texture;
using namespace Ballistic::Loaders;
using namespace Ballistic::Core::Resources;

class TestLoader : public Loader {
public:

    virtual extensionsSet getFileExtensions() {

    }

    virtual std::string getType() {
        return "text";
    }

    virtual void *loadFromData(char *data, size_t size) {
        return (void *) data;
    }
};

class ResourceTest : public ::testing::Test {
protected:

    virtual void SetUp() {
        this->fsh = new FilesystemStorageHandler();
        this->fsh->setWD("../src/test/data");
        this->resMan = new ResourceManager(this->fsh);
    }

    virtual void TearDown() {
        delete this->fsh;
        delete this->resMan;
    }

    ResourceManager *resMan;
    FilesystemStorageHandler *fsh;
};

TEST_F(ResourceTest, FSLoader) {
    FilesystemStorageHandler fsh;
    fsh.setWD("../src/test/data");
    FileData fd = fsh.getResource("text.txt");
    ASSERT_EQ(10, fd.size);

    std::cout << fd.data << std::endl; //TODO: make actual test here

    delete fd.data;
}

TEST_F(ResourceTest, ManagerStatic) {

    TestLoader *testLoader = new TestLoader();
    this->resMan->getLoader().registerStaticPlugin("testLoader", testLoader);
    ResourceHandle resHandle = this->resMan->get("text.txt", "text");
    // std::cout << "Res: " << (char *)resHandle.getData() << std::endl;

}

TEST_F(ResourceTest, TextureLoader) {
    TextureLoader textureLoader;
    this->resMan->getLoader().registerStaticPlugin("textureLoader", &textureLoader);

    ResourceHandle handle = this->resMan->get("tex.gif", "texture");
    Texture *tex = (Texture *) handle.getData();

    ASSERT_FALSE(tex == 0);
    ASSERT_EQ(tex->width, 256);
    ASSERT_EQ(tex->height, 256);
    ASSERT_EQ(tex->bpp, 4);
}