#include "../inc/Controller.h"
#include "../inc/Sensor.h"
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
#define camera_x 1.7826001
#define camera_y 0
#define camera_z 1.4951001
namespace control {
Conroller* Controller::get(){
    if (theController == NULL) {
		theController = new Controller;
	}
	return theController;
}
Controller::Controller(){
    radar[0]=new sensor::Radar (left_front_azmuth, left_front_elevation, left_front_x, left_front_y, left_front_z);
	radar[1]=new sensor::Radar (left_rear_azmuth, left_rear_elevation, left_rear_x, left_rear_y, left_rear_z);
	radar[2]=new sensor::Radar (right_front_azmuth, right_front_elevation, right_front_x, right_front_y, right_front_z);
	radar[3]=new sensor::Radar (right_rear_azmuth, right_rear_elevation, right_rear_x, right_rear_y, right_rear_z);
	camera=new sensor::Camera(camera_x,camera_y,camera_z);
}

}