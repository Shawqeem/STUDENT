#include "STUDENT.h"

extern bool Flg1, Flg2, Flg3, Flg4;

void FunAdm(int ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Admin> &vadm,
            vector<Data> &vdat) {
    cout << "You are Administrator (" << ID << "). Please Input a number between 1 and 15 to choose a module!"
         << endl;
    cout << "1: New Student\n2: New Course\n3: Set Student ID\n4: Set Student Name\n";
    cout << "5: Reset Student Password\n6: Look for Student Password\n7: Set Course ID\n";
    cout << "8: Set Course Name\n9: Delete Student\n10: Delete Course\n11: Print Student List\n";
    cout
            << "12: Print Course List\n13: Print Student List to a File\n14: Print Course List to a File\n15: Exit to Main Menu\n";
    int num;
    cin >> num;
    switch (num) {
        int ID1;
        case 15: {
            Flg3 = false;
            break;
        }
        case 1: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (ID1 / 10000 != 2) {
                cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl << endl;
                break;
            } else if (WhereIsStu(vstu, ID1) + 1) {
                cout << "Student ID " << ID1 << " has been Taken up!" << endl << endl;
                break;
            } else {
                cout << "Please Input the name of Student! Maximum of Name Length: " << MaxNameLen << endl;
                char Name1[MaxNameLen + 1];
                while(cin.peek()!='\n')
                    cin.get();
                cin.get();//deal with other characters input behind "ID1"
                cin.getline(Name1, MaxNameLen + 1);
                cin.clear();
                fflush(stdin);
                NewStudent(ID1, Name1, vstu);
                cout << "New Student: " << ID1 << ", " << Name1 << endl << endl;
                break;
            }
        }
        case 2: {
            cout << "Please Input the ID of Course!" << endl;
            cin >> ID1;
            if (ID1 / 10000 != 1) {
                cout << "Invalid Course ID! Valid ID eg: 10000~19999" << endl << endl;
                break;
            } else if (WhereIsCou(vcou, ID1) + 1) {
                cout << "Course ID " << ID1 << " has been Taken up!" << endl << endl;
                break;
            } else {
                cout << "Please Input the name of Course! Maximum of Name Length: " << MaxNameLen << endl;
                char Name1[MaxNameLen + 1];
                while(cin.peek()!='\n')
                    cin.get();
                cin.get();//deal with other characters input behind "ID1"
                cin.getline(Name1, MaxNameLen + 1);
                cin.clear();
                fflush(stdin);
                NewCourse(ID1, Name1, vcou);
                cout << "New Course: " << ID1 << ", " << Name1 << endl << endl;
                break;
            }
        }
        case 3: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (IdCheck_stu(ID1, vstu)) {
                cout << "Please Input the New ID of Student!" << endl;
                int ID2;
                cin >> ID2;
                if (ID2 / 10000 != 2) {
                    cout << "Invalid Student ID! Valid ID eg: 20000~29999" << endl << endl;
                    break;
                } else if (WhereIsStu(vstu, ID2) + 1) {
                    cout << "Student ID " << ID2 << " has been Taken up!" << endl << endl;
                    break;
                }
                SetStuId(ID1, ID2, vstu);
                cout << "Student ID Reset! New ID: " << ID2 << ", " << GetStuName2(ID2, vstu) << endl << endl;
                for (Data &a: vdat) {
                    if (a.Student::GetId() == ID1) {
                        a.Student::SetId(ID2);
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 4: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (IdCheck_stu(ID1, vstu)) {
                cout << "Please Input the New Name of Student! Maximum of Name Length: " << MaxNameLen << endl;
                char Name2[MaxNameLen + 1];
                while(cin.peek()!='\n')
                    cin.get();
                cin.get();//deal with other characters input behind "ID1"
                cin.getline(Name2, MaxNameLen + 1);
                cin.clear();
                fflush(stdin);
                SetStuName(ID1, Name2, vstu);
                cout << "Student Name Reset! New Name: " << Name2 << ", " << ID1 << endl << endl;
                for (Data &a: vdat) {
                    if (a.Student::GetId() == ID1) {
                        a.Student::SetName(Name2);
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 5: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (IdCheck_stu(ID1, vstu)) {
                ResetStuPasswd(ID1, vstu);
                cout << "Password of Student(" << ID1 << ") Reset!" << endl << endl;
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 6: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (IdCheck_stu(ID1, vstu)) {
                cout << "Password of Student(" << ID1 << "): " << GetStuPasswd(ID1, vstu) << endl << endl;
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 7: {
            cout << "Please Input the ID of Course!" << endl;
            cin >> ID1;
            if (IdCheck_cou(ID1, vcou)) {
                cout << "Please Input the New ID of Course!" << endl;
                int ID2;
                cin >> ID2;
                if (ID2 / 10000 != 1) {
                    cout << "Invalid Course ID! Valid ID eg: 10000~19999" << endl << endl;
                    break;
                } else if (WhereIsCou(vcou, ID2) + 1) {
                    cout << "Course ID " << ID2 << " has been Taken up!" << endl << endl;
                    break;
                }
                SetCouId(ID1, ID2, vcou);
                cout << "Course ID Reset! New ID: " << ID2 << ", " << GetCouName2(ID2, vcou) << endl << endl;
                for (Data &a: vdat) {
                    if (a.Course::GetId() == ID1) {
                        a.Course::SetId(ID2);
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 8: {
            cout << "Please Input the ID of Course!" << endl;
            cin >> ID1;
            if (IdCheck_cou(ID1, vcou)) {
                cout << "Please Input the New Name of Course! Maximum of Name Length: " << MaxNameLen << endl;
                char Name2[MaxNameLen + 1];
                while(cin.peek()!='\n')
                    cin.get();
                cin.get();//deal with other characters input behind "ID1"
                cin.getline(Name2, MaxNameLen + 1);
                cin.clear();
                fflush(stdin);
                SetCouName(ID1, Name2, vcou);
                cout << "Course Name Reset! New Name: " << Name2 << ", " << ID1 << endl << endl;
                for (Data &a: vdat) {
                    if (a.Course::GetId() == ID1) {
                        a.Course::SetName(Name2);
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 9: {
            cout << "Please Input the ID of Student!" << endl;
            cin >> ID1;
            if (IdCheck_stu(ID1, vstu)) {
                DelStu(ID1, vstu);
                cout << endl;
                for (Data &a: vdat) {
                    if (a.Student::GetId() == ID1) {
                        int i = WhereIsData(vdat, ID1, a.Course::GetId());
                        if (vdat.end() == vdat.begin() + i + 1) {
                            vdat.erase(vdat.end() - 1);
                        } else {
                            vector<Data>::iterator ed, it;
                            ed = vdat.end();
                            --ed;
                            it = vdat.begin() + i;
                            it->Student::SetId(ed->Student::GetId());
                            it->Course::SetId(ed->Course::GetId());
                            it->Student::SetName(ed->Student::GetName());
                            it->Course::SetName(ed->Course::GetName());
                            it->Student::SetGrade(ed->Student::GetGrade());
                            vdat.pop_back();
                        }
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 10: {
            cout << "Please Input the ID of Course!" << endl;
            cin >> ID1;
            if (IdCheck_cou(ID1, vcou)) {
                DelCou(ID1, vcou);
                cout << endl;
                for (Data &a: vdat) {
                    if (a.Course::GetId() == ID1) {
                        int i = WhereIsData(vdat, a.Student::GetId(), ID1);
                        if (vdat.end() == vdat.begin() + i + 1) {
                            vdat.erase(vdat.end() - 1);
                        } else {
                            vector<Data>::iterator ed, it;
                            ed = vdat.end();
                            --ed;
                            it = vdat.begin() + i;
                            it->Student::SetId(ed->Student::GetId());
                            it->Course::SetId(ed->Course::GetId());
                            it->Student::SetName(ed->Student::GetName());
                            it->Course::SetName(ed->Course::GetName());
                            it->Student::SetGrade(ed->Student::GetGrade());
                            vdat.pop_back();
                        }
                    }
                }
//                for (const Data &a: vdat) {
//                    cout << a.Student::GetId() << "     " << setiosflags(ios::left) << setw(20) << a.Student::GetName()
//                         << a.Course::GetId() << "    " << setw(20) << a.Course::GetName() << "     "
//                         << a.Student::GetGrade() << endl << endl;
//                }
                break;
            } else {
                cout << endl;
                break;
            }
        }
        case 11: {
            for (const Student &a: vstu) {
                cout << a.GetId() << "  " << a.GetName() << "   " << endl;
            }
            cout << "Student List Printed!" << endl << endl;
            break;
        }
        case 12: {
            for (const Course &a: vcou) {
                cout << a.GetId() << "  " << a.GetName() << "   " << endl;
            }
            cout << "Course List Printed!" << endl << endl;
            break;
        }
        case 13: {
            char *FileName = new char[20];
            strcpy(FileName, "student_list.txt");
            ofstream of(FileName, ios_base::out);
            of << "Student List is as Follow" << endl;
            for (const Student &a: vstu) {
                of << a.GetId() << "        " << setiosflags(ios::left) << setw(20) << a.GetName() << endl;
            }
            of.close();
            delete[]FileName;
            cout << "Student List Printed!" << endl;
            break;
        }
        case 14: {
            char *FileName = new char[20];
            strcpy(FileName, "course_list.txt");
            ofstream of(FileName, ios_base::out);
            of << "Course List is as Follow" << endl;
            for (const Course &a: vcou) {
                of << a.GetId() << "        " << setiosflags(ios::left) << setw(20) << a.GetName() << endl;
            }
            of.close();
            delete[]FileName;
            cout << "Course List Printed!" << endl;
            break;
        }
        default: {
            cout << "Instruction Error!" << endl << endl;
            break;
        }
    }
}
//
// Created by 10048 on 2022/8/18.
//

