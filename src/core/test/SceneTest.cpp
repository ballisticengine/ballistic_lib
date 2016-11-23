#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "../../scene/Object.hpp"
#include "../types/graphics/Mesh.hpp"
#include "../types/graphics/Color.hpp"
#include "../types/graphics/materials/Material.hpp"
#include "../types/graphics/materials/SimpleColorMaterial.hpp"

using namespace Ballistic::Scene;
using namespace Ballistic::Core::Types::Graphics;
using namespace Ballistic::Core::Types::Graphics::Materials;

TEST(Functional, SceneObjectTest) {
    Mesh mesh;
    SimpleColorMaterial material(Color(1,1,1,0));
    Object o(&mesh, &material);
    
    SimpleColorMaterial *mtl = (SimpleColorMaterial *)o.getMaterial()->getMaterialData();
    ASSERT_EQ(mtl->getType(), "SimpleColor");
    
}


