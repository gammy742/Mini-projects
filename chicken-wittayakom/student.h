#pragma once
#include<string>

class Student{
    private:
        std::string name;
        int age;
        std::string gender;
        std::string address;
    public:
        Student();
        ~Student();
        std::string getName() const;
        void setName(const std::string &n);
        int getAge() const;
        void setAge(const int &a);
        std::string getGender() const;
        void setGender(const std::string &g);
        std::string getAddress()const;
        void setAddress(const std::string &ad);
};