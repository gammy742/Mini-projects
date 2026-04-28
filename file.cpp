#include <iostream>
#include<string>
#include<fstream>
#include <cstdlib>
using namespace std;

class Converfiles{
    private:
        std::string inputFile="video.mov";
        std::string outputFile="output.mp4";

        std::string driveDestination="googledrive:Myvideo/";
    public: 
        std::string getInputFile(){return inputFile;}
        void setInputFile(std::string inputFile){
            if(inputFile.empty()){
                std::cerr<<"[ข้อผิดพลาด] ชื่อไฟล์ต้นฉบับต้องไม่เป็นค่าว่าง!' "<<std::endl;
                return;
            }

            this->inputFile=inputFile;
        }

        void startProcess(){
            //Checking File
            std::ifstream fileCheck(inputFile);
            if(!fileCheck){
                std::cerr<<"[ข้อผิดพลาด] หาไฟล์"<<inputFile<<"ไม่พบ\n";
                return;
            }
            fileCheck.close();
            
            //Prepare
            std::string ffmpeg_cmd = "ffmpeg -i " + inputFile +" -vcodec libx264 -crf 18 -acodec aac "+outputFile;
            std::string rclone_cmd ="rclone copy "+outputFile+" "+driveDestination;

            //File COnvert
            std::cout<<"ConvertFile to mp4.\n";
            if(std::system(ffmpeg_cmd.c_str())==0){
                //Upload to drive
                if(std::system(rclone_cmd.c_str())==0){
                    std::cout<<"finishe upload to drive\n";
                }else{
                    std::cerr<<"rclone error\n";
                }

            }else{
                std::cerr<<"[ข้อผิดพลาด] แปลงไฟล์ล้มเหลว โปรดเช็คว่ามีโปรแกรม FFmpeg ในเครื่องหรือไม่\n";
            }
        }
};

int main() {
    Converfiles myApp;

    myApp.setInputFile("IMG_0696.MOV");
    myApp.startProcess();
    return 0;
}