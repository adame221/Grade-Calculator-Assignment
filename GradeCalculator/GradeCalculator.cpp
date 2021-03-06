/* GradeCalculator.cpp : This application prompts the user for their name, id, test scores.  It then calcualates the students scores
	and gives them an average, and a grade based upon the average.  The application then prints that information out to the screen.
*/

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>;
using namespace std;

//Declare structure
struct student {
	string name;
	int idNumber;
	int tests[3];
	double average;
	char grade;
};

//Declare prototypes
student calculateAverage(student);
student calculateGrade(student);
void printTotals(student);

int main() {

	//Declare local variable
	student student;

	//Prompt user for information
	cout << "Enter the name of a student: ";
	cin >> student.name;
	cout << "Enter Student Id number: ";
	cin >> student.idNumber;
	student.average = 0;

	//Call functions
	student = calculateAverage(student);
	student = calculateGrade(student);
	
	cout << "---------------------------------------------------------------------------------" << endl;

	printTotals(student);
}

/*
	This function calcualates the students average from the test scores they entered
*/
student calculateAverage(student student1) {

	cout << "Enter three test scores(seperated by spaces. No commas please): ";
	for (int i = 0; i < 3; i++) {
		cin >> student1.tests[i];
		student1.average = student1.average + student1.tests[i];
	}
	cout << endl;
	student1.average = student1.average / 3.0;
	return student1;
}

/*
	This function calculates the students score and gives them a grade
*/
student calculateGrade(student studentParam) {
	if (studentParam.average >= 91) {
		studentParam.grade = 'A';
	}
	else if (studentParam.average >= 81) {
		studentParam.grade = 'B';
	}
	else if (studentParam.average >= 71) {
		studentParam.grade = 'C';
	}
	else if (studentParam.average >= 61) {
		studentParam.grade = 'D';
	}
	else {
		studentParam.grade = 'F';
	}
	return studentParam;
}

/*
	This function prints the totals to the screen
*/
void printTotals(student student1) {
	cout << "Student Name: " << student1.name << endl;
	cout << "Student Id number: " << student1.idNumber << endl;
	cout << "Average score of tests: ";
	cout << setprecision(0) << fixed << student1.average << endl;
	cout << "Student Grade: " << student1.grade << endl;
	return;
}

