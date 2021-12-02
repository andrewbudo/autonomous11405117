#include "ProjTesting.h"
#include <iostream>
#include <iomanip>


void KrovakModifiedNorthOrientated()
{
	std::cout << "Variant 12" << std::endl;
	std::cout << "Projected Coordinate ReferenceSystem: S-JTSK/05 (Ferro) / Modified Krovak" << std::endl;
	double lat = 50.20901166667;
	double lon = 16.849772;
	std::cout << std::fixed << "lat = " << lat << "; lon = " << lon << "\n";
	const char* src = "+proj=longlat +a=6377397.155 +rf=299.15281 +towgs84=0,0,0,0,0,0,0";
	const char* trg = "+proj=krovak +czech +lat_0=49.5 +lon_0=42.5 +alpha=30.28813972222222 +k=0.9999 +x_0=5000000 +y_0=5000000 +ellps=bessel +pm=ferro +units=m";

	double out_N, out_E;
	if (CalcProj(src, trg, lat, lon, out_N, out_E))
	{
		std::cout << std::setprecision(18) << std::fixed
			<< "N =-" << out_E << "; E =-" << out_N << "\n";
	}
	std::cout << "-----------------------------------------" << std::endl;
}
