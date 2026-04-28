#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
#include <limits>

enum CHOICES{
	jobapply=1,exits=2
};
enum POSITION{
	graphicDesigner=1,marketing=2,humanResorce=3,accounting=4,none=5
};
void printMenu();
void printJobPositioin();
void input(std::string &name,std::string &gender,int &age,double &gpa);
class Jobapply{
	private:
		std::string name,gender,position;
		int age;
		double gpa;
	public:
		Jobapply(){
			name = "Unknown";
			gender ="Unknown";
			position ="General";
			age =0;
			gpa =0;
		};
		Jobapply(std::string name,std::string gender ="Unknown",int age=0,double gpa=0,std::string position ="General"){
			this->name =name;
			this->gender =gender;
			this->age =age;
			this->gpa =gpa;
			this->position = position;
		};
		std::string getName(){return name;}
 		void setName(std::string name){this->name = name;}
		
		std::string getGender(){return gender;}

		virtual void setGender(std::string gender){
			if(gender !="male" &&gender !="female" &&gender !="lgbtq+" &&gender !="lgbtq"){
				this->gender ="Unknown";
			}else{
				this->gender = gender;
			}
		}

		virtual std::string getPosition(){return position;}
		virtual void setPosition(std::string position){
			this->position = position;
		}
		

		double getGpa(){return gpa;}
		virtual void setGpa(double gpa){
			if(gpa<1.5 || gpa>4){
				this->gpa =0;
			}else{
				this->gpa =gpa;
			}
		}

		int getAge(){return age;}
		virtual void setAge(int age){
			if(age < 20 || age >= 60){
				this->age = 0;
			}
			else{
				this->age = age;
			}
			
		}

		virtual void displayDetails(){
			std::cout << "--------Welcome to Chicken Company----------\n";
			std::cout<<"Apply Position "<< position<< '\n';
			std::cout << "-----------Description-------------\n";

			if(age==0 || gpa ==0 || gender =="Unknown"){
				std::cout<<"Your application is rejected\n";
				return;
			}
			std::cout<<"Mr./Ms. "<<name<<'\n';
			std::cout <<"Age "<<age<<'\n';
			std::cout<<"Gender "<<gender<<'\n';
			std::cout<<"GPA  "<<gpa<<'\n';
			std::cout <<"Please wait for the result of your application\n";
		}
		~Jobapply(){}
};

class GraphicDesignerApply:public Jobapply{
	public:
		GraphicDesignerApply(){}
		GraphicDesignerApply(std::string n,std::string g,int age,double gpa,std::string p):Jobapply(n,g,age,gpa,p){}
		void setPosition(std::string position) override{
			Jobapply::setPosition("Graphic  Designer");
		}
};

class MarketingApply:public Jobapply{
	public:
		MarketingApply(){}
		MarketingApply(std::string n,std::string g,int age,double gpa):Jobapply(n,g,age,gpa){}
		void setGpa(double gpa) override{
			if(gpa<2.5 || gpa>4){
				Jobapply::setGpa(0);
			}else{
				Jobapply::setGpa(gpa);
			}
		}
		void setPosition(std::string position) override{
			Jobapply::setPosition("Marketing");
		}
};

class HumanResourceApply:public Jobapply{
	public:
		HumanResourceApply(){}
		HumanResourceApply(std::string n,std::string g,int age,double gpa)
			:Jobapply(n,g,age,gpa){}

		void setGender(std::string gender) override{
			if(gender !="female" && gender !="lgbtq+" &&gender !="lgbtq"){
				Jobapply::setGender("Unknown");
			}else{
				Jobapply::setGender(gender);
			}
		}
		void setPosition(std::string position) override{
			Jobapply::setPosition("Human Resource");
		}

};

class AccountingApply:public Jobapply{
	public:
		AccountingApply(){}
		AccountingApply(std::string n,std::string g,int age,double gpa):Jobapply(n,g,age,gpa){}
		void setPosition(std::string position) override{
			Jobapply::setPosition("Accounting");	
		}	
};

int main(){
	std::string name,gender,position;
	int age;
	double gpa;
	int choices;
	int positionChoices;

	Jobapply job;
	GraphicDesignerApply graphicApply;
	MarketingApply mkt;
	HumanResourceApply hr;
	AccountingApply acc;


	
	do {
		printMenu();
		std::cin >> choices;
		CHOICES choose = static_cast<CHOICES>(choices);
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
		switch (choose) {
			case jobapply: {
				printJobPositioin();
	
				// Move the declaration of applicant outside the inner do-while loop
				Jobapply *applicant = nullptr;
	
				do {
					std::cout << "Enter the one you want to apply\n";
					std::cin >> positionChoices;
					POSITION positionChoose =static_cast<POSITION>(positionChoices);
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
					switch (positionChoose) {
						case graphicDesigner:
							applicant = &graphicApply;
							break;
						case marketing:
							applicant = &mkt;
							break;
						case humanResorce:
							applicant = &hr;
							break;
						case accounting:
							applicant = &acc;
							break;
						case none:
							break;
						default:
							std::cout << "Please enter 1-5\n";
					}
	
					if (applicant == nullptr) {
						std::cout << "Please choose the position you want to apply\n";
					} else {
						input(name, gender, age, gpa);
						applicant->setName(name);
						applicant->setGender(gender);
						applicant->setAge(age);
						applicant->setGpa(gpa);
						applicant->setPosition(applicant->getPosition());
						applicant->displayDetails();
					}
				} while (positionChoices != none);
				
				break;
			}
	
			case exits:
				std::cout << "Thank you for visiting company\n";
				break;
		}
	} while (choices != exits);
	
	return 0;
}

void printMenu(){
	std::cout<<"THis is chicken company\n";
	std::cout<<"1.Apply for job\n";
	std::cout<<"2.Exit\n";
}

void printJobPositioin(){
	std::cout<<"Choose the position you want to apply\n";
	std::cout<<"1.Graphic Designer\n";
	std::cout<<"2.Marketing\n";
	std::cout<<"3.Human resource\n";
	std::cout<<"4.Accounting\n";
}

void input(std::string &name,std::string &gender,int &age,double &gpa){
	std::cout<<"Input your name\n";
	getline(std::cin,name);
	std::for_each(
		name.begin(),
		name.end(),
		//Lamda function
		[](char &ch){
			ch =::tolower(ch);
		}
	);

	std::cout<<"Input your age\n";
	std::cin>>age;
	std::cin.ignore();

	std::cout<<"Input your gender\n";
	getline(std::cin,gender);
	std::for_each(
		gender.begin(),
		gender.end(),
		//Lamda function
		[](char &ch){
			ch =::tolower(ch);
		}
	);

	std::cout<<"Input your GPA\n";
	std::cin>> gpa;
	std::cin.ignore();
}