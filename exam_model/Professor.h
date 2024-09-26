#pragma once
#include <string>
#include <map>
#include <vector>
#include "Equation.h"
#include "Student.h"

using namespace std;

class Solved
{
public:
	Solution sol;
	Equation eq;
	string student_name;

	Solved(Solution _sol, Equation _eq, string name) : sol(_sol), eq(_eq), student_name(name) {};
};




class Professor
{
	map <Student*, int> solved_correctly;
	vector <Equation> equations;
	int number_of_equations;
	int number_of_students;
public:
	Professor(int _students, int _equations) : number_of_students(_students), number_of_equations(_equations) {};
	void get_students(string filename);
	void get_equations(string filename);
	void examine();
	void report();
};