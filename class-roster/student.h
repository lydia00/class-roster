#include<iostream>
#include<string>
using namespace std;
#include "degree.h"

#ifndef student_h
#define student_h

// D. For the Student class, do the following:
// D.1. Create the class Student in the files student.h and student.cpp
class Student {
private:
	string id;
	string firstName;
	string lastName;
	string email;
	int age;
	const static int numCourses = 3;
	int daysInCourse[numCourses];
	DegreeProgram degreeProgram;

public:
	// Default constructor
	Student();

	// D.2.d. constructor using all of the input parameters provided in the table
	Student(string id, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram);

	// Destructor
	~Student();

	// D.2.a. Create a getter for each instance variable
	string get_id();
	string get_firstName();
	string get_lastName();
	string get_email();
	int get_age();
	int* get_daysInCourse();
	DegreeProgram get_degreeProgram();

	// D.2.b. Create a setter for each instance variable
	void set_id(string id);
	void set_firstName(string firstName);
	void set_lastName(string lastName);
	void set_email(string email);
	void set_age(int age);
	void set_daysInCourse(int daysInCourse[]);
	void set_degreeProgram(DegreeProgram degreeProgram);

	// D.2.e. print() to print specific student data.
	void print();
};

#endif // !student_h