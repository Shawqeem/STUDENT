#include "STUDENT.h"

bool Flg1, Flg2, Flg3, Flg4;

bool LogIn(int id, const vector<Student> &vstu, const vector<Teacher> &vtea, const vector<Admin> &vadm) {
    switch (id / 10000) {
        int i;
        case 2: {
            i = WhereIsStu(vstu, id);
            if (i + 1) {
                cout << "Please Input the Password of Student (" << id << ")" << endl;
                char pwd[MaxPasswdLen];
                cin >> pwd;
                if (strcmp((vstu.begin() + i)->GetPasswd(), pwd) == 0) {
                    cout << "Log in Successfully!" << endl;
                    return (Flg1 = true);
                } else {
                    cout << "Wrong Password!" << endl;
                    return false;
                }
            } else {
                cout << "Student Name Not Found!" << endl;
                return false;
            }
        }
        case 3: {
            i = WhereIsTea(vtea, id);
            if (i + 1) {
                cout << "Please Input the Password of Teacher (" << id << ")" << endl;
                char pwd[MaxPasswdLen];
                cin >> pwd;
                if (strcmp((vtea.begin() + i)->GetPasswd(), pwd) == 0) {
                    cout << "Log in Successfully!" << endl;
                    return (Flg2 = true);
                } else {
                    cout << "Wrong Password!" << endl;
                    return false;
                }
            } else {
                cout << "Teacher Name Not Found!" << endl;
                return false;
            }
        }
        case 4: {
            i = WhereIsAdm(vadm, id);
            if (i + 1) {
                cout << "Please Input the Password of Administrator (" << id << ")" << endl;
                char pwd[MaxPasswdLen];
                cin >> pwd;
                if (strcmp((vadm.begin() + i)->GetPasswd(), pwd) == 0) {
                    cout << "Log in Successfully!" << endl;
                    return (Flg3 = true);
                } else {
                    cout << "Wrong Password!" << endl;
                    return false;
                }
            } else {
                cout << "Administrator Name Not Found!" << endl;
                return false;
            }
        }
        default:
            cout << "Invalid ID!" << endl;
            return false;
    }
}

bool IdCheck_stu(int id, const vector<Student> &vstu) {
    if (id / 10000 != 2) {
        cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl;
        return false;
    }
    int i = WhereIsStu(vstu, id);
    if (i + 1)
        return true;
    else {
        cout << "Student (" << id << ") Not Found!" << endl;
        return false;
    }
}

bool IdCheck_cou(int id, const vector<Course> &vcou) {
    if (id / 10000 != 1) {
        cout << "Invalid Course ID! Valid ID eg: 10000~19999" << endl;
        return false;
    }
    int i = WhereIsCou(vcou, id);
    if (i + 1)
        return true;
    else {
        cout << "Course (" << id << ") Not Found!" << endl;
        return false;
    }
}

//Flg1: succeed to log in or not, for Student
//Flg2: ...for Teacher
//Flg3: ...for Admin
//Flg4: true for exit
void menu(int &ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Admin> &vadm,
          vector<Data> &vdat) {
    if (!Flg1 && !Flg2 && !Flg3 && !Flg4) {
        cout << "Please Input your ID! (Student:20000~29999, Teacher:30000~39999, Administrator:40000~49999)" << endl;
        cout << "Zero for Exit!" << endl;
        cin >> ID;
        if (!ID) {
            Flg4 = true;
        } else {
            LogIn(ID, vstu, vtea, vadm);
        }
        return;
    } else if (Flg4) {
        Flg1 = Flg2 = Flg3 = Flg4 = false;
        return;
    } else if (Flg3) {
        FunAdm(ID, vcou, vstu, vtea, vadm, vdat);
        return;
    } else if (Flg2) {
        FunTea(ID, vcou, vstu, vtea, vdat);
        return;
    } else if (Flg1) {
        FunStu(ID, vcou, vstu, vdat);
        return;
    }
}

//
// Created by 10048 on 2022/8/11.
//

