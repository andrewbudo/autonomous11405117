#include "ProjTesting.h"
#include <iostream>
#include <iomanip>

void LambertConicNearConformal()
{
	std::cout << "variant 8(p26)" << std::endl;
	std::cout << "Projected Coordinate Reference System: Deir ez Zor / Levant Zone" << std::endl;

	double lat = 37.521563;
	double lon = 34.13647;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6378249.2 +rf=293.4660213 +wgs84=0,0,0,0,0,0,0";
		const char* trg = "+proj=lcc +lat_1=34.65 +lat_0=34.65 +lon_0=37.35 +k_0=0.9996256 +x_0=300000 +y_0=300000 +a=6378249.2 +rf=293.4660213 +wgs84=0,0,0,0,0,0,0 +units=m";

		double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;

}