#include <Account.h>
#include <Transaction.h>

#include <stdexcept>

#include <gmock/gmock.h>
#include <gtest/gtest.h>

using ::testing::_;
using ::testing::InSequence;
using ::testing::Return;

class MockAccount : public Account {
 public:
  MockAccount(int id, int balance) : Account(id, balance) {}

  MOCK_CONST_METHOD0(GetBalance, int());
  MOCK_METHOD1(ChangeBalance, void(int diff));
  MOCK_METHOD0(Lock, void());
  MOCK_METHOD0(Unlock, void());
};

class MockTransaction : public Transaction {
 public:
  MOCK_METHOD3(SaveToDataBase, void(Account& from, Account& to, int sum));
};

TEST(Transaction, ConstructorSetsDefaultFee) {
  Transaction transaction;

  EXPECT_EQ(transaction.fee(), 1);
}

TEST(Transaction, SetFeeChangesFee) {
  Transaction transaction;

  transaction.set_fee(15);

  EXPECT_EQ(transaction.fee(), 15);
}

TEST(Transaction, MakeThrowsIfAccountsAreSame) {
  Account account(1, 1000);
  Transaction transaction;

  EXPECT_THROW(transaction.Make(account, account, 100), std::logic_error);
}

TEST(Transaction, MakeThrowsIfSumIsNegative) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction transaction;

  EXPECT_THROW(transaction.Make(from, to, -1), std::invalid_argument);
}

TEST(Transaction, MakeThrowsIfSumIsTooSmall) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction transaction;

  EXPECT_THROW(transaction.Make(from, to, 99), std::logic_error);
}

TEST(Transaction, MakeReturnsFalseIfFeeIsTooLarge) {
  Account from(1, 1000);
  Account to(2, 1000);
  Transaction transaction;

  transaction.set_fee(60);

  EXPECT_FALSE(transaction.Make(from, to, 100));
}

TEST(Transaction, MakeTransfersMoneyBetweenRealAccounts) {
  Account from(1, 1000);
  Account to(2, 500);
  Transaction transaction;

  transaction.set_fee(10);

  EXPECT_TRUE(transaction.Make(from, to, 100));
  EXPECT_EQ(from.GetBalance(), 890);
  EXPECT_EQ(to.GetBalance(), 600);
}

TEST(Transaction, MakeRollsBackCreditIfDebitFails) {
  Account from(1, 50);
  Account to(2, 500);
  Transaction transaction;

  transaction.set_fee(10);

  EXPECT_FALSE(transaction.Make(from, to, 100));
  EXPECT_EQ(from.GetBalance(), 50);
  EXPECT_EQ(to.GetBalance(), 500);
}

TEST(Transaction, MakeUsesMockObjectsOnSuccess) {
  MockAccount from(1, 1000);
  MockAccount to(2, 500);
  MockTransaction transaction;

  transaction.set_fee(1);

  InSequence sequence;

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());

  EXPECT_CALL(to, ChangeBalance(100));
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(1000));
  EXPECT_CALL(from, ChangeBalance(-101));

  EXPECT_CALL(transaction, SaveToDataBase(_, _, 100));

  EXPECT_CALL(to, Unlock());
  EXPECT_CALL(from, Unlock());

  EXPECT_TRUE(transaction.Make(from, to, 100));
}

TEST(Transaction, MakeUsesMockObjectsOnFailedDebit) {
  MockAccount from(1, 50);
  MockAccount to(2, 500);
  MockTransaction transaction;

  transaction.set_fee(1);

  InSequence sequence;

  EXPECT_CALL(from, Lock());
  EXPECT_CALL(to, Lock());

  EXPECT_CALL(to, ChangeBalance(100));
  EXPECT_CALL(from, GetBalance()).WillOnce(Return(50));
  EXPECT_CALL(to, ChangeBalance(-100));

  EXPECT_CALL(transaction, SaveToDataBase(_, _, 100));

  EXPECT_CALL(to, Unlock());
  EXPECT_CALL(from, Unlock());

  EXPECT_FALSE(transaction.Make(from, to, 100));
}
