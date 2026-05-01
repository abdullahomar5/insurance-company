/**
 * @file FileManager.h
 * @brief Defines the FileManager class for handling data persistence.
 */

#pragma once
#include "Customer.h"
#include "Claim.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @class FileManager
 * @brief Provides static methods for loading and saving system data to text files.
 */
class FileManager {
public:
    /**
     * @brief Loads customer data from a pipe-delimited text file.
     * @param filename Path to the customers file.
     * @return A vector of Customer objects.
     */
    static vector<Customer> loadCustomers(const string& filename);

    /**
     * @brief Saves customer data to a pipe-delimited text file.
     * @param filename Path to the customers file.
     * @param customers Vector of Customer objects to save.
     */
    static void saveCustomers(const string& filename, const vector<Customer>& customers);

    /**
     * @brief Loads claim data from a pipe-delimited text file.
     * @param filename Path to the claims file.
     * @return A vector of Claim objects.
     */
    static vector<Claim> loadClaims(const string& filename);

    /**
     * @brief Saves claim data to a pipe-delimited text file.
     * @param filename Path to the claims file.
     * @param claims Vector of Claim objects to save.
     */
    static void saveClaims(const string& filename, const vector<Claim>& claims);
};