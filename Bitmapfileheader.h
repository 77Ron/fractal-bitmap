#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>

#pragma pack(2)

using namespace std;

namespace mandelbrotns
{

    struct Bitmapfileheader
    {

        char header[2]{'B', 'M'};
        int32_t filesize;
        int32_t reserved{0};
        int32_t dataoffset;
    };

}

#endif