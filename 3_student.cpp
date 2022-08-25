#include "STUDENT.h"

Student::Student(int id, const char *name, const char *passwd) : Person(id, name, passwd) {

}

Student::Student(const Student &stu) : Person(stu.GetId(), stu.GetName(), stu.GetPasswd()) {

}

Student::~Student() {
//    cout << "Student destructor called" << endl;
}

double Student::AskForGrade(const vector<Data> &vect, int CouId) const {
    for (const Data &a: vect) {
        if (a.Student::GetId() == this->GetId() && a.Course::GetId() == CouId) {
            return a.Student::GetGrade();
        }
    }
    return -1;
}

bool less_cou(const Data &dat1, const Data &dat2) {
    if (dat1.Student::GetGrade() > dat2.Student::GetGrade()) {
        return true;
    } else if (dat1.Student::GetGrade() == dat2.Student::GetGrade()) {
        return dat1.Course::GetId() < dat2.Course::GetId();
    } else return false;
}

void Student::GetReport(const vector<Data> &vect) const {
    int cnt = 0;
    double sct = 0;
    vector<Data> res;
    for (const Data &a: vect) {
        if (a.Student::GetId() == this->GetId()) {
            res.push_back(a);
            ++cnt;
            sct += a.Student::GetGrade();
        }
    }
    if (cnt == 0) {
        cout << "No Data!" << endl;
        return;
    }
//    sort(res.begin(), res.end(), less_cou);
    char *FileName = new char[strlen(this->GetName()) + 15];
    strcpy(FileName, "report_");
    strcat(FileName, this->GetName());
    strcat(FileName, ".txt");
    ofstream of(FileName, ios_base::out);
    of << "Report " << this->GetName() << " (" << this->GetId() << ") as Follow" << endl;
    for (const Data &a: res) {
        of << a.Course::GetId() << "        " << setiosflags(ios::left) << setw(20) << a.Course::GetName() << "    "
           << a.Student::GetGrade() << endl;
    }
    of << "Average Grade: " << setprecision(5) << sct / cnt << endl;
    of.close();
    delete[]FileName;
    cout << "Report " << this->GetName() << " (" << this->GetId() << ") Printed!" << endl;
}

int WhereIsStu(const vector<Student> &vect, int id) {
    int i = 0;
    for (const Student &a: vect) {
        if (a.Student::GetId() == id) {
            return i;
        }
        ++i;
    }
    return -1;
}
