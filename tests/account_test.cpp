#include <Account.h>

#include <stdexcept>

#include <gtest/gtest.h>

TEST(Account, ConstructorSetsIdAndBalance) {
  Account account(7, 500);

  EXPECT_EQ(account.id(), 7);
  EXPECT_EQ(account.GetBalance(), 500);
}

TEST(Account, ChangeBalanceThrowsIfAccountIsNotLocked) {
  Account account(1, 100);

  EXPECT_THROW(account.ChangeBalance(50), std::runtime_error);
}

TEST(Account, ChangeBalanceWorksIfAccountIsLocked) {
  Account account(1, 100);

  account.Lock();
  account.ChangeBalance(50);

  EXPECT_EQ(account.GetBalance(), 150);
}

TEST(Account, LockThrowsIfAccountAlreadyLocked) {
  Account account(1, 100);

  account.Lock();

  EXPECT_THROW(account.Lock(), std::runtime_error);
}

TEST(Account, UnlockAllowsLockAgain) {
  Account account(1, 100);

  account.Lock();
  account.Unlock();

  EXPECT_NO_THROW(account.Lock());
}
