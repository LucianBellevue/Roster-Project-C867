#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;
//Default and Constructor
Student::Student(){}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int firstDays,
	int secondDays, int thirdDays, DegreeProgram degree) {
	setAge(age);
	setNumDays(firstDays, secondDays, thirdDays);
	setEmailAddress(emailAddress);
	setFirstName(firstName);
	setLastName(lastName);
	setStudentID(studentID);
	setDegree(degree);

}
//Accessors
string Student::getFirstName() {
	return this->firstName;
}
string Student::getLastName() {
	return this->lastName;
}
string Student::getStudentID() {
	return this->studentID;
}
string Student::getEmailAddress() {
	return this->emailAddress;
}
DegreeProgram Student::getDegree() {
	return this->degree;
}
int Student::getAge() {
	return this->age;
}
int* Student::getNumDays() {
	return this->num_days;
}

//Mutators
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setStudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setNumDays(int firstDays, int secondDays, int thirdDays) {
	num_days[0] = firstDays;
	num_days[1] = secondDays;
	num_days[2] = thirdDays;
}
void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}
void Student::print() {
	cout << "Student ID: " << studentID << endl;
	cout << "First Name: " << firstName << endl;
	cout << "Last Name: " << lastName << endl;
	cout << "Email Address: " << emailAddress << endl;
	cout << "Age: " << age << endl;
	cout << "Average Days in Course: " << num_days[0] << "," << num_days[1] << "," <<
		num_days[2] << endl;
	cout << "Degree: " << DegreeString[degree] << endl;
	cout << "**" << endl;
}

