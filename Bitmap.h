#ifndef BITMAP_H
#define BITMAP_H

#include <string>
#include <cstdint>
#include <memory>

// #pragma once
using namespace std;

namespace mandelbrotns
{

    class Bitmap
    {

    private:
        int _width{0};
        int _height{0};
        unique_ptr<uint8_t[]> _ptpixels{nullptr};

    public:
        Bitmap(int width, int height);

        bool write(string filename);

        void setpixels(int xp, int yp, uint8_t red, uint8_t green, uint8_t blue);

        virtual ~Bitmap();
    };

}

#endif