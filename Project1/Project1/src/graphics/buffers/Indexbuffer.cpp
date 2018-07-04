#include "Indexbuffer.h"

namespace blackswan {
	namespace graphics {
			IndexBuffer::IndexBuffer(const GLuint *data, GLuint count)
				: count(count)
			{
				glGenBuffers(1, &buffer);
				bind();
				glBufferData(GL_ELEMENT_ARRAY_BUFFER , count * sizeof(GLuint) , data , GL_STATIC_DRAW);
			}

			void IndexBuffer::bind() const
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer);
			}

			void IndexBuffer::unbind() const
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			}

			IndexBuffer::~IndexBuffer()
			{
				glDeleteBuffers(1 , &buffer);
			}
	}
}