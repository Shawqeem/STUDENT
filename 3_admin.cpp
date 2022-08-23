#include "STUDENT.h"

Admin::Admin(int id, const char *name, const char *passwd) : Person(id, name, passwd) {

}

Admin::Admin(const Admin &adm) : Person(adm.GetId(), adm.GetName(), adm.GetPasswd()) {

}

Admin::~Admin() {
//    cout << "Admin destructor called" << endl;
}

void NewStudent(int id, const char *name, vector<Student> &vect) {
    char pwd[7];
    int Id = id;
    pwd[0] = '0';
    for (int i = 1; i < 6; ++i) {
        pwd[6 - i] = Id % 10 + '0';
        Id /= 10;
    }
    Student s(id, name, pwd);
    vect.push_back(s);
}
//passwd is set in advance:"0+number"

void NewCourse(int id, const char *name, vector<Course> &vect) {
    Course c = Course(id, name);
    vect.push_back(c);
}

int SetStuId(int OldId, int NewId, vector<Student> &vect) {
    for (Student &a: vect) {
        if (a.GetId() == OldId) {
            a.SetId(NewId);
            return NewId;
        }
    }
    return -1;
}

const char *SetStuName(int id, const char *NewName, vector<Student> &vect) {
    for (Student &a: vect) {
        if (a.GetId() == id) {
            a.SetName(NewName);
            return NewName;
        }
    }
    return "";
}

int SetCouId(int OldId, int NewId, vector<Course> &vect) {
    for (Course &a: vect) {
        if (a.GetId() == OldId) {
            a.SetId(NewId);
            return NewId;
        }
    }
    return -1;
}

const char *SetCouName(int id, const char *NewName, vector<Course> &vect) {
    for (Course &a: vect) {
        if (a.GetId() == id) {
            a.SetName(NewName);
            return NewName;
        }
    }
    return "";
}

const char *GetStuPasswd(int id, const vector<Student> &vect) {
    for (const Student &a: vect) {
        if (a.GetId() == id) {
            return a.GetPasswd();
        }
    }
    return "";
}

void ResetStuPasswd(int id, vector<Student> &vect) {
    for (Student &a: vect) {
        if (a.GetId() == id) {
            char pwd[7];
            int Id = id;
            pwd[0] = '0';
            for (int i = 1; i < 6; ++i) {
                pwd[6 - i] = Id % 10 + '0';
                Id /= 10;
            }
            a.SetPasswd(pwd);
            return;
        }
    }
}

void DelStu(int id, vector<Student> &vect) {
    int i = WhereIsStu(vect, id);
    if (vect.end() == vect.begin() + i + 1) {
        vect.erase(vect.end() - 1);
    } else {
        vector<Student>::iterator ed, it;
        ed = vect.end();
        --ed;
        it = vect.begin() + i;
        it->SetId(ed->GetId());
        it->SetName(ed->GetName());
        it->SetGrade(ed->GetGrade());
        vect.pop_back();
    }
    cout << "Student (" << id << ") Deleted!" << endl;
}

void DelCou(int id, vector<Course> &vect) {
    int i = WhereIsCou(vect, id);
    if (vect.end() == vect.begin() + i + 1) {
        vect.erase(vect.end() - 1);
    } else {
        vector<Course>::iterator ed, it;
        ed = vect.end();
        --ed;
        it = vect.begin() + i;
        it->SetId(ed->GetId());
        it->SetName(ed->GetName());
        it->SetGrade(ed->GetGrade());
        vect.pop_back();
    }
    cout << "Course (" << id << ") Deleted!" << endl;
}

const char *GetStuName(int id, const vector<Student> &vect) {
    if (id / 10000 != 2) {
        cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl;
        return "";
    }
    for (const Student &a: vect) {
        if (a.GetId() == id) {
            cout << "Student Name (" << id << ") : " << a.GetName() << endl;
            return a.GetName();
        }
    }
    cout << "Student Name (" << id << ") Not Found!" << endl;
    return "";
}

const char *GetStuName2(int id, const vector<Student> &vect) {
//    if (id / 10000 != 2) {
//        cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl;
//        return "";
//    }
    for (const Student &a: vect) {
        if (a.GetId() == id) {
//            cout << "Student Name (" << id << ") : " << a.GetName()<< endl;
            return a.GetName();
        }
    }
//    cout << "Student Name (" << id << ") Not Found!" << endl;
    return "";
}

const char *GetCouName(int id, const vector<Course> &vect) {
    if (id / 10000 != 1) {
        cout << "Invalid Course ID! Valid ID Example: 10000~19999" << endl;
        return "";
    }
    for (const Course &a: vect) {
        if (a.GetId() == id) {
            cout << "Course Name (" << id << ") : " << a.GetName() << endl;
            return a.GetName();
        }
    }
    cout << "Course Name (" << id << ") Not Found!" << endl;
    return "";
}

const char *GetCouName2(int id, const vector<Course> &vect) {
//    if (id / 10000 != 1) {
//        cout << "Invalid Course ID! Valid ID Example: 10000~19999" << endl;
//        return "";
//    }
    for (const Course &a: vect) {
        if (a.GetId() == id) {
//            cout << "Course Name (" << id << ") : " << a.GetName()<< endl;
            return a.GetName();
        }
    }
//    cout << "Course Name (" << id << ") Not Found!" << endl;
    return "";
}

int WhereIsAdm(const vector<Admin> &vect, int id) {
    int i = 0;
    for (const Admin &a: vect) {
        if (a.Admin::GetId() == id) {
            return i;
        }
        ++i;
    }
    return -1;
}

//
// Created by 10048 on 2022/7/22.
//

