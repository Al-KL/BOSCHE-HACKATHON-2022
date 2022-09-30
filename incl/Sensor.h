#include "Data.h"    
namespace signal{
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
    };



}