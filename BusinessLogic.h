/**
 * @file BusinessLogic.h
 * @brief Header-only implementation of the Insurance System Logic.
 * This class provides similar functionality to InsuranceSystem but uses structs from Models.h.
 */

#pragma once
#include "Models.h"
#include "FileManager.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

/**
 * @class InsuranceSystemLogic
 * @brief Business logic layer for managing customers, claims, and workshops.
 */
class InsuranceSystemLogic {
private:
    vector<Customer> customers;             ///< Internal list of customers
    vector<Claim> claims;                   ///< Internal list of claims
    vector<Workshop> registeredWorkshops;   ///< Internal list of registered workshops
    string dataPath;                        ///< Base path for data files

    /**
     * @brief Seeds the system with initial mock workshops.
     */
    void initMockWorkshops() {
        registeredWorkshops.push_back({ "W1", "AutoCare Hub", "Downtown", true });
        registeredWorkshops.push_back({ "W2", "Speedy Repairs", "Uptown", true });
    }

public:
    /**
     * @brief Persists all current data to text files.
     */
    void saveData() {
        FileManager::saveCustomers(dataPath + "customers.txt", customers);
        FileManager::saveClaims(dataPath + "claims.txt", claims);
    }

    /**
     * @brief Constructor. Loads data and initializes workshops.
     * @param path Path to the data directory.
     */
    InsuranceSystemLogic(const string& path) : dataPath(path) {
        initMockWorkshops();
        customers = FileManager::loadCustomers(dataPath + "customers.txt");
        claims = FileManager::loadClaims(dataPath + "claims.txt");
    }

    /**
     * @brief Destructor. Ensures data is saved.
     */
    ~InsuranceSystemLogic() {
        saveData();
    }

    /**
     * @brief Registers a new customer and marks them as subscribed.
     */
    void registerCustomer(const string& id, const string& name, const string& contact, const string& password) {
        Customer c = { id, name, contact, password, true };
        customers.push_back(c);
        saveData();
    }

    /**
     * @brief Handles customer self-registration.
     * @return True if successful, false if ID already exists.
     */
    bool signUpCustomer(const string& id, const string& name, const string& contact, const string& password) {
        for (const auto& c : customers) {
            if (c.customerId == id) return false;
        }
        Customer c = { id, name, contact, password, true };
        customers.push_back(c);
        saveData();
        return true;
    }

    /**
     * @brief Authenticates customer credentials.
     * @return Pointer to Customer struct if successful, nullptr otherwise.
     */
    Customer* signInCustomer(const string& id, const string& password) {
        for (auto& c : customers) {
            if (c.customerId == id && c.password == password) {
                return &c;
            }
        }
        return nullptr;
    }

    /**
     * @brief Validates if a workshop is registered.
     */
    bool isWorkshopRegistered(const string& workshopId) {
        for (const auto& w : registeredWorkshops) {
            if (w.workshopId == workshopId && w.isRegistered) return true;
        }
        return false;
    }

    /**
     * @brief Processes a claim submission.
     * @return True if valid, false otherwise.
     */
    bool submitClaim(const string& customerId, const string& claimId, const string& policyId, const string& workshopId, double amount) {
        bool eligible = false;
        for (const auto& c : customers) {
            if (c.customerId == customerId && c.isSubscribed) {
                eligible = true;
                break;
            }
        }

        if (!eligible) {
            cout << "-> ERROR: Customer is not subscribed to insurance!\n";
            return false;
        }

        if (!isWorkshopRegistered(workshopId)) {
            return false;
        }

        Claim c = { claimId, policyId, workshopId, amount, "PENDING" };
        claims.push_back(c);
        saveData();
        return true;
    }

    /**
     * @brief Updates claim with surveyor's report.
     */
    void addSurveyorReport(const string& claimId, double estimate, const string& recommendation) {
        for (auto& c : claims) {
            if (c.claimId == claimId) {
                c.surveyorEstimate = estimate;
                c.surveyorRecommendation = recommendation;
                c.isSurveyed = true;
                saveData();
                return;
            }
        }
    }

    /**
     * @brief Approves a claim.
     */
    void approveClaim(const string& claimId) {
        for (auto& c : claims) {
            if (c.claimId == claimId) {
                c.status = "APPROVED";
                saveData();
                return;
            }
        }
    }

    /**
     * @brief Rejects a claim.
     */
    void rejectClaim(const string& claimId) {
        for (auto& c : claims) {
            if (c.claimId == claimId) {
                c.status = "REJECTED";
                saveData();
                return;
            }
        }
    }

    /**
     * @brief Returns the list of customers.
     */
    vector<Customer> getCustomers() const {
        return customers;
    }

    /**
     * @brief Returns the list of claims.
     */
    vector<Claim> getClaims() const {
        return claims;
    }
};