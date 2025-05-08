
#include <complex>
#include "Mandelbrot.h"

using namespace std;

namespace mandelbrotns
{

    int Mandelbrot::getiterations(double xi, double yi)
    {

        // for each pixel (Px, Py) on the screen:
        // double X0 scaled x coordinate of pixel (scaled to lie in the Mandelbrot X scale (-2.00, 0.47))
        // double y0 scaled y coordinate of pixel (scaled to lie in the Mandelbrot Y scale (-1.12, 1.12))

        int iterations = 0;

        // Without using complex numbers. (Does not work.)

        /* int xw=0;
        int yw=0;
        double x0 = xi;
        double y0 = yi;
         while ((xw * xw) + (yw * yw) <= (2 * 2) && iterations < MAX_ITERATIONS) {
            double xtemp = (xw * xw) - (yw * yw) + x0;
            yw = 2 * xw *  yw + y0;
            xw = xtemp;
            iterations++;
        }  */

        // Using complex numbers.

        complex<double> z = 0;
        complex<double> c(xi, yi);
        while (iterations < MAX_ITERATIONS)
        {
            z = z * z + c;
            if (abs(z) > 2)
            {
                break;
            }
            iterations++;
        }

        return iterations;
    }
}