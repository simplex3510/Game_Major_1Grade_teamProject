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
	screenPrint(0, 1, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
	screenPrint(0, 2, "¡á");								  screenPrint(124, 2, "¡á");
	screenPrint(0, 3, "¡á");								  screenPrint(124, 3, "¡á");
	screenPrint(0, 4, "¡á");								  screenPrint(124, 4, "¡á");
	screenPrint(0, 5, "¡á");								  screenPrint(124, 5, "¡á");
	screenPrint(0, 6, "¡á");								  screenPrint(124, 6, "¡á");
	screenPrint(0, 7, "¡á");								  screenPrint(124, 7, "¡á");
	screenPrint(0, 8, "¡á");								  screenPrint(124, 8, "¡á");
	screenPrint(0, 9, "¡á");								  screenPrint(124, 9, "¡á");
	screenPrint(0, 10, "¡á");								  screenPrint(124, 10, "¡á");
	screenPrint(0, 11, "¡á");								  screenPrint(124, 11, "¡á");
	screenPrint(0, 12, "¡á");								  screenPrint(124, 12, "¡á");
	screenPrint(0, 13, "¡á");								  screenPrint(124, 13, "¡á");
	screenPrint(0, 14, "¡á");								  screenPrint(124, 14, "¡á");
	screenPrint(0, 15, "¡á");								  screenPrint(124, 15, "¡á");
	screenPrint(0, 16, "¡á");								  screenPrint(124, 16, "¡á");
	screenPrint(0, 17, "¡á");								  screenPrint(124, 17, "¡á");
	screenPrint(0, 18, "¡á");								  screenPrint(124, 18, "¡á");
	screenPrint(0, 19, "¡á");								  screenPrint(124, 19, "¡á");
	screenPrint(0, 20, "¡á");								  screenPrint(124, 20, "¡á");
	screenPrint(0, 21, "¡á");								  screenPrint(124, 21, "¡á");
	screenPrint(0, 22, "¡á");								  screenPrint(124, 22, "¡á");
	screenPrint(0, 23, "¡á");								  screenPrint(124, 23, "¡á");
	screenPrint(0, 24, "¡á");								  screenPrint(124, 24, "¡á");
	screenPrint(0, 25, "¡á");								  screenPrint(124, 25, "¡á");
	screenPrint(0, 26, "¡á");								  screenPrint(124, 26, "¡á");
	screenPrint(0, 27, "¡á");								  screenPrint(124, 27, "¡á");
	screenPrint(0, 28, "¡á");								  screenPrint(124, 28, "¡á");
	screenPrint(0, 29, "¡á");								  screenPrint(124, 29, "¡á");
	screenPrint(0, 30, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");

	// TAKE ME
	screenPrint(4, 4, "¡á¡á¡á");	screenPrint(14, 4, "¡á");		screenPrint(20, 4, "¡á  ¡á");		screenPrint(28, 4, "¡á¡á¡á");			screenPrint(40, 4, "¡á  ¡á");		screenPrint(48, 4, "¡á¡á¡á");
	screenPrint(6, 5, "¡á");		screenPrint(12, 5, "¡á  ¡á");		screenPrint(20, 5, "¡á¡á");		screenPrint(28, 5, "¡á    ");		screenPrint(40, 5, "¡á¡á¡á");		screenPrint(48, 5, "¡á    ");
	screenPrint(6, 6, "¡á");	screenPrint(12, 6, "¡á¡á¡á");		screenPrint(20, 6, "¡á¡á");		screenPrint(28, 6, "¡á¡á¡á");			screenPrint(40, 6, "¡á  ¡á");		screenPrint(48, 6, "¡á¡á¡á");
	screenPrint(6, 7, "¡á");		screenPrint(12, 7, "¡á  ¡á");		screenPrint(20, 7, "¡á  ¡á");		screenPrint(28, 7, "¡á    ");		screenPrint(40, 7, "¡á  ¡á");		screenPrint(48, 7, "¡á    ");
	screenPrint(6, 8, "¡á");	screenPrint(12, 8, "¡á  ¡á");		screenPrint(20, 8, "¡á  ¡á");		screenPrint(28, 8, "¡á¡á¡á");			screenPrint(40, 8, "¡á  ¡á");		screenPrint(48, 8, "¡á¡á¡á");

	//CAMPUS
	screenPrint(60, 4, "¡á¡á¡á"); 		screenPrint(70, 4, "¡á");		screenPrint(76, 4, "¡á  ¡á");		screenPrint(84, 4, "¡á¡á¡á");		screenPrint(92, 4, "¡á  ¡á");		screenPrint(100, 4, "  ¡á¡á");
	screenPrint(60, 5, "¡á");		screenPrint(68, 5, "¡á  ¡á");		screenPrint(76, 5, "¡á¡á¡á");		screenPrint(84, 5, "¡á  ¡á");		screenPrint(92, 5, "¡á  ¡á");		screenPrint(100, 5, "¡á  ");
	screenPrint(60, 6, "¡á");		screenPrint(68, 6, "¡á¡á¡á");		screenPrint(76, 6, "¡á  ¡á");		screenPrint(84, 6, "¡á¡á¡á");		screenPrint(92, 6, "¡á  ¡á");		screenPrint(100, 6, "¡á¡á¡á");
	screenPrint(60, 7, "¡á");		screenPrint(68, 7, "¡á  ¡á");		screenPrint(76, 7, "¡á  ¡á");		screenPrint(84, 7, "¡á");		screenPrint(92, 7, "¡á  ¡á");		screenPrint(100, 7, "    ¡á");
	screenPrint(60, 8, "¡á¡á¡á");		screenPrint(68, 8, "¡á  ¡á");		screenPrint(76, 8, "¡á  ¡á");		screenPrint(84, 8, "¡á");		screenPrint(92, 8, "¡á¡á¡á"); 		screenPrint(100, 8, "¡á¡á ");

	screenPrint(14, 10, "<Keys>");
	screenPrint(16, 13, "¡â");		screenPrint(14, 14, "¢·  ¢¹");			screenPrint(16, 15, "¡ä");
	screenPrint(16, 12, "UP");		screenPrint(9, 14, "LEFT");				screenPrint(21, 14, "RIGHT");	screenPrint(15, 16, "DOWN");


	screenPrint(100, 25, "Go to Campus! ¢Ù¢Ù¢Ù");

}

void stage2()
{
	screenPrint(0, 1, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
	screenPrint(0, 2, "¡á");                          screenPrint(124, 2, "¡á");
	screenPrint(0, 3, "¡á");                                 screenPrint(124, 3, "¡á");
	screenPrint(0, 4, "¡á");                          screenPrint(124, 4, "¡á");
	screenPrint(0, 5, "¡á");                          screenPrint(124, 5, "¡á");
	screenPrint(0, 6, "¡á");   screenPrint(110, 6, "¡á¡á¡á¡á¡á¡á¡á");           screenPrint(124, 6, "¡á");
	screenPrint(0, 7, "¡á");                          screenPrint(124, 7, "¡á");
	screenPrint(0, 8, "¡á");                          screenPrint(124, 8, "¡á");
	screenPrint(0, 9, "¡á");   screenPrint(90, 9, "¡á¡á¡á¡á¡á¡á¡á¡á");              screenPrint(124, 9, "¡á");
	screenPrint(0, 10, "¡á");                          screenPrint(124, 10, "¡á");
	screenPrint(0, 11, "¡á");                          screenPrint(124, 11, "¡á");
	screenPrint(0, 12, "¡á");   screenPrint(70, 12, "¡á¡á¡á¡á¡á¡á¡á¡á");              screenPrint(124, 12, "¡á");
	screenPrint(0, 13, "¡á");                          screenPrint(124, 13, "¡á");
	screenPrint(0, 14, "¡á");                          screenPrint(124, 14, "¡á");
	screenPrint(0, 15, "¡á");   screenPrint(50, 15, "¡á¡á¡á¡á¡á¡á¡á¡á");                 screenPrint(124, 15, "¡á");
	screenPrint(0, 16, "¡á");                          screenPrint(124, 16, "¡á");
	screenPrint(0, 17, "¡á");                          screenPrint(124, 17, "¡á");
	screenPrint(0, 18, "¡á");   screenPrint(30, 18, "¡á¡á¡á¡á¡á¡á¡á¡á");                    screenPrint(124, 18, "¡á");
	screenPrint(0, 19, "¡á");                          screenPrint(124, 19, "¡á");
	screenPrint(0, 20, "¡á");                          screenPrint(124, 20, "¡á");
	screenPrint(0, 21, "¡á");   screenPrint(10, 21, "¡á¡á¡á¡á¡á¡á¡á¡á");                       screenPrint(124, 21, "¡á");
	screenPrint(0, 22, "¡á");                          screenPrint(124, 22, "¡á");
	screenPrint(0, 23, "¡á");                          screenPrint(124, 23, "¡á");
	screenPrint(0, 24, "¡á");   screenPrint(25, 24, "¡á¡á¡á¡á");                       screenPrint(124, 24, "¡á");
	screenPrint(0, 25, "¡á");                          screenPrint(124, 25, "¡á");
	screenPrint(0, 26, "¡á");                          screenPrint(124, 26, "¡á");
	screenPrint(0, 27, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");                          screenPrint(124, 27, "¡á");
	screenPrint(0, 28, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");                          screenPrint(124, 28, "¡á");
	screenPrint(0, 29, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");                          screenPrint(124, 29, "¡á");
	screenPrint(0, 30, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
}

void stage3()
{
	screenPrint(0, 1, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
	screenPrint(0, 2, "¡á");								  screenPrint(124, 2, "¡á");
	screenPrint(0, 3, "¡á");								  screenPrint(124, 3, "¡á");
	screenPrint(0, 4, "¡á");								  screenPrint(124, 4, "¡á");
	screenPrint(0, 5, "¡á");								  screenPrint(124, 5, "¡á");
	screenPrint(0, 6, "¡á");								  screenPrint(124, 6, "¡á");
	screenPrint(0, 7, "¡á");								  screenPrint(124, 7, "¡á");
	screenPrint(0, 8, "¡á");	screenPrint(12, 8, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡â¡â¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");						  screenPrint(124, 8, "¡á");
	screenPrint(0, 9, "¡á");		screenPrint(20, 9, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");	screenPrint(104, 9, "¡á¡á¡á¡á");					  screenPrint(124, 9, "¡á");
	screenPrint(0, 10, "¡á");		screenPrint(20, 10, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");						  screenPrint(124, 10, "¡á");
	screenPrint(0, 11, "¡á");		screenPrint(20, 11, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");						  screenPrint(124, 11, "¡á");
	screenPrint(0, 12, "¡á");		screenPrint(20, 12, "¡á¡á¡á¡á");						  screenPrint(124, 12, "¡á");
	screenPrint(0, 13, "¡á");		screenPrint(20, 13, "¡á¡á¡á¡á");			screenPrint(116, 13, "¡á¡á¡á¡á");			  screenPrint(124, 13, "¡á");
	screenPrint(0, 14, "¡á");   screenPrint(2, 14, "¡á¡â¡â¡á¡á");		screenPrint(20, 14, "¡á¡á¡á¡á");						  screenPrint(124, 14, "¡á");
	screenPrint(0, 15, "¡á");		screenPrint(20, 15, "¡á¡á¡á¡á");						  screenPrint(124, 15, "¡á");
	screenPrint(0, 16, "¡á");		screenPrint(20, 16, "¡á¡á¡á¡á");						  screenPrint(124, 16, "¡á");
	screenPrint(0, 17, "¡á");		screenPrint(20, 17, "¡á¡á¡á¡á");			screenPrint(50, 17, "¡á¡á¡á¡á¡á¡á¡á¡á¡â¡â¡á¡á¡á¡á¡á¡â¡â¡á¡á¡á¡á¡á¡â¡â¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");			  screenPrint(124, 17, "¡á");
	screenPrint(0, 18, "¡á");		screenPrint(20, 18, "¡á¡á¡á¡á");			screenPrint(50, 18, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");		      screenPrint(124, 18, "¡á");
	screenPrint(0, 19, "¡á");	screenPrint(8, 19, "¡á¡á¡á¡á¡á¡á");	screenPrint(20, 19, "¡á¡á¡á¡á");			screenPrint(44, 19, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");			  screenPrint(124, 19, "¡á");
	screenPrint(0, 20, "¡á");		screenPrint(20, 20, "¡á¡á¡á¡á"); 			screenPrint(44, 20, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");			  screenPrint(124, 20, "¡á");
	screenPrint(0, 21, "¡á");		screenPrint(20, 21, "¡á¡á¡á¡á");	screenPrint(28, 21, "¡á¡á¡á¡á");					  screenPrint(124, 21, "¡á");
	screenPrint(0, 22, "¡á");		screenPrint(20, 22, "¡á¡á¡á¡á");	screenPrint(28, 22, "¡á¡á¡á¡á");					  screenPrint(124, 22, "¡á");
	screenPrint(0, 23, "¡á");		screenPrint(20, 23, "¡á¡á¡á¡á");	screenPrint(28, 23, "¡á¡á¡á¡á");					  screenPrint(124, 23, "¡á");
	screenPrint(0, 24, "¡á");		screenPrint(20, 24, "¡á¡á¡á¡á");	screenPrint(28, 24, "¡á¡á¡á¡á¡á¡á¡á¡á");					  screenPrint(124, 24, "¡á");
	screenPrint(0, 25, "¡á");	screenPrint(2, 25, "¡á¡á¡á¡á¡â¡â");	screenPrint(20, 25, "¡á¡á¡á¡á");	screenPrint(28, 25, "¡á¡á¡á¡á¡á¡á¡á¡á");					  screenPrint(124, 25, "¡á");
	screenPrint(0, 26, "¡á");		screenPrint(20, 26, "¡á¡á¡á¡á");	screenPrint(28, 26, "¡á¡á¡á¡á¡á¡á¡á¡á");					  screenPrint(124, 26, "¡á");
	screenPrint(0, 27, "¡á");		screenPrint(20, 27, "¡á¡á¡á¡á");	screenPrint(28, 27, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");		screenPrint(80, 27, "¡á¡á¡á¡á");			  screenPrint(124, 27, "¡á");
	screenPrint(0, 28, "¡á");		screenPrint(20, 28, "¡á¡á¡á¡á");	screenPrint(28, 28, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");		screenPrint(80, 28, "¡á¡á¡á¡á");			  screenPrint(124, 28, "¡á");
	screenPrint(0, 29, "¡á");		screenPrint(20, 29, "¡á¡á¡á¡á");	screenPrint(28, 29, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");		screenPrint(80, 29, "¡á¡á¡á¡á");			  screenPrint(124, 29, "¡á");
	screenPrint(0, 30, "¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡â¡â¡â¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á¡á");
}
