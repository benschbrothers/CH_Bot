//#######################################################
//#
//#		Mouse-Click HEADER
//#		by TaskManager
//#
//#		"maus.cpp" dependency
//#
//#######################################################

//---------- API-Includes ---------
#include <windows.h>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//---------- Klassen ----------
void maus(int iXPos, int iYPos);
void mausWheel(int scroll);
void giveMouseHWND(HWND buffer);