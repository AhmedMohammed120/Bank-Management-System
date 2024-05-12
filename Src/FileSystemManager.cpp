/****************************************************************
 * FILE DESCRIPTION
 ****************************************************************
 *        File     :  FileSystemManager.cpp
 *        Brief    :  Implementation of file system management functions.
 *        Details  :  This file contains the implementation of functions related to managing the file system,
 *                    including reading from and writing to databases, closing databases, and writing errors to log files.
 ****************************************************************/

/****************************************************************
 * INCLUDES
 ****************************************************************/
#include "Header/FileSystemManager.hpp"
#include <iostream>

/****************************************************************
 *    LOCAL MACROS, CONSTANTS, AND FUNCTIONS
 ****************************************************************/

/****************************************************************
 *    LOCAL DATA
 ****************************************************************/


/****************************************************************
 *    GLOBAL DATA
 ****************************************************************/
const static int RowLength = 4;

/****************************************************************
 *    LOCAL FUNCTION PROTOTYPES
 ****************************************************************/
/*
 * Brief    : Split a string into tokens based on a delimiter.
 * Details  : This function takes a string and a delimiter as input and splits the string into tokens based on the delimiter.
 *            It returns a vector of strings containing the tokens.
 * Parameter: s - The input string to be split.
 * Parameter: delimiter - The character used as a delimiter to split the string.
 * Return   : A vector of strings containing the tokens.
 */
std::vector<std::string> static split(const std::string& s, char delimiter);
/****************************************************************
 *    LOCAL FUNCTIONS
 ****************************************************************/
/*
 * Brief    : Split a string into tokens based on a delimiter.
 * Details  : This function takes a string and a delimiter as input and splits the string into tokens based on the delimiter.
 *            It returns a vector of strings containing the tokens.
 * Parameter: s - The input string to be split.
 * Parameter: delimiter - The character used as a delimiter to split the string.
 * Return   : A vector of strings containing the tokens.
 */
std::vector<std::string> static split(const std::string& s, char delimiter)
{
    // Vector to store the tokens
    std::vector<std::string> tokens;
    
    // Temporary string to hold each token
    std::string token;
    
    // Create a string stream from the input string
    std::istringstream tokenStream(s);
    
    // Loop through the string stream, extracting tokens using the delimiter
    while (std::getline(tokenStream, token, delimiter))
    {
        // Add the token to the vector of tokens
        tokens.push_back(token);
    }
    
    // Return the vector of tokens
    return tokens;
}

/****************************************************************
 *    GLOBAL FUNCTIONS
 ****************************************************************/

/*
 * Brief    : Constructor for CSV class.
 * Details  : Initializes the CSV class with the paths for the database and error log files.
 * Parameter: DatabasePathCpy - Path to the database file.
 *            ErrorPathCpy - Path to the error log file.
 */
CSV::CSV(std::string DatabasePathCpy, std::string ErrorPathCpy)
    : DatabasePath{DatabasePathCpy}, ErrorPath{ErrorPathCpy}
{

}

/*
 * Brief    : Read data from the database.
 * Details  : Reads data from the database file and populates the provided bank vector with account information.
 * Parameter: Vec - Reference to the Bank object to store the account information.
 */
void CSV::readDataBase(Bank& Vec)
{
    bool Status = false;
    std::ifstream InputFile(DatabasePath);
    std::vector<std::vector<std::string>> StrVec;
    std::string Line;
    while(std::getline(InputFile, Line))
    {
        Status = true;
        std::vector<std::string> Row;
        std::istringstream iss(Line);
        std::string Str;
        while(std::getline(iss, Str, ','))
        {
            Row.push_back(Str);
        }
        StrVec.push_back(Row);
    }
    if(Status)
    {
        for(auto It: StrVec)
        {
            Vec.AddAccount(std::stoi(It[0]), It[1], It[2], std::stoi(It[3]));
        }
    }
    else
    {
        /* TBD */
    }
    InputFile.close();
}

/*
 * Brief    : Write data to the database.
 * Details  : Writes account information from the provided vector to the database file.
 * Parameter: ContentVec - Vector containing account information to be written to the database.
 */
void CSV::writeDataBase(std::vector<std::string>& ContentVec)
{
    std::ofstream DatabaseFile(DatabasePath, std::ios::app);
    for(int It = 0; It < RowLength; It++)
    {
        DatabaseFile << ContentVec[It];
        if(It < RowLength - 1 )
        {
            DatabaseFile << ',';
        }
    }
    DatabaseFile << std::endl;
    DatabaseFile.close();
}

/*
 * Brief    : Close the database.
 * Details  : Writes all account information from the provided Bank object to the database file and closes it.
 * Parameter: Accounts - Reference to the Bank object containing the account information to be written to the database.
 */
void CSV::CloseDataBase(Bank& Accounts)
{
    std::ofstream DatabaseFile(DatabasePath);
    for(int Counts = 0; Counts < Accounts.GetSize(); Counts++)
    {
        std::vector<std::string> Line;
        Accounts.GetAccountInfo(Line, Counts);
        for(int It = 0; It < RowLength; It++)
        {
            DatabaseFile << Line[It];
            if(It < RowLength - 1)
            {
                DatabaseFile << ',';
            }
        }
        DatabaseFile << std::endl;
    }
    DatabaseFile.close();
}

/*
 * Brief    : Write error message to the error log.
 * Details  : Appends the provided error message to the error log file.
 * Parameter: ErrorMessage - The error message to be written to the error log.
 */
void CSV::writeError(std::string ErrorMessage)
{
    std::ofstream fout(ErrorPath, std::ios::app);
    fout << ErrorMessage << std::endl;
    fout.close();
}


/****************************************************************
 *  END OF FILE: FileSystemManager.cpp
 ****************************************************************/
