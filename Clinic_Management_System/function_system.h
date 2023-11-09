/******************************************************************************
 *
 * Module: Some of prototype of functions
 *
 * File Name: function_system.h
 *
 * Description: Prototype the function of the system
 *
 * Author: Bilal Mohamed
 *
 *******************************************************************************/

#ifndef FUNCTION_SYSTEM_H_
#define FUNCTION_SYSTEM_H_

#include "std_types.h"

/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/

#define PASSWORD 1234
#define NO_OF_SLOTS 5


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

struct Patient_Node
{
   uint8 name[30];
   uint8 gender[30];
   uint32 id;
   uint32 age;
   uint32 slot;
   struct Patient_Node *next;
};


/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/

/*
 * Description :
 * Select Mode (main)Function
 */

void SelectMode_Func(void);


/*
 * Description :
 * Admin Mode Functions
 */

void Admin_Mode(void);
void Admin_ChoiceFunc(void);
void AddPatient_Func(void);
void EditPatientInfo_Func(void);
void ReserveSlot_Func(void);
void CancelReservation_Func(void);


/*
 * Description :
 * User Mode Functions
 */

void User_Mode(void);
void ViewPatientInformation_Func(void);
void ViewPatientsReservations_Func (void);


#endif /* FUNCTION_SYSTEM_H_ */
