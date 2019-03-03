#include <math.h>
#include "mydefs.h"
#include "func3.h"

myfloat_t volumen(myfloat_t radius) {
    return ((4 / 3) * my_pi * pow(radius, 3));
}
