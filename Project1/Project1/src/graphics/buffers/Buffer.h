#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace blackswan {
	namespace graphics {
		class Buffer {
		
		private :

			GLuint buffer;

		public:

			Buffer(const void* data, GLuint count);
			~Buffer();

			void bind() const;
			void unbind() const;
		};
	}
}