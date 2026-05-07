#include "date.h"
#include<iostream>

Date::Date(){
    day=1;
    month=1;
    year=2026;
}

Date::~Date(){
    std::cout<<"Date object destroy\n";
}

void Date::inputDate(){
    std::cout<<"Enter Year: \n";
    std::cin>> year;

    while(year<2026||year>2040){
        std::cerr<<"Invalid\n";
        std::cout<<"Enter year(2026)";
        std::cin>>year;
    }
    setYear(year);

    std::cout<<"Enter Month\n";
    std::cin>>month;

    while(month<1||month>12){
        std::cerr<<"Invalid\n\n";
        std::cout<<"Enter Month(1-12)";
        std::cin>>month;
    }
    setMonth(month);

    std::cout<<"Enter Day: \n";
    std::cin>>day;

    //ลงท้ายด้วยคม
    if(month==1||month==3||month==5||
        month==7||month==8||month==10||month==12){
            while(day<1||day>31){
                std::cerr<<"Invalid\n\n";
                std::cout<<"Enter Day(1-31)";
                std::cin>>day;
            }
    }else if(month==4||month==6||month==9||month==11){
        //ลงท้ายด้วยยน
        while(day<1||day>30){
            std::cerr<<"Invalid\n\n";
            std::cout<<"Enter day(1-30)";
            std::cin>>day;
        }
    }else if(year %4==0){
        while(day<1||day>29){
            std::cerr<<"Invalid\n\n";
            std::cout<<"Enter day(1-29)";
            std::cin>>day;
        }
    }else{
         while(day<1||day>28){
            std::cerr<<"Invalid\n\n";
            std::cout<<"Enter day(1-28)";
            std::cin>>day;
        }
    }

    setDay(day);
}

void Date::displayDate(){
    std::cout<<getMonth()<<"/"<<getDay()<<"/"<<getYear();
}