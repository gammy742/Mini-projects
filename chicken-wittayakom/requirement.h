#pragma once
#include<string>

class Requirement{
    private:
        int age;
        std::string gender;

    public:
        Requirement();
        ~Requirement();
        int getAge() const;
        void setAge(const int &a);
        std::string getGender() const;
        void setGender(const std::string &g);

};

