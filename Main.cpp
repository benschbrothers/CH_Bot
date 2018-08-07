//#######################################
//#
//#		Clicker Heroes Bot 
//#		by TaskManager - Chris
//#
//#######################################

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

//---------- API-Includes ---------
#include <windows.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

//---------- Class-Includes -------
#include "console.h"
#include "maus.h"
#include "automatic.h"

//---------- Klassen ----------
void scroll();
void click();

//---------- Window Handles-----------
HWND Click = FindWindow(NULL, TEXT("CH"));
HWND consoleWindow = GetConsoleWindow();

//---------- Main -------------
int main()
{
	int eingabe;
	boolean done = false;

	SetWindowPos(Click, HWND_TOP, 0, 0, 1200, 800, SWP_SHOWWINDOW);
	SetWindowPos(consoleWindow, HWND_TOP, 1200, 100, 700, 500, SWP_SHOWWINDOW);

	Sleep(50);
	::SetForegroundWindow(consoleWindow);
	Sleep(50);
	::SetForegroundWindow(Click);

	giveMouseHWND(Click);
	giveAutoHWND(Click);

	while (!done) {
		clearConsole(2); clearConsole(3); clearConsole(4); clearConsole(5); clearConsole(6); clearConsole(7); clearConsole(8); clearConsole(9);
		console(0, 12, "Willkommen beim Click Bot V. 1.0");
		console(1, 12, "--------------------------------");
		console(2, 10, "Was willst du tun?");
		console(3, 10, "1. Level Hero");
		console(4, 10, "2. Click");
		console(5, 10, "3. Automatic (beta)");
		console(6, 10, "0. Beenden");
		cin >> eingabe;

		switch (eingabe)
		{
		case 0:
			done = true;
			break;
		case 1:
			earlyGame();
			break;
		case 2:
			click();
			break;
		case 3:
			automatic();
			break;
		}

	}

	return 0;
}
//-----------------------------


//------- Funktionen ----------

void scroll(){

	clearConsole(2); clearConsole(3); clearConsole(4); clearConsole(5); clearConsole(6); clearConsole(7); clearConsole(8); clearConsole(9);
	int scroll;
	console(2, 10, "wohin?");
	cin >> scroll;

	mausWheel(scroll);

}
void click()
{
	clearConsole(2); clearConsole(3); clearConsole(4); clearConsole(5); clearConsole(6); clearConsole(7); clearConsole(8); clearConsole(9);
	bool done = false;
	console(2, 10, "running");
	while (!done)
	{
		maus(900, 450);

		if (GetKeyState(VK_SPACE) & 0x80)
			Sleep(2000);

		if (GetKeyState(VK_DELETE) & 0x80)
			done = true;
	}
}

