#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <vector>
namespace Data{
struct hostData{
    double t;
    double vxvRef;
    double axvRef;
    double vyvRef;
    double ayvRef;
    double psiDtOpt;
    unsigned int absRefTime;
};
struct sensorData{
    double t;
    double dx;
    double dy;
    double dz;
    double vx;
    double vy;
    double ax;
    double az;
    double p;

};
enum objectType{
    noDetection=0U,
    truck=1U,
    car =2U,
    motorbike=3U, 
    bicycle =4U, 
    pedestrian =5U,
    carOrTruck=6U
};
struct cameraData{
    double t;
    double dx;
    double dy;
    double vx;
    double vy;
    objectType type;
};
struct MeasuredData{
    hostData hostInfo;
    sensorData sensInfo[4][15];
    cameraData camInfo;
};
class Reader{
    public:
    Reader(std::string hostFile, std::string sensorFile){
        host=new std::fstream(hostFile);
 
        while(host->get()!='\n'){};
        sensor=new std::fstream(sensorFile);
        while(sensor->get()!='\n'){};
    }
    MeasuredData readData(){
        static bool readHost=true;
        unsigned int bufferSize=1024;
        static char* sensorBuffer=new char[bufferSize];
        static char *hostbuffer=new char[bufferSize];
        //sensor->getline(hostbuffer,bufferSize);
        //parse the read line from host
        if(readHost){
            std::vector<double> v;
            host->getline(hostbuffer,bufferSize);
            std::stringstream ss(hostbuffer);
            while(ss.good()){
                std::string substr;
                std::getline(ss,substr,',');
                v.push_back(atoi(substr.c_str()));
            }
            

        }
        readHost=!readHost;
    }
    private:
        std::fstream *host;
        std::fstream *sensor;
    
};
};
