/**
 * @file Manager.h
 * @brief Defines the Manager class.
 */

#pragma once
#include "Staff.h"

using namespace std;

/**
 * @class Manager
 * @brief Represents a Manager who can review claims and manage system data.
 */
class Manager : public Staff {
public:
    /**
     * @brief Constructor for Manager.
     * @param id Staff ID.
     * @param n Name.
     */
    Manager(string id = "", string n = "") : Staff(id, n, "MANAGER") {}
};