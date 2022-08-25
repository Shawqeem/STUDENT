#include "STUDENT.h"

Data::Data(int id_cou, int id_stu, const char *name_cou, const char *name_stu, double gra) : Student(id_stu, name_stu,
                                                                                                     "000000"),
                                                                                             Course(id_cou, name_cou) {
    Student::SetGrade(gra);
}

Data::Data(const Data &data) : Student(data.Student::GetId(), data.Student::GetName(), "000000"),
                               Course(data.Course::GetId(), data.Course::GetName()) {
    Student::SetGrade(data.Student::GetGrade());
}

Data::~Data() {
//    cout << "Data destructor called" << endl;
}

void SetAvgGrade(int id_s, int id_c, int po_s, int po_c, const vector<Data> &vdat, vector<Course> &vcou,
                 vector<Student> &vstu) {
    int cnt_stu = 0, cnt_cou = 0;
    double gra_stu = 0, gra_cou = 0;
    for (const Data &a: vdat) {
        if (a.Student::GetId() == id_s) {
            gra_stu += a.Student::GetGrade();
            ++cnt_stu;
        }
        if (a.Course::GetId() == id_c) {
            gra_cou += a.Student::GetGrade();
            ++cnt_cou;
        }
    }
    gra_stu /= cnt_stu;
    gra_cou /= cnt_cou;
    (vstu.begin() + po_s)->SetGrade(gra_stu);
    (vcou.begin() + po_c)->SetGrade(gra_cou);
}

void SetAvgGradeOfAll(const vector<Data> &vdat, vector<Course> &vcou, vector<Student> &vstu) {
    double sct;
    int cnt;
    for (Student &a: vstu) {
        sct = 0;
        cnt = 0;
        for (const Data &dat: vdat) {
            if (dat.Student::GetId() == a.GetId()) {
                sct += dat.Student::GetGrade();
                ++cnt;
            }
        }
        a.SetGrade(sct / cnt);
    }
    for (Course &a: vcou) {
        sct = 0;
        cnt = 0;
        for (const Data &dat: vdat) {
            if (dat.Course::GetId() == a.GetId()) {
                sct += dat.Student::GetGrade();
                ++cnt;
            }
        }
        a.SetGrade(sct / cnt);
    }
}

bool InputData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou) {
    //NumOfStu(eg:20000) NumOfCou(eg:10000) Grade(eg:100)
    //eg:20000 10000 100
    cout << "Please Input the Data! Example: IdOfStudent(eg:20000~29999) IdOfCourse(eg:10000~19999) Grade(eg:100)"
         << endl;
    int id_stu = 0, id_cou = 0;
    int po_stu = 0, po_cou = 0;
    double gra;
    DealWithCharBeforeInt();
    cin >> id_stu;
    DealWithCharBeforeInt();
    cin >> id_cou;
    DealWithCharBeforeInt();
    cin >> gra;
    if (id_stu / 10000 != 2) {
        cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl;
        cout << "Data Input Fail!" << endl << endl;
        return false;
    }
    bool flag = false;
    char *name_stu;
    for (const Student &a: vstu) {
        if (a.GetId() == id_stu) {
            name_stu = new char[strlen(a.GetName()) + 1];
            strcpy(name_stu, a.GetName());
            flag = true;
            cout << "Student Name (" << id_stu << ") : " << a.GetName() << endl;
            break;
        }
        ++po_stu;
    }
    if (!flag) {
        cout << "Student Name (" << id_stu << ") Not Found!" << endl;
        cout << "Data Input Fail!" << endl << endl;
        return false;
    }
    if (id_cou / 10000 != 1) {
        cout << "Invalid Course ID! Valid ID Example: 10000~19999" << endl;
        cout << "Data Input Fail!" << endl << endl;
        return false;
    }
    flag = false;
    char *name_cou;
    for (const Course &a: vcou) {
        if (a.GetId() == id_cou) {
            name_cou = new char[strlen(a.GetName()) + 1];
            strcpy(name_cou, a.GetName());
            flag = true;
            cout << "Course Name (" << id_cou << ") : " << a.GetName() << endl;
            break;
        }
        ++po_cou;
    }
    if (!flag) {
        cout << "Course Name (" << id_cou << ") Not Found!" << endl;
        cout << "Data Input Fail!" << endl << endl;
        return false;
    }
    int i = WhereIsData(vect, id_stu, id_cou);
    if (i + 1) {
        cout << "Data (" << id_stu << ", " << id_cou << ", " << (vect.begin() + i)->Student::GetGrade()
             << ") Has Been Input!" << endl;
        cout << "Data Input Fail!" << endl << endl;
        return false;
    }
    vect.push_back(Data(id_cou, id_stu, name_cou, name_stu, gra));
    cout << "Data :" << name_stu << "(" << id_stu << "), " << name_cou << "(" << id_cou << "), Grade: "
         << gra << " Input!" << endl << endl;
    SetAvgGrade(id_stu, id_cou, po_stu, po_cou, vect, vcou, vstu);
    delete[]name_stu;
    delete[]name_cou;
    return true;
}

