#include "hoText2.h"

void hoText2::LoadFont(const char* path, FT_UInt w, FT_UInt h) {
	// FreeType
	FT_Library ft;

	// Todas las funciones regresan un valor diferente a 0 cuando ocurre algún error
	if (FT_Init_FreeType(&ft))
		std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

	// Cargar fuente como 'face'
	FT_Face face;
	// Cargar fuente desde la direccion de 'path' y darle un index de 0
	if (FT_New_Face(ft, path, 0, &face))
		std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

	/*	Set al tamaño de la fuente
		face | ancho | alto		
	*/
	FT_Set_Pixel_Sizes(face, w, h);
	/*	Si el ancho se deja en 0, se ajusta automaticamente dependiendo de la altura
		Lo mismo ocurre con altura en 0
	*/

	// Desactivar restriccion de byte-alignment
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	// Cargar los primeros 128 caracteres de ASCII
	for (GLubyte c = 0; c < 128; c++)
	{
		// Cargar glyph
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
			continue;
		}
		// Generar textura
		GLuint texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(
			GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

		// Set opciones de textura
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		// Guardar caracteres para uso futuro
		Character character = {
			texture,
			glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
			glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
			face->glyph->advance.x
		};
		Characters.insert(std::pair<GLchar, Character>(c, character));
	}
	glBindTexture(GL_TEXTURE_2D, 0);

	// Clearear los recursos de freetype
	FT_Done_Face(face);
	FT_Done_FreeType(ft);

	// Inicializar glew
	GLenum err = glewInit();

	// Configurar VAO/VBO para los texture quads
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

/*	Renderizar texto
	texto,
	posicion X,
	posicion Y,
	escala,
	color
*/
void hoText2::RenderText(Shader shader, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color)
{
	// Activar el render state correspondiente
	shader.Use();
	glUniform3f(glGetUniformLocation(shader.Program, "textColor"), color.x, color.y, color.z);
	glActiveTexture(GL_TEXTURE0);
	glBindVertexArray(VAO);

	// Iterar a traves de todos los caracteres
	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++)
	{
		Character ch = Characters[*c];

		GLfloat xpos = x + ch.Bearing.x * scale;
		GLfloat ypos = y - (ch.Size.y - ch.Bearing.y) * scale;

		GLfloat w = ch.Size.x * scale;
		GLfloat h = ch.Size.y * scale;
		// Actualizar VBO para cada caracter
		GLfloat vertices[6][4] = {
			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos,     ypos,       0.0, 1.0 },
			{ xpos + w, ypos,       1.0, 1.0 },

			{ xpos,     ypos + h,   0.0, 0.0 },
			{ xpos + w, ypos,       1.0, 1.0 },
			{ xpos + w, ypos + h,   1.0, 0.0 }
		};
		// Renderizar glyph sobre la textura
		glBindTexture(GL_TEXTURE_2D, ch.TextureID);
		// Actualizar contenido de la memoria VBO
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices); // Asegurarse de utilizar glBufferSubData y no glBufferData

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		// Renderizar quad
		glDrawArrays(GL_TRIANGLES, 0, 6);
		// Avanzar el cursor para el siguente glyph
		x += (ch.Advance >> 6) * scale; // Bitshift por 6 para conseguir el valor en pixeles
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);
}

