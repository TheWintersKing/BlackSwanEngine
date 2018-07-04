#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>

namespace blackswan {
	namespace graphics {

		class Shader {
		
		private :

			GLuint ProgramID;

		public :

			Shader(const std::string& vertpath, const std ::string& fragpath);
			~Shader();

			void enable() const;
			void disable() const;

		private :

			static GLuint CompileShader(GLenum type, const std::string& source);
			static std::string PraserShader(const std::string& filepath);

		};
	}
}