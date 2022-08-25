#include "STUDENT.h"

extern bool Flg1, Flg2, Flg3, Flg4;

int main() {
    Admin admin(40000, "Administrator", "040000");
    Teacher teacher01(30000, "Teacher One", "030000");
    Teacher teacher02(31000,"Teacher Two","031000");
    Teacher teacher03(32000,"Teacher Three","032000");
    vector<Data> vect_d;
    vector<Student> vect_stu;
    vector<Course> vect_cou;
    vector<Teacher> vect_tea;
    vector<Admin> vect_adm;
    vect_tea.push_back(teacher01);
    vect_tea.push_back(teacher02);
    vect_tea.push_back(teacher03);
    vect_adm.push_back(admin);
    cout << "Welcome to Student Performance Management System!" << endl;
    int ID;
    while (!Flg4) {
        menu(ID, vect_cou, vect_stu, vect_tea, vect_adm, vect_d);
    }
    return 0;
}
