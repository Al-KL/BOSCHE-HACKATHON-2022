#include <vector>
namespace sensor {
	class Radar;
	class Camera;
};

namespace control {
	class Controller {
	public:
		static Controller* get() {
			if (theController == NULL) {
				theController = new Controller;
			}
			return theController;
		}
		void initialise(sensor::Camera* camera, sensor::Radar* radar[4]) {
			radar[0]=new sensor::Radar (left_front_azmuth, left_front_elevation, left_front_x, left_front_y, left_front_z);
			radar[1]=new sensor::Radar (left_rear_azmuth, left_rear_elevation, left_rear_x, left_rear_y, left_rear_z);
			radar[2]=new sensor::Radar (right_front_azmuth, right_front_elevation, right_front_x, right_front_y, right_front_z);
			radar[3]=new sensor::Radar (right_rear_azmuth, right_rear_elevation, right_rear_x, right_rear_y, right_rear_z);
		}

	private:
		static Controller* theController;//init to null
		sensor::Camera *camera;
		sensor::Radar *radar[4];
		bool intialised;

		void normalizeRadar();

	};
	static Controller* theController = NULL;

}