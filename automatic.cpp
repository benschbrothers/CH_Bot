//#######################################################
//#
//#		Automatic-CH-Bot CLASS
//#		by TaskManager - Chris
//#
//#		"automatic.h" dependency
//#
//#######################################################

#include "automatic.h"
#include "console.h"
#include "maus.h"

HWND ClickA;
HDC PixelH;


void giveAutoHWND(HWND buffer)
{
	ClickA = buffer;
	PixelH = GetDC(ClickA);
}

void automatic()
{
	clearConsole(2); clearConsole(3); clearConsole(4); clearConsole(5); clearConsole(6); clearConsole(7); clearConsole(8); clearConsole(9);
	console(2, 10, "running");
	bool done = false;

	clock_t begin = clock();

	Sleep(10);

	activate(0);
	while (!done)
	{
		clock_t current = clock();

		current = current - begin;
		current = current / CLOCKS_PER_SEC;  // rescale to seconds

		console(3, 10, "Elapsed time: " + to_string(current));

		if (GetKeyState(VK_DELETE) & 0x80)
			done = true;

		if (GetKeyState(VK_SPACE) & 0x80)
			Sleep(2000);

		maus(900, 450);

		if (current % 10 == 0)
		{
			//level Hero
			SendMessage(ClickA, WM_KEYDOWN, VK_CONTROL, 0);
			Sleep(5);
			maus(100, 555);
			Sleep(5);
			SendMessage(ClickA, WM_KEYUP, VK_CONTROL, 0);
		}

		if (current % 150 == 0)
		{
			activate(1);
		}

		if (current % 450 == 0){
			boost();
			activate(2);

		}
		if (current % 900 == 0){
			boost();
			activate(0);
			clock_t begin = clock();
		}
	}
	::ReleaseDC(ClickA, PixelH);

	//---------- Some Cords ------------
	//maus(100, 320);	//1
	//maus(100, 420);	//2
	//maus(100,540); //3
	//maus(100, 480); -frostleaf
}

void earlyGame(){
	//first 4 heros
	mausP(100, 320);		//1
	Sleep(100);
	mausP(100, 420);		//2
	Sleep(100);
	mausP(100, 540);		//3
	Sleep(100);
	mausP(100, 650);		//3

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 270);
	Sleep(100);
	mausP(100, 380);
	Sleep(100);
	mausP(100, 490);
	Sleep(100);
	mausP(100, 600);
	Sleep(100);
	mausP(100, 710);

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 430);
	Sleep(100);
	mausP(100, 550);
	Sleep(100);
	mausP(100, 660);
	Sleep(100);

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 355);		//mercedes
	Sleep(100);
	mausP(100, 470);
	Sleep(100);
	mausP(100, 580);
	Sleep(100);
	mausP(100, 690);

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 420);		//King midas
	Sleep(100);
	mausP(100, 530);
	Sleep(100);
	mausP(100, 640);

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 355);		//ma zuh
	Sleep(100);
	mausP(100, 470);
	Sleep(100);
	mausP(100, 580);
	Sleep(100);
	mausP(100, 690);

	Sleep(1000);
	mausWheel(-1);
	Sleep(1000);

	mausP(100, 420);		//aphrodite
	Sleep(100);
	mausP(100, 530);
	Sleep(100);
	mausP(100, 640);
	Sleep(100);
	mausP(100, 745);		//frostleaf
	
	//mausWheel(-1);
}

void boost()
{
	//Progress mode
	COLORREF color = GetPixel(PixelH, 1162, 309);
	Sleep(10);
	int red = GetRValue(color);
	if (red >= 200)
		maus(1162, 309);
}

void activate(int mode)
{
	//Time-Table
	//Abilities 1-2-3-4-5-6-8-7		//0:00
	//Abilities 1-2					//2:30
	//Abilities 1-2					//5:00
	//Abilities 1-2-3-4				//7:30
	//Abilities 1-2					//10:00
	//Abilities 1-2					//12:30
	//Abilities 1-2-3-4-5-6-8-7		//15:00

	if (mode == 0)
	{	
		activate(1);
		activate(2);
		activate(3);
	}
	else if (mode == 1)
	{
		//ABI 1+2
		SendMessage(ClickA, WM_KEYDOWN, 0x31, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x31, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x32, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x32, 0);
	}
	else if (mode == 2)
	{
		//ABI 3+4
		SendMessage(ClickA, WM_KEYDOWN, 0x33, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x33, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x34, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x34, 0);
	}
	else if (mode == 3)
	{
		//ABI 5+8+7
		SendMessage(ClickA, WM_KEYDOWN, 0x35, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x35, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x38, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x38, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x37, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x37, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x36, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x36, 0);
		SendMessage(ClickA, WM_KEYDOWN, 0x39, 0);
		Sleep(5);
		SendMessage(ClickA, WM_KEYUP, 0x39, 0);
	}
}

void mausP(int iXPos, int iYPos)
{
	SendMessage(ClickA, WM_LBUTTONDOWN, 0, MAKELPARAM(iXPos, iYPos));
	Sleep(100);
	SendMessage(ClickA, WM_LBUTTONUP, 0, MAKELPARAM(iXPos, iYPos));
}