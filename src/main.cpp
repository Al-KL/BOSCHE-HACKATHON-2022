#include "Sensor.h"
#define left_front_azmuth 42
#define left_rear_azmuth 135
#define right_front_azmuth -42
#define right_rear_azmuth -135
#define left_front_elevation 0
#define left_rear_elevation 0.48
#define right_front_elevation 0
#define right_rear_elevation 0.48
#define left_front_x 3.4738
#define left_rear_x -0.7664
#define right_front_x 3.4738
#define right_rear_x -0.7664
#define left_front_y 0.6286
#define left_rear_y -0.738
#define right_front_y -0.6286
#define right_rear_y -0.738
#define left_front_z 0.5156
#define left_rear_z 0.7359
#define right_front_z 0.5156
#define right_rear_z -0.7359

int main(int argc, char *argv[]){
    if(argc!=3){
     std::cout<<"Wrong args";   
    }

    Data::Reader dataReader(argv[1],argv[2]);
    Data::MeasuredData measurement= dataReader.readData();


}