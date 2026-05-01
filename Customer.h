/**
 * @file Customer.h
 * @brief Defines the Customer class, representing clients of the insurance system.
 */

#pragma once
#include "Person.h"
#include <string>

using namespace std;

/**
 * @class Customer
 * @brief Represents a customer who can hold policies and submit claims.
 */
class Customer : public Person {
private:
    string customerId; ///< Unique identifier for the customer
    string password;   ///< Login password for the customer portal
    bool isSubscribed; ///< Status indicating if the customer has an active insurance subscription

public:
    /**
     * @brief Constructor for Customer.
     * @param id Customer ID.
     * @param n Name of the customer.
     * @param c Contact info.
     * @param p Password.
     * @param sub Subscription status.
     */
    Customer(string id = "", string n = "", string c = "", string p = "", bool sub = false);

    /**
     * @brief Gets the customer's ID.
     * @return Customer ID string.
     */
    string getCustomerId() const { return customerId; }

    /**
     * @brief Gets the customer's password.
     * @return Password string.
     */
    string getPassword() const { return password; }

    /**
     * @brief Checks if the customer is subscribed.
     * @return True if subscribed, false otherwise.
     */
    bool getIsSubscribed() const { return isSubscribed; }

    /**
     * @brief Sets the customer's subscription status.
     * @param sub New subscription status.
     */
    void setSubscribed(bool sub) { isSubscribed = sub; }
};