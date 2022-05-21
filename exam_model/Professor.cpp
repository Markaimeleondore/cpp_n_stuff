#include "Professor.h"
#include <fstream>
#include <iostream>

void Professor::get_students(string filename)
{
	ifstream fin(filename);
	string name;
	for (int i = 0; i < number_of_students; i++)
	{
		fin >> name;
		switch (rand() % 3)
		{
		case 0:
			solved_correctly.insert(make_pair(new Good_Student(name), 0));
			break;
		case 1:
			solved_correctly.insert(make_pair(new AVG_Student(name), 0));
			break;
		case 2:
			solved_correctly.insert(make_pair(new Bad_Student(name), 0));
			break;
		}
	}
	fin.close();
}

void Professor::get_equations(string filename)
{
	ifstream fin(filename);
	double a, b, c;
	for (int i = 0; i < number_of_equations; i++)
	{
		fin >> a >> b >> c;
		equations.push_back(Equation(a, b, c));
	}
	fin.close();
}

void Professor::examine()
{
	Solution sol, studSol;
	for (auto it = solved_correctly.begin(); it != solved_correctly.end(); it++)
	{
		for (int i = 0; i < number_of_equations; i++)
		{
			sol = equations[i].to_solve();
			studSol = it->first->to_solve(equations[i]);
			if (sol == studSol)
			{
				it->second++;
			}
				
		}
	}
}

void Professor::report()
{
	for (auto it = solved_correctly.begin(); it != solved_correctly.end(); it++)
	{
		cout << it->first->get_name() << " " << it->second << endl;
	}
}




