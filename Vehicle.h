/**
 * @file Vehicle.h
 * @brief Defines the Vehicle struct.
 */

#pragma once
#include <string>

using namespace std;

/**
 * @struct Vehicle
 * @brief Represents a vehicle associated with an insurance policy.
 */
struct Vehicle {
    string regNumber; ///< Vehicle registration number (plate number)
    string model;     ///< Vehicle model name
    int year;         ///< Manufacturing year of the vehicle
};