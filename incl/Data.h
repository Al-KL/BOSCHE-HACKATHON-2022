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
    noDetection=0,
    truck=1,
    car =2,
    motorbike=3, 
    bicycle =4, 
    pedestrian =5,
    carOrTruck=6
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
    sensorData sensInfo[4][10];
    cameraData camInfo[15];
};
class Reader{
    public:
    Reader(std::string hostFile, std::string sensorFile){
        host=new std::fstream(hostFile);
        sensor=new std::fstream(sensorFile);
        if(host->is_open() && sensor->is_open()){
            valid=true;
            while(host->get()!='\n'){};
            while(sensor->get()!='\n'){};
        }
    }
    MeasuredData readData(){
        static bool readHost=true;
        unsigned int bufferSize=1024;
        static char* sensorBuffer=new char[bufferSize];
        static char *hostbuffer=new char[bufferSize];
        static MeasuredData data;
        if(!host->good() || !sensor->good()){
            valid=false;
        }
        //sensor->getline(hostbuffer,bufferSize);
                std::vector<double> l;
        host->getline(sensorBuffer, bufferSize);
        std::stringstream sb(sensorBuffer);
        while (sb.good()) {
            std::string substr1;
            std::getline(sb, substr1, ',');
            l.push_back(atoi(substr1.c_str()));
        }
        data.camInfo[0..14]->t = data.sensInfo[0..4]->t = l[0];
        int j=2;
        for (int i = 0, i < 15, i++) {
            data.camInfo[i].dx = l[j] / 128;
            j++
        }
        for (int i = 0, i < 15, i++) {
            data.camInfo[i].dy = l[j] / 128;
            j++
        }
        for (int i = 0, i < 15, i++) {
            data.camInfo[i].type = static_cast<objectType>((int)l[j]) ;//not really sure
            j++
        }
        for (int i = 0, i < 15, i++) {
            data.camInfo[i].vx = l[j] / 256;
            j++
        }
        for (int i = 0, i < 15, i++) {
            data.camInfo[i].vy = l[j] / 256;
            j++
        }
        j = j + 3;//timestamp
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].ax = l[j] / 2048;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].ay = l[j] / 2048;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].dx = l[j] / 128;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].dy = l[j] / 128;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].dz = l[j] / 128;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].p= l[j] / 128;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].vx= l[j] / 256;
                j++
            }
        }
        for (int i = 0; i < 10, i++) {
            for (int k = 0; k < 4; k++) {
                data.sensInfo[k][i].vy = l[j] / 256;
                j++
            }
        }

        //parse the read line from host
        if(readHost){
            std::vector<double> v;
            host->getline(hostbuffer,bufferSize);
            std::stringstream ss(hostbuffer);
            while(ss.good()){
                std::string substr;
                std::getline(ss,substr,',');
                v.push_back(atof(substr.c_str()));
            }
            data.hostInfo.t=v[0];
            data.hostInfo.axvRef=v[1]/2048;
            data.hostInfo.ayvRef=v[2]/2048;
            data.hostInfo.psiDtOpt=v[3]/16384;
            data.hostInfo.vxvRef=v[4]/256;
            data.hostInfo.vyvRef=v[5]/256;
        }
        readHost=!readHost;
        return data;
    }
    bool isValid(){
        return valid;
    }
    private:
        std::fstream *host;
        std::fstream *sensor;
        bool valid;
    
    //trying commit
};
};
