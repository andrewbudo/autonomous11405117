#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void Amersfoort()
{
	std::cout << "Example 7" << std::endl;
	std::cout << "Projected Coordinate Reference System OSGB 1936 / Amersfoort" << std::endl;
	double lat = 53;
	double lon = 6;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +datum=WGS84";
	const char* trg = "+proj=tmerc +lon_0=5.387639 +lat_0=52.156161 +a=6377397.155 +rf=299.15281 +x_o=155000 +y_0=463000 +k_0=0.9999079 +e=0.08169683 +units=m";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
