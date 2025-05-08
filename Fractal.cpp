
// Create a Mandelbrot fractal bitmap image.
// Colours and colour ranges are random generated based on a seed number. 

#include <iostream>
#include <cstdint>
#include <memory>
#include <math.h>

#include "Fractalcreator.cpp"
#include "Bitmap.cpp"
#include "Mandelbrot.cpp"
#include "Zoomlist.cpp"
#include "RGB.cpp"

using namespace std;
using namespace mandelbrotns;

int main()
{
    //Set seed to a random positive or negative number.
    const int seed = -9866;
    
    
    const int WIDTH = 800;
    const int HEIGHT = 600;

    Fractalcreator F(WIDTH, HEIGHT);

    // Zooms top of mandelbrot.
    //F.fractalzoom(148, 299, 0.14);

    // Zooms closeups of edges.
    F.fractalzoom(174, 294, 0.14);
    F.fractalzoom(108, 302, 0.14);
    F.fractalzoom(160, 217, 0.14);
    F.fractalzoom(478, 423, 0.14);

    F.run("Mandelbrot" + to_string(seed) + ".bmp", seed);

    cout << "Finished." << endl;

    return 0;
}