/****************************************************************
 FILE DESCRIPTION
-----------------------------------------------------------------
*        File     :  BankSystemAPIs.cpp
*        Brief    :  This file contains functions for managing 
*                    bank accounts, including creating new accounts, 
*                    depositing and withdrawing funds, displaying 
*                    account information, and displaying main 
*                    features of the bank management system.

*        Details  :  Detailed descriptions are provided for each 
*                    function below.
*****************************************************************
* INCLUDES
****************************************************************/
#include <limits>
#include <iostream>
#include "Header/BankSystemAPIs.hpp"
#include "Header/FileSystemManager.hpp"
#include <fstream>
#include <string>
/****************************************************************
*    LOCAL MACROS CONSTATN\FUNCTIONS
****************************************************************/

/****************************************************************
*    LOCAL DATA
****************************************************************/
      


/****************************************************************
*    GLOBAL DATA
****************************************************************/
int AccountsCounter ;       // Variable to count Accounts 
Bank Bank_Accounts;            // Object to store all bank accounts
int NewAccountNumber;              // Variable to store account number input
int NewAccountBalance;             // Variable to store new account balance input
std::string NewAccountHolderName;  // Variable to store new account holder name input
std::string NewAccountType;        // Variable to store new account type input
CSV ProjectFiles("BankDataBase/BankDataBase.txt","BankDataBase/BankErrorLog.txt");
/****************************************************************
*    LOCAL FUNCTION PROTOTYPES
****************************************************************/
/*
      Brief    : Function to process a new account number.
	  Details  : This function prompts the user for a new account number and validates its uniqueness.
	  param[in]: Bank_Accounts: Reference to the Bank object containing existing accounts.
	  param[out]: NewNumber_Ret: Pointer to store the new account number.
	  return   : True if a valid new account number is obtained, false otherwise.
*/
static bool NewAccountNumberProcess(int *NewNumber_Ret);

/*
      Brief    : Function to check the validity of a name.
	  Details  : This function checks if a given name contains only alphabetic characters or spaces.
	  param[in]: Author_Name: The name to be checked.
	  return   : True if the name is valid, false otherwise.
*/
static bool Check_Name_Validity(std::string AccountName);

/*
    Brief    : Process the input for a new account holder name.
    Details  : This function prompts the user to input a new account holder name and validates it. 
               It ensures that the input contains only alphabetic characters or spaces.
    param[in]: HolderNameRet - Pointer to store the validated new account holder name.
    return   : Returns true if the input name is valid, false otherwise.
*/
static bool NewAccountNameProcess(std::string* HolderNameRet);

/*
    Brief    : Process the input for a new account type.
    Details  : This function prompts the user to input a new account type and validates it. 
               It ensures that the input contains only alphabetic characters or spaces.
    param[in]: AccountTypeRet - Pointer to store the validated new account type.
    return   : Returns true if the input type is valid, false otherwise.
*/
static bool NewAccountTypeProcess(std::string* AccountTypeRet);

/*
    Brief    : Process the input for a new account balance.
    Details  : This function prompts the user to input a new account balance and validates it. 
               It ensures that the input is a non-negative integer.
    param[in]: AccountBalance - Pointer to store the validated new account balance.
    return   : Returns true if the input balance is valid, false otherwise.
*/
static bool NewAccountBalanceProcess(int* AccountBalance);

/*
    Brief    : Add a new account to the bank system.
    Details  : This function adds a new account to the bank system with the provided account number, 
               holder name, account type, and balance.
    param[in]: AccountNumber       - The account number of the new account.
    param[in]: AccountHolderName   - The holder name of the new account.
    param[in]: AccountType         - The type of the new account.
    param[in]: New_AccountBalance  - The balance of the new account.
    return   : This function does not return anything.
*/
static void NewAccountAdditionProcess(int AccountNumber, std::string AccountHolderName, 
                                      std::string AccountType, u32_t New_AccountBalance);

