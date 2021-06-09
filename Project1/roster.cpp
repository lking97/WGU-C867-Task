#include <iostream>
#include <string>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

//Constructor
Roster::Roster() {}

//Add students to roster
void Roster::add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	Student* student = new Student;

	int index = stoi(studentID.substr(1)) - 1;

	student->setStudentID(studentID);
	student->setFirstName(firstName);
	student->setLastName(lastName);
	student->setEmail(email);
	student->setAge(age);
	student->setNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
	student->setDegreeProgram(degree);
	classRosterArray[index] = student;
}

//Remove students by student ID
void Roster::remove(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = 0;
				cout << "Removing student " << studentID << endl;
				cout << endl;
			}
		}
		else {
			cout << "Error: Student doesn't exist.\n";
		}
	}
}

//Checks emails and prints invalid emails
void Roster::printInvalidEmails() {
	bool at = false;
	bool space = false;
	bool period = false;

	cout << "-------------------------------\n";
	cout << "List of invalid emails: \n";
	cout << endl;

	for (int i = 0; i < 5; i++) {
		string email = classRosterArray[i]->getEmail();
		at = false;
		space = false;
		period = false;

		if (email.find("@") < email.length()) {
			at = true;
		}
		if (email.find(" ") < email.length()) {
			space = true;
		}
		if (email.find(".") < email.length()) {
			period = true;
		}
		if (at == false || space == true || period == false) {
			cout << (classRosterArray[i])->getEmail() << endl;
		}
	}
	cout << endl;
	cout << "-------------------------------\n";
}

//Print average days in course for each student
void Roster::printAverageDays(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				int avgDays = 0;

				avgDays = (classRosterArray[i]->getNumDays()[0] + classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3;

				cout << "Average time for " << studentID << " to finish 3 courses: " << avgDays << " days\n";
			}
		}
	}
}

//Print students by degree
void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegreeProgram() == degree) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}

//Print roster
void Roster::printAll() {
	for (int i = 0; i < 5; i++)
	{
		if (classRosterArray[i]) {
			if (classRosterArray[i] != 0) {
				classRosterArray[i]->print();
			}
		}
	}
}

//Deconstructor
Roster::~Roster() {}