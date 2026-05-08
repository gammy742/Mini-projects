#pragma once
#include<string>
#include<vector>
#include "student.h"
#include"requirement.h"
#include<cctype>
#include <algorithm>
#include <limits>

class School{
    private:
        std::string className;
        int studentLimit;
        int classAmount;
        std::vector<Student> students;

        Student s;
    public:
        School();
        ~School();
        std::string getClassName()const;
        void setClassName(const std::string &cl);
        int getStudentLimit()const;
        void setStudentLimit(const int &s);
        int getClassAmount()const;
        void setClassAmount(const int &cla);
        void printEnrolled();
        void inputEnrolled();

};

class Program{
    private:
        std::string programName;
    public:
        Program();
        ~Program();
        std::string getProgramName() const;
        void setProgramName(const std::string &p);
};

class Gifted :public Program{

};