/*
    Brief    : Display main features of the bank management system.
    Details  : This function lists the main features included in the bank management system project.
    return   : This function does not return anything.
*/
void static MainFeaturesDisplay(void);

/****************************************************************
*    LOCAL FUNCTIONS
****************************************************************/
/*
      Brief    : Function to process a new account number.
	  Details  : This function prompts the user for a new account number and validates its uniqueness.
	  param[in]: Bank_Accounts: Reference to the Bank object containing existing accounts.
	  param[out]: NewNumber_Ret: Pointer to store the new account number.
	  return   : True if a valid new account number is obtained, false otherwise.
*/
static bool NewAccountNumberProcess(int *NewNumber_Ret)
{
    int New_AccountNumber;
    bool Status = true;
    std::cout << "Add New Account Operation:" << std::endl;
    std::cout << "Enter Account Number (0 & Negative numbers are not valid): ";
    std::cin >> New_AccountNumber;
    Status = Bank_Accounts.Check_AccountNumber(New_AccountNumber);
    if (Status == true && New_AccountNumber > 0)
    {
        *NewNumber_Ret = New_AccountNumber;
        std::cout << "Success Operation." << std::endl;
        Status = true;
    }
    else
    {
        while (1)
        {
            if (New_AccountNumber > 0)
            {
                std::cout << "This Account number is currently exist, please try another one, to return to the main menu enter 0" << std::endl;
            }
            else
            {
                std::cout << "Zero and negative numbers are not valid. Please try another one, to return to the main menu enter 0: " << std::endl;
            }
            std::cout << "Enter Account Number: ";
            std::cin >> New_AccountNumber;
            Status = Bank_Accounts.Check_AccountNumber(New_AccountNumber);
            if (Status == true && New_AccountNumber > 0)
            {
                *NewNumber_Ret = New_AccountNumber;
                std::cout << "Success Operation." << std::endl;
                Status = true;
                break;
            }
            else if (New_AccountNumber == 0)
            {
                Status = false;
                break;
            }
        }
    }
    return Status;
}


/*
      Brief    : Function to check the validity of a name.
	  Details  : This function checks if a given name contains only alphabetic characters or spaces.
	  param[in]: AccountName: The name to be checked.
	  return   : True if the name is valid, false otherwise.
*/
static bool Check_Name_Validity(std::string AccountName)
{
    bool Status = false;
    unsigned int AlphaCharDetector = 0;
    for (auto Ch : AccountName)
    {
        if (isalpha(Ch) )
        {
            Status = true;
            AlphaCharDetector = 1;
        }
        else if(isspace(Ch) && AlphaCharDetector>0)
        {
            Status = true;
        }
        else
        {
            Status = false;
            break;
        }
    }
    return Status;
}

/*
    Brief    : Process the input for a new account holder name.
    Details  : This function prompts the user to input a new account holder name and validates it. 
               It ensures that the input contains only alphabetic characters or spaces.
    param[in]: HolderNameRet - Pointer to store the validated new account holder name.
    return   : Returns true if the input name is valid, false otherwise.
*/
static bool NewAccountNameProcess(std::string* HolderNameRet)
{
    bool Status = true;
    bool Terminate_Status = false;
    std::string New_HolderName;
    
    std::cout << "Enter Holder Name: ";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
    std::getline(std::cin, New_HolderName);
    
    Status = Check_Name_Validity(New_HolderName);
    
    if (Status == true)
    {
        *HolderNameRet = New_HolderName;
        std::cout << "Success Operation." << std::endl;
        std::cout << "Holder Name: " << New_HolderName << std::endl;
    }
    else
    {
        Terminate_Status = false;
        while (!Terminate_Status)
        {
            std::cout << "Holder name should not contain numbers or special chars." << std::endl;
            std::cout << "Please enter a valid name or enter 0 to return to the main menu." << std::endl;
            std::cout << "Enter Holder Name: ";
            std::getline(std::cin, New_HolderName);
            Status = Check_Name_Validity(New_HolderName);
            
            if (Status == true)
            {
                Terminate_Status = true;
                Status = true;
                *HolderNameRet = New_HolderName;
                std::cout << "Success Operation." << std::endl;
                std::cout << "Holder Name: " << New_HolderName << std::endl;
            }
            else if (New_HolderName[0] == '0')
            {
                Status = false;
                Terminate_Status = true;
            }
            else
            {
                Status = false;
                Terminate_Status = false;
            }
        }
    }
    return Status;
}

