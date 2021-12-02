#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void LambertConicConformal2SPAksenova()
{
	std::cout << "Example 1" << std::endl;
	std::cout << "Projected Coordinate Reference System: NAD27/Texas South Central(EPSG CRS code 32040)" << std::endl;
	double lat = 28.5;
	double lon = -96.0;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6378206.400 +rf=294.97870 +wgs84=0,0,0,0,0,0,0";
	const char* trg = "+proj=lcc +lat_1=28.383333333 +lat_2=30.28333333333333 +lat_0=27.83333333333333 +lon_0=-99 +a=6378206.400 +rf=294.97870 +x_0=609601.2192024384 +y_0=0 +wgs84=0,0,0,0,0,0,0 +units=us-ft";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
