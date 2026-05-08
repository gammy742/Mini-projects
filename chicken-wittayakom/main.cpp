#include<iostream>
#include<string>
#include"school.h"


int main(){
    School *sch=nullptr;
    sch = new School;

    sch->inputEnrolled();
    sch->printEnrolled();
    delete sch;
    return 0;
}