/*
    Brief    : Process the input for a new account type.
    Details  : This function prompts the user to input a new account type and validates it. 
               It ensures that the input contains only alphabetic characters or spaces.
    param[in]: AccountTypeRet - Pointer to store the validated new account type.
    return   : Returns true if the input type is valid, false otherwise.
*/
static bool NewAccountTypeProcess(std::string* AccountTypeRet)
{
    std::string New_AccountType;
    bool Status;
    bool Terminate_Status;
	
    std::cout << "Enter Account Type: ";
    std::getline(std::cin, New_AccountType);
    Status = Check_Name_Validity(New_AccountType);
    
    if (Status == true)
    {
        *AccountTypeRet = New_AccountType;
        std::cout << "Success Operation." << std::endl;
        std::cout << "Account Type: " << New_AccountType << std::endl;
    }
    else
    {
        Terminate_Status = false;
        while (!Terminate_Status)
        {
            std::cout << "Account Type should not contain numbers or special chars." << std::endl;
            std::cout << "Please enter a valid name or enter 0 to return to the main menu." << std::endl;
            std::cout << "Enter Account Type: ";
            std::getline(std::cin, New_AccountType);
    
            Status = Check_Name_Validity(New_AccountType);
            if (Status == true)
            {
                *AccountTypeRet = New_AccountType;
                std::cout << "Success Operation." << std::endl;
                std::cout << "Account Type: " << New_AccountType << std::endl;
                Terminate_Status = true;
                Status = true;
            }
            else if (New_AccountType[0] == '0')
            {
                Status = false;
                Terminate_Status = true;
            }
            else
            {
                Status = false;
                Terminate_Status = false;
            }
        }
    }
    return Status;
}

/*
    Brief    : Process the input for a new account balance.
    Details  : This function prompts the user to input a new account balance and validates it. 
               It ensures that the input is a non-negative integer.
    param[in]: AccountBalance - Pointer to store the validated new account balance.
    return   : Returns true if the input balance is valid, false otherwise.
*/
static bool NewAccountBalanceProcess(int* AccountBalance)
{
    int New_AccountBalance;
    bool Status ;
    bool Terminate_Status = false;
    std::cout << "Enter Account Balance: ";
    std::cin >> New_AccountBalance;
    
    if (New_AccountBalance >= 0)
    {
        *AccountBalance = New_AccountBalance;
        Status = true;
    }
    else
    {
        Terminate_Status = false;
        while (!Terminate_Status)
        {
            std::cout << "Invalid Account Balance. " << std::endl;
            std::cout << "Account Balance should be non-negative number, Enter -1 to terminate operation." << std::endl;
            std::cout << "Enter Account Balance: ";
            std::cin >> New_AccountBalance;
            
            if (New_AccountBalance >= 0)
            {
                *AccountBalance = New_AccountBalance;
                Terminate_Status = true;
                Status = true;
            }
            else if (New_AccountBalance == -1)
            {
                Terminate_Status = true;
                Status = false;
            }
            else
            {
                Terminate_Status = false;
                Status = false;
            }
        }
    }
    return Status;
}

