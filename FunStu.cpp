#include "STUDENT.h"

extern bool Flg1, Flg2, Flg3, Flg4;

void FunStu(int ID, const vector<Course> &vcou, vector<Student> &vstu, const vector<Data> &vdat) {
    cout << "You are Student (" << ID << "). Please Input a number between 1 and 6 to choose a module!"
         << endl;
    cout << "1: Change Password\n2: Look for Grade\n3: Get Report\n4: Print Report to a File\n";
    cout << "5: Save New Password to a File\n6: Exit to Main Menu\n";
    int num;
    DealWithCharBeforeInt();
    cin >> num;
    switch (num) {
        case 6: {
            Flg1 = false;
            char a;
            bool flg = true;
            while (flg) {
                cout << "Would you like to Save New Password to a File? Input 'y' for YES while 'n' for NOT"
                     << endl;
                cin >> a;
                if (a == 'y') {
                    SaveData(2, vstu, vcou, vdat);
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
            int i = WhereIsStu(vstu, ID);
            char old_passwd[MaxPasswdLen + 1], new_passwd[MaxPasswdLen + 1];
            cout << "Please Input your Old Password!" << endl;
            cin >> old_passwd;
            if (strcmp(old_passwd, (vstu.begin() + i)->GetPasswd()) == 0) {
                cout << "Please Input your New Password! Password Length: between " << MinPasswdLen << " and "
                     << MaxPasswdLen << "!" << endl;
                cin >> new_passwd;
                DealWithCharBehindInt();
                while (strlen(new_passwd) < MinPasswdLen) {
                    cout << "Password Length Invalid! Please Input your New Password! Password Length: between "
                         << MinPasswdLen << " and " << MaxPasswdLen << "!" << endl;
                    cin >> new_passwd;
                    DealWithCharBehindInt();
                }
                (vstu.begin() + i)->SetPasswd(new_passwd);
                cout << "New Password Set!" << endl;
            } else {
                cout << "Password Input Error!" << endl;
            }
            cout << endl;
            break;
        }
        case 2: {
            int i, id_cou;
            cout << "Please Input the ID of Course!" << endl;
            DealWithCharBeforeInt();
            cin >> id_cou;
            if (IdCheck_cou(id_cou, vcou)) {
                i = WhereIsData(vdat, ID, id_cou);
                if (i + 1) {
                    cout << "Grade of Course (" << id_cou << "): " << ((vdat.begin() + i))->Student::GetGrade() << endl
                         << endl;
                } else {
                    cout << "Grade of Course (" << id_cou << ") Not Found!" << endl << endl;
                }
            } else {
                cout << endl;
            }
            break;
        }
        case 3: {
            int i = WhereIsStu(vstu, ID);
            cout << "Report " << (vstu.begin() + i)->GetName() << " (" << ID << ") as Follow" << endl;
            for (const Data &a: vdat) {
                if (a.Student::GetId() == ID) {
                    cout << a.Course::GetId() << "        " << setiosflags(ios::left) << setw(20)
                         << a.Course::GetName() << "    "
                         << a.Student::GetGrade() << endl;
                }
            }
            cout << "Average Grade: " << setprecision(5) << (vstu.begin() + i)->GetGrade() << endl;
            cout << endl;
            break;
        }
        case 4: {
            GetReport(vdat, vstu, vcou, ID, true);
            cout << endl;
            break;
        }
        case 5: {
            SaveData(2, vstu, vcou, vdat);
            break;
        }
        default: {
            cout << "Instruction Error!" << endl << endl;
            break;
        }
    }
}
