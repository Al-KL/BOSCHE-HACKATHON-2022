#include "Data.h"    
namespace sensor{
    class Radar{
        public:
            Radar(double azAng,double elAng, double x,
            double y, double  z);
        private:
            double az_angle;
            double el_angle;
            double xp;
            double yp;
            double zp;
            Data::sensorData data;

    };
    class Camera{
        public:
            Camera( double x, double y, double z);
        private:
            double xp;
            double yp;
            double zp;
            Data::cameraData data;  
    };    
}