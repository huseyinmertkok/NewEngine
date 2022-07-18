#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace newengine {
	namespace graphics {

		class Window {
		private:
			const char* title;
			int width, height;
			GLFWwindow* window;
			bool isClosed;

		public:
			Window(const char* name, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }

		private:
			bool init();
		};

}
}