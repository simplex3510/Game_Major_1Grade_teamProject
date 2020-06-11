#include "maps.h"

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
	screenPrint(0, 1, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	screenPrint(0, 2, "■");								  screenPrint(124, 2, "■");
	screenPrint(0, 3, "■");								  screenPrint(124, 3, "■");
	screenPrint(0, 4, "■");								  screenPrint(124, 4, "■");
	screenPrint(0, 5, "■");								  screenPrint(124, 5, "■");
	screenPrint(0, 6, "■");								  screenPrint(124, 6, "■");
	screenPrint(0, 7, "■");								  screenPrint(124, 7, "■");
	screenPrint(0, 8, "■");								  screenPrint(124, 8, "■");
	screenPrint(0, 9, "■");								  screenPrint(124, 9, "■");
	screenPrint(0, 10, "■");								  screenPrint(124, 10, "■");
	screenPrint(0, 11, "■");								  screenPrint(124, 11, "■");
	screenPrint(0, 12, "■");								  screenPrint(124, 12, "■");
	screenPrint(0, 13, "■");								  screenPrint(124, 13, "■");
	screenPrint(0, 14, "■");								  screenPrint(124, 14, "■");
	screenPrint(0, 15, "■");								  screenPrint(124, 15, "■");
	screenPrint(0, 16, "■");								  screenPrint(124, 16, "■");
	screenPrint(0, 17, "■");								  screenPrint(124, 17, "■");
	screenPrint(0, 18, "■");								  screenPrint(124, 18, "■");
	screenPrint(0, 19, "■");								  screenPrint(124, 19, "■");
	screenPrint(0, 20, "■");								  screenPrint(124, 20, "■");
	screenPrint(0, 21, "■");								  screenPrint(124, 21, "■");
	screenPrint(0, 22, "■");								  screenPrint(124, 22, "■");
	screenPrint(0, 23, "■");								  screenPrint(124, 23, "■");
	screenPrint(0, 24, "■");								  screenPrint(124, 24, "■");
	screenPrint(0, 25, "■");								  screenPrint(124, 25, "■");
	screenPrint(0, 26, "■");								  screenPrint(124, 26, "■");
	screenPrint(0, 27, "■");								  screenPrint(124, 27, "■");
	screenPrint(0, 28, "■");								  screenPrint(124, 28, "■");
	screenPrint(0, 29, "■");								  screenPrint(124, 29, "■");
	screenPrint(0, 30, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	// TAKE ME
	screenPrint(4, 4, "■■■");	screenPrint(14, 4, "■");		screenPrint(20, 4, "■  ■");		screenPrint(28, 4, "■■■");			screenPrint(40, 4, "■  ■");		screenPrint(48, 4, "■■■");
	screenPrint(6, 5, "■");		screenPrint(12, 5, "■  ■");		screenPrint(20, 5, "■■");		screenPrint(28, 5, "■    ");		screenPrint(40, 5, "■■■");		screenPrint(48, 5, "■    ");
	screenPrint(6, 6, "■");	screenPrint(12, 6, "■■■");		screenPrint(20, 6, "■■");		screenPrint(28, 6, "■■■");			screenPrint(40, 6, "■  ■");		screenPrint(48, 6, "■■■");
	screenPrint(6, 7, "■");		screenPrint(12, 7, "■  ■");		screenPrint(20, 7, "■  ■");		screenPrint(28, 7, "■    ");		screenPrint(40, 7, "■  ■");		screenPrint(48, 7, "■    ");
	screenPrint(6, 8, "■");	screenPrint(12, 8, "■  ■");		screenPrint(20, 8, "■  ■");		screenPrint(28, 8, "■■■");			screenPrint(40, 8, "■  ■");		screenPrint(48, 8, "■■■");

	//CAMPUS
	screenPrint(60, 4, "■■■"); 		screenPrint(70, 4, "■");		screenPrint(76, 4, "■  ■");		screenPrint(84, 4, "■■■");		screenPrint(92, 4, "■  ■");		screenPrint(100, 4, "  ■■");
	screenPrint(60, 5, "■");		screenPrint(68, 5, "■  ■");		screenPrint(76, 5, "■■■");		screenPrint(84, 5, "■  ■");		screenPrint(92, 5, "■  ■");		screenPrint(100, 5, "■  ");
	screenPrint(60, 6, "■");		screenPrint(68, 6, "■■■");		screenPrint(76, 6, "■  ■");		screenPrint(84, 6, "■■■");		screenPrint(92, 6, "■  ■");		screenPrint(100, 6, "■■■");
	screenPrint(60, 7, "■");		screenPrint(68, 7, "■  ■");		screenPrint(76, 7, "■  ■");		screenPrint(84, 7, "■");		screenPrint(92, 7, "■  ■");		screenPrint(100, 7, "    ■");
	screenPrint(60, 8, "■■■");		screenPrint(68, 8, "■  ■");		screenPrint(76, 8, "■  ■");		screenPrint(84, 8, "■");		screenPrint(92, 8, "■■■"); 		screenPrint(100, 8, "■■ ");

	screenPrint(14, 10, "<Keys>");
	screenPrint(16, 13, "△");		screenPrint(14, 14, "◁  ▷");			screenPrint(16, 15, "▽");
	screenPrint(16, 12, "UP");		screenPrint(9, 14, "LEFT");				screenPrint(21, 14, "RIGHT");	screenPrint(15, 16, "DOWN");


	screenPrint(100, 25, "Go to Campus! ↘↘↘");

}

void stage2()
{
	// 맵
	screenPrint(0, 1, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	screenPrint(0, 2, "■");                          screenPrint(124, 2, "■");
	screenPrint(0, 3, "■");                                 screenPrint(124, 3, "■");
	screenPrint(0, 4, "■");                          screenPrint(124, 4, "■");
	screenPrint(0, 5, "■");                          screenPrint(124, 5, "■");
	screenPrint(0, 6, "■");   screenPrint(110, 6, "■■■■■■■");           screenPrint(124, 6, "■");
	screenPrint(0, 7, "■");                          screenPrint(124, 7, "■");
	screenPrint(0, 8, "■");                          screenPrint(124, 8, "■");
	screenPrint(0, 9, "■");   screenPrint(90, 9, "■■■■■■■■");              screenPrint(124, 9, "■");
	screenPrint(0, 10, "■");                          screenPrint(124, 10, "■");
	screenPrint(0, 11, "■");                          screenPrint(124, 11, "■");
	screenPrint(0, 12, "■");   screenPrint(70, 12, "■■■■■■■■");              screenPrint(124, 12, "■");
	screenPrint(0, 13, "■");                          screenPrint(124, 13, "■");
	screenPrint(0, 14, "■");                          screenPrint(124, 14, "■");
	screenPrint(0, 15, "■");   screenPrint(50, 15, "■■■■■■■■");                 screenPrint(124, 15, "■");
	screenPrint(0, 16, "■");                          screenPrint(124, 16, "■");
	screenPrint(0, 17, "■");                          screenPrint(124, 17, "■");
	screenPrint(0, 18, "■");   screenPrint(30, 18, "■■■■■■■■");                    screenPrint(124, 18, "■");
	screenPrint(0, 19, "■");                          screenPrint(124, 19, "■");
	screenPrint(0, 20, "■");                          screenPrint(124, 20, "■");
	screenPrint(0, 21, "■");   screenPrint(10, 21, "■■■■■■■■");                       screenPrint(124, 21, "■");
	screenPrint(0, 22, "■");                          screenPrint(124, 22, "■");
	screenPrint(0, 23, "■");                          screenPrint(124, 23, "■");
	screenPrint(0, 24, "■");   screenPrint(26, 24, "■■■■");                       screenPrint(124, 24, "■");
	screenPrint(0, 25, "■");                          screenPrint(124, 25, "■");
	screenPrint(0, 26, "■");                          screenPrint(124, 26, "■");
	screenPrint(0, 27, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");                          screenPrint(124, 27, "■");
	screenPrint(0, 28, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");                          screenPrint(124, 28, "■");
	screenPrint(0, 29, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");                          screenPrint(124, 29, "■");
	screenPrint(0, 30, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	screenPrint(106, 2, "Really? Seriously?");
	screenPrint(110, 7, "Do you wanna"); screenPrint(111, 8, "Go to Campus?");
	screenPrint(90, 10, "But, Someone Can't even go home.");
	screenPrint(70, 13, "Isn't it Cool?");
	screenPrint(50, 16, "senpai or sunbae,");
	screenPrint(30, 19, "freshman,");
	screenPrint(10, 22, "Campus life,");
	screenPrint(20, 25, "We're college"); screenPrint(26, 26, "student.");
}

void stage3(MMX* platform)
{
	// 충돌체
	platform->min.x = 90;
	platform->min.y = 0;
	platform->max.x = 91;
	platform->max.y = 0;


	screenPrint(0, 1, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	screenPrint(0, 2, "■");								  screenPrint(124, 2, "■");
	screenPrint(0, 3, "■");								  screenPrint(124, 3, "■");
	screenPrint(0, 4, "■");								  screenPrint(124, 4, "■");
	screenPrint(0, 5, "■");								  screenPrint(124, 5, "■");
	screenPrint(0, 6, "■");								  screenPrint(124, 6, "■");
	screenPrint(0, 7, "■");								  screenPrint(124, 7, "■");
	screenPrint(0, 8, "■");	screenPrint(12, 8, "■■■■■■■■■■■■■■■■■■△△■■■■■■■■■■■■■■■■■■■■■■■■■■");						  screenPrint(124, 8, "■");
	screenPrint(0, 9, "■");		screenPrint(20, 9, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");	screenPrint(104, 9, "■■■■");					  screenPrint(124, 9, "■");
	screenPrint(0, 10, "■");		screenPrint(20, 10, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");						  screenPrint(124, 10, "■");
	screenPrint(0, 11, "■");		screenPrint(20, 11, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");						  screenPrint(124, 11, "■");
	screenPrint(0, 12, "■");		screenPrint(20, 12, "■■■■");						  screenPrint(124, 12, "■");
	screenPrint(0, 13, "■");		screenPrint(20, 13, "■■■■");			screenPrint(116, 13, "■■■■");			  screenPrint(124, 13, "■");
	screenPrint(0, 14, "■");   screenPrint(2, 14, "■△△■■");		screenPrint(20, 14, "■■■■");						  screenPrint(124, 14, "■");
	screenPrint(0, 15, "■");	screenPrint(2, 15, "■■■■■");	screenPrint(20, 15, "■■■■");						  screenPrint(124, 15, "■");
	screenPrint(0, 16, "■");		screenPrint(20, 16, "■■■■");						  screenPrint(124, 16, "■");
	screenPrint(0, 17, "■");		screenPrint(20, 17, "■■■■");			screenPrint(50, 17, "■■■■■■■■△△■■■■■△△■■■■■△△■■■■■■■■■■■■■");			  screenPrint(124, 17, "■");
	screenPrint(0, 18, "■");		screenPrint(20, 18, "■■■■");			screenPrint(50, 18, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");		      screenPrint(124, 18, "■");
	screenPrint(0, 19, "■");	screenPrint(8, 19, "■■■■■■");	screenPrint(20, 19, "■■■■");			screenPrint(44, 19, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");			  screenPrint(124, 19, "■");
	screenPrint(0, 20, "■");										screenPrint(20, 20, "■■■■"); 			screenPrint(44, 20, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");			  screenPrint(124, 20, "■");
	screenPrint(0, 21, "■");		screenPrint(20, 21, "■■■■");	screenPrint(28, 21, "■■■■");					  screenPrint(124, 21, "■");
	screenPrint(0, 22, "■");		screenPrint(20, 22, "■■■■");	screenPrint(28, 22, "■■■■");					  screenPrint(124, 22, "■");
	screenPrint(0, 23, "■");		screenPrint(20, 23, "■■■■");	screenPrint(28, 23, "■■■■");					  screenPrint(124, 23, "■");
	screenPrint(0, 24, "■");		screenPrint(20, 24, "■■■■");	screenPrint(28, 24, "■■■■■■■■");					  screenPrint(124, 24, "■");
	screenPrint(0, 25, "■");	screenPrint(2, 25, "■■■△△■");	screenPrint(20, 25, "■■■■");	screenPrint(28, 25, "■■■■■■■■");					  screenPrint(124, 25, "■");
	screenPrint(0, 26, "■");	screenPrint(2, 26, "■■■■■■");	screenPrint(20, 26, "■■■■");	screenPrint(28, 26, "■■■■■■■■");					  screenPrint(124, 26, "■");
	screenPrint(0, 27, "■");		screenPrint(20, 27, "■■■■");	screenPrint(28, 27, "■■■■■■■■■■■■");		screenPrint(80, 27, "■■■■");			  screenPrint(124, 27, "■");
	screenPrint(0, 28, "■");		screenPrint(20, 28, "■■■■");	screenPrint(28, 28, "■■■■■■■■■■■■");		screenPrint(80, 28, "■■■■");			  screenPrint(124, 28, "■");
	screenPrint(0, 29, "■");		screenPrint(20, 29, "■■■■");	screenPrint(28, 29, "■■■■■■■■■■■■");		screenPrint(80, 29, "■■■■");			  screenPrint(124, 29, "■");
	screenPrint(0, 30, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■△△△■■■■■■■■■■△△■■■■■■■■■■■");


	screenPrint(101, 2, "← Campus");
	screenPrint(118, 2, "Home↓");

	screenPrint(2, 2, "You finally decided to go...");
	screenPrint(2, 3, "Anyway, You can use 7016.");
	screenPrint(9, 20, "SM Campus↘");

	screenPrint(68, 12, "Well, that's a good idea, bro.");
	screenPrint(29, 12, "If you don't go out of the house,");
	screenPrint(50, 21, "They can go home.");
	screenPrint(73, 21, "Please stay at home.");
	screenPrint(100, 21, "Let's Go Home! ↘");

}

void stageEnding(MMX* platform)
{
	// 충돌체
	platform->min.x = 90;
	platform->min.y = 0;
	platform->max.x = 91;
	platform->max.y = 0;

	screenPrint(0, 1, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");
	screenPrint(0, 2, "■");								  screenPrint(124, 2, "■");
	screenPrint(0, 3, "■");								  screenPrint(124, 3, "■");
	screenPrint(0, 4, "■");								  screenPrint(124, 4, "■");
	screenPrint(0, 5, "■");								  screenPrint(124, 5, "■");
	screenPrint(0, 6, "■");								  screenPrint(124, 6, "■");
	screenPrint(0, 7, "■");								  screenPrint(124, 7, "■");
	screenPrint(0, 8, "■");								  screenPrint(124, 8, "■");
	screenPrint(0, 9, "■");								  screenPrint(124, 9, "■");
	screenPrint(0, 10, "■");								  screenPrint(124, 10, "■");
	screenPrint(0, 11, "■");								  screenPrint(124, 11, "■");
	screenPrint(0, 12, "■");								  screenPrint(124, 12, "■");
	screenPrint(0, 13, "■");								  screenPrint(124, 13, "■");
	screenPrint(0, 14, "■");								  screenPrint(124, 14, "■");
	screenPrint(0, 15, "■");								  screenPrint(124, 15, "■");
	screenPrint(0, 16, "■");								  screenPrint(124, 16, "■");
	screenPrint(0, 17, "■");								  screenPrint(124, 17, "■");
	screenPrint(0, 18, "■");								  screenPrint(124, 18, "■");
	screenPrint(0, 19, "■");								  screenPrint(124, 19, "■");
	screenPrint(0, 20, "■");								  screenPrint(124, 20, "■");
	screenPrint(0, 21, "■");								  screenPrint(124, 21, "■");
	screenPrint(0, 22, "■");								  screenPrint(124, 22, "■");
	screenPrint(0, 23, "■");								  screenPrint(124, 23, "■");
	screenPrint(0, 24, "■");								  screenPrint(124, 24, "■");
	screenPrint(0, 25, "■");								  screenPrint(124, 25, "■");
	screenPrint(0, 26, "■");								  screenPrint(124, 26, "■");
	screenPrint(0, 27, "■");								  screenPrint(124, 27, "■");
	screenPrint(0, 28, "■");								  screenPrint(124, 28, "■");
	screenPrint(0, 29, "■");								  screenPrint(124, 29, "■");
	screenPrint(0, 30, "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■");

	screenPrint(10, 2, "I'm sorry. To show you this, I've focused your attention.");
	screenPrint(10, 3, "We can't take risks.");
	screenPrint(10, 4, "We don't go to Campus.");
	screenPrint(10, 5, "We Cam Use E-Campus");
	screenPrint(10, 6, "...Do you hear me...?");
	screenPrint(10, 7, "um....Anyway, Good End. Bye!");
}