#include "Equation.h"
#include <cmath>

bool Solution::operator==(const Solution& same)
{
    return (same.number_of_roots == this->number_of_roots && same.x1 == this->x1 && same.x2 == this->x2);
}

Solution Equation::to_solve()
{
    double discr = (b * b) - 4 * a * c, x1, x2;
    int number_of_roots;
    if (discr >= 0)
    {
        x1 = (-b + sqrt(discr)) / (2 * a);
        x2 = (-b - sqrt(discr)) / (2 * a);
        number_of_roots = ( discr == 0 ) ? 1 : 2;
    }
    else
    {
        x1 = x2 = number_of_roots = 0;
    }
    return {number_of_roots, x1, x2};
}


