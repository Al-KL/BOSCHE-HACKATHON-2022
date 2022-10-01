#include "../inc/Sensor.h"
namespace sensor{
Radar::Radar(double azAng,double elAng, double x,double y, double  z){
    az_angle=azAng;
    el_angle=elAng;
    xp=x;
    yp=y;
    zp=z;
}
void Radar::setData(std::vector<Data::sensorData>& data){
    this->data=data;
}
void Camera::setData(std::vector<Data::cameraData>& data){
    this->data=data;
}
};