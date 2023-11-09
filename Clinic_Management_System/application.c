/******************************************************************************
 *
 * Module: Clinic_Management_System
 *
 * File Name: Application.c
 *
 * Description: the main function of application
 *
 * Author: Bilal Mohamed
 *
 *******************************************************************************/

#include "function_system.h"
#include <stdio.h>


int main(void)
{
	setvbuf(stdout,NULL_PTR,_IONBF,0);
	setvbuf(stderr,NULL_PTR,_IONBF,0);
	/* Call The Select Mode Functions */
	SelectMode_Func();


	return 0;
}
