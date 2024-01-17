#include <MainScript.hpp>

namespace scripts {
	Point ver[4] = {
		{  0.5,  0.5, 0 },
		{  0.5, -0.5, 0 },
		{ -0.5, -0.5, 0 },
		{ -0.5,  0.5, 0 }
	};
	Square tr(ver);

	void MainScript::Start() {
		Window window;

		window.set_size(800, 600);
		window.set_title("shiiiiii");
		window.set_background_color(255, 255, 255);
		tr.set_color({ 255, 0, 0 });
	}

	void MainScript::Update() {
		tr.draw();
	}
}