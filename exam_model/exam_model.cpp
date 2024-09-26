#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <Windows.h>

#include "Professor.h"

using namespace std;

int main()
{
    srand(42);
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Professor teacher(4, 4);
    teacher.get_equations("equations_list.txt");
    teacher.get_students("students_list.txt");
    teacher.examine();
    teacher.report();
    return 0;
}

