
#pragma once
#include "student.h"

class Roster {
private:
    int lastIndex = -1;
    const static int numStudents = 5;
public:
    // Create an array of pointers, classRosterArray, to hold the data provided
    //in the “studentData Table.”
    Student* classRosterArray[numStudents];
    
    void parse(string row);
    
    void add(string studentID,
                      string firstName,
                      string lastName,
                      string emailAddress,
                      int age,
                      int daysInCourse1,
                      int daysInCourse2,
                      int daysInCourse3,
                      DegreeProgram degreeprogram);
    
    void remove(string studentID);
    
    void printAll();
    
    void printAverageDaysInCourse(string studentID);
    
    void printInvalidEmails();
    
    void printByDegreeProgram(DegreeProgram degreeProgram);
    
    ~Roster();
    
};
