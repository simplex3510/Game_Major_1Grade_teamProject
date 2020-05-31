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
	screenPrint(0, 1, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
	screenPrint(0, 2,  "กแ");								  screenPrint(124, 2,  "กแ");
	screenPrint(0, 3,  "กแ");								  screenPrint(124, 3,  "กแ");
	screenPrint(0, 4,  "กแ");								  screenPrint(124, 4,  "กแ");
	screenPrint(0, 5 , "กแ");								  screenPrint(124, 5,  "กแ");
	screenPrint(0, 6 , "กแ");								  screenPrint(124, 6,  "กแ");
	screenPrint(0, 7 , "กแ");								  screenPrint(124, 7,  "กแ");
	screenPrint(0, 8 , "กแ");								  screenPrint(124, 8,  "กแ");
	screenPrint(0, 9 , "กแ");								  screenPrint(124, 9,  "กแ");
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
}

void stage2()
{
	screenPrint(0, 1, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");
	screenPrint(0, 2,  "กแ");								  screenPrint(124, 2,  "กแ");
	screenPrint(0, 3,  "กแ");								  screenPrint(124, 3,  "กแ");
	screenPrint(0, 4,  "กแ");								  screenPrint(124, 4,  "กแ");
	screenPrint(0, 5,  "กแ");								  screenPrint(124, 5,  "กแ");
	screenPrint(0, 6,  "กแ");								  screenPrint(124, 6,  "กแ");
	screenPrint(0, 7,  "กแ");								  screenPrint(124, 7,  "กแ");
	screenPrint(0, 8,  "กแ");								  screenPrint(124, 8,  "กแ");
	screenPrint(0, 9,  "กแ");								  screenPrint(124, 9,  "กแ");
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
	screenPrint(0, 30, "กแกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกใกแ");
	screenPrint(0, 30, "กแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแกแ");



}
