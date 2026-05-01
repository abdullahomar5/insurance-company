/**
 * @file InsuranceSystem.h
 * @brief Controller class for the Automobile Insurance Information System.
 */

#pragma once
#include "Customer.h"
#include "Claim.h"
#include "Workshop.h"
#include "FileManager.h"
#include <vector>
#include <string>

using namespace std;

/**
 * @class InsuranceSystem
 * @brief Manages the overall system logic, including user authentication, claim submission, and data persistence.
 */
class InsuranceSystem {
private:
    vector<Customer> customers;             ///< List of all registered customers
    vector<Claim> claims;                   ///< List of all submitted insurance claims
    vector<Workshop> registeredWorkshops;   ///< List of officially registered workshops
    string dataPath;                        ///< Directory path for data storage

    /**
     * @brief Initializes a mock list of registered workshops for demonstration.
     */
    void initMockWorkshops();

public:
    /**
     * @brief Constructor for InsuranceSystem.
     * @param path Path to the directory where data files are stored.
     */
    InsuranceSystem(const string& path);

    /**
     * @brief Destructor. Automatically saves data to files upon exit.
     */
    ~InsuranceSystem();

    /**
     * @brief Manually triggers saving of all system data.
     */
    void saveData();

    /**
     * @brief Registers a new customer into the system (used by Manager/Salesman).
     */
    void registerCustomer(const string& id, const string& name, const string& contact, const string& password);

    /**
     * @brief Handles customer self-registration/sign-up.
     * @return True if successful, false if ID already exists.
     */
    bool signUpCustomer(const string& id, const string& name, const string& contact, const string& password);

    /**
     * @brief Authenticates a customer.
     * @return Pointer to the Customer object if successful, nullptr otherwise.
     */
    Customer* signInCustomer(const string& id, const string& password);

    /**
     * @brief Checks if a workshop ID is valid and registered.
     */
    bool isWorkshopRegistered(const string& workshopId);

    /**
     * @brief Submits a new insurance claim.
     * @return True if claim is valid and submitted, false otherwise.
     */
    bool submitClaim(const string& customerId, const string& claimId, const string& policyId, const string& workshopId, double amount);

    /**
     * @brief Adds a surveyor's inspection report to an existing claim.
     */
    void addSurveyorReport(const string& claimId, double estimate, const string& recommendation);

    /**
     * @brief Approves a claim (Manager action).
     */
    void approveClaim(const string& claimId);

    /**
     * @brief Rejects a claim (Manager action).
     */
    void rejectClaim(const string& claimId);

    /**
     * @brief Gets the list of customers.
     */
    vector<Customer> getCustomers() const { return customers; }

    /**
     * @brief Gets the list of claims.
     */
    vector<Claim> getClaims() const { return claims; }
};