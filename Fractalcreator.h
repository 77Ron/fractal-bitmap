#ifndef FRACTALCREATOR_H
#define FRACTALCREATOR_H

// #pragma once
#include <string>
#include "Mandelbrot.h"
#include "RGB.h"
#include "Zoom.h"
#include "Zoomlist.h"
#include "Bitmap.h"

using namespace std;

namespace mandelbrotns
{

    class Fractalcreator
    {
    private:
        int f_width;
        int f_height;
        int f_max;
        int f_seed[0];
        unique_ptr<int[]> fractal{nullptr};
        unique_ptr<int[]> histogram{nullptr};
        int total{0};
        Bitmap f_bitmap;
        Zoomlist f_zoomlist;

        vector<int> _ranges;
        vector<RGB> _colours;
        vector<int> _rangetotals;

        bool _gotfirst{false};
        
        void ranges(int f_seed);
        void calculateiterations();
        void drawfractal();
        int getrange(int iteratiions) const;
        void writebitmap(string name);

    public:
        Fractalcreator(int width, int height);
        void fractalzoom(int zx, int zy, double zs);
        void addrange(double rangeend, const RGB &RGB);
        void calculaterangetotals();
        void run(string name, int f_seed);

        // Why is this virtual?
        virtual ~Fractalcreator();
    };

}

#endif