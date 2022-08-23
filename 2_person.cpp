#include "STUDENT.h"

Person::Person(int id, const char *name, const char *passwd) : Item(id, name) {
    strcpy(Passwd, passwd);
}

Person::Person(const Person &per) : Item(per.GetId(), per.GetName()) {
    strcpy(Passwd, per.Passwd);
}

Person::~Person() {
    //cout<<"Person destructor called"<<endl;
}

const char *Person::GetPasswd() const {
    return this->Passwd;
}

void Person::SetPasswd(const char *NewPasswd) {
    strcpy(this->Passwd, NewPasswd);
}
//
// Created by 10048 on 2022/7/24.
//

