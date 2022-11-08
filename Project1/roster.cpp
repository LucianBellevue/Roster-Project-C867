#include <iostream>
#include <string>
#include "student.h"
#include "roster.h"
#include "degree.h"

using namespace std;
//constructor and adding students to roster
Roster::Roster() {}
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
	int firstDays, int secondDays, int thirdDays, DegreeProgram degree){

	Student* student = new Student;
	int index = stoi(studentID.substr(1)) - 1;
	student->setStudentID(studentID);
	student->setFirstName(firstName);
	student->setLastName(lastName);
	student->setEmailAddress(emailAddress);
	student->setAge(age);
	student->setNumDays(firstDays, secondDays, thirdDays);
	student->setDegree(degree);
	classRosterArray[index] = student;
}
//Remove student by ID
void Roster::remove(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				classRosterArray[i] = 0;
				cout << "NOTICE!\n";
				cout << "Student " << studentID << " removed. " << endl;
				cout << "**\n";
				cout << endl;
			}
		}
		else {
			cout << "Error: Student with this " << studentID << " ID was not found.\n";
			cout << "**\n";
		}
	}
}
//Validates email, prints if invalid
void Roster::printInvalidEmails() {
	bool at = false;
	bool space = false;
	bool period = false;
	cout << "**\n";
	cout << "Invalid Email Address: \n";
	cout << endl;
	for (int i = 0; i < 5; i++) {
		string emailAdress = classRosterArray[i]->getEmailAddress();
		at = false;
		space = false;
		period = false;
		if (emailAdress.find("@") < emailAdress.length()) {
			at = true;
		}
		if (emailAdress.find(" ") < emailAdress.length()) {
			space = true;
		}
		if (emailAdress.find(".") < emailAdress.length()) {
			period = true;
		}
		if (at == false || space == true || period == false) {
			cout << (classRosterArray[i])->getEmailAddress() << endl;
		}
	}
	cout << endl;
}
//Prints the average days in course for student
void Roster::printAverageDaysInCourse(string studentID) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]) {
			if (classRosterArray[i]->getStudentID() == studentID) {
				int avgDays = 0;
				avgDays = ((classRosterArray[i]->getNumDays()[0] +
					classRosterArray[i]->getNumDays()[1] + classRosterArray[i]->getNumDays()[2]) / 3);
				cout << "Average days for " << studentID << " to finish three courses: " << avgDays << " days\n";
			}
		}
	}
}
//Prints by degree
void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]->getDegree() == degree) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
}
//Prints roster
void Roster::printAll() {
	for (int i = 0; i < 5; i++) {
		if (classRosterArray[i]) {
			if (classRosterArray[i] != 0) {
				classRosterArray[i]->print();
			}
		}
	}
}