#include "ProjTesting.h"
#include <iostream>
#include <iomanip>

void Krovak()
{
	std::cout << "Variant 10(p31)" << std::endl;
	std::cout << "Krovak" << std::endl;
	double lat = 50.20901166667;
	double lon = 16.849772;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6377397.155 +rf=299.15281 +towgs84=0,0,0,0,0,0,0 +no_defs";
	const char* trg = "+proj=krovak  +lat_0=49.5 +lon_0=42.5 +alpha=30.28813972222222 +k=0.9999 +x_0=0 +y_0=0 +ellps=bessel +pm=ferro +units=m +no_defs";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N = " << out_N << "; E =" << out_E << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
