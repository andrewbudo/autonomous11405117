#pragma once
bool CalcProj(
    const char* src, //"EPSG:4326"
    const char* trg,
    double input_first,
    double input_second,
    double& out_first,
    double& out_second
);

