#include <MainScript.hpp>

namespace scripts {
	Size s = { 1, 1 };
	Rectangle tr(s);

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