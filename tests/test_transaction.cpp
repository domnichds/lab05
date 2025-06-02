#include "transaction.hpp"
#include "mocks/mock_account.hpp"
#include <gtest/gtest.h>

using ::testing::_;

TEST(TransactionTest, ExecuteSuccess) {
    MockAccount source, target;
    Transaction transaction;
    
    EXPECT_CALL(source, Lock());
    EXPECT_CALL(source, ChangeBalance(-100));
    EXPECT_CALL(source, Unlock());
    
    EXPECT_CALL(target, Lock());
    EXPECT_CALL(target, ChangeBalance(100));
    EXPECT_CALL(target, Unlock());
    
    transaction.set_source(&source);
    transaction.set_target(&target);
    transaction.set_amount(100);
    
    ASSERT_TRUE(transaction.Execute());
}
