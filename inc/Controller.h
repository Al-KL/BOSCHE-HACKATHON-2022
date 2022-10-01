#include <vector>
namespace sensor {
	class Radar;
	class Camera;
};

namespace control {
	class Controller {
	public:
		static Controller* get();
	private:
		Controller();
		static Controller* theController;//init to null
		sensor::Camera *camera;
		sensor::Radar *radar[4];
		void normalizeRadar();

	};
	static Controller* theController = NULL;
}