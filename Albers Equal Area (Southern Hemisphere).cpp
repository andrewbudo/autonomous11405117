
#include <iostream>
#include <proj.h>
#include <iomanip>

int main()
{
    std::cout << "Our Proj Tests" << std::endl;
    PJ* P;
    PJ_COORD c, c_out;

    P = proj_create_crs_to_crs(
        PJ_DEFAULT_CTX,
        "+proj=longlat +a=6378160.0 +rf=298.25 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +no_defs",
        "+proj=aea +lat_1=-5.0 +lat_2=-42.0 +lat_0=-32.0 +lon_0=-60.0 +x_0=0 +y_0=0 +ellps=GRS80 +towgs84=0,0,0,0,0,0,0 +units=m +no_defs",
        NULL);
    if (P == 0)
        return 1;

    double lat = -18.50056;
    double lon = -46.00042722;

    c.lpzt.phi = lat;
    c.lpzt.lam = lon;
    c.lpzt.z = 0.0;
    c.lpzt.t = HUGE_VAL;

    c_out = proj_trans(P, PJ_FWD, c);

    std::cout << std::setprecision(18) << std::fixed << "N = " << c_out.xy.y << "; E = " << c_out.xy.x << "\n";
    proj_destroy(P);
    return 0;
}
