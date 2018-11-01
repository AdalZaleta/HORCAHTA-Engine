#include "hoText.h"

void hoText::TEMP_CreateBitmapFont(const char *_fontName, int _fontSize) {
	// 14pt Courier Font
	/*
	
	HFONT CreateFont(
		int nHeight,					// logical height of font
		int nWidth,						// logical average charcter width
		int nEscapement,				// angle of escapement
		int nOrientation,				// base-line orientation angle
		int fnWeigth,					// font weight
		DWORD fdwItalic,				// italic attribute flag
		DWORD fdwUnderline,				// underline attribute flag
		DWORD fdwStrikeOut,				// strikeout attribute flag
		DWORD fdwCharSet,				// character set identifier
		DWORD fdwOutputPrecision,		// output precision
		DWORD fdwClipPrecision,			// clipping precision
		DWORD fdwQuality,				// output quality
		DWORD fdwPitchAndFamily,		// pitch and family
		LPCTSTR lpszFace				// pointer to typeface name string
	);

	// Create 14pt Courier Font
	hFont = CreateFont(14, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, "Courier");

	HDC g_HDC;

	// Select a device context for the font
	SelectObject(g_HDC, hFont);

	// Prepare the bitmap font
	wglUseFontBitmaps(g_HDC, 32, 96, base);

	*/

	// Windows Font
	HFONT hFont;

	// Create Base
	unsigned int _base = glGenLists(96);

	if (_stricmp(_fontName, "symbol") == 0) {
		hFont = CreateFont(_fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, SYMBOL_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, _fontName);
	}
	else {
		hFont = CreateFont(_fontSize, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, ANSI_CHARSET, OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, ANTIALIASED_QUALITY, FF_DONTCARE | DEFAULT_PITCH, _fontName);
	}

	if (!hFont)
		return;

	SelectObject(hDC, hFont);
	wglUseFontBitmaps(hDC, 32, 96, _base);

	base = _base;
}

void hoText::TEMP_DrawText(const char *_str) {
	if ((base == 0) || (!_str))
		return;
	
	glPushAttrib(GL_LIST_BIT);
		glListBase(base - 32);
		glCallLists((int)strlen(_str), GL_UNSIGNED_BYTE, _str);
	glPopAttrib();
}

void hoText::TEMP_ReleaseFont() {
	if (base != 0)
		glDeleteLists(base, 96);
}