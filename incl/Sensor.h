#include "Data.h"
#include <vector>    
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
            std::vector<Data::sensorData> data;

    };
    class Camera{
        public:
            Camera( double x, double y, double z);
        private:
            double xp;
            double yp;
            double zp;
            std::vector<Data::cameraData> data;  
    };    
}