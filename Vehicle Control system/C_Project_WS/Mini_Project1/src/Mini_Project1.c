/*
 ============================================================================
 Name        : Mini_Project1.c
 Author      : Bilal Mohamed
 Description : Vehicle Control System Project
 Date        : 01/08/2023
 ============================================================================
 */

#include <stdio.h>

/*** Requirement 9 ***/
#define WITH_ENGINE_TEMP_CONTROLLER 1

typedef enum
{
	AC_OFF, AC_ON
}Air_Condion_State;

typedef enum
{
	CONTROLLER_OFF, CONTROLLER_ON
}Engine_Temperature_Controller_State;

typedef enum
{
	ENGINE_OFF, ENGINE_ON
}Engine_State;

Air_Condion_State Vehicle_SetupRoomTemp(int *temp_ptr)
{
	Air_Condion_State State = AC_OFF;
	if(*temp_ptr < 10)
	{
		State = AC_ON;
		*temp_ptr = 20;
	}
	else if(*temp_ptr > 30)
	{
		State = AC_ON;
		*temp_ptr = 20;
	}
	else
	{
		State = AC_OFF;
	}
	return State;
}

int Vehicle_CalculateSpeed(char Light)
{
	int Speed;

	if((Light == 'G') || (Light == 'g'))	Speed = 100;
	if((Light == 'O') || (Light == 'o'))    Speed = 30;
	if((Light == 'R') || (Light == 'r'))	Speed = 0;

	return Speed;
}

Engine_Temperature_Controller_State Vehicle_SetupEngineTempController(int *temp_ptr)
{
	Engine_Temperature_Controller_State State = CONTROLLER_OFF;
	if(*temp_ptr < 100)
	{
		State = CONTROLLER_ON;
		*temp_ptr = 125;
	}
	else if(*temp_ptr > 150)
	{
		State = CONTROLLER_ON;
		*temp_ptr = 125;
	}
	else
	{
		State = CONTROLLER_OFF;
	}
	return State;
}

int main(void)
{
	/* For printf eclipse issue */
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);

	char User_Input;
	char Sensors_States;
	char Traffic_Light;

	Engine_State Engine = ENGINE_OFF;
	Air_Condion_State AC_State = AC_OFF;
	int Vehicle_Speed = 0;
	int Temp_Room = 35;

#if (WITH_ENGINE_TEMP_CONTROLLER == 1) /*** Requirement 9 ***/
	Engine_Temperature_Controller_State Engine_Temp_Control = CONTROLLER_OFF;
	int Temp_Engine = 90;
#endif

    for(;;)
    {
		/********************************** Requirement 1 **********************************/
		printf("a. Turn on the vehicle engine\n");
		printf("b. Turn off the vehicle engine\n");
		printf("c. Quit the system\n\n");
		/***********************************************************************************/

		/* Get input from user (a,A) or (b,B) or (c,C) */
		scanf(" %c",&User_Input);

		/********************************** Requirement 2 and 4 ****************************/
		/* if the input is 'c' or 'C' the system should be terminated */
		if((User_Input == 'c') || (User_Input == 'C'))
		{
			printf("Quit The System \n\n");
			break;
		}
		/***********************************************************************************/

		/********************************** Requirement 3 and 4 ****************************/
		/* if the input is 'b' or 'B' Turn OFF Vehicle Engine */
		else if((User_Input == 'b') || (User_Input == 'B'))
		{
			Engine = ENGINE_OFF;
			printf("Turn oFF Vehicle Engine\n\n");
		}
		/***********************************************************************************/

		/********************************** Requirement 5 and 6 ****************************/
		else if((User_Input == 'a') || (User_Input == 'A'))
		{
			for(;;)
			{
				Engine = ENGINE_ON; /* Turn ON Vehicle Engine */

				printf("a. Turn off the engine\n");
				printf("b. Set the traffic light color\n");
				printf("c. Set the room temperature(Temperature Sensor)\n");

#if (WITH_ENGINE_TEMP_CONTROLLER == 1) /*** Requirement 9 ***/
				printf("d. Set the engine temperature\n\n");
#endif
				/***********************************************************************************/
				scanf(" %c",&Sensors_States);

				/********************************** Requirement 8 **********************************/
				if((Sensors_States == 'a') || (Sensors_States == 'A'))
				{
					Engine = ENGINE_OFF; /* Turn OFF Vehicle Engine */
					/* Break the inner for loop and go to Requirement 1 */
					break;
				}


				/********************************** Requirement 7-a ********************************/
				/* For Traffic_Light Light */
				if((Sensors_States=='b') || (Sensors_States=='B'))
				{
					printf("Enter the required color:\n");
					scanf(" %c",&Traffic_Light);

					Vehicle_Speed = Vehicle_CalculateSpeed(Traffic_Light);
				}
				/***********************************************************************************/

				/********************************** Requirement 7-b ********************************/
				/* For Room Temperature */
				if((Sensors_States == 'c') || (Sensors_States == 'C'))
				{
					printf("Enter the required room temp:\n");
					scanf("%d",&Temp_Room);

					/* Update AC State and Temp_Room */
					AC_State = Vehicle_SetupRoomTemp(&Temp_Room);
				}
				/************************************************************************************/

				/********************************** Requirement 7-c *********************************/
				/* For Engine Temperature */
#if (WITH_ENGINE_TEMP_CONTROLLER == 1) /*** Requirement 9 ***/
				if((Sensors_States == 'd') || (Sensors_States == 'D'))
				{
					printf("Enter the required engine temperature:\n");
					scanf("%d",&Temp_Engine);

					/* Update Engine Temp Controller State and Temp_Engine */
					Engine_Temp_Control = Vehicle_SetupEngineTempController(&Temp_Engine);
				}
#endif
				/***********************************************************************************/

				/********************************* Requirement 7-d *********************************/
				if(Vehicle_Speed == 30)
				{
					if(AC_State == AC_OFF)
					{
						AC_State = AC_ON;
					}
					Temp_Room = ((Temp_Room * 5) / 4) + 1;

#if (WITH_ENGINE_TEMP_CONTROLLER == 1) /*** Requirement 9 ***/
					if(Engine_Temp_Control == CONTROLLER_OFF)
					{
						Engine_Temp_Control = CONTROLLER_ON;
					}
					Temp_Engine = ((Temp_Engine * 5) / 4) + 1;
#endif
				}
				/***********************************************************************************/

				/*********************************** Requirement 7-e *******************************/
				if(Engine == ENGINE_OFF)
				{
					printf("Engine is OFF\n");
				}
				else
				{
					printf("Engine is ON\n");
				}
				if(AC_State == AC_OFF)
				{
					printf("AC is OFF\n");
				}
				else
				{
					printf("AC is ON\n");
				}

				printf("Vehicle Speed: %d Km/Hr\n",Vehicle_Speed);

				printf("Room Temperature: %d C\n",Temp_Room);

#if (WITH_ENGINE_TEMP_CONTROLLER == 1) /*** Requirement 9 ***/
				if(Engine_Temp_Control == CONTROLLER_OFF)
				{
					printf("Engine Temp Controller is OFF\n");
				}
				else
				{
					printf("Engine Temp Controller is ON\n");
				}
				printf("Engine Temperature: %d C\n\n",Temp_Engine);
#endif
				/************************************************************************************/

			}
		}
		else
		{
			printf("Error please enter valid input (a,A) or (b,B) or (c,C) \n\n");
		}
	} /* outer for loop */

    return 0;
}

