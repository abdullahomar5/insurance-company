/**
 * @file Salesman.h
 * @brief Defines the Salesman class.
 */

#pragma once
#include "Staff.h"

using namespace std;

/**
 * @class Salesman
 * @brief Represents a Salesman who registers customers into the system.
 */
class Salesman : public Staff {
public:
    /**
     * @brief Constructor for Salesman.
     * @param id Staff ID.
     * @param n Name.
     */
    Salesman(string id = "", string n = "") : Staff(id, n, "SALESMAN") {}
};