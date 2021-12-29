#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void LambertConicConformalSouthernHemisphere()
{
	std::cout << "Example 1" << std::endl;
	std::cout << "Projected Coordinate Reference System: AGD66 / Vicgrid66 (EPSG CRS code 3110)" << std::endl;
	double lat = -37.75;
	double lon = 145.75;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6378160.0 +rf=298.25 +wgs84=0,0,0,0,0,0,0";
	const char* trg = "+proj=lcc +lat_1=-36 +lat_2=-38 +lat_0=-37 +lon_0=145 +a=6378160.0 +rf=298.25 +x_0=2500000 +y_0=4500000 +wgs84=0,0,0,0,0,0,0 +units=m";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
