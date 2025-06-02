#include "transaction.hpp"

Transaction::Transaction() : source_(nullptr), target_(nullptr), amount_(0) {}

void Transaction::set_source(Account* account) { source_ = account; }
void Transaction::set_target(Account* account) { target_ = account; }
void Transaction::set_amount(int amount) { amount_ = amount; }

bool Transaction::Execute() {
    if (!source_ || !target_) return false;
    
    source_->Lock();
    target_->Lock();
    
    try {
        source_->ChangeBalance(-amount_);
        target_->ChangeBalance(amount_);
    } catch (...) {
        source_->Unlock();
        target_->Unlock();
        return false;
    }
    
    source_->Unlock();
    target_->Unlock();
    return true;
}
