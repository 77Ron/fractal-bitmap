#ifndef BITMAPINFOHEADER_H
#define BITMAPINFOHEADER_H

#include <cstdint>

#pragma pack(2)

using namespace std;

namespace mandelbrotns
{

    struct Bitmapinfoheader
    {

        int32_t headerize{40};
        int32_t width;
        int32_t height;
        int16_t planes{1};
        int16_t bitsperpixel{24};
        int32_t compression{0};
        int32_t datasize{0};
        int32_t horisontalresolution{2400};
        int32_t verticalresolution{2400};
        int32_t colours{0};
        int32_t importantcolours{0};
    };

}

#endif