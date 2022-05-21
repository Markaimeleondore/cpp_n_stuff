#pragma once
#include "Equation.h"
#include <string>

using namespace std;

class Student
{
public:
	Student(const string& _name) : name(_name) {};
	Student() : name("Not yet") {};
	string get_name() { return name; };
	virtual Solution to_solve(Equation& instance) = 0;
	virtual ~Student() {};

private:
	string name;
};

class Bad_Student : public Student
{
public:
	Bad_Student(const string& name) : Student(name) {};
	Bad_Student() {};
	Solution to_solve(Equation& instance) override;
};

class AVG_Student : public Student
{
public:
	AVG_Student(const string& name) : Student(name) {};
	AVG_Student() {};
	Solution to_solve(Equation& instance) override;
};


class Good_Student : public Student
{
public:
	Good_Student(const string& name) : Student(name) {};
	Good_Student() {};
	Solution to_solve(Equation& instance) override;
};