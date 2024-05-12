/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  Bank.cpp
*        Brief    :  Implementation file for the Bank class, containing member function definitions.
*        Details  :  This file implements the member functions of the Bank class declared in Bank.hpp. 
*                    It includes functions for adding accounts, calculating total balances, and
*                    displaying account information.
*
*****************************************************************
* INCLUDES
****************************************************************/
#include "Header/Bank.hpp"  

/****************************************************************
*    LOCAL MACROS CONSTANTS\FUNCTIONS
****************************************************************/


/****************************************************************
*    LOCAL DATA
****************************************************************/


/****************************************************************
*    GLOBAL DATA
****************************************************************/

/****************************************************************
*    LOCAL FUNCTION PROTOTYPES
****************************************************************/


/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/


/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/
/*
      Brief    : Function to add a new bank account.
	  Details  : This function creates a new BankAccount object and adds it to the bank's records.
	  param[in]: New_Acc_Number: Account number of the new account.
	  param[in]: NewHolder_Name: Name of the account holder.
	  param[in]: New_Account_Type: Type of the account (e.g., savings, checking).
	  param[in]: New_Account_Balance: Initial balance of the new account.
*/
void Bank::AddAccount(s32_t New_Acc_Number, std::string NewHolder_Name, std::string New_Account_Type, u64_t New_Account_Balance)
{
    BankAccount New_Account(New_Acc_Number, NewHolder_Name, New_Account_Type, New_Account_Balance);
    Bank_Accounts.push_back(New_Account);
}

/*
      Brief    : Function to calculate the total balance across all accounts.
	  Details  : This function iterates through all bank accounts and calculates the sum of their balances.
	  return   : Total balance across all accounts.
*/
u64_t Bank::GetTotalBalance(void)
{
    s32_t TotalBalance = 0;
if(Bank_Accounts.size()!=0)
{
    for(unsigned int Account_Counts = 0; Account_Counts < Bank_Accounts.size(); Account_Counts++)
    {
        TotalBalance += Bank_Accounts[Account_Counts].Account_Balance;
    }
}
    return TotalBalance;
}

/*
      Brief    : Function to display details of all accounts.
	  Details  : This function iterates through all bank accounts and calls the DisplayAccountInfo() method of each account to display its                          information.
*/
void Bank::DisplayAllAccounts(void)
{
    
        for (unsigned int Account_Counts = 0; Account_Counts < Bank_Accounts.size(); Account_Counts++)
        {
            std::cout << "\nAccount " << Account_Counts + 1 << " :" << std::endl;
            Bank_Accounts[Account_Counts].DisplayAccountInfo();
        }
    
}

/*
      Brief    : Function to check if an account number is already in use.
	  Details  : This function checks if the provided account number is already assigned to an existing account.
	  param[in]: AccountNumber: The account number to be checked.
	  return   : True if the account number is not in use, false otherwise.
*/
bool Bank::Check_AccountNumber(u32_t AccountNumber)
{
    bool Status = true;
    for (u32_t Account_Counter = 0; Account_Counter < Bank_Accounts.size(); Account_Counter++)
    {
        if (AccountNumber == Bank_Accounts[Account_Counter].Account_Number)
        {
            Status = false;
            break;
        }
        else
        {
            /*To be done*/  
        }
    }
    return Status;
}
/*
      Brief    : Function to deposit funds into an account.
	  Details  : This function finds the account with the given account number and deposits the specified funds into it.
	  param[in]: Input_Number: The account number.
	  param[in]: Funds: The amount to deposit.
*/
void Bank::DepositFunds(u32_t Input_Number, int Funds)
{
        for (unsigned int Account_Counts = 0; Account_Counts < Bank_Accounts.size(); Account_Counts++)
        {
            if (Bank_Accounts[Account_Counts].Account_Number == Input_Number)
            {
                Bank_Accounts[Account_Counts].Deposit(Funds);
                break;
            }
        }
}
/*
      Brief    : Function to withdraw funds from an account.
	  Details  : This function finds the account with the given account number and withdraws the 
                 specified funds from it.
	  param[in]: Input_Number: The account number.
	  param[in]: Funds: The amount to withdraw.
*/

void Bank::WithdrawFunds(u32_t Input_Number, int Funds)
{
        for (unsigned int Account_Counts = 0; Account_Counts < Bank_Accounts.size(); Account_Counts++)
        {
            if (Bank_Accounts[Account_Counts].Account_Number == Input_Number)
            {
                Bank_Accounts[Account_Counts].Withdraw(Funds);
                break;
            }
        }
}

/*
 * Brief    : Get the number of accounts in the system.
 * Details  : This method returns the total number of accounts currently registered in the system.
 * Return   : The number of accounts.
 */
s32_t Bank::GetSize(void)
{
    return Bank_Accounts.size();
}

/*
 * Brief    : Get information about an account.
 * Details  : This method retrieves information about an account and populates the provided vector with the account details.
 * Parameter: Line - A vector to store the account information.
 * Parameter: Counts - The number of accounts to retrieve information for.
 */
void Bank::GetAccountInfo(std::vector<std::string>& Line,int Counts)
{
     Line.push_back(std::to_string(Bank_Accounts[Counts].GetAccountNumber()));
     Line.push_back(Bank_Accounts[Counts].GetAccountHolder());
     Line.push_back(Bank_Accounts[Counts].GetAccountType());
     Line.push_back(std::to_string(Bank_Accounts[Counts].GetAccountBalance()));
    
}
/****************************************************************
*  END OF  FILE: Bank.cpp
****************************************************************/