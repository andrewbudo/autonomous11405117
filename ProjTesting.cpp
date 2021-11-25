#include <iostream>
#include <proj.h>
#include <iomanip>

#include "BritishNationalGrid.h"
#include "MercatorVariantD.h"

bool CalcProj(
    const char* src, //"EPSG:4326"
    const char* trg, 
    double input_first,
    double input_second,
    double& out_first,
    double& out_second
)
{
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
    MercatorVariantD();
    return 0;
}