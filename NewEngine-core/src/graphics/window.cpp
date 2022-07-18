#include "window.h"

namespace newengine {
	namespace graphics {
		
		void windowResize(GLFWwindow* window, int width, int height);
	
		Window::Window(const char* title, int width, int height) {
			this->title = title;
			this->width = width;
			this->height = height;

			if (!init())
				glfwTerminate();
		}

		Window::~Window() {
			glfwTerminate();
		}

		bool Window::init() {
			if (!glfwInit()) {
				std::cout << "Failed to initialize GLFW!" << std::endl;
				return false;
			}

			window = glfwCreateWindow(width, height, title, NULL, NULL);
			if (!window) {
				glfwTerminate();
;				std::cout << "Failed to create GLFW window!" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(window);
			glfwSetWindowSizeCallback(window, windowResize);

			std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK) {
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			return true;

		}

		void Window::clear() const {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		void Window::update(){
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
	
		bool Window::closed() const {
			return glfwWindowShouldClose(window);
		}

		void windowResize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	
	}
}