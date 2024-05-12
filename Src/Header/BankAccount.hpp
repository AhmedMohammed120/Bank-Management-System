/****************************************************************
 FILE DESCRIPTION
----------------------------------------------------------------
*        File     :  BankAccount.hpp
*        Brief    :  Header file for defining the BankAccount class.
*        Details  :  Contains the class definition for BankAccount along with its attributes and methods.
*
****************************************************************/
#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
/****************************************************************
* INCLUDES
****************************************************************/
#include "Std_Types.hpp" 
#include <iostream> 
#include <string> 
/****************************************************************
*    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
****************************************************************/
/*
      Brief  : Declaration of the BankAccount class.
	  Details  : The class represents a bank account and includes attributes such as account number, holder name, account type, and balance. It also contains methods for depositing, withdrawing, and accessing account information.
*/

class BankAccount
{
    /*Attributes*/
    public: 
    s32_t Account_Number; 
    std::string Holder_Name; 
    std::string Account_Type;
    u64_t Account_Balance; 

    /*Methods*/
    public:
    /*
        Brief   : Constructor for BankAccount class.
        Details : Initializes a BankAccount object with provided parameters.
        param[in] New_Acc_Number: New account number.
        param[in] NewHolder_Name: New account holder's name.
        param[in] New_Account_Type: New account type.
        param[in] New_Account_Balance: New account balance.
    */
    BankAccount(s32_t New_Acc_Number, std::string NewHolder_Name,std::string New_Account_Type,s32_t New_Account_Balance);
    
    /*Setters*/
    /*
        Brief   : Method to deposit funds into the account.
        Details : Increases the account balance by the specified amount.
        param[in] Funds: Amount to be deposited.
    */
    void Deposit(s32_t Funds);

    /*
        Brief   : Method to withdraw funds from the account.
        Details : Decreases the account balance by the specified amount.
        param[in] Funds: Amount to be withdrawn.
    */
    void Withdraw(s32_t Funds);

    /*Getters*/
    /*
        Brief   : Method to get account number.
        Details : Returns the account number.
        return   : Account number.
    */
    u32_t GetAccountNumber(void);

    /*
        Brief   : Method to get account holder's name.
        Details : Returns the account holder's name.
        return   : Account holder's name.
    */
    std::string GetAccountHolder(void);

    /*
        Brief   : Method to get account type.
        Details : Returns the account type.
        return   : Account type.
    */
    std::string GetAccountType(void);

    /*
        Brief   : Method to get account balance.
        Details : Returns the account balance.
        return   : Account balance.
    */
    s32_t GetAccountBalance(void);

    /*
        Brief   : Method to display account information.
        Details : Prints the account details including account number, holder's name, account type, and balance.
    */
    void DisplayAccountInfo(void);  
};




/****************************************************************
*    GLOBAL CONSTANT MACROS
****************************************************************/

 
/****************************************************************
*    GLOBAL DATA PROTOTYPES
****************************************************************/


#endif
/****************************************************************
*  END OF  FILE: BankAccount.hpp
****************************************************************/
