#include<iostream>
#include<string>
#include <iomanip> // for pretty output
using namespace std;
#include "roster.h"
#include "student.h"

int main() {
	const int numStudents = 5;

	// A. Modify the "studentData Table" to include your personal information as the last item.
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Lydia,H,student@wgu.edu,35,20,25,30,SOFTWARE"
	};

	// F.1. Print the course title, the programming language used, your WGU student ID, and your name.
	cout << "*********************************************" << endl;
	cout << "C867 - Scripting and Programming Applications" << endl;
	cout << "              Language: C++" << endl;
	cout << "         Student ID: #-------" << endl;
	cout << "               Lydia H" << endl;
	cout << "*********************************************" << endl << endl;

	// F.2. Create an instance of the Roster class called classRoster.
	Roster classRoster;

	// F.3. Add each student to classRoster.
	int i = 0;
	for (i = 0; i < numStudents; ++i) {
		classRoster.parseStudentData(studentData[i]);
	}

	// F.4. Complete the rest of the main() function:
	// Print the complete class roster
	cout << "------------" << endl;
	cout << "Class roster" << endl;
	cout << "------------" << endl << endl;
	classRoster.printAll();
	cout << endl << endl;

	// Print a list of invalid email addresses
	cout << "-----------------------" << endl;
	cout << "Invalid email addresses" << endl;
	cout << "-----------------------" << endl << endl;
	classRoster.printInvalidEmails();
	cout << endl << endl;

	// Print average days in course by student ID
	cout << "----------------------" << endl;
	cout << "Average days in course" << endl;
	cout << "----------------------" << endl << endl;

	// Pretty output
	cout << left << setw(10) << "ID";
	cout << left << setw(10) << "Average days";
	cout << endl << endl;

	int j = 0;
	for (int j = 0; j < numStudents; ++j) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[j]->get_id());
	}
	cout << endl << endl;

	// Print students in the SOFTWARE program
	cout << "----------------------------" << endl;
	cout << "Students in Software program" << endl;
	cout << "----------------------------" << endl << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl << endl;

	// Remove student by student ID
	cout << "--------------" << endl;
	cout << "Remove student" << endl;
	cout << "--------------" << endl << endl;
	classRoster.remove("A3");
	cout << endl << endl;

	// Print class roster again
	cout << "-------------------" << endl;
	cout << "Update class roster" << endl;
	cout << "-------------------" << endl << endl;
	classRoster.printAll();
	cout << endl << endl;

	// Retry removal on same student (should state that the student was not found)
	cout << "--------------------" << endl;
	cout << "Retry remove student" << endl;
	cout << "--------------------" << endl << endl;
	classRoster.remove("A3");
	cout << endl << endl;

	// F.5. Implement the destructor to release the memory that was allocated dynamically in Roster.
	cout << "--------------" << endl;
	cout << "Run destructor" << endl;
	cout << "--------------" << endl << endl;
}
