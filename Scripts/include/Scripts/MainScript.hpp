#pragma once

#include <Engine/Engine.hpp>

namespace scripts {
	class MainScript {
	public:
		int WIDTH_WINDOW = 800;
		int HEIGHT_WINDOW = 600;
		std::string TITLE_WINDOW = "GameEngine";

		void Start();
		void Update();
	};
}