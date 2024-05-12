/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  Bank.hpp
*        Brief    :  Header file defining the Bank class for managing bank accounts.
*        Details  :  This file contains declarations for the Bank class, which handles operations related
*                    to bank accounts such as adding new accounts, calculating total balances,
*                    and displaying account information.
*
****************************************************************/
#ifndef BANK_H 
#define BANK_H

/****************************************************************
* INCLUDES
****************************************************************/
#include <iostream>         
#include <vector>           
#include <string>           
#include "BankAccount.hpp"    

/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
/*
      Brief  : Declaration of the Bank class.
	  Details  : This class represents a bank and manages bank accounts.
*/
class Bank
{
    /*Attributes*/
    protected:
    std::vector<BankAccount> Bank_Accounts;   // Vector to store bank accounts

    /*Methods*/
    public:
    /*
      Brief  : Method to add a new bank account.
	  Details  : This method adds a new bank account to the bank's records.
	  param[in] New_Acc_Number: Account number of the new account.
	  param[in] NewHolder_Name: Name of the account holder.
	  param[in] New_Account_Type: Type of the account (e.g., savings, checking).
	  param[in] New_Account_Balance: Initial balance of the new account.
*/
    void AddAccount(s32_t New_Acc_Number, std::string NewHolder_Name, std::string New_Account_Type, u64_t New_Account_Balance);

    /*
      Brief  : Method to get the total balance across all accounts.
	  Details  : This method calculates and retrieves the total balance across all bank accounts.
	  return: Total balance across all accounts.
*/
  u64_t GetTotalBalance(void);

    /*
      Brief  : Method to display details of all accounts.
	  Details  : This method displays details of all bank accounts managed by the bank.
*/
    void DisplayAllAccounts(void);

    /*
      Brief  : Method to check if an account number is already in use.
	  Details  : This method checks if the provided account number is already assigned to an existing account.
	  param[in] AccountNumber: The account number to be checked.
	  return   : True if the account number is not in use, false otherwise.
*/
bool Check_AccountNumber(u32_t AccountNumber);

/*
 * Brief    : Deposit funds into an account.
 * Details  : This method finds the account with the given account number and deposits the specified funds into it.
 * Parameter: Account_Number - The account number.
 * Parameter: Funds - The amount to deposit.
 */
void DepositFunds(u32_t Account_Number, int Funds);

/*
 * Brief    : Withdraw funds from an account.
 * Details  : This method finds the account with the given account number and withdraws the specified funds from it.
 * Parameter: Account_Number - The account number.
 * Parameter: Funds - The amount to withdraw.
 */
void WithdrawFunds(u32_t Account_Number, int Funds);

/*
 * Brief    : Get the number of accounts in the system.
 * Details  : This method returns the total number of accounts currently registered in the system.
 * Return   : The number of accounts.
 */
s32_t GetSize(void);

/*
 * Brief    : Get information about an account.
 * Details  : This method retrieves information about an account and populates the provided vector with the account details.
 * Parameter: Line - A vector to store the account information.
 * Parameter: Counts - The number of accounts to retrieve information for.
 */
void GetAccountInfo(std::vector<std::string>& Line, int Counts);

};


/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/


/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/

#endif
/****************************************************************
*  END OF  FILE: Bank.hpp
****************************************************************/
