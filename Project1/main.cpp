#include <sstream>
#include <cstring>
#include <iostream>
#include <string>
#include "roster.h"
#include "student.h"
#include "degree.h"

int main()
{
	//Title
	cout << "**\n";
	cout << "Course: Scriting and Programming Applications - C867\n";
	cout << "Language used: C++\n";
	cout << "Student ID: 001485722\n";
	cout << "Student Name: Diego Medina\n";
	cout << "**\n";
	cout << endl;
	//Student Data
	const string studentData[] = {
		"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Diego,Medina,dmedi61@wgu.edu,31,31,31,31,SOFTWARE"
	};
	//instances
	Roster classRoster;
	DegreeProgram myDegree{};
	//adding students to roster 
	for (int i = 0; i < 5; i++) {
		stringstream row(studentData[i]);
		string student[9];
		for (int i = 0;
			i < 9; i++) {
			getline(row, student[i], ',');
		}
		if (student[8] == "SECURITY") {
			myDegree = DegreeProgram::SECURITY;
		}
		if (student[8] == "SOFTWARE") {
			myDegree = DegreeProgram::SOFTWARE;
		}
		if (student[8] == "NETWORK") {
			myDegree = DegreeProgram::NETWORK;
		}
		classRoster.add(student[0], student[1], student[2], student[3], stoi(student[4]),
			stoi(student[5]), stoi(student[6]), stoi(student[7]), myDegree);
	}
	//Prints method for students and invalid email
	classRoster.printAll();
	classRoster.printInvalidEmails();
	//Average day class complete logic
	for (int i = 0; i < 5; i++) {
		classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
	}
	//Call Method
	cout << endl;
	cout << "**\n";
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << "**\n";
	classRoster.remove("A3");
	cout << "Notice: Student Removed \n";
	cout << "**\n";
	classRoster.printAll();
	classRoster.remove("A3");
	//Destructor
	classRoster.~Roster();

	return 0;

}