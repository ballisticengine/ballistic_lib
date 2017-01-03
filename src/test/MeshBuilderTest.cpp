#include <iostream>
#include <limits.h>
#include <gtest/gtest.h>

#include "builders/mesh/AbstractMeshBuilder.hpp"
#include "builders/mesh/TriMeshBuilder.hpp"
#include "types/graphics/Mesh.hpp"

#include "VectorAssert.hpp"

using namespace Ballistic::Core::Builders;
using namespace Ballistic::Core::Types::Graphics;

TEST(Basic, MeshBuilderTest) {
   
    TriMeshBuilder triMb;
    triMb.startPolygon();
    triMb.addPolyVertex(Vector3d(0,-1,0));
    triMb.addPolyVertex(Vector3d(0,1,0));
    triMb.addPolyVertex(Vector3d(1,1,0));
   
    triMb.addPolyNormal(Vector3d(0,-1,0));
    triMb.addPolyNormal(Vector3d(0,1,0));
    triMb.addPolyNormal(Vector3d(1,1,0));
    
    triMb.endPolygon();
    
    Mesh *m = (Mesh *)triMb.build();
    
    ASSERT_EQ(m->n_triangles, 1);
    ASSERT_EQ(m->n_vertices, 3);
    ASSERT_EQ(m->n_normals, 3);
   
    ASSERT_VECTORS_EQ(Vector3d(0,-1,0), m->vertices[m->triangles[0].indices[0]]);
    ASSERT_VECTORS_EQ(Vector3d(0,1,0), m->vertices[m->triangles[0].indices[1]]);
    ASSERT_VECTORS_EQ(Vector3d(1,1,0), m->vertices[m->triangles[0].indices[2]]);
    
//    ASSERT_VECTORS_EQ(Vector3d(0,-1,0), m->normals[m->triangles[0].normals[0]]);
//    ASSERT_VECTORS_EQ(Vector3d(0,1,0), m->normals[m->triangles[0].normals[1]]);
//    ASSERT_VECTORS_EQ(Vector3d(1,1,0), m->normals[m->triangles[0].normals[2]]);
    
}