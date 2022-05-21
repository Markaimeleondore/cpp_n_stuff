#pragma once

class Solution
{
public:
	int number_of_roots;
	double x1, x2;

	Solution(int _number_of_roots, double _x1, double _x2) : number_of_roots(_number_of_roots), x1(_x1), x2(_x2) {};
	Solution() : number_of_roots(0), x1(0), x2(0) {};
	bool operator== (const Solution& same);

};

class Equation
{
public:
	double a, b, c;
	Equation(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {};
	Solution to_solve();
};

