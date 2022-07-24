

#include <vector>
#include "Script.h"

class ElieEngine
{
public:
	//int start();
	int EngineVN();
	int NewGame();

private:
	int fade; // if it is fade out, then fade < 0, if fade in - fade > 0

	std::size_t ip; //Like instruction pointer

	std::string resRoot;
	std::string::size_type textPos;
	std::vector<Statement> statements;
	bool hasPrintedText;
	int delay;

	bool hideText;
	bool fadeOn;

	bool debug;
};