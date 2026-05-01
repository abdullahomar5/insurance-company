/**
 * @file main.cpp
 * @brief Entry point for the Automobile Insurance Information System.
 * This file contains the main menu and role-based workflows (Customer, Surveyor, Manager).
 */

#include "InsuranceSystem.h"
#include <iostream>
#include <string>

/**
 * @brief Displays the top-level selection menu.
 */
void displayMainMenu() {
    std::cout << "\n============================================\n";
    std::cout << "   Automobile Insurance Information System  \n";
    std::cout << "============================================\n";
    std::cout << "Login as:\n";
    std::cout << "1. Customer\n";
    std::cout << "2. Surveyor\n";
    std::cout << "3. Manager\n";
    std::cout << "4. Exit\n";
    std::cout << "============================================\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Displays options available to a logged-in customer.
 */
void displayCustomerMenu() {
    std::cout << "\n--- Customer Menu ---\n";
    std::cout << "1. Submit Claim\n";
    std::cout << "2. Logout\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Displays options available to a surveyor.
 */
void displaySurveyorMenu() {
    std::cout << "\n--- Surveyor Menu ---\n";
    std::cout << "1. View Pending Claims\n";
    std::cout << "2. Add Inspection Report\n";
    std::cout << "3. Logout\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Displays options available to a manager.
 */
void displayManagerMenu() {
    std::cout << "\n--- Manager Menu ---\n";
    std::cout << "1. Register Customer (Salesman)\n";
    std::cout << "2. View Customers\n";
    std::cout << "3. View All Claims (with Surveyor Info)\n";
    std::cout << "4. Approve/Reject Claim\n";
    std::cout << "5. Logout\n";
    std::cout << "Enter your choice: ";
}

/**
 * @brief Main execution loop.
 */
int main() {
    // Initialize the system with the local data directory
    InsuranceSystem system("./");

    int roleChoice = 0;
    while (true) {
        displayMainMenu();
        if (!(std::cin >> roleChoice)) {
            std::cout << "Invalid input. Exiting.\n";
            break;
        }

        // --- CUSTOMER WORKFLOW ---
        if (roleChoice == 1) {
            int subChoice = 0;
            while (true) {
                std::cout << "\n--- Customer Portal ---\n";
                std::cout << "1. Sign Up (Subscribe)\n";
                std::cout << "2. Sign In\n";
                std::cout << "3. Back\n";
                std::cout << "Enter choice: ";
                if (!(std::cin >> subChoice)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }
                if (subChoice == 3) break;

                if (subChoice == 1) {
                    // Self-registration
                    std::string id, name, contact, pwd;
                    std::cout << "Enter Customer ID: "; std::cin >> id;
                    std::cin.ignore();
                    std::cout << "Enter Name: "; std::getline(std::cin, name);
                    std::cout << "Enter Contact: "; std::getline(std::cin, contact);
                    std::cout << "Enter Password: "; std::cin >> pwd;
                    if (system.signUpCustomer(id, name, contact, pwd)) {
                        std::cout << "-> Signed up successfully! You are now subscribed and eligible for claims.\n";
                    } else {
                        std::cout << "-> ERROR: ID already exists.\n";
                    }
                } else if (subChoice == 2) {
                    // Authentication
                    std::string id, pwd;
                    std::cout << "Enter ID: "; std::cin >> id;
                    std::cout << "Enter Password: "; std::cin >> pwd;
                    Customer* loggedIn = system.signInCustomer(id, pwd);
                    
                    if (loggedIn) {
                        std::cout << "\n--- Welcome " << loggedIn->getName() << " (Subscribed: " << (loggedIn->getIsSubscribed() ? "YES" : "NO") << ") ---\n";
                        
                        int choice = 0;
                        while (true) {
                            displayCustomerMenu();
                            if (!(std::cin >> choice)) {
                                std::cin.clear();
                                std::cin.ignore(10000, '\n');
                                break;
                            }

                            if (choice == 1) {
                                // Claim submission
                                std::string cId, pId, wId;
                                double amt;
                                std::cout << "Enter Claim ID: "; std::cin >> cId;
                                std::cout << "Enter Policy ID: "; std::cin >> pId;
                                std::cout << "Enter Workshop ID (Try W1 or W2): "; std::cin >> wId;
                                std::cout << "Enter Estimated Amount: "; std::cin >> amt;

                                if (system.submitClaim(loggedIn->getCustomerId(), cId, pId, wId, amt)) {
                                    std::cout << "-> Claim submitted successfully! Status is PENDING.\n";
                                } else {
                                    std::cout << "-> Claim submission failed.\n";
                                }
                            } else if (choice == 2) {
                                std::cout << "Logging out...\n";
                                break;
                            } else {
                                std::cout << "Invalid choice. Please try again.\n";
                            }
                        }
                    } else {
                        std::cout << "-> Invalid ID or password.\n";
                    }
                }
            }
        } 
        // --- SURVEYOR WORKFLOW ---
        else if (roleChoice == 2) {
            std::string password;
            std::cout << "Enter Surveyor Password (hint: surveyor): ";
            std::cin >> password;

            if (password != "surveyor") {
                std::cout << "Incorrect password!\n";
                continue;
            }

            int choice = 0;
            while (true) {
                displaySurveyorMenu();
                if (!(std::cin >> choice)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                if (choice == 1) {
                    // View claims needing survey
                    std::cout << "\n--- Pending Claims for Survey ---\n";
                    auto claims = system.getClaims();
                    for (const auto& c : claims) {
                        if (c.status == "PENDING" && !c.isSurveyed) {
                            std::cout << "Claim ID: " << c.claimId << " | Policy: " << c.policyId << " | Amount: $" << c.amount << "\n";
                        }
                    }
                } else if (choice == 2) {
                    // Add report
                    std::string cId, recommend;
                    double est;
                    std::cout << "Enter Claim ID to survey: "; std::cin >> cId;
                    std::cout << "Enter Estimated Repair Cost: "; std::cin >> est;
                    std::cout << "Recommendation (APPROVE/REJECT): "; std::cin >> recommend;
                    system.addSurveyorReport(cId, est, recommend);
                    std::cout << "-> Report added successfully!\n";
                } else if (choice == 3) {
                    std::cout << "Logging out...\n";
                    break;
                } else {
                    std::cout << "Invalid choice. Please try again.\n";
                }
            }
        } 
        // --- MANAGER WORKFLOW ---
        else if (roleChoice == 3) {
            std::string password;
            std::cout << "Enter Manager Password (hint: admin): ";
            std::cin >> password;

            if (password != "admin") {
                std::cout << "Incorrect password!\n";
                continue;
            }

            int choice = 0;
            while (true) {
                displayManagerMenu();
                if (!(std::cin >> choice)) {
                    std::cin.clear();
                    std::cin.ignore(10000, '\n');
                    break;
                }

                if (choice == 1) {
                    // Manual customer registration
                    std::string id, name, contact, pwd;
                    std::cout << "Enter Customer ID: "; std::cin >> id;
                    std::cin.ignore();
                    std::cout << "Enter Name: "; std::getline(std::cin, name);
                    std::cout << "Enter Contact: "; std::getline(std::cin, contact);
                    std::cout << "Enter Password: "; std::cin >> pwd;
                    system.registerCustomer(id, name, contact, pwd);
                    std::cout << "-> Customer successfully registered and subscribed!\n";

                } else if (choice == 2) {
                    // List customers
                    std::cout << "\n--- Registered Customers ---\n";
                    auto customers = system.getCustomers();
                    for (const auto& c : customers) {
                        std::cout << "ID: " << c.getCustomerId() << " | Name: " << c.getName() << " | Contact: " << c.getContact() << " | Subscribed: " << (c.getIsSubscribed() ? "YES" : "NO") << "\n";
                    }

                } else if (choice == 3) {
                    // List all claims
                    std::cout << "\n--- All Claims ---\n";
                    auto claims = system.getClaims();
                    for (const auto& c : claims) {
                        std::cout << "Claim ID: " << c.claimId << " | Policy: " << c.policyId 
                             << " | Amount: $" << c.amount << " | Status: " << c.status << "\n";
                        if (c.isSurveyed) {
                            std::cout << "   [Surveyor] Estimate: $" << c.surveyorEstimate 
                                 << " | Recommendation: " << c.surveyorRecommendation << "\n";
                        } else {
                            std::cout << "   [Surveyor] NOT YET SURVEYED\n";
                        }
                    }

                } else if (choice == 4) {
                    // Claim approval/rejection
                    std::string cId, decision;
                    std::cout << "Enter Claim ID to review: "; std::cin >> cId;
                    
                    auto claims = system.getClaims();
                    for(const auto& c : claims) {
                        if(c.claimId == cId) {
                            if(c.isSurveyed) {
                                std::cout << "-> Surveyor Recommendation: " << c.surveyorRecommendation << "\n";
                                std::cout << "-> Surveyor Estimate: $" << c.surveyorEstimate << "\n";
                            } else {
                                std::cout << "-> WARNING: This claim has not been surveyed yet!\n";
                            }
                            break;
                        }
                    }

                    std::cout << "Approve or Reject? (A/R): "; std::cin >> decision;

                    if (decision == "A" || decision == "a") {
                        system.approveClaim(cId);
                        std::cout << "-> Claim Approved.\n";
                    } else if (decision == "R" || decision == "r") {
                        system.rejectClaim(cId);
                        std::cout << "-> Claim Rejected.\n";
                    } else {
                        std::cout << "-> Invalid decision.\n";
                    }

                } else if (choice == 5) {
                    std::cout << "Logging out...\n";
                    break;
                } else {
                    std::cout << "Invalid choice. Please try again.\n";
                }
            }
        } else if (roleChoice == 4) {
            std::cout << "Saving data and exiting...\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
