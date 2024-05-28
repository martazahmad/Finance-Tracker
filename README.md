# Finance Tracker

Finance Tracker is a console-based application designed to help users manage their financial transactions. It allows users to add, display, and analyze transactions based on various criteria, such as category and persons involved. The application also provides functionality to export reports to text files.

## Table of Contents

- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
  - [Adding a Transaction](#adding-a-transaction)
  - [Displaying Transactions](#displaying-transactions)
  - [Analyzing Spending](#analyzing-spending)
  - [Analyzing Spending by Category](#analyzing-spending-by-category)
  - [Analyzing Spending by Person](#analyzing-spending-by-person)
  - [Exporting Reports](#exporting-reports)
- [File Structure](#file-structure)
- [Classes](#classes)
  - [Transaction](#transaction)
  - [FinanceTracker](#financetracker)
- [License](#license)
- [Contributing](#contributing)
- [Contact](#contact)

## Features

- **Add Transactions**: Add income or expense transactions with details such as type, category, amount, description, and persons involved.
- **Display Transactions**: View all recorded transactions.
- **Analyze Spending**: Analyze total income and expenses.
- **Analyze Spending by Category**: Analyze expenses based on categories.
- **Analyze Spending by Person**: Analyze expenses based on persons involved in the transactions.
- **Export Reports**: Export various reports to text files.

## Installation

1. **Clone the repository**:
    ```bash
    git clone https://github.com/martazahmad/Finance-Tracker.git
    cd financetracker
    ```

2. **Compile the code**:
    Ensure you have a C++ compiler installed. Compile the code using the following command:
    ```bash
    g++ FinanceTracker.cpp -o FinanceTracker
    ```

3. **Run the application**:
    ```bash
    ./FinanceTracker
    ```

## Usage

1. **Adding a Transaction**:
    - Select "Add Transaction" from the menu.
    - Enter the required details such as type (income/expense), category, amount, description, and number of persons involved.
    - If multiple persons are involved, you will be prompted to enter their names and the amount each person is responsible for.

2. **Displaying Transactions**:
    - Select "Display all Transactions" from the menu to view all recorded transactions.
    - Optionally, export the transactions to a text file.

3. **Analyzing Spending**:
    - Select "Analyse Spending" to view the total income and expenses.
    - Optionally, export the report to a text file.

4. **Analyzing Spending by Category**:
    - Select "Analyze Spending by Category" to view expenses based on categories.
    - Optionally, export the report to a text file.

5. **Analyzing Spending by Person**:
    - Select "Analyze Spending by Person" to view expenses based on persons involved.
    - Optionally, export the report to a text file.

6. **Exporting Reports**:
    - You can export various reports (spending, category spending, person spending, and all transactions) to text files by selecting the appropriate option from the menu.

## File Structure

The project consists of the following files:
finance-tracker/
│
├── FinanceTracker.h       # Header file containing the class definitions
├── main.cpp               # Main program file
├── transactions.txt       # File to store transactions
├── README.md              # Project documentation


## Classes

### Transaction

Represents a financial transaction.

- **Attributes**:
  - `type`: The type of transaction (income/expense).
  - `category`: The category of the transaction.
  - `amount`: The amount of the transaction.
  - `description`: A description of the transaction.
  - `persons`: Number of persons involved in the transaction.
  - `personNames`: Names of the persons involved.
  - `personAmounts`: Amount each person is responsible for.

- **Methods**:
  - `toString()`: Converts the transaction to a string format for saving to a file.
  - `fromString()`: Converts a string to a `Transaction` object for loading from a file.

### FinanceTracker

Manages multiple transactions.

- **Attributes**:
  - `transactions`: A vector of `Transaction` objects.

- **Methods**:
  - `addTransaction()`: Adds a new transaction.
  - `displayTransactions()`: Displays all transactions.
  - `analyzeSpending()`: Analyzes total income and expenses.
  - `analyzeSpendingCategory()`: Analyzes expenses based on categories.
  - `analyzeSpendingPerson()`: Analyzes expenses based on persons involved.
  - `exportSpendingReport()`: Exports the spending report to a text file.
  - `exportSpendingCategoryReport()`: Exports the category spending report to a text file.
  - `exportSpendingPersonReport()`: Exports the person spending report to a text file.
  - `exportAllTransactionsReport()`: Exports all transactions to a text file.
  - `saveToFile()`: Saves transactions to a file.
  - `loadFromFile()`: Loads transactions from a file.

## Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.

## Contact

For any inquiries or issues, please contact [martaz.1.official@gmail.com](mailto:martaz.1.official@gmail.com).
