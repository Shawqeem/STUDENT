#include <iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
#include <cstdlib>

#define MaxPasswdLen 16
#define MaxNameLen 10

using namespace std;

class Item {
public:
    Item(int id, const char *name);

    virtual ~Item();

    Item(const Item &info);

    int GetId() const;

    double GetGrade() const;

    const char *GetName() const;

    int SetId(int NewId);

    double SetGrade(double NewGrade);

    const char *SetName(const char *NewName);

    bool DelName();

private:
    int ID; //from X0000 to X9999, X: 1->lesson, 2->student, 3->teacher, 4->admin
    double Grade; //to save the average grade
    char *Name = NULL;
};

class Student;

class Data;

class Course : public Item {
public:
    Course(int id, const char *name);

    virtual ~Course();

    Course(const Course &cou);

    double AskForGrade(const vector<Data> &vect, int StuId) const;

    void GetReport(const vector<Data> &vect) const;
    //Get the report of the course, and save the result to "report_/NameOfCourse/.txt"
};

int WhereIsCou(const vector<Course> &vect, int id);

class Person : public Item {
public:
    Person(int id, const char *name, const char *passwd);

    virtual ~Person();

    Person(const Person &per);

    const char *GetPasswd() const;

    void SetPasswd(const char *NewPasswd);

private:
    char Passwd[MaxPasswdLen + 1];
};

class Student : public Person {
public:
    Student(int id, const char *name, const char *passwd);

    virtual ~Student();

    Student(const Student &stu);

    double AskForGrade(const vector<Data> &vect, int CouId) const;

    void GetReport(const vector<Data> &vect) const;
    //Get the student's own report, and save the result to "report_/NameOfStudent/.txt"
};

int WhereIsStu(const vector<Student> &vect, int id);

class Teacher : public Person {
public:
    Teacher(int id, const char *name, const char *passwd);

    virtual ~Teacher();

    Teacher(const Teacher &tea);

};

int WhereIsTea(const vector<Teacher> &vect, int id);

class Admin : public Person {
public:
    Admin(int id, const char *name, const char *passwd);

    virtual ~Admin();

    Admin(const Admin &adm);
};

int WhereIsAdm(const vector<Admin> &vect, int id);

void NewStudent(int id, const char *name, vector<Student> &vect);//passwd is set in advance:"0+number"

void NewCourse(int id, const char *name, vector<Course> &vect);

int SetStuId(int OldId, int NewId, vector<Student> &vect);

const char *SetStuName(int id, const char *NewName, vector<Student> &vect);

int SetCouId(int OldId, int NewId, vector<Course> &vect);

const char *SetCouName(int id, const char *NewName, vector<Course> &vect);

void DelStu(int id, vector<Student> &vect);

void DelCou(int id, vector<Course> &vect);

const char *GetStuPasswd(int id, const vector<Student> &vect);

void ResetStuPasswd(int id, vector<Student> &vect);

const char *GetStuName(int id, const vector<Student> &vect);

const char *GetCouName(int id, const vector<Course> &vect);

const char *GetStuName2(int id, const vector<Student> &vect);

const char *GetCouName2(int id, const vector<Course> &vect);

class Data : public Student, public Course {
public:
    Data(int id_cou, int id_stu, const char *name_cou, const char *name_stu, double gra);

    virtual ~Data();

    Data(const Data &data);

};

int WhereIsData(const vector<Data> &vect, int id_stu, int id_cou);

bool InputData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou);
//Student::Grade==input.grade, get_avg_grade

bool DelData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou);

bool SetData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou);

double AskForGrade(const vector<Data> &vect, int CouId, int StuId);

void GetReport(const vector<Data> &vect, const vector<Student> &vstu, const vector<Course> &vcou,
               int Id);//Get the Student's own report, and save the result to "report_/NameOfStudent/.txt"
//Get the report of the typical course, and save the result to "report_/NameOfCourse/.txt"

bool less_stu2(const Student &stu1, const Student &stu2);

void GetReport(vector<Student> &vstu);
//Get the report of all students' average grade, and save the result to "report_AvgGrade.txt"

bool less_cou(const Data &dat1, const Data &dat2);

bool less_stu(const Data &dat1, const Data &dat2);

bool IsNumber(char *a, int len);

bool LogIn(int id, const vector<Student> &vstu, const vector<Teacher> &vtea, const vector<Admin> &adm);

bool IdCheck_stu(int id, const vector<Student> &vstu);

bool IdCheck_cou(int id, const vector<Course> &vcou);

void menu(int &ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Admin> &vadm,
          vector<Data> &vdat);

void FunAdm(int ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Admin> &vadm,
            vector<Data> &vdat);

void FunTea(int ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Data> &vdat);

void FunStu(int ID, const vector<Course> &vcou, vector<Student> &vstu, const vector<Data> &vdat);

void SetAvgGrade(int id_s,int id_c,int po_s, int po_c, const vector<Data> &vdat, vector<Course> &vcou, vector<Student> &vstu);
//
// Created by 10048 on 2022/7/18.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H

#endif //STUDENT_STUDENT_H
