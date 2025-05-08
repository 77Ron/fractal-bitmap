
#include <fstream>
#include "Bitmap.h"
#include "Bitmapfileheader.h"
#include "Bitmapinfoheader.h"

namespace mandelbrotns
{

    Bitmap::Bitmap(int width, int height) : _width(width), _height(height), _ptpixels(new uint8_t[width * height * 3]{}) {}

    bool Bitmap::write(string filename)
    {

        Bitmapfileheader fileheader;
        Bitmapinfoheader infoheader;

        fileheader.filesize = sizeof(Bitmapinfoheader) + sizeof(Bitmapfileheader) + (_width * _height * 3);
        fileheader.dataoffset = sizeof(Bitmapinfoheader) + sizeof(Bitmapfileheader);

        infoheader.width = _width;
        infoheader.height = _height;

        fstream file;

        file.open(filename, ios::binary | ios::out);

        if (file.is_open())
        {

            file.write((char *)&fileheader, sizeof(fileheader));
            file.write((char *)&infoheader, sizeof(infoheader));
            file.write((char *)_ptpixels.get(), (_width * _height * 3));

            file.close();
            return true;
        }

        else
        {
            return false;
        }
    }

    void Bitmap::setpixels(int xp, int yp, uint8_t red, uint8_t green, uint8_t blue)
    {

        uint8_t *ptpixel = _ptpixels.get();

        ptpixel += (yp * 3) * _width + (xp * 3);

        ptpixel[0] = blue;
        ptpixel[1] = green;
        ptpixel[2] = red;
    }

    Bitmap::~Bitmap()
    {
    }

}