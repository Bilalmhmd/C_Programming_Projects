/***************************************************************************
 * Author      : Bilal Mohamed Elqaqei                                     *
 * Description : Emplyee Record System                                     *
 * File Name   : Emplyee_Fun.c                                             *
 * Date        : 18-12-2023                                                *
 ***************************************************************************/

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "Emplyee_Fun.h"
#include "std_types.h"



struct Emplyee_Node *head = NULL_PTR;
uint32 i ;

/*
 * Description :
 * Select Mode (main)Function
 */

void SelectMode_Func(void)
{
	uint32 Choice_Num;
	printf("\n<<<<<<<<<<<<<<<<<<   Emplyee Record System    >>>>>>>>>>>>>>>>>>\n\n");

	while(1)
	{
		system("cls");  // built function to clear screen after your choice
		printf("1-Add a new emplyee data \n");
		printf("2-Delete the data of an emplyee \n");
		printf("3-Modify the data of an emplyee \n");
		printf("4-View the data of an emplyee \n");
		printf("5-View all the emplyee's data \n");
		printf("6-Exit \n");

		/* Scanning The User Required Choice */
		printf("Please Enter The Number That Represent Your Choice From This List :");
		scanf("%d",&Choice_Num);

		switch (Choice_Num)
		{

		case 1:
			printf("------------------------------------------------------------------\n");
			/* Call Add New emplyee Informations Function To The Emplyee Record Database */
			AddEmplyee_Func();
			break;

		case 2:
			printf("------------------------------------------------------------------\n");
			/* Call Delete emplyee Informations Function In The Emplyee Record Database */
			DeleteEmplyeeData_Func();
			break;

		case 3:
			printf("------------------------------------------------------------------\n");
			/* Call Edit emplyee Informations Function In The Emplyee Record Database */
			ModifyEmplyeeData_Func();
			break;

		case 4:
			printf("------------------------------------------------------------------\n");
			/* Call View emplyee Informations Function In The Emplyee Record Database */
			ViewEmplyeeData_Func();
			break;

		case 5:
			printf("------------------------------------------------------------------\n");
			/* Call View All emplyees Informations Function In The Emplyee Record Database */
			ViewAllData_Func();
			break;
        case 6:
			printf("------------------------------------------------------------------\n");
			/* Call The Exit To Return Back To The Select Mode Page Again */
			Exit_Func();
			break;    
		default:
			printf("                     ********* Invalid Choice ********* \n");
			printf("             ********* Please Choose the right action ********* \n");
            SelectMode_Func(); // return again to the main function
			break;
		}
	}
}

void AddEmplyee_Func(void)
{
	/* Create New Node Containing The New Emplyee Informations */
	struct Emplyee_Node *link = (struct Emplyee_Node*) malloc(sizeof(struct Emplyee_Node));

	/* Scanning The Emplyee Informations From The Admin */
	printf("                ********* Please Enter The Emplyee Informations ********* \n");
	printf("\n");
	printf("Emplyee Name : ");
	fflush(stdin);
	gets(link->name);
	printf("\n");
	printf("Age : ");
	scanf("%d",&link->age);
	printf("\n");
	printf("Salary : ");
	scanf("%d",&link->salary);
	printf("\n");
	printf("Title : ");
	fflush(stdin);
	gets(link->title);
	printf("\n");
	printf("ID : ");
	scanf("%d",&link->id);
	printf("\n");

	/* Set The Intitial Value Of The Next Of The New Link Node To NULL */
	link->next = NULL_PTR;
	/* Check If There Is Already Node Exist Or Not */
	if(head == NULL_PTR)
	{
		/* As The Head Pointer Still NULL And There Is No Linked List So Create A New Node In The Linked List */
		head = link;
	}
	else
	{
		struct Emplyee_Node *Ptr1,*Ptr2;
		Ptr1 = Ptr2 = head;
		/*Check If the Input ID Is Already Exist Or Not And If it Exists Re Enter A New ID */
		while(Ptr2 != NULL_PTR)
		{
			if(link->id == Ptr2->id)
			{
				printf("\nThis ID already exists.\n"
						"Please Enter New ID : ");
				scanf("%d",&link->id);
				Ptr2 = head;
			}
			Ptr1 = Ptr2;
			Ptr2 = Ptr2->next;
		}
		Ptr1->next = link;
	}
}

void DeleteEmplyeeData_Func(void)
{
	struct Emplyee_Node* Ptr1;
	uint32 ID;
	Ptr1 = head;
	/* Check If There Is Emplyee Informations In The Database Or Not If Not Print This Message For The Admin */
	if(Ptr1 == NULL_PTR)
	{
		printf("There are no Emplyee In The Database \n");
		delay(3); //Delay for 3 second 
	}
	/* If There Is Emplyee Informations In The Database Ask The Admin To Enter The ID
	 *        Of The Emplyee That Want To Delete .                          */
	else
	{
		printf("Please Enter The Emplyee ID That you want to Delete : ");
		scanf("%d",&ID);
		/* Make A Loop Until You Find The Node That Contains The Same ID Of The Required Emplyee
		 * Then Delete
		 */
		while(Ptr1 != NULL_PTR)
		{
			if(Ptr1->id == ID)
			{
				printf("              ************** Delete Emplyee Informations Done ****************\n");
				delay(3); //Delay for 3 second 
				return;
			}
			else
			{
				/* Set The Pointer To The Following Node To Check For The ID Till You Find */
				Ptr1 = Ptr1->next;
			}
		}
		/*If The Admin Entered Wrong ID Print A Message To Re Enter The Right ID */
		printf(" Incorrect ID Please Re Enter The Right ID \n");
		DeleteEmplyeeData_Func(); // return again to the main function
	}
}

