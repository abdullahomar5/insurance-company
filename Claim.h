/**
 * @file Claim.h
 * @brief Defines the Claim class, representing an insurance claim submitted by a customer.
 */

#pragma once
#include <string>

using namespace std;

/**
 * @class Claim
 * @brief Represents an insurance claim with details about the policy, workshop, and status.
 */
class Claim {
public:
    string claimId;    ///< Unique identifier for the claim
    string policyId;   ///< ID of the insurance policy associated with this claim
    string workshopId; ///< ID of the workshop where the vehicle is being repaired
    double amount;     ///< Estimated repair amount claimed by the customer
    string status;     ///< Current status of the claim (e.g., PENDING, APPROVED, REJECTED)

    double surveyorEstimate;        ///< Repair cost estimated by the surveyor
    string surveyorRecommendation;  ///< Recommendation from the surveyor (e.g., APPROVE/REJECT)
    bool isSurveyed;                ///< Flag indicating if the claim has been inspected by a surveyor

    /**
     * @brief Constructor for Claim.
     * @param cId Claim ID.
     * @param pId Policy ID.
     * @param wId Workshop ID.
     * @param amt Initial amount.
     * @param st Initial status.
     */
    Claim(string cId = "", string pId = "", string wId = "", double amt = 0.0, string st = "PENDING");
};