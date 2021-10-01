#include "pch.h"
#include "C:\Users\pi-77\source\repos\lab2\lab2\Catenary.cpp"

TEST(ALL_CONSTRUCTOR, CONSTRUCTOR_1)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);
    ASSERT_GT(C.get_Vert().x, C.get_LLim().x);
    ASSERT_GT(C.get_RLim().x, C.get_LLim().x);
    ASSERT_LT(C.get_Vert().x, C.get_RLim().x);
    ASSERT_LT(C.get_Vert().y, C.get_LLim().y);
    ASSERT_LT(C.get_Vert().y, C.get_RLim().y);
}

TEST(ALL_FIND, FIND_Y)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);

    ASSERT_FLOAT_EQ(3.7768478, C.find_y((float)2.5, true));
    ASSERT_FLOAT_EQ(7.8966355, C.find_y((float)-4.1, true));
    ASSERT_ANY_THROW(C.find_y((float)-6, true));
    ASSERT_ANY_THROW(C.find_y((float)4, true));
}

TEST(ALL_FIND, FIND_ARCLENGTH)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);
    ASSERT_FLOAT_EQ(16.358967, C.find_ArcLength());
}

TEST(ALL_FIND, FIND_RADOFCURVUATE)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);

    ASSERT_FLOAT_EQ(3.35241, C.find_RadOfCurvature((float)-1.5));
    ASSERT_ANY_THROW(C.find_RadOfCurvature((float)-6));
    ASSERT_ANY_THROW(C.find_RadOfCurvature((float)4));
}

TEST(ALL_FIND, FIND_CENTEROFCURVUATE)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);

    ASSERT_FLOAT_EQ(5.638217, C.find_CenterOfCurvature((float)-1.5).x);
    ASSERT_FLOAT_EQ(5.9417763, C.find_CenterOfCurvature((float)-1.5).y);
    ASSERT_ANY_THROW(C.find_CenterOfCurvature((float)-6));
    ASSERT_ANY_THROW(C.find_CenterOfCurvature((float)4));
}

TEST(ALL_FIND, FIND_AREA)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);

    ASSERT_FLOAT_EQ(32.717934, C.find_Area());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
