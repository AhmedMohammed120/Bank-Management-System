/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  BankSystemAPIs.hpp
*        Brief    :  Declaration of functions for bank system operations.
*        Details  :  This file contains declarations of various functions 
*                    used for different operations in the bank system.
*
****************************************************************/
#ifndef BANK_SYSTEM_APIS_HPP
#define BANK_SYSTEM_APIS_HPP
/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>
#include "Bank.hpp"
/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
/*
    Brief    : Process to create a new account.
    Details  : This function orchestrates the process of creating a new account. 
               It collects information such as account number, holder name, account type, and balance 
               through various helper functions and adds the new account if all information is valid.
    return   : This function does not return anything.
*/
void NewAccountProcess(void);

/*
    Brief    : Process to deposit funds into an account.
    Details  : This function prompts the user to enter an account number and the amount to deposit. 
               It then verifies the account number's existence and the validity of the deposit amount 
               before proceeding with the deposit operation.
    return   : This function does not return anything.
*/
void DepositFundsProcess(void);

/*
    Brief    : Process to withdraw funds from an account.
    Details  : This function prompts the user to enter an account number and the amount to withdraw. 
               It then verifies the account number's existence and the validity of the withdrawal amount 
               before proceeding with the withdrawal operation.
    return   : This function does not return anything.
*/
void WithdrawFundsProcess(void);

/*
    Brief    : Process to display the total balance of the bank.
    Details  : This function displays the total balance of all accounts in the bank system.
    return   : This function does not return anything.
*/
void GetTotalBalanceProcess(void);

/*
    Brief    : Display all accounts.
    Details  : This function displays information about all accounts in the bank system.
    return   : This function does not return anything.
*/
void DisplayAllAccounts(void);

/*
    Brief    : Display the main menu.
    Details  : This function displays the main menu of the bank management system, 
               prompting the user to choose from various operations.
    return   : This function does not return anything.
*/
void DisplayMenu(void);

/*
 * Brief    : Initialize the system.
 * Details  : This function initializes the system by displaying the main features of the program,
 *            restoring system data from the database file, and initializing the accounts counter.
 */
void InitSystem(void);

/*
 * Brief    : Close the program.
 * Details  : This function uploads the updated system information to the database file
 *            and then exits the program.
 */
void CloseProgram(void);

/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/

#endif
/****************************************************************
*  END OF  FILE: BankSystemAPIs.hpp
****************************************************************/
