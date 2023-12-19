/***************************************************************************
 * Author      : Bilal Mohamed Elqaqei                                     *
 * Description : Emplyee Record System                                     *
 * File Name   : Emplyee_Fun.h                                             *
 * Date        : 18-12-2023                                                *
 ***************************************************************************/


#ifndef EMPLYEE_SYSTEM_H_
#define EMPLYEE_SYSTEM_H_

#include "std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

struct Emplyee_Node
{
   uint8 name[100];
   uint8 age;
   uint32 salary;
   uint8 title[100];
   uint32 id;
   struct Emplyee_Node *next;
};

/*******************************************************************************
 *                              Functions Prototypes                           *
 *******************************************************************************/
void SelectMode_Func(void)       ;
void AddEmplyee_Func(void)       ;
void DeleteEmplyeeData_Func(void);
void ModifyEmplyeeData_Func(void);
void ViewEmplyeeData_Func(void)  ;
void ViewAllData_Func(void)      ;
int Exit_Func(void)              ;
void delay(uint32 seconds)       ;


#endif
