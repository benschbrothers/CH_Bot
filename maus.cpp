//#######################################################
//#
//#		Mouse-click CLASS
//#		by TaskManager
//#
//#		"maus.h" dependency
//#
//#######################################################

#include "maus.h"

HWND ClickM;

void giveMouseHWND(HWND buffer)
{
	ClickM = buffer;
}

void maus(int iXPos, int iYPos)
{
	SendMessage(ClickM, WM_LBUTTONDOWN, 0, MAKELPARAM(iXPos, iYPos));
	Sleep(5);
	SendMessage(ClickM, WM_LBUTTONUP, 0, MAKELPARAM(iXPos, iYPos));
}

void mausWheel(int scroll)
{
	SendMessage(ClickM, WM_MOUSEWHEEL, MAKEWPARAM(0, WHEEL_DELTA * scroll), MAKELPARAM(0, 0));
	Sleep(5);
	SendMessage(ClickM, WM_MOUSEWHEEL, MAKEWPARAM(0, WHEEL_DELTA * scroll), MAKELPARAM(0, 0));
}