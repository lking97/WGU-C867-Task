#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

class Roster {
public:

	//Constructor
	Roster();

	//Array of student pointers
	Student* classRosterArray[5];

	//Sets the instance variables from student.h and updates the roster
	void add(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);

	//Removes students by student ID
	void remove(string studentID);

	//Print functions
	void printAll();
	void printInvalidEmails();
	void printAverageDays(string studentID);
	void printByDegreeProgram(DegreeProgram degreeProgram);

	//Deconstructor
	~Roster();
};