#include "window.h"

namespace blackswan {
	namespace graphics {

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height);

		Window::Window(const char *title , int height , int width) 
		{
			this->title = title;
			this->height = height;
			this->width = width;
			if (!init())
				glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to init to glfw" << std::endl;
			}

			glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR , 3);
			glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
			glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

			window = glfwCreateWindow(width , height , title , NULL , NULL);
			
			if (window == NULL)
			{
				std::cout << "Failed to create Window" << std::endl;
				return false;
			}

			glfwMakeContextCurrent(window);
			glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
			
			if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
			{
				std::cout << "Failed to intialize GLAD" << std::endl;
				return false;
			}

			return true;
		}

		void Window::update()
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		void Window::clear() const
		{
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		}

		bool Window::isClosed()
		{
			return glfwWindowShouldClose(window);
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
		{
			glViewport(0, 0, width, height);
		}
	}
}