#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account {
public:
    virtual int GetBalance() const = 0;
    virtual void ChangeBalance(int amount) = 0;
    virtual void Lock() = 0;
    virtual void Unlock() = 0;
    virtual ~Account() = default;
};

#endif
