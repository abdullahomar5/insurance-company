/**
 * @file Surveyor.h
 * @brief Defines the Surveyor class.
 */

#pragma once
#include "Staff.h"

using namespace std;

/**
 * @class Surveyor
 * @brief Represents a Surveyor who inspects vehicles and provides repair estimates.
 */
class Surveyor : public Staff {
public:
    /**
     * @brief Constructor for Surveyor.
     * @param id Staff ID.
     * @param n Name.
     */
    Surveyor(string id = "", string n = "") : Staff(id, n, "SURVEYOR") {}
};