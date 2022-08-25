#include "STUDENT.h"

Course::Course(int id, const char *name) : Item(id, name) {

}

Course::Course(const Course &cou) : Item(cou.GetId(), cou.GetName()) {

}

Course::~Course() {
//    cout<<"Course destructor called"<<endl;
}

double Course::AskForGrade(const vector<Data> &vect, int StuId) const {
    for (const Data &a: vect) {
        if (a.Student::GetId() == StuId && a.Course::GetId() == this->GetId()) {
            return a.Student::GetGrade();
        }
    }
    return -1;
}

bool less_stu(const Data &dat1, const Data &dat2) {
    if (dat1.Student::GetGrade() > dat2.Student::GetGrade()) {
        return true;
    } else if (dat1.Student::GetGrade() == dat2.Student::GetGrade()) {
        return dat1.Student::GetId() < dat2.Student::GetId();
    } else return false;
}

void Course::GetReport(const vector<Data> &vect) const {
    int cnt = 0;
    double sct = 0;
    vector<Data> res;
    for (const Data &a: vect) {
        if (a.Course::GetId() == this->GetId()) {
            res.push_back(a);
            ++cnt;
            sct += a.Student::GetGrade();
        }
    }
    if (cnt == 0) {
        cout << "No Data!" << endl;
        return;
    }
    sort(res.begin(), res.end(), less_stu);
    char *FileName = new char[strlen(this->GetName()) + 100];
    strcpy(FileName, "D:\\1_summer\\c++\\STUDENT\\report\\teacher\\report_");
    strcat(FileName, this->GetName());
    strcat(FileName, ".txt");
    ofstream of(FileName, ios_base::out);
    of << "Report " << this->GetName() << " (" << this->GetId() << ") as Follow" << endl;
    for (const Data &a: res) {
        of << a.Student::GetId() << "        " << setiosflags(ios::left) << setw(20) << a.Student::GetName() << "    "
           << a.Student::GetGrade() << endl;
    }
    of << "Average Grade: " << setprecision(5) << sct / cnt << endl;
    of.close();
    delete[]FileName;
    cout << "Report " << this->GetName() << " (" << this->GetId() << ") Printed!" << endl;
}
//Get the report of the course, and save the result to "report_/NameOfCourse/.txt"

int WhereIsCou(const vector<Course> &vect, int id) {
    int i = 0;
    for (const Course &a: vect) {
        if (a.Course::GetId() == id) {
            return i;
        }
        ++i;
    }
    return -1;
}
