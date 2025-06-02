#include "account.hpp"
#include <mutex>

class AccountImpl : public Account {
public:
    int GetBalance() const override { return balance_; }
    void ChangeBalance(int amount) override { balance_ += amount; }
    void Lock() override { mutex_.lock(); }
    void Unlock() override { mutex_.unlock(); }

private:
    int balance_ = 0;
    std::mutex mutex_;
};

Account* create_account() {
    return new AccountImpl();
}
