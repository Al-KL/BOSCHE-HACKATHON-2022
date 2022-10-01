#include "Data.h"
#include <vector>
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
namespace control{
    class Controller;
};    
namespace sensor{
    class Radar{
        friend class control::Controller;
        public:
            Radar(double azAng,double elAng, double x,double y, double  z);
            void setData(std::vector<Data::sensorData>& data);
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
            void setData(std::vector<Data::cameraData>& data);
        private:
            double xp;
            double yp;
            double zp;
            std::vector<Data::cameraData> data;  
    };    
};