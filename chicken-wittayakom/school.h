#pragma once
#include<string>

class School{
    private:
        std::string className;
        int studentLimit;
    public:
        School();
        ~School();
        std::string getClassName()const;
        void setClassName(const std::string &cl);
        int getStudentLimit()const;
        int setStudentLimit(const int &s);
    
};