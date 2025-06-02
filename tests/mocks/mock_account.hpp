#ifndef MOCK_ACCOUNT_HPP
#define MOCK_ACCOUNT_HPP

#include "account.hpp"
#include <gmock/gmock.h>

class MockAccount : public Account {
public:
    MOCK_METHOD(int, GetBalance, (), (const, override));
    MOCK_METHOD(void, ChangeBalance, (int), (override));
    MOCK_METHOD(void, Lock, (), (override));
    MOCK_METHOD(void, Unlock, (), (override));
};

#endif
