/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  Bank_System_Program.cpp
*        Brief    :  Implementation of a simple bank system program allowing account creation, deposit,
*                    withdrawal, balance checking, and account display.
*        Details  :  This file contains the main function that serves as the entry point for 
*                    the bank system program. It allows users to perform various operations 
*                    on bank accounts such as creating accounts, depositing funds, withdrawing funds,
*                    checking total balances, and displaying account information.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>                   
#include "Header/BankSystemAPIs.hpp"          

/****************************************************************
*    GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Main function.
	  Details  : Entry point for the bank system program. It presents a menu to the user to perform
                 various operations on bank accounts.
	  param[in]: None.
*/
int main(void)
{
    /*1. Main Program Features*/
     InitSystem();
    /*2. Init Variables*/
    s32_t Operation_ID = 0;       
    /*3. Start while loop*/
    while (1)
    {
        /*4. Ask user to Enter Operation ID*/
        DisplayMenu();
        std::cin >> Operation_ID; 
        
        /*5. Get the Required Operation*/
        switch(Operation_ID)
        {
            case 1:
                /*6. function for creating an account */
                NewAccountProcess();                                                 
                break;
            case 2:
                /*7. function for depositing funds */
                DepositFundsProcess();
                break;
            case 3:
                /*8. function for withdraw funds */
                WithdrawFundsProcess();
                break;
            case 4:
                /*9. function for checking total balance */
                GetTotalBalanceProcess();
                break;

            case 5:
                /*10. function for displaying all accounts */
                DisplayAllAccounts();
                break;
            case 6:
                /*11. Exit the program */
                CloseProgram();
                break;
                /*12. If user enter an Invalid Operation ID */
            default:
                std::cout << "Invalid Operation ID, Please Enter a valid ID number." << std::endl;

                break;
        }
    }
    /*14. End of function*/
    return 0;
}
/****************************************************************
*  END OF  FILE: Bank_System_Program.cpp
****************************************************************/
