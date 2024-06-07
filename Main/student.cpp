

#include "student.h"
#include "degree.h"

    // an accessor (i.e., getter) for each instance variable
    string Student::getStudentID() {return this->studentID;}
    string Student::getFirstName() {return this->firstName;}
    string Student::getLastName() {return this->lastName;}
    string Student::getEmail() {return this->emailAddress;}
    int Student::getAge() {return this->age;}
    int* Student::getDays() {return this->numOfDaysArray;}
    DegreeProgram Student::getDegreeProgram() {return this->degreeProgram;}
    // a mutator (i.e., setter) for each instance variable
    void Student::setStudentID(string studentID) {this->studentID = studentID;}
    void Student::setFirstName(string firstName) {this->firstName = firstName;}
    void Student::setLastName(string lastName) {this->lastName = lastName;}
    void Student::setEmail(string emailAddress) {this->emailAddress = emailAddress;}
    void Student::setAge(int age) {this->age = age;}
    void Student::setDays(int numOfDaysArray[]) {
        for (int i = 0; i < numOfDaysArraySize; ++i )
            this->numOfDaysArray[i] = numOfDaysArray[i];
    }
    void Student::setDegreeProgram(DegreeProgram degreeProgram) {this->degreeProgram = degreeProgram;}

// constructor using all of the input parameters provided in the table
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
                 int age, int numOfDaysArray[], DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < numOfDaysArraySize; ++i) {
        this->numOfDaysArray[i] = numOfDaysArray[i];
    }
    this->degreeProgram = degreeProgram;
}
    // print() to print specific student data
    void Student::print() {
    cout << this->getStudentID() << "\t";
    cout << this->getFirstName() << "\t";
    cout << this->getLastName() << "\t\t";
    cout << this->getEmail() << "\t\t";
    cout << this->getAge() << "\t\t";
    cout << "{" << this->getDays()[0] << ",";
    cout << this->getDays()[1] << ",";
    cout << this->getDays()[2] << "}" << "\t\t";
    // Use the parallel array of strings to print DegreeProgram to string
    cout << degreeProStrings[this->getDegreeProgram()] << std::endl;
}