int WhereIsData(const vector<Data> &vect, int id_stu, int id_cou) {
    int i = 0;
    for (const Data &a: vect) {
        if (a.Student::GetId() == id_stu && a.Course::GetId() == id_cou) {
            return i;
        }
        ++i;
    }
    return -1;
}

bool DelData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou) {
    cout << "Please Input the Data to Be Deleted! Example: IdOfStudent(eg:20000~29999) IdOfCourse(eg:10000~19999)"
         << endl;
    int id_stu = 0, id_cou = 0, i = 0;
    DealWithCharBeforeInt();
    cin >> id_stu;
    DealWithCharBeforeInt();
    cin >> id_cou;
    int po_stu, po_cou;
    i = WhereIsData(vect, id_stu, id_cou);
    if (i + 1) {
        cout << "Data (" << id_stu << ", " << id_cou << ") Found!" << endl;
        if (vect.end() == vect.begin() + i + 1) {
            vect.erase(vect.end() - 1);
        } else {
            vector<Data>::iterator ed, it;
            ed = vect.end();
            --ed;
            it = vect.begin() + i;
            it->Student::SetId(ed->Student::GetId());
            it->Course::SetId(ed->Course::GetId());
            it->Student::SetName(ed->Student::GetName());
            it->Course::SetName(ed->Course::GetName());
            it->Student::SetGrade(ed->Student::GetGrade());
            vect.pop_back();
        }
        cout << "Data (" << id_stu << ", " << id_cou << ") Deleted!" << endl << endl;
        po_stu = WhereIsStu(vstu, id_stu);
        po_cou = WhereIsCou(vcou, id_cou);
        SetAvgGrade(id_stu, id_cou, po_stu, po_cou, vect, vcou, vstu);
        return true;
    } else {
        cout << "Data (" << id_stu << ", " << id_cou << ") Not Found!" << endl << endl;
        return false;
    }
}

