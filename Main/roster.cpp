
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

// Parse each set of data identified in the “studentData Table.”

void Roster::parse(string studentData) {
    
    std::size_t rhs = studentData.find(",");
    string studentID = studentData.substr(0, rhs);
    
    std::size_t lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs, rhs - lhs);
    
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs, rhs - lhs));
  
    lhs = rhs + 1;
        rhs = studentData.find(",", lhs);
        DegreeProgram degreeprogram;
        string degreeString = studentData.substr(lhs, rhs - lhs);
    if (degreeString == "SECURITY") {
        degreeprogram  = DegreeProgram::SECURITY;
    }
    else if (degreeString == "NETWORK") {
        degreeprogram  = DegreeProgram::NETWORK;
    }
    else {
        degreeprogram  = DegreeProgram::SOFTWARE;
    }
    // Add each student object to classRosterArray.
    add(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2,
        daysInCourse3, degreeprogram);
}

/* public void add(string studentID, string firstName, string lastName, string
 emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
 DegreeProgram degreeprogram)  that sets the instance variables from part D1 and
 updates the roster*/
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram) {
    
    int daysArray[3] = {daysInCourse1, daysInCourse2, daysInCourse3};
    // Constructor for classRosterArray lastIndex is - 1 so ++lastIndex starts the index at 0
    classRosterArray[++lastIndex] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeprogram);
    
}
/*public void remove(string studentID)  that removes students from the roster by
 student ID. If the student ID does not exist, the function prints an error message
 indicating that the student was not found.*/
void Roster::remove(string studentID) {
    bool foundStu = false;
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID){
            foundStu = true;
            
            for (int j = i; j <= Roster::lastIndex; ++ j) {
            if (j < numStudents - 1) {
                Student* temp = classRosterArray[j];
                classRosterArray[j] = classRosterArray[j + 1];
                classRosterArray[j + 1] = temp;
            }
        }
            Roster::lastIndex--;
        }
    }
    if (foundStu) {
        cout << "Removing " << studentID << ":" << endl;
    }
    else {
        cout << "The student with the ID: " << studentID << " was not found" << endl;
    }
}

/*public void printAll() that prints a complete tab-separated list of student data
 in the provided format: A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20
 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. The printAll() function should
 loop through all the students in classRosterArray and call the print() function for each
 student.*/
void Roster::printAll() {
    cout << "Displaying all students: " << endl;
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        classRosterArray[i]->print();
    }
    cout << endl;
}
/*public void printAverageDaysInCourse(string studentID)  that correctly prints a
 student’s average number of days in the three courses. The student is identified by
 the studentID parameter.
*/
void Roster::printAverageDaysInCourse(string studentID) {
    for (int i = 0; i <= Roster::lastIndex; ++i) {
        if (classRosterArray[i]->getStudentID() == studentID) {
            cout << "Student ID: " << studentID << ", average days in course is: ";
            cout << (classRosterArray[i]->getDays()[0] + classRosterArray[i]->getDays()[1] +
                     classRosterArray[i]->getDays()[2]) / 3 << endl;
        }
    }
   
}
/*public void printInvalidEmails() that verifies student email addresses and displays all
 invalid email addresses to the user.*/
void Roster::printInvalidEmails() {
    bool invalid = false;
    for (int i =0; i < Roster::lastIndex; ++i) {
        string emailAddress = (classRosterArray[i]->getEmail());
        if (emailAddress.find("@") == string::npos || emailAddress.find(".") == string::npos
            || emailAddress.find(" ") != string::npos) {
            invalid = true;
            cout << emailAddress << " - " << "is invalid." << endl;
        }
        else if (!invalid) {
            cout << "NONE" << endl;
        }
    
    }
}
/*public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student 
 information for a degree program specified by an enumerated type
*/
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    for (int i = 0; i < numStudents; ++i) {
        if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }
    }
    cout << endl;
}

Roster::~Roster() {
    for (int i = 0; i < numStudents; ++i) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
