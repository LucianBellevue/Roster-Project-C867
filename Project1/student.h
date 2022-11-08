#pragma once
#include <string>
#include "degree.h"
using namespace std;

class Student
{

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int num_days[3];
	DegreeProgram degree;

public:
	const static int num_days_total = 3;
	//constructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int firstDays,
		int secondDays, int thirdDays, DegreeProgram degree);

	//accessors
    string getStudentID();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getNumDays();
	DegreeProgram getDegree();

	//mutators
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int a);
	void setNumDays(int firstDays, int secondDays, int thirdDays);
	void setDegree(DegreeProgram degree);
    void print();

	//destructor
	~Student();

};