bool SetData(vector<Data> &vect, vector<Student> &vstu, vector<Course> &vcou) {
    cout << "Please Input the Data to Be Changed! Example: IdOfStudent(eg:20000~29999) IdOfCourse(eg:10000~19999)"
         << endl;
    int id_stu_old = 0, id_cou_old = 0, i = 0;
    DealWithCharBeforeInt();
    cin >> id_stu_old;
    DealWithCharBeforeInt();
    cin >> id_cou_old;
    i = WhereIsData(vect, id_stu_old, id_cou_old);
    if (i + 1) {
        cout << "Data (" << id_stu_old << ", " << id_cou_old << ") Found!" << endl;
        cout
                << "Please Input the New Data! Example: IdOfStudent(eg:20000~29999) IdOfCourse(eg:10000~19999) Grade(eg:100)"
                << endl;
        int id_stu_new = 0, id_cou_new = 0;
        double gra;
        DealWithCharBeforeInt();
        cin >> id_stu_new;
        DealWithCharBeforeInt();
        cin >> id_cou_new;
        DealWithCharBeforeInt();
        cin >> gra;
        if (id_stu_new / 10000 != 2) {
            cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl;
            cout << "Data Input Fail!" << endl << endl;
            return false;
        }
        int j = 0;
        j = WhereIsStu(vstu, id_stu_new);
        if (j + 1 == 0) {
            cout << "Student Name (" << id_stu_new << ") Not Found!" << endl;
            cout << "Data Input Fail!" << endl << endl;
            return false;
        }
        if (id_cou_new / 10000 != 1) {
            cout << "Invalid Course ID! Valid ID Example: 10000~19999" << endl;
            cout << "Data Input Fail!" << endl << endl;
            return false;
        }
        j = WhereIsCou(vcou, id_cou_new);
        if (j + 1 == 0) {
            cout << "Course Name (" << id_cou_new << ") Not Found!" << endl;
            cout << "Data Input Fail!" << endl << endl;
            return false;
        }
        int po_stu, po_cou;
        vector<Data>::iterator it;
        it = vect.begin() + i;
        it->Student::SetId(id_stu_new);
        it->Course::SetId(id_cou_new);
        it->Student::SetName(GetStuName(id_stu_new, vstu));
        it->Course::SetName(GetCouName(id_cou_new, vcou));
        it->Student::SetGrade(gra);
        cout << "Data Changed! New: " << GetStuName2(id_stu_new, vstu) << "(" << id_stu_new << "), "
             << GetCouName2(id_cou_new, vcou) << "(" << id_cou_new << "), Grade: "
             << gra << " Input!" << endl << endl;
        po_stu = WhereIsStu(vstu, id_stu_old);
        po_cou = WhereIsCou(vcou, id_cou_old);
        SetAvgGrade(id_stu_old, id_cou_old, po_stu, po_cou, vect, vcou, vstu);
        po_stu = WhereIsStu(vstu, id_stu_new);
        po_cou = WhereIsCou(vcou, id_cou_new);
        SetAvgGrade(id_stu_new, id_cou_new, po_stu, po_cou, vect, vcou, vstu);
        return true;
    } else {
        cout << "Data (" << id_stu_old << ", " << id_cou_old << ") Not Found!" << endl << endl;
        return false;
    }
}

double AskForGrade(const vector<Data> &vect, int CouId, int StuId) {
    for (const Data &a: vect) {
        if (a.Student::GetId() == StuId && a.Course::GetId() == CouId) {
            return a.Student::GetGrade();
        }
    }
    return -1;
}

void GetReport(const vector<Data> &vect, const vector<Student> &vstu, const vector<Course> &vcou, int Id, bool flg) {
    if (vstu.empty()) {
        cout << "No Data!" << endl;
        return;
    }
    if (Id / 10000 == 1) {
        for (const Course &co: vcou) {
            if (co.GetId() == Id) {
                co.GetReport(vect);
                break;
            }
        }
    } else if (Id / 10000 == 2) {
        for (const Student &st: vstu) {
            if (st.GetId() == Id) {
                st.GetReport(vect, flg);
                break;
            }
        }
    }
}
//Get the Student's own report, and save the result to "report_/NameOfStudent/.txt"
//Get the report of the typical course, and save the result to "report_/NameOfCourse/.txt"

bool less_stu2(const Student &stu1, const Student &stu2) {
    if (stu1.GetGrade() > stu2.GetGrade()) {
        return true;
    } else if (stu1.GetGrade() == stu2.GetGrade()) {
        return stu1.GetId() < stu2.GetId();
    } else return false;
}

void GetReport(vector<Student> &vstu) {
    int cnt = 0;
    double sct = 0;
    sort(vstu.begin(), vstu.end(), less_stu2);
    char *FileName = new char[100];
    strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\report\\teacher\\report_all_students.txt");
    ofstream of(FileName, ios_base::out);
    if (of.is_open()) {
        of << "Report of All Students is as Follow" << endl;
        for (const Student &a: vstu) {
            of << a.GetId() << "        " << setiosflags(ios::left) << setw(20) << a.GetName() << "    "
               << a.GetGrade() << endl;
            ++cnt;
        }
        of << "Average Grade: " << setprecision(5) << sct / cnt << endl;
        of.close();
        delete[]FileName;
        cout << "Report of All Students Printed!" << endl;
    } else {
        delete[]FileName;
        cout << "File Open Error!" << endl << endl;
    }
}
//Get the report of all students' average grade, and save the result to "report_AvgGrade.txt"
