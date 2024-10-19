#include "complex.h"

complex *complex_div(complex *z, complex *w)
{
    double denominator = w->x * w->x + w->y * w->y;
    double real_part = (z->x * w->x + z->y * w->y) / denominator;
    double imag_part = (z->y * w->x - z->x * w->y) / denominator;

    return complex_new(real_part, imag_part);
}
