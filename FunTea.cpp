#include "STUDENT.h"

extern bool Flg1, Flg2, Flg3, Flg4;

void FunTea(int ID, vector<Course> &vcou, vector<Student> &vstu, vector<Teacher> &vtea, vector<Data> &vdat) {
    cout << "You are Teacher (" << ID << "). Please Input a number between 1 and 14 to choose a module!"
         << endl;
    cout << "1: Input Grade\n2: Set Grade\n3: Delete Grade\n4: Look for Grade\n";
    cout
            << "5: Get Average Grade of a Student\n6: Get Average Grade of a Course\n7: Get Average Grade of All Students\n";
    cout << "8: Get Report of a Student\n9: Get Report of a Course\n10: Get Report of All Students\n";
    cout
            << "11: Print Report of a Student to a File\n12: Print Report of a Course to a File\n13: Print Report of All Students to a File\n";
    cout << "14: Save Data of Grades to a File\n15: Exit to Main Menu\n";
    int num;
    DealWithCharBeforeInt();
    cin >> num;
    switch (num) {
        int id_stu, id_cou;
        case 15: {
            Flg2 = false;
            char a;
            bool flg = true;
            while (flg) {
                cout << "Would you like to Save Data of Grades to a File? Input 'y' for YES while 'n' for NOT" << endl;
                cin >> a;
                if (a == 'y') {
                    SaveData(1, vstu, vcou, vdat);
                    SaveData(2, vstu, vcou, vdat);
                    SaveData(3, vstu, vcou, vdat);
                    flg = false;
                } else if (a == 'n') {
                    flg = false;
                } else {
                    cout << "Instruction Error!" << endl << endl;
                }
                DealWithCharBehindInt();
            }
            break;
        }
        case 1: {
            InputData(vdat, vstu, vcou);
            break;
        }
        case 2: {
            SetData(vdat, vstu, vcou);
            break;
        }
        case 3: {
            DelData(vdat, vstu, vcou);
            break;
        }
        case 4: {
            cout
                    << "Please Input the Data to Be Sought! Example: IdOfStudent(eg:20000~29999) IdOfCourse(eg:10000~19999)"
                    << endl;
            DealWithCharBeforeInt();
            cin >> id_stu;
            DealWithCharBeforeInt();
            cin >> id_cou;
            int i;
            i = WhereIsData(vdat, id_stu, id_cou);
            if (i + 1) {
                cout << "Data (" << id_stu << ", " << id_cou << ") Found!" << endl;
                vector<Data>::iterator it;
                it = vdat.begin() + i;
                cout << "Grade (" << id_stu << ", " << id_cou << "): " << it->Student::GetGrade() << endl << endl;
            } else {
                cout << "Data (" << id_stu << ", " << id_cou << ") Not Found!" << endl << endl;
            }
            break;
        }
        case 5: {
            int i = 0;
            cout << "Please Input the ID of Student!" << endl;
            DealWithCharBeforeInt();
            cin >> id_stu;
            if (IdCheck_stu(id_stu, vstu)) {
                i = WhereIsStu(vstu, id_stu);
                cout << "Average Grade of Student (" << id_stu << "): " << ((vstu.begin() + i))->GetGrade()
                     << endl << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 6: {
            int i = 0;
            cout << "Please Input the ID of Course!" << endl;
            DealWithCharBeforeInt();
            cin >> id_cou;
            if (IdCheck_cou(id_cou, vcou)) {
                i = WhereIsCou(vcou, id_cou);
                cout << "Average Grade of Course (" << id_cou << "): " << ((vcou.begin() + i))->GetGrade()
                     << endl << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 7: {
            int cnt = 0;
            double gra = 0;
            for (const Student &a: vstu) {
                gra += a.GetGrade();
                ++cnt;
            }
            gra = gra / cnt;
            cout << "Average Grade of All Students: " << gra << endl << endl;
            break;
        }
        case 8: {
            int i = 0;
            cout << "Please Input the ID of Student!" << endl;
            DealWithCharBeforeInt();
            cin >> id_stu;
            if (IdCheck_stu(id_stu, vstu)) {
                i = WhereIsStu(vstu, id_stu);
                cout << "Report " << (vstu.begin() + i)->GetName() << " (" << id_stu << ") as Follow" << endl;
                for (const Data &a: vdat) {
                    if (a.Student::GetId() == id_stu) {
                        cout << a.Course::GetId() << "        " << setiosflags(ios::left) << setw(20)
                             << a.Course::GetName() << "    "
                             << a.Student::GetGrade() << endl;
                    }
                }
                cout << "Average Grade: " << setprecision(5) << (vstu.begin() + i)->GetGrade() << endl;
                cout << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 9: {
            int i = 0;
            cout << "Please Input the ID of Course!" << endl;
            DealWithCharBeforeInt();
            cin >> id_cou;
            if (IdCheck_cou(id_cou, vcou)) {
                i = WhereIsCou(vcou, id_cou);
                cout << "Report " << (vcou.begin() + i)->GetName() << " (" << id_cou << ") as Follow" << endl;
                for (const Data &a: vdat) {
                    if (a.Course::GetId() == id_cou) {
                        cout << a.Student::GetId() << "        " << setiosflags(ios::left) << setw(20)
                             << a.Student::GetName() << "    "
                             << a.Student::GetGrade() << endl;
                    }
                }
                cout << "Average Grade: " << setprecision(5) << (vcou.begin() + i)->GetGrade() << endl;
                cout << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 10: {
            int cnt = 0;
            double gra = 0;
            cout << "Report of All Students is as Follow" << endl;
            for (const Student &a: vstu) {
                cout << a.GetId() << "        " << setiosflags(ios::left) << setw(20) << a.GetName() << "    "
                     << a.GetGrade() << endl;
                gra += a.GetGrade();
                ++cnt;
            }
            cout << "Average Grade: " << setprecision(5) << gra / cnt << endl;
            cout << endl;
            break;
        }
        case 11: {
            cout << "Please Input the ID of Student!" << endl;
            DealWithCharBeforeInt();
            cin >> id_stu;
            if (IdCheck_stu(id_stu, vstu)) {
                GetReport(vdat, vstu, vcou, id_stu, false);
                cout << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 12: {
            cout << "Please Input the ID of Course!" << endl;
            DealWithCharBeforeInt();
            cin >> id_cou;
            if (IdCheck_cou(id_cou, vcou)) {
                GetReport(vdat, vstu, vcou, id_cou, true);
                cout << endl;
            } else {
                cout << endl;
            }
            break;
        }
        case 13: {
            GetReport(vstu);
            cout << endl;
            break;
        }
        case 14: {
            SaveData(1, vstu, vcou, vdat);
            SaveData(2, vstu, vcou, vdat);
            SaveData(3, vstu, vcou, vdat);
            break;
        }
        default: {
            cout << "Instruction Error!" << endl << endl;
            break;
        }
    }
}
