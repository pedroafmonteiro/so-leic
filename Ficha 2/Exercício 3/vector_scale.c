#include "vector.h"

vector *vector_scale(double x, vector *v) {
    return vector_new(x * v->x, x * v->y, x * v->z);
}