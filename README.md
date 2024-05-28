# Finance Tracker

Welcome to the Finance Tracker application! This application helps you track your financial transactions, analyze your spending habits, and generate reports based on your transactions.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Class Descriptions](#class-descriptions)
  - [Transaction](#transaction)
  - [FinanceTracker](#financetracker)
- [Functions](#functions)
  - [FinanceTracker Class Functions](#financetracker-class-functions)
- [File Structure](#file-structure)
- [Contributing](#contributing)
- [License](#license)

## Features

- Add transactions (income or expense)
- Display all transactions
- Analyze spending overall
- Analyze spending by category
- Analyze spending by person
- Export reports in text format

## Installation

To run this project, you need to have a C++ compiler installed on your system. Follow these steps to get started:

1. Clone the repository:

git clone https://github.com/your-username/finance-tracker.git

2. Navigate to the project directory:
   
cd finance-tracker

3. Compile the project:

g++ -o finance_tracker main.cpp FinanceTracker.h

4. Run the executable:

./finance_tracker

## Usage

Upon running the application, you will be presented with a menu to choose from various operations. Here's a brief overview:

1. Add Transaction: Add a new transaction specifying type (income/expense), category, amount, description, and persons involved.
2. Display all Transactions: View all transactions entered so far.
3. Analyze Spending: View total income and expenses.
4. Analyze Spending by Category: View total expenses categorized by the category.
5. Analyze Spending by Person: View total expenses categorized by person.
6. Export Spending Report: Export a report of total income and expenses to a text file.
7. Export Category Spending Report: Export a report of expenses categorized by category to a text file.
8. Export Person Spending Report: Export a report of expenses categorized by person to a text file.
9. Export All Transactions Report: Export all transactions to a text file.

## Class Descriptions

**Transaction**
This class represents a financial transaction. It has the following attributes:

**type:** The type of transaction (income or expense)
**category:** The category of the transaction (only for expenses)
**amount:** The amount of the transaction
**description:** A brief description of the transaction
**persons:** The number of persons involved in the transaction
**personNames:** A vector of names of the persons involved
**personAmounts:** A map of amounts attributed to each person involved

**FinanceTracker**
This class manages all the transactions and provides functionality to add transactions, analyze spending, and export reports. It has the following attributes and methods:

**Attributes:**

**transactions:** A vector of Transaction objects

**Methods:**

**addTransaction:** Adds a new transaction
**displayTransactions:** Displays all transactions
**analyzeSpending:** Analyzes and displays total income and expenses
**analyzeSpendingCategory:** Analyzes and displays expenses by category
**analyzeSpendingPerson:** Analyzes and displays expenses by person
**exportSpendingReport:** Exports total income and expenses to a file
**exportSpendingCategoryReport:** Exports expenses by category to a file
**exportSpendingPersonReport:** Exports expenses by person to a file
**exportAllTransactionsReport:** Exports all transactions to a file
**saveToFile:** Saves all transactions to a file
**loadFromFile:** Loads transactions from a file

## File Structure

The project consists of the following files:
finance-tracker/
│
├── FinanceTracker.h       # Header file containing the class definitions
├── main.cpp               # Main program file
├── transactions.txt       # File to store transactions
├── README.md              # Project documentation
