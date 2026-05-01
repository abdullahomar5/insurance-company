/**
 * @file Models.h
 * @brief Collection of data structures (structs) used throughout the Automobile Insurance System.
 * This file serves as a central location for simplified model definitions.
 */

#pragma once
#include <string>
#include <vector>

using namespace std;

/**
 * @struct Vehicle
 * @brief Represents vehicle information.
 */
struct Vehicle {
    string regNumber; ///< Registration or plate number
    string model;     ///< Vehicle model
    int year;         ///< Year of manufacture
};

/**
 * @struct InsurancePolicy
 * @brief Represents an insurance policy.
 */
struct InsurancePolicy {
    string policyId;    ///< Unique policy ID
    string customerId;  ///< ID of the associated customer
    string vehicleReg;  ///< Registered vehicle number
    double premium;     ///< Policy premium amount
};

/**
 * @struct Customer
 * @brief Represents customer data for storage and logic processing.
 */
struct Customer {
    string customerId;  ///< Unique customer ID
    string name;        ///< Customer name
    string contact;     ///< Contact details
    string password;    ///< Login password
    bool isSubscribed = false; ///< Subscription status
};

/**
 * @struct Claim
 * @brief Represents an insurance claim record.
 */
struct Claim {
    string claimId;     ///< Unique claim ID
    string policyId;    ///< Associated policy ID
    string workshopId;  ///< Associated workshop ID
    double amount;      ///< Claimed amount
    string status;      ///< Current status (PENDING, APPROVED, REJECTED)

    double surveyorEstimate = 0.0;        ///< Estimate provided by the surveyor
    string surveyorRecommendation = "NONE"; ///< Recommendation from surveyor
    bool isSurveyed = false;               ///< Has the claim been surveyed?
};

/**
 * @struct InspectionReport
 * @brief Represents a report generated after inspecting a vehicle claim.
 */
struct InspectionReport {
    string reportId;       ///< Unique report ID
    string claimId;        ///< Associated claim ID
    string surveyorId;     ///< ID of the surveyor who conducted the inspection
    string description;    ///< Detailed inspection findings
    double estimatedCost;  ///< Estimated repair cost
    bool isTotalLoss;      ///< Flag if the vehicle is considered a total loss
};

/**
 * @struct Staff
 * @brief Represents a staff member record.
 */
struct Staff {
    string staffId; ///< Unique staff ID
    string name;    ///< Staff name
    string role;    ///< Role (MANAGER, SURVEYOR, etc.)
};

/**
 * @struct Workshop
 * @brief Represents a vehicle repair workshop.
 */
struct Workshop {
    string workshopId; ///< Unique workshop ID
    string name;       ///< Workshop name
    string location;   ///< Workshop location
    bool isRegistered; ///< Is the workshop registered with the system?
};