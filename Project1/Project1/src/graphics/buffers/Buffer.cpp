#include "Buffer.h"

namespace blackswan {
	namespace graphics {

			Buffer::Buffer(const void* data, GLuint count)
			{
				glGenBuffers(1, &buffer);
				bind();
				glBufferData(GL_ARRAY_BUFFER , count , data , GL_STATIC_DRAW);
			}

			void Buffer::bind() const
			{
				glBindBuffer(GL_ARRAY_BUFFER, buffer);
			}

			void Buffer::unbind() const
			{
				glBindBuffer(GL_ARRAY_BUFFER, 0);
			}

			Buffer::~Buffer()
			{
				glDeleteBuffers(1 , &buffer);
			}
	}
}