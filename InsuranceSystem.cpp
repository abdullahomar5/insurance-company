/**
 * @file InsuranceSystem.cpp
 * @brief Implementation of the system controller logic.
 */

#include "InsuranceSystem.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructor. Loads existing data from the filesystem.
 * @param path Directory path for data files.
 */
InsuranceSystem::InsuranceSystem(const string& path) : dataPath(path) {
    initMockWorkshops();
    customers = FileManager::loadCustomers(dataPath + "customers.txt");
    claims = FileManager::loadClaims(dataPath + "claims.txt");
}

/**
 * @brief Destructor. Ensures all data is saved before the object is destroyed.
 */
InsuranceSystem::~InsuranceSystem() {
    saveData();
}

/**
 * @brief Seeds the system with initial workshops.
 */
void InsuranceSystem::initMockWorkshops() {
    registeredWorkshops.push_back(Workshop("W1", "AutoCare Hub", "Downtown", true));
    registeredWorkshops.push_back(Workshop("W2", "Speedy Repairs", "Uptown", true));
}

/**
 * @brief Persists customers and claims to text files.
 */
void InsuranceSystem::saveData() {
    FileManager::saveCustomers(dataPath + "customers.txt", customers);
    FileManager::saveClaims(dataPath + "claims.txt", claims);
}

/**
 * @brief Registers a customer and immediately marks them as subscribed.
 */
void InsuranceSystem::registerCustomer(const string& id, const string& name, const string& contact, const string& password) {
    customers.push_back(Customer(id, name, contact, password, true));
    saveData();
}

/**
 * @brief Handles new customer sign-ups. Checks for unique ID.
 */
bool InsuranceSystem::signUpCustomer(const string& id, const string& name, const string& contact, const string& password) {
    for (const auto& c : customers) {
        if (c.getCustomerId() == id) return false;
    }
    customers.push_back(Customer(id, name, contact, password, true));
    saveData();
    return true;
}

/**
 * @brief Validates customer login credentials.
 */
Customer* InsuranceSystem::signInCustomer(const string& id, const string& password) {
    for (auto& c : customers) {
        if (c.getCustomerId() == id && c.getPassword() == password) {
            return &c;
        }
    }
    return nullptr;
}

/**
 * @brief Verifies if a workshop is in the registered list.
 */
bool InsuranceSystem::isWorkshopRegistered(const string& workshopId) {
    for (const auto& w : registeredWorkshops) {
        if (w.workshopId == workshopId && w.isRegistered) return true;
    }
    return false;
}

/**
 * @brief Processes a new claim submission with validation.
 * 
 * Validation checks:
 * 1. Customer must exist and be subscribed.
 * 2. Workshop must be registered.
 */
bool InsuranceSystem::submitClaim(const string& customerId, const string& claimId, const string& policyId, const string& workshopId, double amount) {
    bool eligible = false;
    for (const auto& c : customers) {
        if (c.getCustomerId() == customerId && c.getIsSubscribed()) {
            eligible = true;
            break;
        }
    }

    if (!eligible) {
        cout << "-> ERROR: Customer is not subscribed to insurance!\n";
        return false;
    }

    if (!isWorkshopRegistered(workshopId)) {
        cout << "-> ERROR: Workshop is not registered!\n";
        return false;
    }

    claims.push_back(Claim(claimId, policyId, workshopId, amount, "PENDING"));
    saveData();
    return true;
}

/**
 * @brief Updates a claim with surveyor's findings.
 */
void InsuranceSystem::addSurveyorReport(const string& claimId, double estimate, const string& recommendation) {
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
 * @brief Sets claim status to APPROVED.
 */
void InsuranceSystem::approveClaim(const string& claimId) {
    for (auto& c : claims) {
        if (c.claimId == claimId) {
            c.status = "APPROVED";
            saveData();
            return;
        }
    }
}

/**
 * @brief Sets claim status to REJECTED.
 */
void InsuranceSystem::rejectClaim(const string& claimId) {
    for (auto& c : claims) {
        if (c.claimId == claimId) {
            c.status = "REJECTED";
            saveData();
            return;
        }
    }
}