void ModifyEmplyeeData_Func(void)
{
	/* Create A Local Pointer To Move On All The Nodes And Search
	 * For The Right ID Of The Emplyee To Edit His/Her Informations
	 */
	struct Emplyee_Node *Ptr1 = head;
	uint32 ID;
	uint32 count=0;
	printf("\nPlease Enter the ID of the Emplyee that you want to change His/Her Information : ");
	fflush(stdin);
	scanf("%d",&ID);
	/* Search For The Patient ID That You Want To Edit His/Her Informations */
	while(Ptr1 != (NULL_PTR))
	{
		if(ID == Ptr1->id)
		{
			/* Once You Find The Patient ID Edit This Patient Informations By Entering His/Her Information Again */
			count=1;
			printf("\n");
			printf("Please Enter the New Emplyee Name : ");
	        fflush(stdin);
	        gets(Ptr1->name);
			printf("\n");
			printf("Please Enter the New Emplyee Age : ");
			scanf("%d",&Ptr1->age);
			printf("\n");
			printf("Please Enter the New Emplyee Salary : ");
			scanf("%d",&Ptr1->salary);
			printf("\n");
			printf("Please Enter the New Emplyee Title : ");
			fflush(stdin);
	        gets(Ptr1->name);
			printf("Please Enter the New Emplyee ID : ");
			scanf("%d",&Ptr1->id);
			printf("\n");
			break;
		}
		Ptr1 = Ptr1->next;
	}
	/* If You Didn't Find The Emplyee ID Print A message For The User To Re Enter The Right ID */
	if (count == 0)
	{
		printf("                                ********* Invalid ID ************ \n");
		printf("If you still want to edit a Emplyee info choose Edit Emplyee Informations from the list again \n");
		printf("-------------------------------------------------------------------------------------------------\n");
		ModifyEmplyeeData_Func(); //return again to the main function
	}
}

void ViewEmplyeeData_Func(void)
{
	/* Create A Pointer To Move On All The Emplyees Nodes To Print Every Emplyee Node Informations*/
	struct Emplyee_Node *Ptr1;
	uint32 ID;
	Ptr1 = head;
	if(Ptr1 == NULL_PTR)
	{
		/* Check If There Is Emplyee Informations In The Database Or Not If Not Print This Message For The User */
		printf("There are no Emplyees.\n");
	}
	else
	{
		printf("Enter Emplyee ID : ");
		scanf("%d",&ID);
		/*Make A Loop On All The Nodes And Print Every Patient Informations */
		while(Ptr1!= NULL_PTR)
		{
			if(ID == Ptr1->id)
			{
				printf("Emplyee Name : %s",Ptr1->name);
				printf("\n");
				printf("Emplyee Age : %d",Ptr1->age);
				printf("\n");
				printf("Emplyee Salary : %d",Ptr1->salary);
				printf("\n");
				printf("Emplyee Title : %s",Ptr1->title);
				printf("\n");
				printf("Emplyee ID : %d",Ptr1->id);
				printf("\n");
				delay(5); //Delay for 5 second 
				return;
			}
			else
			{
				Ptr1 = Ptr1->next;
			}
		}
		/*If The User Entered Wrong ID Print A Message To Re Enter The Right ID */
		printf("Incorrect ID Please Re Enter The Right ID \n");
		ViewEmplyeeData_Func(); //return again to the main function
	}
}

void ViewAllData_Func(void)
{
	/* Create A Pointer To Move On All The Emplyees Nodes To Print All The Emplyee Information  */
	struct Emplyee_Node *Ptr1;
	Ptr1 = head;
	if(Ptr1 == NULL_PTR ) 
	{
		/* Check If There Is Emplyees Informations In The Database Or Not If Not Print This Message For The User */
		printf("\nThere are no Emplyees.\n");
	}
	else
	{
		/* Print All The Informations Of All The Emplyees */
		printf("ID: reservation slot:\n");
		while(Ptr1!= NULL_PTR)
		{
			printf("Emplyee Name : %s",Ptr1->name);
			printf("\n");
			printf("Emplyee Age : %d",Ptr1->age);
			printf("\n");
			printf("Emplyee Salary : %d",Ptr1->salary);
			printf("\n");
			printf("Emplyee Title : %s",Ptr1->title);
			printf("\n");
			printf("Emplyee ID : %d",Ptr1->id);
			printf("\n");
			printf("------------------------------------------------------------------\n");
			Ptr1 = Ptr1->next;
		}
		delay(10); //Delay for 10 second
	}
}

int Exit_Func(void)
{
    exit(0);
}

void delay(uint32 seconds) 
{
    usleep(seconds * 1000 * 1000); // usleep takes microseconds, so multiply by 1000 * 1000 to convert to seconds
}