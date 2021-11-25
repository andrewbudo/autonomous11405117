#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void BritishNationalGrid()
{
    std::cout << "Example 1" << std::endl;
    std::cout << "Projected Coordinate Reference System OSGB 1936 / British National Grid" << std::endl;
    double lat = 50.5;
    double lon = 0.5;
    std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
    const char* src = "+proj=longlat +a=6377563.396 +rf=299.32496 +wgs84=0000000";
    const char* trg = "+proj=tmerc +lat_0=49 +lon_0=-2 +k=0.9996012717 +x_0=400000 +y_0=-100000 +a=6377563.396 +rf=299.32496 +units=m";

    double out_N, out_E;
    if (CalcProj(src, trg, lat, lon, out_N, out_E))
    {
        std::cout << std::setprecision(18) << std::fixed 
            << "N = " << out_N << "; E = " << out_E << "\n";
    }
    std::cout << "-----------------------------------------" << std::endl;
}
