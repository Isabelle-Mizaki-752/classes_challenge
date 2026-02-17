# Bank Account Class (example)

A C++ class for representing a Bank Account in a Bank system

## Data Dictionary

| Attribute           | Data Type     | Description
|---------------------|---------------|
| 'accountNumber'     | 'std::string' | The bank account's ID number.                                                                |
| 'accountHolderName' | 'std::string' | The name of the bank account's holder.                                                       |
| 'balance'           | 'double'      | The amount of money on the bank account.                                                     |
| 'IDnumber'          | 'int'         | the temporary holder for the ID number.                                                      |
| 'temptotal'         | 'double'      | The temporary holder for the balance to make sure withdrawing won't put one below 0 dollars. |

## Methods List

| Method Signature                                  | Return Type   | Description
|                                                   |               |
|---------------------------------------------------|---------------|---------------
|                                                   |               |
| 'BankAccount()'                                   | (Constructor) | Default constructor.
|                                                   |               |
| 'BankAccount(std::string AccountName)'            | (Constructor) | Paramatarized Constructor.
|                                                   |               |
| 'SetAccountHolderName(std::string accountholder)' | 'void'        | Sets the bank account holder's name.    |
|                                                   |               |                                         |
| 'GetAccountHolderName() const'                    | 'std::string' | Gets the bank account's holder's name.  |
|                                                   |               |
| 'GetAccountNumber() const'                        | 'std::string' | Gets the bank account's id.
|                                                   |               |
| 'GetBalance() const'                              | 'double'      | Gets the bank account's balance.
|                                                   |               |
| 'deposit(double& amount)'                         | 'void'        | Deposits money into the bank account
|                                                   |               |
| 'withdraw(double& amount)'                        | 'void'        | Withdraws money from the bank account
|                                                   |               |
