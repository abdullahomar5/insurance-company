/**
 * @file Claim.cpp
 * @brief Implementation of the Claim class.
 */

#include "Claim.h"

using namespace std;

/**
 * @brief Constructs a new Claim object with specified details.
 * Initializes surveyor data to default empty/zero values.
 * 
 * @param cId Unique Claim ID.
 * @param pId Associated Policy ID.
 * @param wId Target Workshop ID.
 * @param amt Claim amount requested.
 * @param st Initial status (defaults to PENDING).
 */
Claim::Claim(string cId, string pId, string wId, double amt, string st)
    : claimId(cId), policyId(pId), workshopId(wId), amount(amt), status(st),
    surveyorEstimate(0.0), surveyorRecommendation("NONE"), isSurveyed(false) {
}