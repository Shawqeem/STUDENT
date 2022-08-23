#include "STUDENT.h"

Teacher::Teacher(int id, const char *name, const char *passwd) : Person(id, name, passwd) {

}

Teacher::~Teacher() {
//    cout << "Teacher destructor called" << endl;
}

Teacher::Teacher(const Teacher &tea) : Person(tea.GetId(), tea.GetName(), tea.GetPasswd()) {

}

int WhereIsTea(const vector<Teacher> &vect, int id) {
    int i = 0;
    for (const Teacher &a: vect) {
        if (a.Teacher::GetId() == id) {
            return i;
        }
        ++i;
    }
    return -1;
}

//
// Created by 10048 on 2022/7/22.
//

