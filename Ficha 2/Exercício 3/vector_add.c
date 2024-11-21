#include "vector.h"

vector *vector_add(vector *v, vector *w) {
    return vector_new(v->x + w->x, v->y + w->y, v->z + w->z);
}