/*
    Brief    : Add a new account to the bank system.
    Details  : This function adds a new account to the bank system with the provided account number, 
               holder name, account type, and balance.
    param[in]: AccountNumber       - The account number of the new account.
    param[in]: AccountHolderName   - The holder name of the new account.
    param[in]: AccountType         - The type of the new account.
    param[in]: New_AccountBalance  - The balance of the new account.
    return   : This function does not return anything.
*/
static void NewAccountAdditionProcess(int AccountNumber, std::string AccountHolderName, 
                                      std::string AccountType, u32_t New_AccountBalance)
{
    Bank_Accounts.AddAccount(AccountNumber, AccountHolderName, AccountType, New_AccountBalance);
    std::vector<std::string> Vector;
    Vector.push_back(std::to_string(AccountNumber));
    Vector.push_back(AccountHolderName);
    Vector.push_back(AccountType);
    Vector.push_back(std::to_string(New_AccountBalance));
    ProjectFiles.writeDataBase(Vector);
    AccountsCounter++;
    std::cout << "Process finished Successfully.  " << std::endl;
}

/*
    Brief    : Display main features of the bank management system.
    Details  : This function lists the main features included in the bank management system project.
    return   : This function does not return anything.
*/
void static MainFeaturesDisplay(void)
{
    std::cout << "\n\nFeatures included in the Bank Management System Project" << std::endl;
    std::cout << "1. Data base for store system information" << std::endl;
    std::cout << "2. Terminate Operation Option during New Account Creation" << std::endl;
    std::cout << "3. Error checking when entering invalid or existing Account numbers" << std::endl;
    std::cout << "4. Ensure that each account has a unique Account Number" << std::endl;
    std::cout << "5. Error checking when writing special characters or numbers in Holder Name" << std::endl;
    std::cout << "6. Holder name can contain spaces" << std::endl;
    std::cout << "7. Error checking when writing special characters or numbers in Account Type" << std::endl;
    std::cout << "8. Error checking in Balance Value" << std::endl;
    
}


/****************************************************************
*   GLOBAL FUNCTIONS
****************************************************************/
/*
    Brief    : Process to create a new account.
    Details  : This function orchestrates the process of creating a new account. 
               It collects information such as account number, holder name, account type, and balance 
               through various helper functions and adds the new account if all information is valid.
    return   : This function does not return anything.
*/
void NewAccountProcess(void)
{
    bool Status;
    
    // Step 6: Logic for creating an account
    Status = NewAccountNumberProcess(&NewAccountNumber);
    if (Status == true)
        Status = NewAccountNameProcess(&NewAccountHolderName);
    if (Status == true)
        Status = NewAccountTypeProcess(&NewAccountType); 
    if (Status == true)
        Status = NewAccountBalanceProcess(&NewAccountBalance);

    // Step 7: When user enters a valid account type, Start to get balance
    if (Status == true)
        NewAccountAdditionProcess(NewAccountNumber, NewAccountHolderName, NewAccountType, NewAccountBalance);
    else
        std::cout << "Process Terminated." << std::endl;
}

/*
    Brief    : Process to deposit funds into an account.
    Details  : This function prompts the user to enter an account number and the amount to deposit. 
               It then verifies the account number's existence and the validity of the deposit amount 
               before proceeding with the deposit operation.
    return   : This function does not return anything.
*/
void DepositFundsProcess(void)
{
    int AccountNumber;
    int Funds;
    bool Status = false;
    
    std::cout << "Deposit Operation" << std::endl;
    
    if (AccountsCounter > 0)
    {
        std::cout << "Enter Account Number: ";
        std::cin >> AccountNumber;
        
        Status = Bank_Accounts.Check_AccountNumber(AccountNumber);
        if (Status == 0)  // Account exists
        {
            std::cout << "Enter Funds Value: ";
            std::cin >> Funds;
            
            // Check if funds has a valid non-negative value
            if (Funds >= 0)
            {
                Bank_Accounts.DepositFunds(AccountNumber, Funds);
                std::cout << "Success Operation" << std::endl;
            }
            else
            {
                std::cout << "Funds should not be negative value." << std::endl;
                std::cout << "Process Terminated." << std::endl; 
            }
        }
        else
        {
            std::cout << "Undefined Account." << std::endl;
            std::cout << "Process Terminated." << std::endl; 
        }
    }
    else
    {
        std::cout << "Error, Bank list is Empty. Please Add Account First." << std::endl;     
        std::cout << "Process Terminated." << std::endl;  
    }          
}

