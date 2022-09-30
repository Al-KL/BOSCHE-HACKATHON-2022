namespace Data{
struct hostData{
    double vxfRef;
    double axvRef;
    double vxyRef;
    double psiDtOpt;
};
struct sensorData{
    double dx;
    double dy;
    double vx;
    double vy;
    double ax;
    double az;

};
enum objectType{
    noDetection=0U,
    truck=1U,
    car =2U,
    motorbike=3U, 
    bicycle =4U, 
    pedestrian =5U,
    carOrTruck=6U
};
struct cameraData{
    double dx;
    double dy;
    double vx;
    double vy;
    double ax;
    double az;
    objectType type;
};

struct MeasuredData{
    hostData hostInfo;
    sensorData sensInfo[4][15];
    cameraData camInfo;
};
}