#include <iostream>
#include "JobCenter.h"
using namespace std;

void JobCenter::addStudent(Student *pStudent) {
    studentList[numStudent++] = pStudent;
}

void JobCenter::addExperienced(Experienced *pExperienced) {
    experiencedList[numExperienced++] = pExperienced;
}

void JobCenter::publishMessage(const string &message) {
    this -> message = message;
    cout << message << endl;
}

void JobCenter::notifyJobSeekers() {
    cout << "Notify all Job Seekers..." << endl;
    for(int i = 0; i < numStudent; i++) {
        cout << "My name is " << (studentList[i]) -> getName() << ", I am a graduate, and I have received your information: ";
        (studentList[i]) -> answerPhoneStu(message);
    }
    for(int i = 0; i < numExperienced; i++) {
        cout << "My name is " << (experiencedList[i]) -> getName() << ", I have working experience, and I have received your information: ";
        (experiencedList[i]) -> answerPhoneExp(message);
    }
}

JobCenter::JobCenter() {
    numJobSeeker = 0;
    numStudent = 0;
    numExperienced = 0;
}

string JobSeeker::getName() {
    return name;
}

JobSeeker::JobSeeker(const string &name, int age) {
    this -> name = name;
    this -> age = age;
}

JobSeeker::JobSeeker(const JobSeeker &jobSeeker) {
    name = jobSeeker.name;
    age = jobSeeker.age;
}

Student::Student (const string &name, int age, double GPA, JobCenter *jobCenter){
    this -> name = name;
    this -> age = age;
    this -> GPA = GPA;
    jobCenter -> addStudent(this);
}

Experienced::Experienced (const string &name, int age, JobCenter *jobCenter) {
    this -> name = name;
    this -> age = age;
    jobCenter -> addExperienced(this);
}

bool University::graduationExam(Student *student) {
    return (student -> getGPA() >= 2.5);
}

University::University (const string &name) {
    this -> name = name;
}

double Student::getGPA() {
    return GPA;
}

void Student::answerPhoneStu(const string &message) {
    cout << message;
    if (university -> graduationExam(this)) cout << ". Able to apply." << endl;
    else cout << "Could not graduate. Unable to apply. " << endl;
}

void Experienced::answerPhoneExp(const string &message) {
    cout << message;
    const string str = "³ÌÐòÔ±";
    if(message.find(str)) cout << "Able to apply." << endl;
    else cout << "Job inappropriate. Unable to apply." << endl;
}
