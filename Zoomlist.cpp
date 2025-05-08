#include "iostream"
#include "Zoomlist.h"

using namespace std;

namespace mandelbrotns
{

    // Zoomlist::Zoomlist(){};

    Zoomlist::Zoomlist(int width, int height) : _width(width), _height(height)
    {
    }

    void Zoomlist::addzoom(const Zoom &zoom)
    {
        zooms.push_back(zoom);

        _xcentre += (zoom.xz - _width / 2) * _scale;
        _ycentre += (zoom.yz - _height / 2) * _scale;
        _scale *= zoom.scale;

        cout << zoom.xz << "," << zoom.yz << "," << zoom.scale << endl;
        cout << _xcentre << "," << _ycentre << "," << _scale << endl;
    }

    pair<double, double> Zoomlist::dozoom(int xza, int yza)
    {

        double xfractal = (xza - _width / 2) * _scale + _xcentre;
        double yfractal = -(yza - _height / 2) * _scale + _ycentre;

        return pair<double, double>(xfractal, yfractal);
    }

}