#include "STUDENT.h"

extern bool Flg1, Flg2, Flg3, Flg4;

int main() {
    Course ln(10000, "Linear Algebra");
    Course cl(10001, "Calculus");
    Course c(10002, "C++");
    Course dm(10003, "Discrete Mathematics");
    Student yxq(20000, "Xiaoquan You", "123456");
    Student hs(20001, "Sanford Huang", "147258");
    Student lcy(20002, "Chengyun Li", "132785");
    Student lzh(20003, "Zonghao Liu", "111111");
    Teacher zwm(30000, "Wenming Zou", "2.71828");
    Admin wxq(40000, "Xiqin Wang", "000000");
    vector<Data> vect_d;
    vect_d.push_back(Data(10000, 20000, "Linear Algebra", "Xiaoquan You", 100));
    vect_d.push_back(Data(10002, 20000, "C++", "Xiaoquan You", 90));
    vect_d.push_back(Data(10001, 20000, "Calculus", "Xiaoquan You", 90));
    vect_d.push_back(Data(10003, 20000, "Discrete Mathematics", "Xiaoquan You", 99));
    vect_d.push_back(Data(10001, 20001, "Calculus", "Sanford Huang", 90));
    vect_d.push_back(Data(10002, 20001, "C++", "Sanford Huang", 95));
    vect_d.push_back(Data(10003, 20001, "Discrete Mathematics", "Sanford Huang", 100));
    vect_d.push_back(Data(10001, 20002, "Calculus", "Chengyun Li", 85));
    vector<Student> vect_stu;
    vector<Course> vect_cou;
    vector<Teacher> vect_tea;
    vector<Admin> vect_adm;
    vect_stu.push_back(yxq);
    vect_stu.push_back(hs);
    vect_stu.push_back(lcy);
    vect_stu.push_back(lzh);
    vect_cou.push_back(ln);
    vect_cou.push_back(cl);
    vect_cou.push_back(c);
    vect_cou.push_back(dm);
    vect_tea.push_back(zwm);
    vect_adm.push_back(wxq);
    cout << "Welcome to Student Performance Management System!" << endl;
    int ID;
    while (!Flg4) {
        menu(ID, vect_cou, vect_stu, vect_tea, vect_adm, vect_d);
    }
    return 0;
}
