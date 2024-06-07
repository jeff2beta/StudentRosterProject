
#pragma once
#include <iostream>
#include <iomanip>
#include <string>
#include "degree.h"
using std::string;
using std::cout;
//Create the class Student  in the files student.h and student.cpp

class Student {
public:
    const static int numOfDaysArraySize = 3;
    
private:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int numOfDaysArray[numOfDaysArraySize];
    DegreeProgram degreeProgram;
public:
    Student();
    // Constructor
    Student(string studentID, string firstName, string lastName, string emailAddress,
            int age, int numOfDaysArray[], DegreeProgram degreeProgram);
    
    //Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmail();
    int getAge();
    int* getDays();
    DegreeProgram getDegreeProgram();
    
    //Setters
    void setStudentID(string studentID);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setEmail(string emailAddress);
    void setAge(int age);
    void setDays(int numOfDaysArray[]);
    void setDegreeProgram(DegreeProgram degreeProgram);
    
    void print(); 
    
};

