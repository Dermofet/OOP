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

TEST(ALL_GETTERS, GETTER_1)
{
    geom::Catenary C = geom::Catenary(-5, 3, 0, 2);

    ASSERT_FLOAT_EQ(3.7768478, C.get_y((float)2.5, true));
    ASSERT_FLOAT_EQ(7.8966355, C.get_y((float)-4.1, true));

    ASSERT_FLOAT_EQ(16.358967, C.get_ArcLength());
    ASSERT_FLOAT_EQ(3.35241, C.get_RadOfCurvature((float)-1.5));
    ASSERT_FLOAT_EQ(5.638217, C.get_CenterOfCurvature((float)-1.5).x);
    ASSERT_FLOAT_EQ(5.9417763, C.get_CenterOfCurvature((float)-1.5).y);
    ASSERT_FLOAT_EQ(32.717934, C.get_Square());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
