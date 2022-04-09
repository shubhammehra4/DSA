#include <bits/stdc++.h>
using namespace std;

class Bank
{
private:
    int n;
    vector<long long> balance;

    bool isValidAccount(int account)
    {
        return account >= 1 && account <= n;
    }

public:
    Bank(vector<long long> &_balance) : n(size(_balance)), balance(move(_balance)){};

    bool transfer(int account1, int account2, long long money)
    {
        if (!isValidAccount(account1) || !isValidAccount(account2) || money > balance[account1 - 1])
            return false;

        balance[account1 - 1] -= money;
        balance[account2 - 1] += money;
        return true;
    }

    bool deposit(int account, long long money)
    {
        if (!isValidAccount(account))
            return false;

        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money)
    {
        if (!isValidAccount(account) || balance[account - 1] < money)
            return false;

        balance[account - 1] -= money;
        return true;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */