
#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {
    const int numStudents = 5;
    const string studentData[] =

    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Jeff,Beta,jeffbeta22@gmail.com,38,34,16,25,SOFTWARE"
    };
    /*Print out to the screen, via your application, the course title, the programming language used, your WGU student ID, and your name. */
        cout << "Course Title: C867 Scripting and Programming Applications" << endl;
        cout << "Programming Language Used: C++" << endl;
        cout << "WGU Student ID: 010841241" << endl;
        cout << "Student Name: Jeffrey Betancur" << endl;
        cout << endl;
    //Create an instance of the Roster class called classRoster.
    Roster classRoster;
    
    for (int i = 0; i < numStudents; ++i) {
        classRoster.parse(studentData[i]);
    }
    
    // Prints the roster
    classRoster.printAll();
    cout << endl;
    
    cout << "Displaying invalid emails: " << endl;
    cout << "\n";
    classRoster.printInvalidEmails();
    cout << endl;
    
    // loop through classRosterArray and for each element
    for (int i = 0; i < numStudents; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
    }
    cout << endl;
    
    cout << "Showing students in degree program: SOFTWARE " << endl;
    cout<< "\n";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
   
    cout << endl;
    
    classRoster.remove("A3");
    cout<< endl;
    
    classRoster.printAll();
    cout << endl;
    
    classRoster.remove("A3");
    cout<< endl;
    
    
    return 0;
}
