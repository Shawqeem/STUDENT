cmake_minimum_required(VERSION 3.20)
project(STUDENT)

set(CMAKE_CXX_STANDARD 20)

add_executable(STUDENT main.cpp 1_item.cpp STUDENT.h 3_student.cpp 3_teacher.cpp 3_admin.cpp 2_person.cpp 2_course.cpp 4_data.cpp menu.cpp FunAdm.cpp FunTea.cpp FunStu.cpp)
