#include <iostream>
#include <proj.h>
#include <iomanip>

#include "BritishNationalGrid.h"
#include "MercatorVariantB.h"
#include "Amersfoort.h"

bool CalcProj(
    const char* src, //"EPSG:4326"
    const char* trg, 
    double input_first,
    double input_second,
    double& out_first,
    double& out_second
)
{
	/*
	PJ *proj_create_conversion_lambert_conic_conformal_2sp_michigan(
    PJ_CONTEXT *ctx, double latitude_false_origin,
    double longitude_false_origin, double latitude_first_parallel,
    double latitude_second_parallel, double easting_false_origin,
    double northing_false_origin, double ellipsoid_scaling_factor,
    const char *ang_unit_name, double ang_unit_conv_factor,
    const char *linear_unit_name, double linear_unit_conv_factor)
	*/


    PJ* P;
    PJ_COORD c, c_out;

	
    P = proj_create_crs_to_crs(PJ_DEFAULT_CTX, src, trg, NULL);

    if (P == 0)
    {
        std::cout << "Something go wrong :(" << std::endl;
        return false;
    }

    c.lpzt.phi = input_first;  // lat;
    c.lpzt.lam = input_second; // lon;
    c.lpzt.z = 0.0;
    c.lpzt.t = HUGE_VAL;

    c_out = proj_trans(P, PJ_FWD, c);
    proj_destroy(P);

    out_first = c_out.xy.y;
    out_second = c_out.xy.x;
    return true;
}

int main()
{
    std::cout << "Our Proj Tests" << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    BritishNationalGrid();
    MercatorVariantB();
	Amersfoort();
    return 0;
}