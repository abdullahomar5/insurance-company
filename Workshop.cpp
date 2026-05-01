/**
 * @file Workshop.cpp
 * @brief Implementation of the Workshop class.
 */

#include "Workshop.h"

using namespace std;

/**
 * @brief Constructs a new Workshop object.
 * 
 * @param id Unique Workshop ID.
 * @param n Workshop Name.
 * @param loc Workshop Location.
 * @param reg Registration status.
 */
Workshop::Workshop(string id, string n, string loc, bool reg)
    : workshopId(id), name(n), location(loc), isRegistered(reg) {
}