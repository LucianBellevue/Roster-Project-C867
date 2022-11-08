#pragma once
#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

class Roster {
	
public:
	//constructor
	Roster();

	Student* classRosterArray[5];

	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, int firstDays, int secondDays, int thirdDays, DegreeProgram degree);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
	
	//destructor
	~Roster() {}
	
};