#include<iostream>
#include<string>
using namespace std;

class Student{
	private:
		string name;
		int score;
		char grade;

		void setGrade(){

			if(score<0 || score>100){
				grade = 'X';
			}
			else if(score>=80){
				grade = 'A';
			}
			else if(score>=70){
				grade = 'B';
			}
			else if(score>=60){
				grade = 'C';
			}	
			else if(score>=50){
				grade = 'D';
			}
			else{
				grade ='F';
			}
		}
	public:
		Student(string name ="Unknown",int score =0){
			this->name =name;
			this->score =score;
			setGrade();
		};
		
		string getName(){
			return name;
		}
		void setName(string name){
			this->name = name;
		}

		int getScore(){
			return score;
		}
		void setScore(int score){
			this->score = score;
			setGrade();
		}
		
		char getGrade(){
			return grade;
		}


		void displayDetails(){
			cout << "-----------Description-------------\n";
			cout<<"Student = "<<name<<endl;
			cout <<"Score = "<<score<<endl;
			cout<<"Grade = "<<grade <<endl;
		}
		
};

int main(){
	Student student1;
		
	int score;
	string name;

	cout<<"Input student name\n";
	getline(cin,name);

	cout <<"Input score = \n";
	cin>>score;
	
	student1.setScore(score);

	student1.setName(name);
	if(student1.getGrade() =='X'){
		std::cout<<"Grade Error\n";
		return 1;
	}
	
	student1.displayDetails();
	
	
	return 0;
}


