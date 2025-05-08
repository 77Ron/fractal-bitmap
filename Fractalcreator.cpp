#include <iostream>
#include "Fractalcreator.h"
#include "assert.h"

using namespace std;

namespace mandelbrotns
{

    Fractalcreator::Fractalcreator(int width, int height) : f_width(width), f_height(height),
                                                            f_max(Mandelbrot::MAX_ITERATIONS), fractal{new int[width * height]{0}}, histogram{new int[f_max]{0}},
                                                            f_bitmap(f_width, f_height), f_zoomlist(f_width, f_height)
    {

        f_zoomlist.addzoom(Zoom(f_width / 2, f_height / 2, 4.0 / f_width));
    }

    void Fractalcreator::fractalzoom(int zx, int zy, double zs)
    {
        f_zoomlist.addzoom(Zoom(zx, zy, zs));
    }

    void Fractalcreator::ranges(int f_seed)
    {
        srand(f_seed);

        double r2{0.1 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1 - 0.1)))};
        double r3{r2 + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (1 - r2)))};
        cout << "Range: 0.0 " << r2 << " " << r3 << " 1.5" << endl;

        addrange(0.0, RGB(rand() % 255, rand() % 255, rand() % 255));
        addrange(r2, RGB(rand() % 255, rand() % 255, rand() % 255));
        addrange(r3, RGB(rand() % 255, rand() % 255, rand() % 255));
        addrange(1.5, RGB(rand() % 255, rand() % 255, rand() % 255));
    }

    void Fractalcreator::addrange(double rangeend, const RGB &RGB)
    {

        _ranges.push_back(rangeend * f_max);
        _colours.push_back(RGB);

        if (_gotfirst == true)
        {
            _rangetotals.push_back(0);
        }
        else
            _gotfirst = true;
    }

    int Fractalcreator::getrange(int its) const
    {
        int range = 0;
        for (int i = 0; i < _ranges.size(); i++)
        {
            range = i;
            if (_ranges[i] > its)
            {
                break;
            }
        }

        range--;

        // Check that range is within vector size.
        assert(range > -1);
        assert(range < _ranges.size());

        return range;
    }

    void Fractalcreator::run(string name, int f_seed)
    {   
        ranges(f_seed);
        calculateiterations();
        calculaterangetotals();
        drawfractal();
        writebitmap(name);
    }

    void Fractalcreator::calculateiterations()
    {

        for (int y = 0; y < f_height; y++)
        {

            cout << "." << flush;

            for (int x = 0; x < f_width; x++)
            {

                pair<double, double> coord = f_zoomlist.dozoom(x, y);

                int iterate = Mandelbrot::getiterations(coord.first, coord.second);

                fractal[y * f_width + x] = iterate;

                if (iterate != f_max)
                {
                    histogram[iterate]++;
                    total++;
                }
            }
        }
    }

    void Fractalcreator::calculaterangetotals()
    {
        int rangeindex = -1;

        for (int i = 0; i < f_max; i++)
        {
            int pixels = histogram[i];
            if (i >= _ranges[rangeindex + 1])
            {
                rangeindex++;
            }
            _rangetotals[rangeindex] += pixels;
        }

        cout << endl;
        for (int i : _rangetotals)
        {
            cout << "Range total: " << i << endl;
        }
        cout << "Matching total: " << total << endl;
    }

    void Fractalcreator::drawfractal()
    {

        for (int y = 0; y < f_height; y++)
        {

            cout << "." << flush;

            for (int x = 0; x < f_width; x++)
            {

                int iterate = fractal[y * f_width + x];

                int range = getrange(iterate);
                int rangetotal = _rangetotals[range];
                int rangestart = _ranges[range];

                RGB startcolour = _colours[range];
                RGB endcolour = _colours[range + 1];
                RGB diffcolour = endcolour - startcolour;

                uint8_t redi = 0;
                uint8_t greeni = 0;
                uint8_t bluei = 0;

                if (iterate != f_max)
                {

                    // double hue = 0.0;
                    int totalpixels = 0;

                    for (int i = rangestart; i <= iterate; i++)
                    {
                        totalpixels += histogram[i];
                        // hue += ((double)histogram[i]) / total;
                    }

                    redi = startcolour.r + ((diffcolour.r * (double)totalpixels) / rangetotal);
                    greeni = startcolour.g + ((diffcolour.g * (double)totalpixels) / rangetotal);
                    bluei = startcolour.b + ((diffcolour.b * (double)totalpixels) / rangetotal);
                }

                f_bitmap.setpixels(x, y, redi, greeni, bluei);
            }
        }
    }

    void Fractalcreator::writebitmap(string name)
    {
        f_bitmap.write(name);
    }

    Fractalcreator::~Fractalcreator()
    {
    }

}