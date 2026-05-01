/**
 * @file Customer.cpp
 * @brief Implementation of the Customer class.
 */

#include "Customer.h"

using namespace std;

/**
 * @brief Constructs a new Customer object.
 * Calls the base Person constructor and initializes customer-specific fields.
 * 
 * @param id Unique Customer ID.
 * @param n Name of the customer.
 * @param c Contact info.
 * @param p Password for authentication.
 * @param sub Subscription status.
 */
Customer::Customer(string id, string n, string c, string p, bool sub)
    : Person(n, c), customerId(id), password(p), isSubscribed(sub) {
}