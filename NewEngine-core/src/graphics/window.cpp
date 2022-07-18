#include "window.h"

namespace newengine {
	namespace graphics {
		
		bool Window::keys[GLFW_KEY_LAST];
		bool Window::buttons[GLFW_MOUSE_BUTTON_LAST];
		double Window::mouseX;
		double Window::mouseY;

		void window_resize(GLFWwindow* window, int width, int height);
	
		Window::Window(const char* title, int width, int height) {
			this->title = title;
			this->width = width;
			this->height = height;

			if (!init())
				glfwTerminate();

			for(int i = 0; i < GLFW_KEY_LAST; i++) {
				keys[i] = false;
			}
			
			for(int i = 0; i < GLFW_MOUSE_BUTTON_LAST; i++) {
				buttons[i] = false;
			}
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
			glfwSetWindowUserPointer(window, this);
			glfwSetWindowSizeCallback(window, window_resize);
			glfwSetKeyCallback(window, [](GLFWwindow* win,
				int key,
				int scanCode,
				int action,
				int mods) {
					Window* frame = (Window*)glfwGetWindowUserPointer(win);
					frame->keys[key] = action != GLFW_RELEASE;
				});

			glfwSetMouseButtonCallback(window, [](GLFWwindow* win, 
				int button, 
				int action, 
				int mods){
					Window* frame = (Window*)glfwGetWindowUserPointer(win);
					frame->buttons[button] = action != GLFW_RELEASE;
				});

			glfwSetCursorPosCallback(window, [](GLFWwindow* win, 
				double xpos, 
				double ypos)
				{
					Window* frame = (Window*)glfwGetWindowUserPointer(win);
					frame->mouseX = xpos;
					frame->mouseY = ypos;
				});

			std::cout << "OpenGL: " << glGetString(GL_VERSION) << std::endl;

			if (glewInit() != GLEW_OK) {
				std::cout << "Could not initialize GLEW!" << std::endl;
				return false;
			}

			return true;

		}

		bool Window::isKeyPresssed(unsigned int keycode) const{
			if (keycode >= GLFW_KEY_LAST)
				return false;
			return keys[keycode];
		}

		bool Window::isMouseButtonPresssed(unsigned int buttoncode) const{
			if (buttoncode >= GLFW_MOUSE_BUTTON_LAST)
				return false;
			return buttons[buttoncode];
		}

		void Window::getMousePosition(double& x, double& y) const {
			x = mouseX;
			y = mouseY;
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

		void window_resize(GLFWwindow* window, int width, int height) {
			glViewport(0, 0, width, height);
		}
	}
}