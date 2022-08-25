#include "STUDENT.h"

Item::Item(int id, const char *name) : ID(id) {
    Grade = 0;
    strcpy(Name, name);
}

Item::~Item() {
//    cout << "Item destructor called" << endl;
}

Item::Item(const Item &info) : ID(info.ID) {
    Grade = info.Grade;
    strcpy(Name, info.Name);
}

int Item::GetId() const {
    return ID;
}

double Item::GetGrade() const {
    return Grade;
}

const char *Item::GetName() const {
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
    strcpy(Name, NewName);
    return Name;
}
