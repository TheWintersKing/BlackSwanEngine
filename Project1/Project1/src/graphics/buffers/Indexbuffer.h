#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace blackswan {
	namespace graphics {
		class IndexBuffer {
		
		private :

			GLuint buffer;
			GLuint count;

		public:

			IndexBuffer(const GLuint *data, GLuint count);
			~IndexBuffer();

			void bind() const;
			void unbind() const;

			inline GLuint getCount() { return count; }
		};
	}
}