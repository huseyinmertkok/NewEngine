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

			static bool keys[GLFW_KEY_LAST];
			static bool buttons[GLFW_MOUSE_BUTTON_LAST];
			static double mouseX, mouseY;

		public:
			Window(const char* name, int width, int height);
			~Window();
			void clear() const;
			void update();
			bool closed() const;

			inline int getWidth() const { return width; }
			inline int getHeight() const { return height; }

			bool isKeyPresssed(unsigned int keycode) const;
			bool isMouseButtonPresssed(unsigned int buttoncode) const;
			void getMousePosition(double& x, double& y) const;

		private:
			bool init();
		};

}
}