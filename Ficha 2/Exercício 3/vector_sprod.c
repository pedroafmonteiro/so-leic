#include "vector.h"

double vector_sprod(vector *v, vector*w) {
    return v->x * w->x + v->y * w->y + v->z * w->z;
}