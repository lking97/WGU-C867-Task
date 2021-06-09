#pragma once
#include <string>
#include "degree.h"

using namespace std;

class Student {
private:
	string studentID, firstName, lastName, email;
	int age, numDays[3]; 
	DegreeProgram degree;

public: 
    //Constructor
	Student();
	Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree);
	
	//Accessors
	string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmail();
	int getAge();
	int* getNumDays();
	DegreeProgram getDegreeProgram();

	//Mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmail(string email);
	void setAge(int age);
	void setNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void setDegreeProgram(DegreeProgram degree);

	//Print function
	void print();

	//Deconstructor
	~Student();
};