#include <limits.h>
#include <gtest/gtest.h>

#include "VectorTest.cpp"
#include "ModuleTest.cpp"
#include "EventTest.cpp"
#include "PipelineTest.cpp"

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}