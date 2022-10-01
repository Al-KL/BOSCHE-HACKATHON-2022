#include "../inc/Sensor.h"
#include "../inc/Controller.h"
#include  <iostream>
int main(int argc, char *argv[]){
    if(argc!=3){   
        return 0;
    }
    Data::Reader dataReader(argv[1],argv[2]);
    while(dataReader.isValid()){
            Data::MeasuredData measurement= dataReader.readData();
    }
}
