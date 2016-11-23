#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "meshBuilder/AbstractMeshBuilder.hpp"
#include "meshBuilder/TriMeshBuilder.hpp"
#include "types/graphics/Mesh.hpp"

#include "VectorAssert.hpp"

using namespace Ballistic::Core::MeshBuilder;
using namespace Ballistic::Core::Types::Graphics;

TEST(Basic, MeshBuilderTest) {
   
    TriMeshBuilder triMb;
    triMb.startPolygon();
    triMb.addPolyVertex(Vector3d(0,-1,0));
    triMb.addPolyVertex(Vector3d(0,1,0));
    triMb.addPolyVertex(Vector3d(1,1,0));
    triMb.endPolygon();
    Mesh *m = (Mesh *)triMb.build();
    
    ASSERT_EQ(m->n_triangles, 1);
    ASSERT_EQ(m->n_vertices, 3);
   
    ASSERT_VECTORS_EQ(Vector3d(0,-1,0), m->vertices[m->triangles[0].indices[0]]);
    ASSERT_VECTORS_EQ(Vector3d(0,1,0), m->vertices[m->triangles[0].indices[1]]);
    ASSERT_VECTORS_EQ(Vector3d(1,1,0), m->vertices[m->triangles[0].indices[2]]);
    
}