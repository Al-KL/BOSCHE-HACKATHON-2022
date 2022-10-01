#include "Sensor.h"
int main(int argc, char *argv[]){
    if(argc!=3){
     std::cout<<"Wrong args";   
    }

    Data::Reader dataReader(argv[1],argv[2]);
    Data::MeasuredData measurement= dataReader.readData();


}