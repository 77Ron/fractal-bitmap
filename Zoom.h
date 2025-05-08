#ifndef ZOOM_H
#define ZOOM_H

// #pragma once

namespace mandelbrotns
{

    struct Zoom
    {
        int xz{0};
        int yz{0};
        double scale{0.0};

        Zoom(int xz, int yz, double scale) : xz(xz), yz(yz), scale(scale){};
    };

}
#endif