#include "supportive.h"

#include <TXLib.h>
#include <math.h>

const double ACC = 0.0001;

bool is_equal(double a, double b) {
    if (isnan(a) || isnan(b)) {
        if (isnan(a) && isnan(b))
            return true;

        return false;
    }
    else {
        double x = fabs(a - b);
        if (x >= ACC)
            return false;

        return true;
    }
}
