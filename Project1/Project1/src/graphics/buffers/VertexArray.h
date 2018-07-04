#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Buffer.h"
#include "VertexLayout.h"

namespace blackswan {
	namespace graphics {

		class VertexArray
		{
		private :

			GLuint buffer;
			
		public :

			VertexArray();
			~VertexArray();

			void addBuffers(const Buffer& vb ,  const VertexLayout& layout);

			void bind() const;
			void unbind() const;

		};
	}
}