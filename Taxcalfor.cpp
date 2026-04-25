#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdio>
#include <vector>

class Calculator{
    public: 
        double cost;
        int choice,percent;
        std::string name;

    void printOutput(){
        std::cout << "Enter Your name\n";
        std::getline(std::cin , name);
        std::cout << "Hello " << name << '\n';
        std::cout << "\n";

        std::cout << "Enter The cost\n";
        std::cin >> cost;

        std::cout << "Enter The profit you want(%)\n";
        std::cin >> percent;

    }
    

};

class Stat : public Calculator{
    double priceBeforeVat;
    double vat;
    double pricePlusVat;
    double profit;  

    public:
        double priceBeforeVatCal(double cost,int percent){
            return (cost*100)/(100-percent);   
        }
        double vatCal(double cost,int percent){
            return priceBeforeVatCal(cost,percent) * 0.07;
        }
        double pricePlusVatCal(double cost,int percent){
            return priceBeforeVatCal(cost,percent) + vatCal(cost,percent);
        }
        double profitCal(double cost,int percent){
            return priceBeforeVatCal(cost,percent) - cost;
        }
        bool percentValid(int percent){
            if(percent >100){
                std:: cout << "That's too expensive\n";
                return false;
            }else if(percent <=0){
                std::cout << "That's not valid amount\n";
                return false;
            }else{
                return true;
            }
        }
        void calculateAll(){
            pricePlusVat=pricePlusVatCal(cost,percent);
            priceBeforeVat=priceBeforeVatCal(cost,percent);
            vat=vatCal(cost,percent);
            profit=profitCal(cost,percent);
        }
        void showResult(){
            std::cout << "The price should be sale is " << std::setprecision(2) << std::fixed << pricePlusVat<< " Bath\n";
            std::cout << "The price before vat is " << std::setprecision(2) << std::fixed << priceBeforeVat << " Bath\n";
            std::cout << name << " will get profit " << std::setprecision(2) << std::fixed << profit << " Bath\n";
            std::cout << name << " Vat: " << std::setprecision(2) << std::fixed << vat<< " Bath\n";
            
        }
        
        
};

class Target : public Calculator{
    public:
        std::vector<std::string> names;
        double fixCost,availableCost;

};
int main(){
   Stat myCal;
   Target target;
   int choice;

   do{
        std::cout << "Please choose the menu\n";
        std::cout << "************************\n";
        std::cout << "1.Price Calculator\n";
        std::cout << "2.exit\n";

        std::cin >> choice;
        std::cin.clear(); 
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice){
            case 1:  
                myCal.printOutput();
                if((!myCal.percentValid(myCal.percent))){
                break;
               }
                myCal.calculateAll();
                myCal.showResult();
                break;
            case 2: 
                
                std::cout << "thank you\n";
                break;
        }
    }while(choice !=2);
  
    return 0;
}

