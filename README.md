# 🚗 Automobile Insurance Information System

### ✍️ Authors & Group Members
*   **Abdullah Omar** (24L-0576)
*   **Zoha Sarwar** (24L-0536)

---

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![macOS](https://img.shields.io/badge/mac%20os-000000?style=for-the-badge&logo=macos&logoColor=F0F0F0)

> A console-based C++ application designed to manage and streamline automobile insurance operations with role-based workflows and file-based persistence.

## 📋 Table of Contents
- [Overview](#-overview)
- [Features](#-features)
- [Architecture & Design](#-architecture--design)
- [Getting Started](#-getting-started)
- [Usage & Login Details](#-usage--login-details)
- [Documentation](#-documentation)

---

## 📖 Overview
The **Automobile Insurance Information System** is a robust C++ system built to handle day-to-day automobile insurance operations. It provides role-based portals for **Customers**, **Surveyors**, and **Managers**, enabling seamless interaction with the insurance workflow. It features a reliable file-based data persistence layer to securely store customer and claim data across sessions without relying on external databases.

---

## ✨ Features

### 🔐 Role-Based Access Control
The application provides distinct portals tailored to different stakeholders:

#### 🧑‍💻 Customer Portal
*   **Self-Registration:** Sign up and subscribe to the insurance service.
*   **Secure Authentication:** Log in securely using user credentials.
*   **Claim Submission:** File new insurance claims, specifying policy and preferred workshop details.

#### 🕵️‍♂️ Surveyor Portal
*   **Claim Assignment:** View a list of pending claims needing inspection.
*   **Inspection Reports:** Submit detailed surveys, including estimated repair costs and recommendations (Approve/Reject).

#### 👔 Manager Portal
*   **Manual Registration:** Register new customers acting as a Salesman.
*   **Directory Management:** View all registered customers and their subscription statuses.
*   **Claim Review:** Review all claims alongside Surveyor inspection reports.
*   **Final Decision:** Approve or reject claims based on estimates and recommendations.

### 💾 Data Persistence
The system uses efficient local text files (e.g., `customers.txt.txt`, `claims.txt.txt`) to persist all records. Changes made during a session are instantly saved to disk, ensuring zero data loss and maintaining application state between executions.

---

## 🏗 Architecture & Design
The system is built applying clean **Object-Oriented Programming (OOP)** principles in C++, promoting a modular and maintainable codebase.

*   **Models:** Core entities such as `Customer`, `Claim`, `Workshop`, `Surveyor`, and `Manager`.
*   **Business Logic:** Handles the processing workflows of claims and customer operations.
*   **File Manager:** Manages file I/O operations seamlessly.
*   **Insurance System:** The central orchestrator coupling the console UI, business logic, and file management.

---

## 🚀 Getting Started

### Prerequisites
*   A standard C++ compiler (e.g., GCC, MSVC, Clang).
*   Windows / Linux / macOS environment.

### Compilation
To compile the project using standard C++ compilers (like `g++`):

```bash
g++ *.cpp -o AutoInsuranceSystem
```

### Running the Application
Execute the compiled binary to start the application:

**Linux/macOS:**
```bash
./AutoInsuranceSystem
```

**Windows:**
```bash
AutoInsuranceSystem.exe
```

---

## 🖥 Usage & Login Details
Upon starting the application, you'll be greeted with the main menu to select your role:

1.  **Customer**: Create an account or sign in with your custom credentials.
2.  **Surveyor**: Use the default password `surveyor` to access the surveyor portal.
3.  **Manager**: Use the default password `admin` to access the manager portal.

---

## 📚 Documentation
We have provided system architecture and user interaction diagrams in the repository:
*   [UML Diagram](UML_24L-0536_24L-0576.drawio.png)
*   [Use Case Diagram](UseCase_24L-0536_24L-0576.drawio.png)
