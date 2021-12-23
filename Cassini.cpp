#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void Cassini()
{
	std::cout << "Variant 30 (p.50)" << std::endl;
	std::cout << "Projected Coordinate Reference System: Trinidad 1903 / Trinidad Grid" << std::endl;
	double lat = 10;
	double lon = 62;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=31706587.88 +rf=294.2606764 +units=link no_defs +towgs84=0,0,0,0,0,0,0";
	const char* trg = "+proj=cass +lat_0=10.441667 +lon_0=-61.3333 +x_0=430000 +y_0=325000 +a=31706587.88 +rf=294.2606764 +units=link +no_defs";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}