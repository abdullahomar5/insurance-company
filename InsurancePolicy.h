/**
 * @file InsurancePolicy.h
 * @brief Defines the InsurancePolicy struct.
 */

#pragma once
#include <string>

using namespace std;

/**
 * @struct InsurancePolicy
 * @brief Represents an insurance policy held by a customer for a specific vehicle.
 */
struct InsurancePolicy {
    string policyId;    ///< Unique identifier for the insurance policy
    string customerId;  ///< ID of the customer who owns the policy
    string vehicleReg;  ///< Registration number of the vehicle covered by the policy
    double premium;     ///< The annual premium amount for the policy
};