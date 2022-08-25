#include "STUDENT.h"

const int check_code = 0x1234abcd;

//write data to file "data_student/course/grade.dat"
void SaveData(int flg, const vector<Student> &vstu, const vector<Course> &vcou, const vector<Data> &vdat) {
    char *FileName = new char[100];
    int length, TotalSize;
    if (flg == 1) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_course.dat");
        ofstream of(FileName, ios_base::out | ios_base::binary);
        if (of.is_open()) {
            of.write((char *) &check_code, sizeof(int));
            length = vcou.size();
            TotalSize = length * sizeof(Course);
            of.write((char *) &length, sizeof(int));
            of.write((char *) &TotalSize, sizeof(int));
            of.write((char *) &vcou[0], TotalSize);
            of.write((char *) &check_code, sizeof(int));
            of.close();
            cout << "Data of Course Saved Successfully!" << endl << endl;
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else if (flg == 2) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_student.dat");
        ofstream of(FileName, ios_base::out | ios_base::binary);
        if (of.is_open()) {
            of.write((char *) &check_code, sizeof(int));
            length = vstu.size();
            TotalSize = length * sizeof(Student);
            of.write((char *) &length, sizeof(int));
            of.write((char *) &TotalSize, sizeof(int));
            of.write((char *) &vstu[0], TotalSize);
            of.write((char *) &check_code, sizeof(int));
            of.close();
            cout << "Data of Student Saved Successfully!" << endl << endl;
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else if (flg == 3) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_grade.dat");
        ofstream of(FileName, ios_base::out | ios_base::binary);
        if (of.is_open()) {
            of.write((char *) &check_code, sizeof(int));
            length = vdat.size();
            TotalSize = length * sizeof(Data);
            of.write((char *) &length, sizeof(int));
            of.write((char *) &TotalSize, sizeof(int));
            of.write((char *) &vdat[0], TotalSize);
            of.write((char *) &check_code, sizeof(int));
            of.close();
            cout << "Data of Grade Saved Successfully!" << endl << endl;
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else {
        cout << "Instruction Error!" << endl << endl;
    }
    delete[]FileName;
}

void Restore(int flg, vector<Student> &vstu, vector<Course> &vcou, vector<Data> &vdat) {
    char *FileName = new char[100];
    int Tmpcheck_code;
    int length, TotalSize;
    if (flg == 1) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_course.dat");
        ifstream ifile(FileName, ios_base::in | ios_base::binary);
        if (ifile.is_open()) {
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            Course tmp(0, "");
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the begin of File!" << endl;
                return;
            }
            ifile.read((char *) &length, sizeof(int));
            ifile.read((char *) &TotalSize, sizeof(int));
            while (!vcou.empty()) {
                vcou.pop_back();
            }
            for (int i = 1; i <= length; ++i) {
                ifile.read((char *) &tmp, sizeof(Course));
                vcou.push_back(tmp);
            }
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the end of File!" << endl;
                return;
            }
            ifile.close();
            cout << "Data of Course Restored Successfully!" << endl << endl;
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else if (flg == 2) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_student.dat");
        ifstream ifile(FileName, ios_base::in | ios_base::binary);
        if (ifile.is_open()) {
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            Student tmp(0, "", "");
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the begin of File!" << endl;
                return;
            }
            ifile.read((char *) &length, sizeof(int));
            ifile.read((char *) &TotalSize, sizeof(int));
            while (!vstu.empty()) {
                vstu.pop_back();
            }
            for (int i = 1; i <= length; ++i) {
                ifile.read((char *) &tmp, sizeof(Student));
                vstu.push_back(tmp);
            }
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the end of File!" << endl;
                return;
            }
            ifile.close();
            cout << "Data of Student Restored Successfully!" << endl << endl;
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else if (flg == 3) {
        strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\data\\data_grade.dat");
        ifstream ifile(FileName, ios_base::in | ios_base::binary);
        if (ifile.is_open()) {
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            Data tmp(0, 0, "", "", 0);
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the begin of File!" << endl;
                return;
            }
            ifile.read((char *) &length, sizeof(int));
            ifile.read((char *) &TotalSize, sizeof(int));
            while (!vdat.empty()) {
                vdat.pop_back();
            }
            for (int i = 1; i <= length; ++i) {
                ifile.read((char *) &tmp, sizeof(Data));
                vdat.push_back(tmp);
            }
            ifile.read((char *) &Tmpcheck_code, sizeof(int));
            if (Tmpcheck_code != check_code) {
                cout << "Unknown Format at the end of File!" << endl;
                return;
            }
            ifile.close();
            cout << "Data of Grade Restored Successfully!" << endl << endl;
            SetAvgGradeOfAll(vdat, vcou, vstu);
        } else {
            cout << "File Open Error!" << endl << endl;
        }
    } else {
        cout << "Instruction Error!" << endl << endl;
    }
    delete[]FileName;
}
