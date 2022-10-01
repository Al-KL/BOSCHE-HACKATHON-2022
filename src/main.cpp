#include "../inc/Sensor.h"
#include "../inc/Controller.h"
#include  <iostream>
int main(int argc, char *argv[]){
    if(argc!=3){   
        return 0;
    }
    Data::Reader dataReader(argv[1],argv[2]);
    sensor::Radar radarLR(left_rear_azmuth,left_rear_elevation,left_rear_x,left_rear_y,left_rear_z);
    sensor::Radar radarRF(right_front_azmuth,right_front_elevation,right_front_x,right_front_y,right_front_z);
    sensor::Radar radatRR(right_rear_azmuth,right_rear_elevation,right_rear_x,right_rear_y,right_rear_z);
    sensor::Camera(camera_x,camera_y,camera_z);
    while(dataReader.isValid()){
            Data::MeasuredData measurement= dataReader.readData();
    }
}
