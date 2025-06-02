#ifndef TRANSACTION_HPP
#define TRANSACTION_HPP

#include "account.hpp"

class Transaction {
public:
    Transaction();
    void set_source(Account* account);
    void set_target(Account* account);
    void set_amount(int amount);
    bool Execute();

private:
    Account* source_;
    Account* target_;
    int amount_;
};

#endif
