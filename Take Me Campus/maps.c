#include "screen.h"
#include "object.h"

#pragma warning (disable:4996)

#define MAP_WIDTH 123
#define MAP_HEIGHT 33


// space_bar: 32
// up:		224, 68
// down:	224, 80
// left:	224, 75
// right:	224, 77

void stage1()
{
	screenPrint(0, 1, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
	screenPrint(0, 2, "กแ");								  screenPrint(124, 2, "กแ");
	screenPrint(0, 3, "กแ");								  screenPrint(124, 3, "กแ");
	screenPrint(0, 4, "กแ");								  screenPrint(124, 4, "กแ");
	screenPrint(0, 5, "กแ");								  screenPrint(124, 5, "กแ");
	screenPrint(0, 6, "กแ");								  screenPrint(124, 6, "กแ");
	screenPrint(0, 7, "กแ");								  screenPrint(124, 7, "กแ");
	screenPrint(0, 8, "กแ");								  screenPrint(124, 8, "กแ");
	screenPrint(0, 9, "กแ");								  screenPrint(124, 9, "กแ");
	screenPrint(0, 10, "กแ");								  screenPrint(124, 10, "กแ");
	screenPrint(0, 11, "กแ");								  screenPrint(124, 11, "กแ");
	screenPrint(0, 12, "กแ");								  screenPrint(124, 12, "กแ");
	screenPrint(0, 13, "กแ");								  screenPrint(124, 13, "กแ");
	screenPrint(0, 14, "กแ");								  screenPrint(124, 14, "กแ");
	screenPrint(0, 15, "กแ");								  screenPrint(124, 15, "กแ");
	screenPrint(0, 16, "กแ");								  screenPrint(124, 16, "กแ");
	screenPrint(0, 17, "กแ");								  screenPrint(124, 17, "กแ");
	screenPrint(0, 18, "กแ");								  screenPrint(124, 18, "กแ");
	screenPrint(0, 19, "กแ");								  screenPrint(124, 19, "กแ");
	screenPrint(0, 20, "กแ");								  screenPrint(124, 20, "กแ");
	screenPrint(0, 21, "กแ");								  screenPrint(124, 21, "กแ");
	screenPrint(0, 22, "กแ");								  screenPrint(124, 22, "กแ");
	screenPrint(0, 23, "กแ");								  screenPrint(124, 23, "กแ");
	screenPrint(0, 24, "กแ");								  screenPrint(124, 24, "กแ");
	screenPrint(0, 25, "กแ");								  screenPrint(124, 25, "กแ");
	screenPrint(0, 26, "กแ");								  screenPrint(124, 26, "กแ");
	screenPrint(0, 27, "กแ");								  screenPrint(124, 27, "กแ");
	screenPrint(0, 28, "กแ");								  screenPrint(124, 28, "กแ");
	screenPrint(0, 29, "กแ");								  screenPrint(124, 29, "กแ");
	screenPrint(0, 30, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");

	// TAKE ME
	screenPrint(4, 4, "กแกแกแ");	screenPrint(14, 4, "กแ");		screenPrint(20, 4, "กแ  กแ");		screenPrint(28, 4, "กแกแกแ");			screenPrint(40, 4, "กแ  กแ");		screenPrint(48, 4, "กแกแกแ");
	screenPrint(6, 5, "กแ");		screenPrint(12, 5, "กแ  กแ");		screenPrint(20, 5, "กแกแ");		screenPrint(28, 5, "กแ    ");		screenPrint(40, 5, "กแกแกแ");		screenPrint(48, 5, "กแ    ");
	screenPrint(6, 6, "กแ");	screenPrint(12, 6, "กแกแกแ");		screenPrint(20, 6, "กแกแ");		screenPrint(28, 6, "กแกแกแ");			screenPrint(40, 6, "กแ  กแ");		screenPrint(48, 6, "กแกแกแ");
	screenPrint(6, 7, "กแ");		screenPrint(12, 7, "กแ  กแ");		screenPrint(20, 7, "กแ  กแ");		screenPrint(28, 7, "กแ    ");		screenPrint(40, 7, "กแ  กแ");		screenPrint(48, 7, "กแ    ");
	screenPrint(6, 8, "กแ");	screenPrint(12, 8, "กแ  กแ");		screenPrint(20, 8, "กแ  กแ");		screenPrint(28, 8, "กแกแกแ");			screenPrint(40, 8, "กแ  กแ");		screenPrint(48, 8, "กแกแกแ");

	//CAMPUS
	screenPrint(60, 4, "กแกแกแ"); 		screenPrint(70, 4, "กแ");		screenPrint(76, 4, "กแ  กแ");		screenPrint(84, 4, "กแกแกแ");		screenPrint(92, 4, "กแ  กแ");		screenPrint(100, 4, "  กแกแ");
	screenPrint(60, 5, "กแ");		screenPrint(68, 5, "กแ  กแ");		screenPrint(76, 5, "กแกแกแ");		screenPrint(84, 5, "กแ  กแ");		screenPrint(92, 5, "กแ  กแ");		screenPrint(100, 5, "กแ  ");
	screenPrint(60, 6, "กแ");		screenPrint(68, 6, "กแกแกแ");		screenPrint(76, 6, "กแ  กแ");		screenPrint(84, 6, "กแกแกแ");		screenPrint(92, 6, "กแ  กแ");		screenPrint(100, 6, "กแกแกแ");
	screenPrint(60, 7, "กแ");		screenPrint(68, 7, "กแ  กแ");		screenPrint(76, 7, "กแ  กแ");		screenPrint(84, 7, "กแ");		screenPrint(92, 7, "กแ  กแ");		screenPrint(100, 7, "    กแ");
	screenPrint(60, 8, "กแกแกแ");		screenPrint(68, 8, "กแ  กแ");		screenPrint(76, 8, "กแ  กแ");		screenPrint(84, 8, "กแ");		screenPrint(92, 8, "กแกแกแ"); 		screenPrint(100, 8, "กแกแ ");

	screenPrint(14, 10, "<Keys>");
	screenPrint(16, 13, "กโ");		screenPrint(14, 14, "ขท  ขน");			screenPrint(16, 15, "กไ");
	screenPrint(16, 12, "UP");		screenPrint(9, 14, "LEFT");				screenPrint(21, 14, "RIGHT");	screenPrint(15, 16, "DOWN");


	screenPrint(100, 25, "Go to Campus! ขูขูขู");

}
void stage2()
{
	screenPrint(0, 1, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
	screenPrint(0, 2, "กแ");								  screenPrint(124, 2, "กแ");
	screenPrint(0, 3, "กแ");								  screenPrint(124, 3, "กแ");
	screenPrint(0, 4, "กแ");								  screenPrint(124, 4, "กแ");
	screenPrint(0, 5, "กแ");								  screenPrint(124, 5, "กแ");
	screenPrint(0, 6, "กแ");								  screenPrint(124, 6, "กแ");
	screenPrint(0, 7, "กแ");								  screenPrint(124, 7, "กแ");
	screenPrint(0, 8, "กแ");								  screenPrint(124, 8, "กแ");
	screenPrint(0, 9, "กแ");								  screenPrint(124, 9, "กแ");
	screenPrint(0, 10, "กแ");								  screenPrint(124, 10, "กแ");
	screenPrint(0, 11, "กแ");								  screenPrint(124, 11, "กแ");
	screenPrint(0, 12, "กแ");								  screenPrint(124, 12, "กแ");
	screenPrint(0, 13, "กแ");								  screenPrint(124, 13, "กแ");
	screenPrint(0, 14, "กแ");								  screenPrint(124, 14, "กแ");
	screenPrint(0, 15, "กแ");								  screenPrint(124, 15, "กแ");
	screenPrint(0, 16, "กแ");								  screenPrint(124, 16, "กแ");
	screenPrint(0, 17, "กแ");								  screenPrint(124, 17, "กแ");
	screenPrint(0, 18, "กแ");								  screenPrint(124, 18, "กแ");
	screenPrint(0, 19, "กแ");								  screenPrint(124, 19, "กแ");
	screenPrint(0, 20, "กแ");								  screenPrint(124, 20, "กแ");
	screenPrint(0, 21, "กแ");								  screenPrint(124, 21, "กแ");
	screenPrint(0, 22, "กแ");								  screenPrint(124, 22, "กแ");
	screenPrint(0, 23, "กแ");								  screenPrint(124, 23, "กแ");
	screenPrint(0, 24, "กแ");								  screenPrint(124, 24, "กแ");
	screenPrint(0, 25, "กแ");								  screenPrint(124, 25, "กแ");
	screenPrint(0, 26, "กแ");								  screenPrint(124, 26, "กแ");
	screenPrint(0, 27, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");								  screenPrint(124, 27, "กแ");
	screenPrint(0, 28, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");								  screenPrint(124, 28, "กแ");
	screenPrint(0, 29, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");								  screenPrint(124, 29, "กแ");
	screenPrint(0, 30, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
}

void stage3()
{
	screenPrint(0, 1, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
	screenPrint(0, 2, "กแ");                          screenPrint(124, 2, "กแ");
	screenPrint(0, 3, "กแ");                                 screenPrint(124, 3, "กแ");
	screenPrint(0, 4, "กแ");                          screenPrint(124, 4, "กแ");
	screenPrint(0, 5, "กแ");                          screenPrint(124, 5, "กแ");
	screenPrint(0, 6, "กแ");   screenPrint(110, 6, "กแกแกแกแกแกแกแ");           screenPrint(124, 6, "กแ");
	screenPrint(0, 7, "กแ");                          screenPrint(124, 7, "กแ");
	screenPrint(0, 8, "กแ");                          screenPrint(124, 8, "กแ");
	screenPrint(0, 9, "กแ");   screenPrint(90, 9, "กแกแกแกแกแกแกแกแ");              screenPrint(124, 9, "กแ");
	screenPrint(0, 10, "กแ");                          screenPrint(124, 10, "กแ");
	screenPrint(0, 11, "กแ");                          screenPrint(124, 11, "กแ");
	screenPrint(0, 12, "กแ");   screenPrint(70, 12, "กแกแกแกแกแกแกแกแ");              screenPrint(124, 12, "กแ");
	screenPrint(0, 13, "กแ");                          screenPrint(124, 13, "กแ");
	screenPrint(0, 14, "กแ");                          screenPrint(124, 14, "กแ");
	screenPrint(0, 15, "กแ");   screenPrint(50, 15, "กแกแกแกแกแกแกแกแ");                 screenPrint(124, 15, "กแ");
	screenPrint(0, 16, "กแ");                          screenPrint(124, 16, "กแ");
	screenPrint(0, 17, "กแ");                          screenPrint(124, 17, "กแ");
	screenPrint(0, 18, "กแ");   screenPrint(30, 18, "กแกแกแกแกแกแกแกแ");                    screenPrint(124, 18, "กแ");
	screenPrint(0, 19, "กแ");                          screenPrint(124, 19, "กแ");
	screenPrint(0, 20, "กแ");                          screenPrint(124, 20, "กแ");
	screenPrint(0, 21, "กแ");   screenPrint(10, 21, "กแกแกแกแกแกแกแกแ");                       screenPrint(124, 21, "กแ");
	screenPrint(0, 22, "กแ");                          screenPrint(124, 22, "กแ");
	screenPrint(0, 23, "กแ");                          screenPrint(124, 23, "กแ");
	screenPrint(0, 24, "กแ");   screenPrint(25, 24, "กแกแกแกแ");                       screenPrint(124, 24, "กแ");
	screenPrint(0, 25, "กแ");                          screenPrint(124, 25, "กแ");
	screenPrint(0, 26, "กแ");                          screenPrint(124, 26, "กแ");
	screenPrint(0, 27, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");                          screenPrint(124, 27, "กแ");
	screenPrint(0, 28, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");                          screenPrint(124, 28, "กแ");
	screenPrint(0, 29, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");                          screenPrint(124, 29, "กแ");
	screenPrint(0, 30, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
}

