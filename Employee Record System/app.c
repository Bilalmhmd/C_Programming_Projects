/***************************************************************************
 * Author      : Bilal Mohamed Elqaqei                                     *
 * Description : Emplyee Record System                                     *
 * File Name   : app.c                                                     *
 * Date        : 18-12-2023                                                *
 ***************************************************************************/

#include <stdio.h>
#include "Emplyee_Fun.h"
#include "std_types.h"

int main(void)
{
	setvbuf(stdout,NULL_PTR,_IONBF,0);
	setvbuf(stderr,NULL_PTR,_IONBF,0);
	/* Call The Select Mode Functions */
	SelectMode_Func();

	return 0;
}
