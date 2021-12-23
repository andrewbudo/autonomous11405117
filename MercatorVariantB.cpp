#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void MercatorVariantB()
{
    // p.45
    std::cout << "Example 16" << std::endl;
    std::cout << "For Projected Coordinate Reference System: Pulkovo 1942 / Caspian Sea Mercator / MercatorVariantB" << std::endl;
	
    double lat = 53;
    double lon = 53;
    std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
    const char* src = "+proj=longlat +datum=WGS84";
    const char* trg = "+proj=merc +lon_0=51 +lat_ts=42 +a=6378245.0 +rf=298.3 +units=m +no_defs";

    double out_N, out_E;
    if (CalcProj(src, trg, lat, lon, out_N, out_E))
    {
        std::cout << std::setprecision(18) << std::fixed 
            << "N = " << out_N << "; E = " << out_E << "\n";
    }
    std::cout << "-----------------------------------------" << std::endl;
}
