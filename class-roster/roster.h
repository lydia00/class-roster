#include<iostream>
#include<string>
using namespace std;
#include "student.h"

#ifndef roster_h
#define roster_h

class Roster {
private:
	int dataEnd = -1;
	const static int numStudents = 5;

public:
	// E.1. Create an array of pointers, classRosterArray.
	Student* classRosterArray[numStudents];

	// E.2.a. Parse each set of data identified in the "studentData Table."
	// E.2.b. Add each student object to classRosterArray.
	void parseStudentData(string studentData);

	// E.3.a add() sets the instance variables and updates the roster.
	void add(string id, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

	// E.3.b remove() removes students from the roster by student ID.
	void remove(string id);

	// E.3.c printAll() prints a complete tab-separated list of student data.
	void printAll();

	// E.3.d printAverageDaysInCourse() prints a student's average number of days in the three courses.
	void printAverageDaysInCourse(string id);

	// E.3.e printInvalidEmails() verfies student email addresses.
	void printInvalidEmails();

	// E.3.f. printByDegreeProgram() prints out student information for a degree program.
	void printByDegreeProgram(DegreeProgram degreeProgram);

	// Destructor
	~Roster();
};

#endif // !roster_h