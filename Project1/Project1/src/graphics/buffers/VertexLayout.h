#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "Buffer.h"

namespace blackswan {
	namespace graphics {

		struct VertexLayoutElements
		{
			GLenum type;
			GLint count;
			GLboolean normalized;
		};

		class VertexLayout
		{
		private :
			 
			std::vector<VertexLayoutElements> Elements;
			GLuint Stride;
	
		public:

			VertexLayout() :Stride(0)
			{
			}

			template<typename T>
			void Push(GLint count)
			{
				static_assert(false);
			}

			template <>
			void Push<GLfloat>(GLint count)
			{
				Elements.push_back({GL_FLOAT , count  , GL_FALSE});
				Stride += count * sizeof(GLfloat);
			}

			template <>
			void Push<GLuint>(GLint count)
			{
				Elements.push_back({ GL_UNSIGNED_INT , count  , GL_FALSE });
				Stride += count * sizeof(GLuint);
			}

			template <>
			void Push<GLubyte>(GLint count)
			{
				Elements.push_back({ GL_UNSIGNED_BYTE , count  , GL_TRUE });
				Stride += count * sizeof(GLubyte);
			}

			inline const std::vector<VertexLayoutElements> GetElements() const { return Elements; }

			inline GLuint GetStride() const { return Stride; }

		};
	}
}