#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void LambertConicConformal2SPBelgium()
{
	std::cout << "Variant 6" << std::endl;
	std::cout << "Projected Coordinate Reference System Belge 1972 / Belge Lambert 72" << std::endl;
	double lat = 50.6795725;
	double lon = 5.80737028;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6378388 +rf=297 +ellps=intl +towgs84=-106.869,52.2978,-103.724,0.3366,-0.457,1.8422,-1.2747";
	const char* trg = "+proj=lcc +lat_0=90 +lon_0=4.35693972 +lat_1=49.833333 +lat_2=51.166667 +y_0=5400088.44 +x_0=150000.01 +a=6378388 +rf=297 +units=m";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
