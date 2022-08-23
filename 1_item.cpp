#include "STUDENT.h"

Item::Item(int id, const char *name) : ID(id) {
    Grade = 0;
    int len = strlen(name);
    Name = new char[len + 1];
    strcpy(Name, name);
}

Item::~Item() {
    if (Name != NULL) {
        delete[]Name;
//        cout << "Item destructor called" << endl;
    }
}

Item::Item(const Item &info) : ID(info.ID) {
    Grade = info.Grade;
    int len = strlen(info.Name);
    Name = new char[len + 1];
    strcpy(Name, info.Name);
}

int Item::GetId() const {
    return ID;
}

double Item::GetGrade() const {
    return Grade;
}

const char *Item::GetName() const {
//    int len = strlen(Name);
//    char *res = new char[len + 1];
//    strcpy(res, Name);
    return this->Name;
}

int Item::SetId(int NewId) {
    ID = NewId;
    return NewId;
}

double Item::SetGrade(double NewGrade) {
    Grade = NewGrade;
    return NewGrade;
}

const char *Item::SetName(const char *NewName) {
    if (Name != NULL) {
        delete[]Name;
        Name=NULL;
    }
    int len = strlen(NewName);
    Name = new char[len + 1];
    strcpy(Name, NewName);
    return Name;
}

bool Item::DelName() {
    if (Name != NULL) {
        delete[]Name;
        return true;
    } else return false;
}

//
// Created by 10048 on 2022/7/18.
//