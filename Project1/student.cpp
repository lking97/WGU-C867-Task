#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

using namespace std;

//Constructor
Student::Student() {}
Student::Student(string studentID, string firstName, string lastName, string email, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degree) {
	setAge(age);
	setNumDays(daysInCourse1, daysInCourse2, daysInCourse3);
	setStudentID(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmail(email);
	setDegreeProgram(degree);
}

//Accessor functions
string Student::getStudentID() {
	return this->studentID;
}
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getEmail() {
	return this->email;
}
int Student::getAge() {
	return this->age;
}
int* Student::getNumDays() {
	return this->numDays;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degree;
}

//Mutator functions
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmail(string email) {
	this->email = email;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDays(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	numDays[0] = daysInCourse1;
	numDays[1] = daysInCourse2;
	numDays[2] = daysInCourse3;
}
void Student::setDegreeProgram(DegreeProgram degree) {
	this->degree = degree;
}

//Print function
void Student::print() {
	cout << "Student ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email: " << email << endl;
	cout << "Age: " << age << endl;
	cout << "Days in Course: " << numDays[0] << ", " << numDays[1] << ", " << numDays[2] << endl;
	cout << "Degree Program: " << DegreeProgramString[degree] << endl;
	cout << endl;
}

//Deconstructor
Student::~Student() {}