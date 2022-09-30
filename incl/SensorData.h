namespace Data{
struct hostData{
    int vxfRef;
    int axvRef;
    int vxyRef;
    int psiDtOpt;
};
struct sensorData{
    int dx;
    int dy;
    int vx;
    int vy;
    int ax;
    int az;

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
    int dx;
    int dy;
    int vx;
    int vy;
    int ax;
    int az;
    objectType type;
};

struct MeasuredData{
    hostData hostInfo;
    sensorData sensInfo[4][15];
    cameraData camInfo;
};
}