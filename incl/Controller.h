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
		void initialise(sensor::Camera* camera, sensor::Radar* radar[4]);

	private:
		static Controller* theController;//init to null
		sensor::Camera *camera;
		sensor::Radar *radar[4];


	};
	static Controller* theController = NULL;

}