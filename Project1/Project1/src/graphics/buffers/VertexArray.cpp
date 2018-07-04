#include "VertexArray.h"

namespace blackswan {
	namespace graphics {

		VertexArray::VertexArray()
		{
			glGenVertexArrays(1, &buffer);
		}

		VertexArray::~VertexArray()
		{
			glDeleteVertexArrays(1, &buffer);
		}

		void VertexArray::addBuffers(const Buffer& vb, const VertexLayout& layout)
		{
			bind();
			vb.bind();
			const auto& elements = layout.GetElements();
			unsigned int offset = 0;
			
			for (unsigned int i = 0; i < elements.size(); i++)
			
			{
				glVertexAttribPointer(i, elements[i].count, elements[i].type, elements[i].normalized, layout.GetStride(), (const void*)offset);
				glEnableVertexAttribArray(i);
				offset += elements[i].count;
			}
			unbind();

		}

		void VertexArray::bind() const
		{
			glBindVertexArray(buffer);
		}


		void VertexArray::unbind() const
		{
			glBindVertexArray(0);
		}
	}
}