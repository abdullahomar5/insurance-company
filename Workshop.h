/**
 * @file Workshop.h
 * @brief Defines the Workshop class, representing a repair center in the system.
 */

#pragma once
#include <string>

using namespace std;

/**
 * @class Workshop
 * @brief Represents a registered workshop that can perform repairs for insurance claims.
 */
class Workshop {
public:
    string workshopId; ///< Unique identifier for the workshop
    string name;       ///< Name of the workshop
    string location;   ///< Physical location of the workshop
    bool isRegistered; ///< Flag indicating if the workshop is officially registered with the insurance provider

    /**
     * @brief Constructor for Workshop.
     * @param id Workshop ID.
     * @param n Name.
     * @param loc Location.
     * @param reg Registration status.
     */
    Workshop(string id = "", string n = "", string loc = "", bool reg = false);
};