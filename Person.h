/**
 * @file Person.h
 * @brief Defines the base Person class for all individuals in the system.
 */

#pragma once
#include <string>

using namespace std;

/**
 * @class Person
 * @brief A base class representing a generic person with a name and contact information.
 */
class Person {
protected:
    string name;    ///< Full name of the person
    string contact; ///< Contact information (phone or email)

public:
    /**
     * @brief Constructor for Person.
     * @param n Name of the person.
     * @param c Contact info of the person.
     */
    Person(string n = "", string c = "") : name(n), contact(c) {}

    /**
     * @brief Virtual destructor for proper inheritance cleanup.
     */
    virtual ~Person() {}

    /**
     * @brief Sets the person's name.
     * @param n New name.
     */
    void setName(string n) { name = n; }

    /**
     * @brief Gets the person's name.
     * @return Current name.
     */
    string getName() const { return name; }

    /**
     * @brief Sets the person's contact info.
     * @param c New contact info.
     */
    void setContact(string c) { contact = c; }

    /**
     * @brief Gets the person's contact info.
     * @return Current contact info.
     */
    string getContact() const { return contact; }
};