/**
 * @file Staff.h
 * @brief Defines the Staff class, representing employees in the insurance system.
 */

#pragma once
#include "Person.h"
#include <string>

using namespace std;

/**
 * @class Staff
 * @brief Represents a staff member, inheriting from Person with additional role and ID information.
 */
class Staff : public Person {
protected:
    string staffId; ///< Unique identifier for the staff member
    string role;    ///< Role of the staff member (e.g., MANAGER, SURVEYOR, SALESMAN)

public:
    /**
     * @brief Constructor for Staff.
     * @param id Staff ID.
     * @param n Name of the staff member.
     * @param r Role of the staff member.
     */
    Staff(string id = "", string n = "", string r = "")
        : Person(n, ""), staffId(id), role(r) {
    }

    /**
     * @brief Gets the staff member's ID.
     * @return Staff ID string.
     */
    string getStaffId() const { return staffId; }

    /**
     * @brief Gets the staff member's role.
     * @return Role string.
     */
    string getRole() const { return role; }
};