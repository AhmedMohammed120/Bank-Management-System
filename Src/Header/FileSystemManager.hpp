/****************************************************************
 * FILE DESCRIPTION
 ****************************************************************
 *        File     :  FileSystemManager.hpp
 *        Brief    :  Header file for file system management.
 *        Details  :  This file contains declarations for classes and functions related to managing the file system,
 *                    including reading from and writing to databases, closing databases, and writing errors to log files.
 ****************************************************************/
#ifndef FILE_SYSTEM_MANAGER_HPP
#define FILE_SYSTEM_MANAGER_HPP

/****************************************************************
 * INCLUDES
 ****************************************************************/
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Std_Types.hpp"
#include "Bank.hpp"

/****************************************************************
 *    GLOBAL DATA TYPE AND INSTRUCTIONS Union, Enum & Struct
 ****************************************************************/

/*
 * Brief    : Class for CSV file management.
 * Details  : This class provides methods for reading from and writing to CSV files, as well as managing error logs.
 */
class CSV
{
    private:
    std::string DatabasePath; // Path to the database file
    std::string ErrorPath;    // Path to the error log file
    public:
    /*
     * Brief    : Constructor for CSV class.
     * Details  : Initializes the CSV class with the paths for the database and error log files.
     * Parameter: DatabasePathCpy - Path to the database file.
     *            ErrorPathCpy - Path to the error log file.
     */
    CSV(std::string DatabasePathCpy, std::string ErrorPathCpy);

    /*
     * Brief    : Read data from the database.
     * Details  : Reads data from the database file and populates the provided bank vector with account information.
     * Parameter: Vec - Reference to the Bank object to store the account information.
     */
    void readDataBase(Bank& Vec);

    /*
     * Brief    : Write data to the database.
     * Details  : Writes account information from the provided vector to the database file.
     * Parameter: ContentVec - Vector containing account information to be written to the database.
     */
    void writeDataBase(std::vector<std::string>& ContentVec);
 
    /*
     * Brief    : Write error message to the error log.
     * Details  : Appends the provided error message to the error log file.
     * Parameter: ErrorMessage - The error message to be written to the error log.
     */
    void writeError(std::string ErrorMessage);

    /*
     * Brief    : Close the database.
     * Details  : Writes all account information from the provided Bank object to the database file and closes it.
     * Parameter: Accounts - Reference to the Bank object containing the account information to be written to the database.
     */
    void CloseDataBase(Bank& Accounts);
};

/****************************************************************
 *    GLOBAL CONSTANT MACROS
 ****************************************************************/
 
/****************************************************************
 *    GLOBAL DATA PROTOTYPES
 ****************************************************************/

#endif 

/****************************************************************
 *  END OF  FILE: FileSystemManager.hpp
 ****************************************************************/
