#ifndef MANDELBROT_H
#define MANDELBROT_H

// #pragma once
namespace mandelbrotns
{

    class Mandelbrot
    {

    public:
        static const int MAX_ITERATIONS = 1500;

        static int getiterations(double xi, double yi);
    };
}
#endif