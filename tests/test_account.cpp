#include "account.hpp"
#include "mocks/mock_account.hpp"
#include <gtest/gtest.h>

TEST(AccountTest, GetBalance) {
    MockAccount account;
    EXPECT_CALL(account, GetBalance()).WillOnce(::testing::Return(100));
    ASSERT_EQ(account.GetBalance(), 100);
}
