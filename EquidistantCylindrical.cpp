#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void EquidistantCylindrical()
{
	std::cout << "Variant 6 (p.71)" << std::endl;
	std::cout << "Coordinate Reference System: WGS84 / World Equidistant Cylindrical" << std::endl;
	double lat = 55;
	double lon = 10;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +e=0.08181919084262 +a=6378137 +rf=298.257223563  +ellps=WGS84 +units=m no_defs +towgs84=0,0,0,0,0,0,0";
	const char* trg = "+proj=eqc +lat_0=0 +lon_0=0 +x_0=0 +y_0=0 +datum=WGS84 +units=m +no_defs";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
