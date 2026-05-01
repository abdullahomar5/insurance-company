/**
 * @file FileManager.cpp
 * @brief Implementation of file-based data persistence logic.
 */

#include "FileManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

/**
 * @brief Loads customers from a file.
 * Expected format: ID|Name|Contact|Password|IsSubscribed(0/1)
 * 
 * @param filename Path to the customers file.
 * @return vector<Customer> List of loaded customers.
 */
vector<Customer> FileManager::loadCustomers(const string& filename) {
    vector<Customer> customers;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "-> WARNING: Could not open " << filename << " for reading.\n";
        return customers;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        string id, name, contact, pwd, isSubscribedStr;
        
        // Parse pipe-delimited fields
        getline(ss, id, '|');
        getline(ss, name, '|');
        getline(ss, contact, '|');
        getline(ss, pwd, '|');
        getline(ss, isSubscribedStr, '|');

        if (!id.empty()) {
            customers.push_back(Customer(id, name, contact, pwd, (isSubscribedStr == "1")));
        }
    }
    file.close();
    return customers;
}

/**
 * @brief Saves customer list to a file.
 * 
 * @param filename Path to the customers file.
 * @param customers Vector of customers to persist.
 */
void FileManager::saveCustomers(const string& filename, const vector<Customer>& customers) {
    ofstream file(filename, ios::trunc);
    if (!file.is_open()) {
        cerr << "-> ERROR: Could not open " << filename << " for writing!\n";
        return;
    }
    for (const auto& c : customers) {
        file << c.getCustomerId() << "|" << c.getName() << "|" << c.getContact() << "|"
            << c.getPassword() << "|" << (c.getIsSubscribed() ? "1" : "0") << "\n";
    }
    file.flush();
    file.close();
}

/**
 * @brief Loads claims from a file.
 * Expected format: ID|PolicyID|WorkshopID|Amount|Status|SurveyorEstimate|Recommendation|IsSurveyed(0/1)
 * 
 * @param filename Path to the claims file.
 * @return vector<Claim> List of loaded claims.
 */
vector<Claim> FileManager::loadClaims(const string& filename) {
    vector<Claim> claims;
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "-> WARNING: Could not open " << filename << " for reading.\n";
        return claims;
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) continue;
        stringstream ss(line);
        Claim c;
        string amountStr, estStr, isSurveyedStr;

        // Parse pipe-delimited fields
        getline(ss, c.claimId, '|');
        getline(ss, c.policyId, '|');
        getline(ss, c.workshopId, '|');
        getline(ss, amountStr, '|');
        getline(ss, c.status, '|');
        getline(ss, estStr, '|');
        getline(ss, c.surveyorRecommendation, '|');
        getline(ss, isSurveyedStr, '|');

        if (!c.claimId.empty()) {
            try { c.amount = stod(amountStr); }
            catch (...) { c.amount = 0.0; }
            try { c.surveyorEstimate = stod(estStr); }
            catch (...) { c.surveyorEstimate = 0.0; }
            c.isSurveyed = (isSurveyedStr == "1");
            claims.push_back(c);
        }
    }
    file.close();
    return claims;
}

/**
 * @brief Saves claim list to a file.
 * 
 * @param filename Path to the claims file.
 * @param claims Vector of claims to persist.
 */
void FileManager::saveClaims(const string& filename, const vector<Claim>& claims) {
    ofstream file(filename, ios::trunc);
    if (!file.is_open()) {
        cerr << "-> ERROR: Could not open " << filename << " for writing!\n";
        return;
    }
    for (const auto& c : claims) {
        file << c.claimId << "|" << c.policyId << "|" << c.workshopId << "|"
            << c.amount << "|" << c.status << "|" << c.surveyorEstimate << "|"
            << c.surveyorRecommendation << "|" << (c.isSurveyed ? "1" : "0") << "\n";
    }
    file.flush();
    file.close();
}