/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  Std_Macros.h
*        Brief    :  This header file defines standard macros for
*                    bitwise operations.
*        Details  :  This file provides macros for setting, clearing,
*                    toggling, and reading individual bits of a 
*                    variable.
*
****************************************************************/
#ifndef STD_MACROS_H
#define STD_MACROS_H
/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
typedef unsigned char      u8_t;
typedef unsigned short     u16_t;
typedef unsigned int       u32_t;
typedef unsigned long long u64_t;
typedef signed char        s8_t;
typedef signed short       s16_t;
typedef signed int         s32_t;


/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/
#define SET_BIT(VAR,BITNO)                (VAR=(VAR|(1<<BITNO)))  // Set a bit at a specified position
#define CLR_BIT(VAR,BITNO)                (VAR=(VAR&~(1<<BITNO))) // Clear a bit at a specified position
#define TOGGLE_BIT(VAR,BITNO)             (VAR=(VAR^(1<<BITNO)))   // Toggle a bit at a specified position
#define READ_BIT(VAR,BITNO)               ((VAR&(1<<BITNO))>>BITNO) // Read a bit at a specified position
 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/


#endif
/****************************************************************
*  END OF  FILE: Std_Macros.h
****************************************************************/
