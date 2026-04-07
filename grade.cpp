#include<iostream>
char getGrade(int score);
int main(){
	int score =0;
	std::cout << "Enter your score\n";
	std::cin>>score;
	char grade = getGrade(score);
	
	if(grade =='X'){
		std::cout << "Invalid\n";
		return 1;
	}
	std::cout<<"Your grade is "<<grade<<std::endl;
	return 0;

}

char getGrade(int score){
	if(score < 0 || score > 100){
		return 'X';
	}else if(score >=80){
		return 'A';
	}else if(score >=70){
		return'B';
	}else if(score >=60){
		return'C';
	}else{
		return 'F';
	}
}