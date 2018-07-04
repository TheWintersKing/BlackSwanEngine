#include "src/graphics/window.h"
#include "src/graphics/shaders.h" 
#include "src/graphics/buffers/Buffer.h"
#include "src/graphics/buffers/Indexbuffer.h"
#include "src/graphics/buffers/VertexArray.h"


int main(void)
{
	using namespace blackswan;
	using namespace graphics;

	GLfloat vertices[] = {
		0.5f , 0.5f , 0.0f , 
		0.5f , -0.5f , 0.0f , 
		-0.5f , -0.5f , 0.0f ,
		-0.5f , 0.5f , 0.0f
	};

	GLuint indices[] = 
	{
		0 , 1 , 2 ,
		2 , 3 , 0
	};

	Window window( "Test" , 600 , 800 );

	Shader shade("res/shaders/basic.vert", "res/shaders/basic.frag");

	VertexArray vao;
	Buffer vbo(vertices , 4 * 3 * sizeof(GLfloat));
	VertexLayout layout;
	layout.Push<GLfloat>(3);
	vao.addBuffers(vbo, layout);
	
	IndexBuffer ibo(indices , 6);

	vbo.unbind();
	ibo.unbind();
	glBindVertexArray(0);
	glClearColor(0.0f , 0.0f , 0.0f , 1.0f );
	
	

	while (!window.isClosed())
	{
		window.clear();
		shade.enable();
		vao.bind();
		ibo.bind();
		glDrawElements(GL_TRIANGLES , 6 , GL_UNSIGNED_INT , NULL);
		window.update();
	}
	shade.disable();
}

