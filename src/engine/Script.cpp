
#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <codecvt>
#include "../include/Script.h"

#ifdef _WIN32
#include "Include/SDL.h"
#include "Include/SDL_image.h"
#include "Include/SDL_test_log.h"
#include "Include/SDL_ttf.h"
#elif __linux__
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#endif

unsigned int lastTime = 0, GEclock;

bool ElieGEVNScript::open(std::string filename) {
	m_file.open(filename);
	return m_file.good();
}

std::vector<Statement> ElieGEVNScript::parse()
{
	m_file.imbue(std::locale(std::locale(), new std::codecvt_utf8<wchar_t, 0x10ffffUL, std::codecvt_mode::consume_header>));

	std::vector<Statement> v;

	std::wstring stStr;
    GEclock = SDL_GetTicks();
	int line = 0;

	//Read file line by line
	while (std::getline(m_file, stStr))
	{
		std::wstring type;
		Statement s;
		line++;

		for (int i=0;i<stStr.size();i++) {
			if (stStr[i] == L' ') {
				type = stStr.substr(0, i);

				if (type == L"txt") {
					s.wtext = stStr.substr(i+1);
				} else {
					char mbstr[255];
					std::wcstombs(mbstr, stStr.substr(i+1).c_str(), 255);
					std::string cstr(mbstr);
					s.content = cstr;
				}
				break;
			}
		}
		

		//Determine statement type
		//Sorry, for this IF tree
		if (type == L"track") {
			s.type = StatementType::TRACK;
		} else if (type == L"background") {
			s.type = StatementType::BACKGROUND;
		} else if (type == L"delay") {
			s.type = StatementType::DELAY;
		} else if (type == L"text") {
			s.type = StatementType::TEXT;
		} else if (type == L"actor") {
			s.type = StatementType::ACTOR;
		} else if (type == L"character") {
			s.type = StatementType::CHARACTER;
		} else if (type == L"font") {
			s.type = StatementType::FONT;
		} else if (type == L"text_color") {
			s.type = StatementType::TEXT_COLOR;
		} else if (type == L"fade") {
			s.type = StatementType::FADE;
		} else {
			continue;
		}

		v.push_back(s);
	}

	return v;
}
