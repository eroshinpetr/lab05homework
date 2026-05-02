[![Coverage Status](https://coveralls.io/repos/github/eroshinpetr/lab05homework/badge.svg?branch=main)](https://coveralls.io/github/eroshinpetr/lab05homework?branch=main)
```sh
Running tests...
UpdateCTestConfiguration  from :/home/vboxuser/workspace/projects/lab05/_build/DartConfiguration.tcl
UpdateCTestConfiguration  from :/home/vboxuser/workspace/projects/lab05/_build/DartConfiguration.tcl
Test project /home/vboxuser/workspace/projects/lab05/_build
Constructing a list of tests
Done constructing a list of tests
Updating test list for fixtures
Added 0 tests to meet fixture requirements
Checking test dependency graph...
Checking test dependency graph end
test 1
    Start 1: check

1: Test command: /home/vboxuser/workspace/projects/lab05/_build/check
1: Working Directory: /home/vboxuser/workspace/projects/lab05/_build
1: Test timeout computed to be: 10000000
1: Running main() from gmock_main.cc
1: [==========] Running 15 tests from 2 test cases.
1: [----------] Global test environment set-up.
1: [----------] 5 tests from Account
1: [ RUN      ] Account.ConstructorSetsIdAndBalance
1: [       OK ] Account.ConstructorSetsIdAndBalance (0 ms)
1: [ RUN      ] Account.ChangeBalanceThrowsIfAccountIsNotLocked
1: [       OK ] Account.ChangeBalanceThrowsIfAccountIsNotLocked (0 ms)
1: [ RUN      ] Account.ChangeBalanceWorksIfAccountIsLocked
1: [       OK ] Account.ChangeBalanceWorksIfAccountIsLocked (0 ms)
1: [ RUN      ] Account.LockThrowsIfAccountAlreadyLocked
1: [       OK ] Account.LockThrowsIfAccountAlreadyLocked (0 ms)
1: [ RUN      ] Account.UnlockAllowsLockAgain
1: [       OK ] Account.UnlockAllowsLockAgain (0 ms)
1: [----------] 5 tests from Account (0 ms total)
1: 
1: [----------] 10 tests from Transaction
1: [ RUN      ] Transaction.ConstructorSetsDefaultFee
1: [       OK ] Transaction.ConstructorSetsDefaultFee (0 ms)
1: [ RUN      ] Transaction.SetFeeChangesFee
1: [       OK ] Transaction.SetFeeChangesFee (0 ms)
1: [ RUN      ] Transaction.MakeThrowsIfAccountsAreSame
1: [       OK ] Transaction.MakeThrowsIfAccountsAreSame (0 ms)
1: [ RUN      ] Transaction.MakeThrowsIfSumIsNegative
1: [       OK ] Transaction.MakeThrowsIfSumIsNegative (0 ms)
1: [ RUN      ] Transaction.MakeThrowsIfSumIsTooSmall
1: [       OK ] Transaction.MakeThrowsIfSumIsTooSmall (0 ms)
1: [ RUN      ] Transaction.MakeReturnsFalseIfFeeIsTooLarge
1: [       OK ] Transaction.MakeReturnsFalseIfFeeIsTooLarge (0 ms)
1: [ RUN      ] Transaction.MakeTransfersMoneyBetweenRealAccounts
1: 1 send to 2 $100
1: Balance 1 is 890
1: Balance 2 is 600
1: [       OK ] Transaction.MakeTransfersMoneyBetweenRealAccounts (0 ms)
1: [ RUN      ] Transaction.MakeRollsBackCreditIfDebitFails
1: 1 send to 2 $100
1: Balance 1 is 50
1: Balance 2 is 500
1: [       OK ] Transaction.MakeRollsBackCreditIfDebitFails (0 ms)
1: [ RUN      ] Transaction.MakeUsesMockObjectsOnSuccess
1: [       OK ] Transaction.MakeUsesMockObjectsOnSuccess (0 ms)
1: [ RUN      ] Transaction.MakeUsesMockObjectsOnFailedDebit
1: [       OK ] Transaction.MakeUsesMockObjectsOnFailedDebit (0 ms)
1: [----------] 10 tests from Transaction (1 ms total)
1: 
1: [----------] Global test environment tear-down
1: [==========] 15 tests from 2 test cases ran. (1 ms total)
1: [  PASSED  ] 15 tests.
1/1 Test #1: check ............................   Passed    0.00 sec

100% tests passed, 0 tests failed out of 1

Total Test time (real) =   0.00 sec
Running main() from gmock_main.cc
[==========] Running 15 tests from 2 test cases.
[----------] Global test environment set-up.
[----------] 5 tests from Account
[ RUN      ] Account.ConstructorSetsIdAndBalance
[       OK ] Account.ConstructorSetsIdAndBalance (0 ms)
[ RUN      ] Account.ChangeBalanceThrowsIfAccountIsNotLocked
[       OK ] Account.ChangeBalanceThrowsIfAccountIsNotLocked (0 ms)
[ RUN      ] Account.ChangeBalanceWorksIfAccountIsLocked
[       OK ] Account.ChangeBalanceWorksIfAccountIsLocked (0 ms)
[ RUN      ] Account.LockThrowsIfAccountAlreadyLocked
[       OK ] Account.LockThrowsIfAccountAlreadyLocked (0 ms)
[ RUN      ] Account.UnlockAllowsLockAgain
[       OK ] Account.UnlockAllowsLockAgain (0 ms)
[----------] 5 tests from Account (0 ms total)

[----------] 10 tests from Transaction
[ RUN      ] Transaction.ConstructorSetsDefaultFee
[
OK ] Transaction.ConstructorSetsDefaultFee (0 ms)
[ RUN      ] Transaction.SetFeeChangesFee
[       OK ] Transaction.SetFeeChangesFee (0 ms)
[ RUN      ] Transaction.MakeThrowsIfAccountsAreSame
[       OK ] Transaction.MakeThrowsIfAccountsAreSame (0 ms)
[ RUN      ] Transaction.MakeThrowsIfSumIsNegative
[       OK ] Transaction.MakeThrowsIfSumIsNegative (0 ms)
[ RUN      ] Transaction.MakeThrowsIfSumIsTooSmall
[       OK ] Transaction.MakeThrowsIfSumIsTooSmall (0 ms)
[ RUN      ] Transaction.MakeReturnsFalseIfFeeIsTooLarge
[       OK ] Transaction.MakeReturnsFalseIfFeeIsTooLarge (0 ms)
[ RUN      ] Transaction.MakeTransfersMoneyBetweenRealAccounts
1 send to 2 $100
Balance 1 is 890
Balance 2 is 600
[       OK ] Transaction.MakeTransfersMoneyBetweenRealAccounts (0 ms)
[ RUN      ] Transaction.MakeRollsBackCreditIfDebitFails
1 send to 2 $100
Balance 1 is 50
Balance 2 is 500
[       OK ] Transaction.MakeRollsBackCreditIfDebitFails (0 ms)
[ RUN      ] Transaction.MakeUsesMockObjectsOnSuccess
[       OK ] Transaction.MakeUsesMockObjectsOnSuccess (0 ms)
[ RUN      ] Transaction.MakeUsesMockObjectsOnFailedDebit
[       OK ] Transaction.MakeUsesMockObjectsOnFailedDebit (0 ms)
[----------] 10 tests from Transaction (0 ms total)

[----------] Global test environment tear-down
```
[==========] 15 tests from 2 test cases ran. (0 ms total)
[  PASSED  ] 15 tests.
