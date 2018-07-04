#include "shaders.h"

namespace blackswan {
	namespace graphics {

		Shader::Shader(const std::string& vertpath, const std::string& fragpath)
		{
			ProgramID = glCreateProgram();

			const std::string vertexShader = PraserShader(vertpath);
			const std::string fragShader = PraserShader(fragpath);

			GLuint vs = CompileShader(GL_VERTEX_SHADER , vertexShader);
			GLuint fs = CompileShader(GL_FRAGMENT_SHADER, fragShader);

			glAttachShader(ProgramID, vs);
			glAttachShader(ProgramID, fs);
			glLinkProgram(ProgramID);
			glValidateProgram(ProgramID);

			int success;
			char infoLog[512];

			glGetProgramiv(ProgramID, GL_LINK_STATUS, &success);
			if (!success) {
				glGetProgramInfoLog(ProgramID, 512, NULL, infoLog);
				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
			}

			glDeleteShader(vs);
			glDeleteShader(fs);
			
		}

		GLuint Shader::CompileShader(GLenum type, const std::string& source)
		{
			int result;

			GLuint id = glCreateShader(type);

			const char *src = source.c_str();

			glShaderSource(id , 1 ,&src , NULL);
			glCompileShader(id);

			glGetShaderiv(id , GL_COMPILE_STATUS ,&result);

			if (!result)
			{
				int lenght;

				glGetShaderiv(id, GL_INFO_LOG_LENGTH, &lenght);

				char* message = (char*)alloca(lenght * sizeof(char));

				glGetShaderInfoLog(id, lenght, &lenght, message);

				std::cout << "Failed to complie" <<
					(type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGEMENT")
					<< "shader" << std::endl;

				std::cout << message << std::endl;

				glDeleteShader(id);

				return 0;
			}

			return id;

		}

		std::string Shader::PraserShader(const std::string& filepath)
		{
			std::ifstream inFile(filepath);

			std::string lines;

			std::string content;

			while (std::getline(inFile, lines))
			{
				content.append(lines + "\n");
			}

			return content;
		}

		void Shader::enable() const
		{
			glUseProgram(ProgramID);
		}
	
		void Shader::disable() const
		{
			glUseProgram(0);
		}

		Shader::~Shader()
		{
			glDeleteProgram(ProgramID);
		}
	}
}