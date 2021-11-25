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
        "+proj=longlat +datum=WGS84 +no_defs", //"EPSG:4326",
        "+proj=tmerc +lat_0=0 +lon_0=27 +k=1 +x_0=5500000 +y_0=0 +ellps=krass +towgs84=24.47,-130.89,-81.56,-0,-0,0.13,-0.22 +units=m +no_defs",
        NULL);

    if (P == 0)
        return 1;

    double lat = 52.0;
    double lon = 27.0;

    c.lpzt.phi = lat;
    c.lpzt.lam = lon;
    c.lpzt.z = 0.0;
    c.lpzt.t = HUGE_VAL;

    c_out = proj_trans(P, PJ_FWD, c);

    std::cout << std::setprecision(18) << std::fixed << "N = " << c_out.xy.y << "; E = " << c_out.xy.x << "\n";
    // 5763462,701654 5500125,253360						     
    proj_destroy(P);
    return 0;
}