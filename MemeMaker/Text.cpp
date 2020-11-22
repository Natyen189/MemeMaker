#include "Text.h"

void Text::makeRasterFont()
{
	GLuint i, j;
	fontOffset = glGenLists(128);
	for (i = 0, j = 'A'; i < 26; i++, j++) {
		glNewList(fontOffset + j, GL_COMPILE);
			glBitmap(8, 13, 0.0, 0.0, 12.0, 0.0, letters[i]);
		glEndList();
	}
}

void Text::printString(char* s)
{
	glPushAttrib(GL_LIST_BIT);
	glListBase(fontOffset);
	glCallLists(strlen(s), GL_UNSIGNED_BYTE, (GLubyte*)s);
	glPopAttrib();
}

void Text::generateText(const std::string& InputString)
{	
	std::string fonstList = (InputString.compare("") == 0) ? "No input string found" : InputString;
	const char* fontChar = fonstList.c_str();
	printString((char*)fontChar);
}
