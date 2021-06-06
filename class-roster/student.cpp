#include<iostream>
#include<string>
#include <iomanip> // for pretty output
using namespace std;
#include "student.h"

// D.1. Create the class Student in the files student.h and student.cpp

// Default contstructor
Student::Student() {
	this->id = "none";
	this->firstName = "none";
	this->lastName = "none";
	this->email = "none";
	this->age = 0;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = 0;
	}
	this->degreeProgram = UNKNOWN;
}

// D.2.d. Cconstructor using all of the input parameters provided in the table
Student::Student(string id, string firstName, string lastName, string email, int age, int daysInCourse[], DegreeProgram degreeProgram) {
	this->id = id;
	this->firstName = firstName;
	this->lastName = lastName;
	this->email = email;
	this->age = age;
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
	this->degreeProgram = degreeProgram;
}

// D.2.a. Create a getter for each instance variable
string Student::get_id() {
	return this->id;
}
string Student::get_firstName() {
	return this->firstName;
}
string Student::get_lastName() {
	return this->lastName;
}
string Student::get_email() {
	return this->email;
}
int Student::get_age() {
	return this->age;
}
int* Student::get_daysInCourse() {
	return this->daysInCourse;
}
DegreeProgram Student::get_degreeProgram() {
	return this->degreeProgram;
}

// D.2.b. Create a setter for each instance variable
void Student::set_id(string id) {
	this->id = id;
}
void Student::set_firstName(string firstName) {
	this->firstName = firstName;
}
void Student::set_lastName(string lastName) {
	this->lastName = lastName;
}
void Student::set_email(string email) {
	this->email = email;
}
void Student::set_age(int age) {
	this->age = age;
}
void Student::set_daysInCourse(int daysInCourse[]) {
	int i = 0;
	for (i = 0; i < numCourses; ++i) {
		this->daysInCourse[i] = daysInCourse[i];
	}
}
void Student::set_degreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// D.2.e. print() to print specific student data.
void Student::print() {

	// Convert degree program enum to string
	string programString = "UNKNOWN";
	if (degreeProgram == SECURITY) {
		programString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		programString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		programString = "SOFTWARE";
	}
	else {
		programString = "UNKNOWN";
	}

	// Pretty output
	cout << left << setw(5)  << id;
	cout << left << setw(15) << firstName;
	cout << left << setw(15) << lastName;
	cout << left << setw(30) << email;
	cout << left << setw(10) << age;
	cout << left << setw(5) << daysInCourse[0];
	cout << left << setw(5) << daysInCourse[1];
	cout << left << setw(10) << daysInCourse[2];
	cout << left << setw(15) << programString;
	cout << endl;

	// Original output
	// cout << id << '\t';
	// cout << "First Name: " << firstName << '\t';
	// cout << "Last Name: " << lastName << '\t';
	// cout << "Email: " << email << '\t';
	// cout << "Age: " << age << '\t';
	// cout << "Days in Course: {" << daysInCourse[0] << ',' << daysInCourse[1] << ',' << daysInCourse[2] << "}\t";
	// cout << "Degree Program: " << programString << endl;
}

// Destructor
Student::~Student() {
	// Empty
}