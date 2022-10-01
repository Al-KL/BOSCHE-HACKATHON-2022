#include "Data.h"
#include <vector>
namespace control{
    class Controller;
};    
namespace sensor{
    class Radar{
        friend class control::Controller;
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
            friend class control::Controller;
            Camera( double x, double y, double z);
        private:
            double xp;
            double yp;
            double zp;
            std::vector<Data::cameraData> data;  
    };    
}