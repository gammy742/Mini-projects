#include"student.h"
#include<iostream>
#include<cctype>

Student::Student(){
    name="Unknown";
    age=0;
    gender="Unknown";
    address="Unknown";
};

Student::~Student(){
    std::cout<<"Object is Destroy\n";
}

//Name
std::string Student::getName()const{
    return name;
}
void Student::setName(const std::string &n){
    this->name =n;
}

//Age
int Student::getAge()const{
    return age;
}
void Student::setAge(const int &a){
    this->age=a;
}

//Gender
std::string Student::getGender()const{
    return gender;
}
void Student::setGender(const std::string &g){
    this->gender=g;
}

//Address
std::string Student::getAddress() const{
    return address;
}
void Student::setAddress(const std::string &ad){
    this->address=ad;
}
