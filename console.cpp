//#######################################################
//#
//#		Console-style CLASS
//#		by BloodRaptor
//#
//#		"console.h" dependency
//#
//#######################################################

#include "console.h"

void console(int y, int color, string write)
{
	char con[500];
	strcpy(con, write.c_str());
	//Initialize the coordinates
	COORD coord = { 0, y };
	//Set the position
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	//change Color
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
	//write
	cout << con << endl;
	coord.Y = coord.Y + 1;
	//set cursor to next line
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void clearConsole(int line)
{
	if (line == 100)
	{
		for (int i = 0; i <= 10; i++)
		{
			console(i, 0, "                                                                                                         ");
		}
	}
	else
	{
		console(line, 0, "                                                                                                         ");
	}
}