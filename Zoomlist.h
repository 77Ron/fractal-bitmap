#ifndef ZOOMLIST_H
#define ZOOMLIST_H

#include <vector>
#include <utility>
#include "Zoom.h"

using namespace std;

// #pragma once

namespace mandelbrotns
{

    class Zoomlist
    {
    private:
        double _xcentre{0.0};
        double _ycentre{0.0};
        double _scale{1.0};
        int _width{0};
        int _height{0};

        vector<Zoom> zooms;

    public:
        // Zoomlist();
        Zoomlist(int width, int height);
        void addzoom(const Zoom &zoom);
        pair<double, double> dozoom(int xza, int yza);
    };

}

#endif