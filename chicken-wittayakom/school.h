#pragma once
#include<string>
#include<vector>
#include "student.h"

class School{
    private:
        std::string className;
        int studentLimit;
        int classAmount;
        std::vector<Student> students;
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