#pragma once
#include"PublicLibrary.h"
#include"Director.h"
class MenuHouse
{
public:
	void FirstScreen();
	void MenuSignin(Director& dr);
	void MenuRegister();
};

void DrawFrame(short x, short y);
string inputPassWord();
bool Register(string username, string password);
void gotoxy(short x, short y);
void HouseIntro();