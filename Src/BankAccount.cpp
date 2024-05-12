/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  BankAccount.cpp
*        Brief    :  Implementation file for the BankAccount class.
*                    
*        Details  :  Contains the definitions of member functions of the BankAccount class.
*

*****************************************************************
* INCLUDES
****************************************************************/
#include "Header/BankAccount.hpp"
/****************************************************************
*    LOCAL MACROS CONSTATN\FUNCTIONS
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
      Brief    : Constructor for BankAccount class.
	  Details  : Initializes a BankAccount object with provided parameters.
	  param[in]: New_Acc_Number: New account number.
	  param[in]: NewHolder_Name: New account holder's name.
	  param[in]: New_Account_Type: New account type.
	  param[in]: New_Account_Balance: New account balance.
*/
 BankAccount::BankAccount(s32_t New_Acc_Number, std::string NewHolder_Name,std::string New_Account_Type,s32_t New_Account_Balance)
{
    Account_Number = New_Acc_Number;
    Holder_Name = NewHolder_Name;
    Account_Type = New_Account_Type; 
    Account_Balance = New_Account_Balance;
}

/*
      Brief    : Method to deposit funds into the account.
	  Details  : Increases the account balance by the specified amount.
	  param[in]: Funds: Amount to be deposited.
*/
void BankAccount::Deposit(s32_t Funds)
{
    Account_Balance += Funds;
}

/*
      Brief    : Method to withdraw funds from the account.
	  Details  : Decreases the account balance by the specified amount.
	  param[in]: Funds: Amount to be withdrawn.
*/
void BankAccount::Withdraw(s32_t Funds)
{
    Account_Balance -= Funds;
}

/*
      Brief    : Method to get account number.
	  Details  : Returns the account number.
	  return   : Account number.
*/
u32_t BankAccount::GetAccountNumber(void)
{
    return Account_Number;
}

/*
      Brief    : Method to get account holder's name.
	  Details  : Returns the account holder's name.
	  return   : Account holder's name.
*/
std::string BankAccount::GetAccountHolder(void)
{
    return Holder_Name;
}

/*
      Brief    : Method to get account type.
	  Details  : Returns the account type.
	  return   : Account type.
*/
std::string BankAccount::GetAccountType(void)
{
    return Account_Type;
}

/*
      Brief    : Method to get account balance.
	  Details  : Returns the account balance.
	  return   : Account balance.
*/
s32_t BankAccount::GetAccountBalance(void)
{
    return Account_Balance;
}

/*
      Brief    : Method to display account information.
	  Details  : Prints the account details including account number, holder's name, account type, and balance.
*/
void BankAccount::DisplayAccountInfo(void)
{
    
    std::cout << "Account Number: " << Account_Number << std::endl;
    std::cout << "Account Holder: " << Holder_Name << std::endl;
    std::cout << "Account Type: " << Account_Type << std::endl;
    std::cout << "Account Balance: " << Account_Balance << std::endl;
}
 /****************************************************************
*  END OF  FILE: BankAccount.cpp
****************************************************************/
