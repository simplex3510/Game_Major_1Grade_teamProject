#include <stdio.h>
#include "screen.h"
#include "maps.h"

#pragma warning (disable:4996)

#define MAP_WIDTH 123
#define MAP_HEIGHT 33


// space_bar: 32
// up:		224, 72
// down:	224, 80
// left:	224, 75
// right:	224, 77

void stage1()
{
	screenPrint(0, 1, "бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");
	screenPrint(0, 2,  "бс");								  screenPrint(124, 2,  "бс");
	screenPrint(0, 3,  "бс");								  screenPrint(124, 3,  "бс");
	screenPrint(0, 4,  "бс");								  screenPrint(124, 4,  "бс");
	screenPrint(0, 5 , "бс");								  screenPrint(124, 5,  "бс");
	screenPrint(0, 6 , "бс");								  screenPrint(124, 6,  "бс");
	screenPrint(0, 7 , "бс");								  screenPrint(124, 7,  "бс");
	screenPrint(0, 8 , "бс");								  screenPrint(124, 8,  "бс");
	screenPrint(0, 9 , "бс");								  screenPrint(124, 9,  "бс");
	screenPrint(0, 10, "бс");								  screenPrint(124, 10, "бс");
	screenPrint(0, 11, "бс");								  screenPrint(124, 11, "бс");
	screenPrint(0, 12, "бс");								  screenPrint(124, 12, "бс");
	screenPrint(0, 13, "бс");								  screenPrint(124, 13, "бс");
	screenPrint(0, 14, "бс");								  screenPrint(124, 14, "бс");
	screenPrint(0, 15, "бс");								  screenPrint(124, 15, "бс");
	screenPrint(0, 16, "бс");								  screenPrint(124, 16, "бс");
	screenPrint(0, 17, "бс");								  screenPrint(124, 17, "бс");
	screenPrint(0, 18, "бс");								  screenPrint(124, 18, "бс");
	screenPrint(0, 19, "бс");								  screenPrint(124, 19, "бс");
	screenPrint(0, 20, "бс");								  screenPrint(124, 20, "бс");
	screenPrint(0, 21, "бс");								  screenPrint(124, 21, "бс");
	screenPrint(0, 22, "бс");								  screenPrint(124, 22, "бс");
	screenPrint(0, 23, "бс");								  screenPrint(124, 23, "бс");
	screenPrint(0, 24, "бс");								  screenPrint(124, 24, "бс");
	screenPrint(0, 25, "бс");								  screenPrint(124, 25, "бс");
	screenPrint(0, 26, "бс");								  screenPrint(124, 26, "бс");
	screenPrint(0, 27, "бс");								  screenPrint(124, 27, "бс");
	screenPrint(0, 28, "бс");								  screenPrint(124, 28, "бс");
	screenPrint(0, 29, "бс");								  screenPrint(124, 29, "бс");
	screenPrint(0, 30, "бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");
}

void stage2()
{
	screenPrint(0, 1, "бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");
	screenPrint(0, 2,  "бс");								  screenPrint(124, 2,  "бс");
	screenPrint(0, 3,  "бс");								  screenPrint(124, 3,  "бс");
	screenPrint(0, 4,  "бс");								  screenPrint(124, 4,  "бс");
	screenPrint(0, 5,  "бс");								  screenPrint(124, 5,  "бс");
	screenPrint(0, 6,  "бс");								  screenPrint(124, 6,  "бс");
	screenPrint(0, 7,  "бс");								  screenPrint(124, 7,  "бс");
	screenPrint(0, 8,  "бс");								  screenPrint(124, 8,  "бс");
	screenPrint(0, 9,  "бс");								  screenPrint(124, 9,  "бс");
	screenPrint(0, 10, "бс");								  screenPrint(124, 10, "бс");
	screenPrint(0, 11, "бс");								  screenPrint(124, 11, "бс");
	screenPrint(0, 12, "бс");								  screenPrint(124, 12, "бс");
	screenPrint(0, 13, "бс");								  screenPrint(124, 13, "бс");
	screenPrint(0, 14, "бс");								  screenPrint(124, 14, "бс");
	screenPrint(0, 15, "бс");								  screenPrint(124, 15, "бс");
	screenPrint(0, 16, "бс");								  screenPrint(124, 16, "бс");
	screenPrint(0, 17, "бс");								  screenPrint(124, 17, "бс");
	screenPrint(0, 18, "бс");								  screenPrint(124, 18, "бс");
	screenPrint(0, 19, "бс");								  screenPrint(124, 19, "бс");
	screenPrint(0, 20, "бс");								  screenPrint(124, 20, "бс");
	screenPrint(0, 21, "бс");								  screenPrint(124, 21, "бс");
	screenPrint(0, 22, "бс");								  screenPrint(124, 22, "бс");
	screenPrint(0, 23, "бс");								  screenPrint(124, 23, "бс");
	screenPrint(0, 24, "бс");								  screenPrint(124, 24, "бс");
	screenPrint(0, 25, "бс");								  screenPrint(124, 25, "бс");
	screenPrint(0, 26, "бс");								  screenPrint(124, 26, "бс");
	screenPrint(0, 27, "бс");								  screenPrint(124, 27, "бс");
	screenPrint(0, 28, "бс");								  screenPrint(124, 28, "бс");
	screenPrint(0, 30, "бсбубубубубубубубубубубубубубубубубубубубубубубубубубубубубубубубубубубс");
	screenPrint(0, 30, "бсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбсбс");



}
