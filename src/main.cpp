#include "Sensor.h"
#define left_front_azmuth 42
#define left_rear_azmuth 135
#define right_front_azmuth -42
#define right_rear_azmuth -135
#define left_front_elevation 0
#define left_rear_elevation 0.48
#define right_front_elevation 0
#define right_rear_elevation 0.48

int main(int argc, char *argv[]){
    if(argc!=3){
     std::cout<<"Wrong args";   
    }

    Data::Reader dataReader(argv[1],argv[2]);
    Data::MeasuredData measurement= dataReader.readData();


}