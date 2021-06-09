#include <sstream>
#include <cstring>
#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main() {
	//Title
	cout << "*****************************************************************\n";
	cout << "Course: Scripting and Programming - Applications - C867\n";
	cout << "Language used: C++\n";
	cout << "Student ID: #001111769\n";
	cout << "Student Name: Lloyd King\n";
	cout << "*****************************************************************\n";
	cout << endl;

	//Student data with my own data for the last student
	const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Lloyd,King,lkin135@wgu.edu,28,50,48,40,SOFTWARE"};
	
	//instances of Roster and Degree 
	Roster classRoster;
	DegreeProgram myDegree{};
	
	//Adding students to the roster from student data
	for (int i = 0; i < 5; i++){
		stringstream row(studentData[i]);
		string student[9];

		for (int i = 0; i < 9; i++){
			getline(row, student[i], ',');
		}

		//Checks for degree program
		if (student[8] == "SECURITY"){
			myDegree = DegreeProgram::SECURITY;
		}
		if (student[8] == "SOFTWARE"){
			myDegree = DegreeProgram::SOFTWARE;
		}
		if (student[8] == "NETWORK"){
			myDegree = DegreeProgram::NETWORK;
		}

		//Add students to the roster using the add method, also converting string values to int
		classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]), stoi(student[5]), stoi(student[6]), stoi(student[7]), myDegree);
	}

	//Prints method for students and invalid emails
	classRoster.printAll();
	classRoster.printInvalidEmails();

	//Calculate average days to complete course
	for (int i = 0; i < 5; i++){
		classRoster.printAverageDays(classRoster.classRosterArray[i] -> getStudentID());
	}

	//Calling methods and some formatting for the console
	cout << endl;
	cout << "-------------------------------\n";
	cout << "Students in software degree program: \n";
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "-------------------------------\n";
	classRoster.remove("A3");
	cout << "-------------------------------\n";
	classRoster.printAll();
	cout << "-------------------------------\n";
	cout << "Remove student A3\n";
	classRoster.remove("A3");
	classRoster.~Roster();
	
	return 0;
}
