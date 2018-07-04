#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>

namespace blackswan {
	namespace graphics {
		class Window {
		
		private :
			
			GLFWwindow * window;
			int height, width;
			const char *title;

		public :

			Window(const char *title , int height , int width);

			~Window();

			void update();

			bool isClosed();

			void clear() const;
		
		private :

			bool init();
			
		};
	}
}