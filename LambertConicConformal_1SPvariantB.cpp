#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void  LambertConicConformal_1SPvariantB()
{
	std::cout << "Variant 5(p23)" << std::endl;
	std::cout << "Lambert Conic Conformal (1SP variant B) " << std::endl;
	double lat = 47;
	double lon = 7;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6378137.0 +rf=298.2572221 +towgs84=0,0,0,0,0,0,0 +no_defs";
	const char* trg = "+proj=lcc +lat_1=44.37916666666667 +lat_0=45.18333333333333 +lon_0=6.816666666666666 +x_0=150000 +y_0=50000 +k_0=1 +ellps=GRS80 +units=m + no_defs";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E = " << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
