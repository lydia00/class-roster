#include<iostream>
#include<string>
#include <iomanip> // for pretty output
using namespace std;
#include "roster.h"

// E.2.a. Parse each set of data identified in the studentData table.
// E.2.b. Add each student object to classRosterArray.
void Roster::parseStudentData(string studentData)
{
	// Parse student ID
	int itemEnd = studentData.find(",");
	string id = studentData.substr(0, itemEnd);

	// Parse first name
	int itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string firstName = studentData.substr(itemStart, itemEnd - itemStart);

	// Parse last name
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string lastName = studentData.substr(itemStart, itemEnd - itemStart);

	// Parse email
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	string email = studentData.substr(itemStart, itemEnd - itemStart);

	// Parse age
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int age = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// Parse days in course 1
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse1 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// Parse days in course 2
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse2 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// Parse days in course 3
	itemStart = itemEnd + 1;
	itemEnd = studentData.find(",", itemStart);
	int daysInCourse3 = stoi(studentData.substr(itemStart, itemEnd - itemStart));

	// Parse degree program
	itemStart = itemEnd + 1;
	itemEnd = studentData.find('/0', itemStart);
	DegreeProgram degreeProgram = UNKNOWN;
	if (studentData.substr(itemStart, itemEnd - itemStart) == "SECURITY") {
		degreeProgram = SECURITY;
	}
	else if (studentData.substr(itemStart, itemEnd - itemStart) == "NETWORK") {
		degreeProgram = NETWORK;
	}
	else if (studentData.substr(itemStart, itemEnd - itemStart) == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}
	else {
		degreeProgram = UNKNOWN;
	}

	// Add this data to the roster
	add(id, firstName, lastName, email, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

// E.3.a add() sets the instance variables and updates the roster.
void Roster::add(string id, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
	// Build the daysInCourse array to add to the roster
	int daysInCourse[3] = { daysInCourse1,daysInCourse2,daysInCourse3 };

	// Build the roster
	classRosterArray[++dataEnd] = new Student(id, firstName, lastName, email, age, daysInCourse, degreeProgram);
}

// E.3.b remove() removes students from the roster by student ID.
void Roster::remove(string studentId)
{
	// Find matching student ID in classRosterArray
	int i = 0;
	bool foundStudent = false;
	for (i = 0; i < dataEnd; ++i) {
		if (classRosterArray[i]->get_id() == studentId) {
			
			// Mark that the student was found and remove the student by moving subsequent elements up
			foundStudent = true;
			int j = i;
			for (j = i; j < dataEnd; ++j) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			dataEnd--;
			cout << "Student " << studentId << " removed from roster." << endl;
		}
	}
	// Print a message if the student ID wasn't found
	if (foundStudent == false) {
			cout << "Student ID not found." << endl;
	}
}

// E.3.c printAll() prints a complete tab-separated list of student data.
void Roster::printAll()
{
	// Pretty output
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First name";
	cout << left << setw(15) << "Last name";
	cout << left << setw(30) << "Email address";
	cout << left << setw(10) << "Age";
	cout << left << setw(20) << "Days in course";
	cout << left << setw(15) << "Degree program";
	cout << endl << endl;

	// Call print() function from Student class
	int i = 0;
	for (i = 0; i <= dataEnd; ++i) {
		classRosterArray[i]->print();
	}
}

// E.3.d printAverageDaysInCourse() prints a student's average number of days in the three courses.
void Roster::printAverageDaysInCourse(string id)
{
	int days1 = 0;
	int days2 = 0;
	int days3 = 0;
	double avgDays = 0.0;
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_id() == id) {
			days1 = classRosterArray[i]->get_daysInCourse()[0];
			days2 = classRosterArray[i]->get_daysInCourse()[1];
			days3 = classRosterArray[i]->get_daysInCourse()[2];
			avgDays = (days1 + days2 + days3) / 3.0;

			// Pretty output
			cout << left << setw(10) << id;
			cout << left << setw(10) << avgDays;
			cout << endl;

			// Original output
			// cout << "Student: " << id << '\t';
			// cout << "Average days: " << avgDays << endl;
		}
	}
}

// E.3.e printInvalidEmails() verfies student email addresses.
void Roster::printInvalidEmails()
{
	bool invalidEmail = false;
	string emailToCheck = "none";
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		emailToCheck = classRosterArray[i]->get_email();

		// Verify '@' is present
		if (emailToCheck.find('@') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		// Verify '.' is present
		else if (emailToCheck.find('.') == string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

		// Verify ' ' is not present
		else if (emailToCheck.find(' ') != string::npos) {
			invalidEmail = true;
			cout << emailToCheck << endl;
		}

	}

	// Print if there are no invalid email addresses.
	if (invalidEmail == false) {
		cout << "None found." << endl;
	}
}

// E.3.f. printByDegreeProgram() prints student information for a degree program.
void Roster::printByDegreeProgram(DegreeProgram degreeProgram)
{
	// Convert degree program enum to string
	string progamString = "UNKNOWN";
	if (degreeProgram == SECURITY) {
		progamString = "SECURITY";
	}
	else if (degreeProgram == NETWORK) {
		progamString = "NETWORK";
	}
	else if (degreeProgram == SOFTWARE) {
		progamString = "SOFTWARE";
	}
	else {
		progamString = "UNKNOWN";
	}

	// Pretty output
	cout << left << setw(5) << "ID";
	cout << left << setw(15) << "First name";
	cout << left << setw(15) << "Last name";
	cout << left << setw(30) << "Email address";
	cout << left << setw(10) << "Age";
	cout << left << setw(20) << "Days in course";
	cout << left << setw(15) << "Degree program";
	cout << endl << endl;

	// Find and print students in the requested program.
	bool studentInProgram = false;
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		if (classRosterArray[i]->get_degreeProgram() == degreeProgram) {
			studentInProgram = true;
			classRosterArray[i]->print();
		}
	}

	// Print if there are no students in the program.
	if (studentInProgram == false) {
		cout << "None found." << endl;
	}
}

// F.5. Implement the destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster()
{
	int i = 0;
	for (i = 0; i < dataEnd; ++i) {
		delete classRosterArray[i];
	}
	cout << "Roster cleared." << endl;
}