/*
    Brief    : Process to withdraw funds from an account.
    Details  : This function prompts the user to enter an account number and the amount to withdraw. 
               It then verifies the account number's existence and the validity of the withdrawal amount 
               before proceeding with the withdrawal operation.
    return   : This function does not return anything.
*/
void WithdrawFundsProcess(void)
{
    int AccountNumber;
    int Funds;
    bool Status = false;
    
    std::cout << "Withdraw Operation" << std::endl;
    
    if (AccountsCounter > 0)
    {
        std::cout << "Enter Account Number: ";
        std::cin >> AccountNumber;
        
        Status = Bank_Accounts.Check_AccountNumber(AccountNumber);
        if (Status == 0)  // Account exists
        {
            std::cout << "Enter Funds Value: ";
            std::cin >> Funds;
            
            // Check if funds has a valid non-negative value
            if (Funds >= 0)
            {
                Bank_Accounts.WithdrawFunds(AccountNumber, Funds);
                std::cout << "Success Operation" << std::endl;
            }
            else
            {
                std::cout << "Funds should not be negative value." << std::endl;
                std::cout << "Process Terminated." << std::endl; 
            }
        }
        else
        {
            std::cout << "Undefined Account." << std::endl;
            std::cout << "Process Terminated." << std::endl; 
        }
    }
    else
    {
        std::cout << "Error, Bank list is Empty. Please Add Account First." << std::endl;     
        std::cout << "Process Terminated." << std::endl;  
    }          
}

/*
    Brief    : Process to display the total balance of the bank.
    Details  : This function displays the total balance of all accounts in the bank system.
    return   : This function does not return anything.
*/
void GetTotalBalanceProcess(void)
{
    std::cout << "Display Bank Total Balance Operation" << std::endl;
    
    if (AccountsCounter > 0)
    {
        std::cout << "Total Balance: " << Bank_Accounts.GetTotalBalance() << std::endl;
    }
    else
    {
        std::cout << "Error, Bank list is Empty. Please Add Account First." << std::endl;    
    }
}

/*
    Brief    : Display all accounts.
    Details  : This function displays information about all accounts in the bank system.
    return   : This function does not return anything.
*/
void DisplayAllAccounts(void)
{
    std::cout << "Display All Accounts Operation" << std::endl;
    
    if (AccountsCounter > 0)
    {
        Bank_Accounts.DisplayAllAccounts();
    }
    else
    {
        std::cout << "Error, Bank list is Empty. Please Add Account First." << std::endl;    
    }
    
}



/*
    Brief    : Display the main menu.
    Details  : This function displays the main menu of the bank management system, 
               prompting the user to choose from various operations.
    return   : This function does not return anything.
*/
void DisplayMenu(void)
{
    std::cout << "Menu:\n1. Create an Account.\n2. Deposit funds\n3. Withdraw funds\n4. Total Balance\n5. Display All Accounts\n6. Exit\nEnter your choice: ";
}

/*
 * Brief    : Close the program.
 * Details  : This function uploads the updated system information to the database file
 *            and then exits the program.
 */
void CloseProgram(void)
{
    /* Step 1: Upload Updated system Information to Database file */
    ProjectFiles.CloseDataBase(Bank_Accounts);

    /* Step 2: Exit the main program */
    exit(0);
}

/*
 * Brief    : Initialize the system.
 * Details  : This function initializes the system by displaying the main features of the program,
 *            restoring system data from the database file, and initializing the accounts counter.
 */
void InitSystem(void)
{
    /* Step 1: Display main features of the program */
    MainFeaturesDisplay();

    /* Step 2: Restore System data from Database file */
    ProjectFiles.readDataBase(Bank_Accounts);

    /* Step 3: Initialize Counter */
    AccountsCounter = Bank_Accounts.GetSize();
}



/****************************************************************
*  END OF  FILE: BankSystemAPIs.cpp
****************************************************************/