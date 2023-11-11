#include "PolyCube.hpp"
#include <iostream>

int main(int argc, char** argv)
{
    PolyCube::PointList cubes_1 ({{0,0,0}, {1,1,1}});
    PolyCube::PointList cubes_2 ({{1,1,1}, {0,0,0}});
    PolyCube::PointList cubes_3 ({{1,1,1}, {0,0,1}});
    PolyCube::PointList cubes_4 ({{1,1,1}, {2,2,2}});
    std::cout << "cube_1 == cube_1: " << (cubes_1 == cubes_1) << std::endl;
    std::cout << "cube_1 == cube_2: " << (cubes_1 == cubes_2) << std::endl;
    std::cout << "cube_1 == cube_3: " << (cubes_1 == cubes_3) << std::endl;
    std::cout << "cube_1 == cube_4: " << (cubes_1 == cubes_4) << std::endl;
    return 10;
}
