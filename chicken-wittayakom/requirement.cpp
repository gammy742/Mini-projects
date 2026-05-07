#include "requirement.h"
#include<iostream>

Requirement::Requirement(){
    age=0;
    gender="Unknown";
}

Requirement::~Requirement(){
    std::cout<<"Requirement object destroy\n";
}

void Requirement::setGender(const std::string &g){
    if(g=="male"||g=="female"||g=="lgbtq"||g=="lgbtq+"){
        this->gender = g;
    }else{
        std::cerr<<"Invalid gender\n";
    }
}

void Requirement::setAge(const int &a){
    if(a>=0 && a<=18){
        this->age=a;
    }else{
        std::cerr<<"Invalid gender\n";
    }

}