
#include <iostream>
using namespace std;

class JobCenter;
class University;

class JobSeeker {
public:
    JobSeeker(const string &name, int age);
    JobSeeker(const JobSeeker&);
    JobSeeker() {}
    string getName();
protected:
    string name;
    int age;
};

class Student: public JobSeeker {
public:
    Student(const string &name, int age, double GPA, JobCenter *jobCenter);
    void answerPhoneStu(const string &message);
    double getGPA();
private:
    double GPA;
    University *university;
};

class Experienced: public JobSeeker {
public:
    Experienced(const string &name, int age, JobCenter *JobCenter);
    void answerPhoneExp(const string &message);
};

class JobCenter {
public:
     JobCenter();
    void addStudent(Student *pStudent);
    void addExperienced(Experienced *pExperienced);
    void publishMessage(const string &message);
    void notifyJobSeekers();
private:
    string message;
    int numJobSeeker;
    int numStudent;
    int numExperienced;
    Student *studentList[100];
    Experienced *experiencedList[100];
};


class University {
public:
    University(const string &name);
    bool graduationExam(Student *student);
private:
    string name;
};

