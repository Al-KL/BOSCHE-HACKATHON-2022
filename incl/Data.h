#include <string>
#include <iostream>
#include <fstream>
namespace Data{
struct hostData{
    double vxvRef;
    double axvRef;
    double vyvRef;
    double ayvRef;
    double psiDtOpt;
    unsigned int absRefTime;
};
struct sensorData{
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

    }
    private:
        std::fstream *host;
        std::fstream *sensor;
    
};
};
