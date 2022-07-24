#include <string>
#include <cstring>
#include <iostream>
#include "../include/Game.h"

GameGEVN game;
void Command(std::string cmd) {
	int pos = 0;
	bool first = true;
    char ptr;
    char *word[100];
    int length;
	std::string command = "";
	for(int i = 0; i < cmd.length(); i++)
	{
		if(first)
		{
			if(cmd[i] == '[')
			{
				pos = i + 1;
				first = false;
			}
		} else if(!first) {
 			if(cmd[i] == ']') {
 				std::string n = cmd.substr(pos, i - pos);
				command = n;
				if(n == "background") {
					printf("Load the background\n");
                    std::string CMD (cmd);
                    CMD.erase(0,13);
                    const char* c = CMD.c_str();
                    //std::string c (CMD);
                    game.NextStatement("background", c);
                    std::cout << CMD << '\n';
				         first = true;
				} 
                else if (n == "track") {
					printf("Load the track\n");
                    std::string CMD (cmd);
                    CMD.erase(0,8);
                    const char* c = CMD.c_str();
                    game.NextStatement("track", c);
                    std::cout << CMD << '\n';
                    
				         first = true;

                }
                else if (n == "actor") {
					printf("Load the actor\n");
                    std::string CMD (cmd);
                    CMD.erase(0,8);
                    const char* c = CMD.c_str();
                    game.NextStatement("actor", c);
                    std::cout << CMD << '\n';
                    
				         first = true;

                }
                else if (n == "character") {
					      printf("Load the character name\n");
                    std::string CMD (cmd);
                    CMD.erase(0,12);
                    const char* c = CMD.c_str();
                    game.NextStatement("character", c);
                    std::cout << CMD << '\n';
                    
				         first = true;

                }
                else if (n == "text") {
					printf("Load the text\n");
                    std::string CMD (cmd);
                    CMD.erase(0,7);
                    const char* c = CMD.c_str();
                    game.NextStatement("text", c);
                    std::cout << CMD << '\n';
                    
				         first = true;

                }
                else if (n == "phone") {
					printf("Load the phone REEEE\n");
                    std::string CMD (cmd);
                    CMD.erase(0,8);
                    const char* c = CMD.c_str();
                    game.NextStatement("phone", c);
                    std::cout << CMD << '\n';
				         first = true;

                }
			} 
		}
	}
}
