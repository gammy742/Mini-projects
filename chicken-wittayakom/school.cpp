#include "school.h"
#include<iostream>


School::School(){
    className="Unknown";
    studentLimit=0;
    classAmount=0;

    
}

School::~School(){
    std::cout<<"Object is destroy\n";
}

std::string School::getClassName()const{
    return className;
};
        
void School::setClassName(const std::string &cl){
    this->className=cl;
};

int School::getStudentLimit()const{
    return studentLimit;
};

void School::setStudentLimit(const int &s){
    if(s>0 && s<40){
        this->studentLimit=s;
    }else{
        std::cerr<<"Invalid student limit(1-40)\n";
    }
};

int School::getClassAmount()const{
    return classAmount;
};

void School::setClassAmount(const int &cla){
    if(cla>0 && cla<=14){
        this->classAmount=cla;
    }else{
        std::cerr<<"Invalid class limit(1-14)\n";
    }
};

void School::inputEnrolled(){
    std::string tempName;
    int tempAge;
    std::string tempGender;
    std::string tempAddress;
    
    std::cout<<"*****************************\n\n";
    std::cout<<"Enter Your Information\n";
    std::cout<<"*****************************\n\n";

    std::cout<<"Enter your name\n";
    std::cin.ignore();
    std::getline(std::cin,tempName);
    s.setName(tempName);

    std::cout<<"Enter Your Age\n";
    std::cin>>tempAge;
    std::cin.clear();
    s.setAge(tempAge);

    std::cout<<"Enter your Gender\n";
    std::cin.ignore();
    std::cin>>tempGender;

    std::for_each(
        tempGender.begin(),
        tempGender.end(),
        [](char &ch){
            ch=::tolower(ch);
        }
    );
    s.setGender(tempGender);

    std::cout<<"Enter your Address\n";
    std::cin.ignore();
    std::getline(std::cin,tempAddress);
    s.setAddress(tempAddress);
};


void School::printEnrolled(){
    std::cout<<"*****************************\n";
    std::cout<<"Welcome to Chicken-Wittayakom\n";
    std::cout<<"*****************************\n";

    std::cout<<"Thank you for Your Enrolled\n";
    std::cout<<s.getName()<<'\n';
    std::cout<<s.getAge()<<'\n';
    std::cout<<s.getGender()<<'\n';
    std::cout<<s.getAddress()<<'\n';
    
}