#include "Student.h"

Solution Bad_Student::to_solve(Equation& instance)
{
    return { 0, 0, 0 };
}

Solution AVG_Student::to_solve(Equation& instance)
{
    if (rand() % 2)
        return instance.to_solve();
    else
        return { 0, 0, 0 };
}

Solution Good_Student::to_solve(Equation& instance)
{
    return instance.to_solve();
}
