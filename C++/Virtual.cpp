#include<iostream>
#include<iomanip>
using namespace std;

class Account {
public:
    Account() {};
    ~Account();
    virtual void credit(double addMoney) {
        balance += addMoney;
    };
    virtual void debit(double takeMoney) {
        if(balance - takeMoney < 0) cout << "Debit amount exceeded account balance" << endl;
        else balance -= takeMoney;
    };
    double getBalance() {
        return balance;
    }
    void setBalance(double NB) {
        balance = NB;
    }
    void addBalance(double add) {
        balance += add;
    }
private:
    double balance;
};

class SavingsAccount: public Account {
public:
    SavingsAccount(double , double);
    void credit(double addMoney) {
        addBalance(addMoney);
    };
    void debit(double takeMoney) {
        if(getBalance() - takeMoney < 0) cout << "Debit amount exceeded account balance" << endl;
        else addBalance(-takeMoney);
    };
    ~SavingsAccount();
    double calculateInterest() {
        return interestRate / 100 * getBalance();
    }
private:
    double interestRate;
};

class CheckingAccount: public Account {
public:
    CheckingAccount(double ,double );
    void credit(double );
    void debit(double );
    ~CheckingAccount();
private:
    double fee;
};

CheckingAccount::CheckingAccount(double Balance, double Fee) {
    setBalance(Balance);
    fee = Fee;
}

SavingsAccount::SavingsAccount(double Balance, double InterestRate) {
    setBalance(Balance);
    interestRate = InterestRate;
}

void CheckingAccount::credit(double addMoney) {
    addBalance(addMoney);
    if(getBalance() - fee < 0) {
                cout << "Transaction fee exceeded account balance while crediting" << endl;
                addBalance(- addMoney);
        }
        else addBalance(- fee);
}

void CheckingAccount::debit(double takeMoney) {
    if(getBalance() - takeMoney < 0) cout << "Debit amount exceeded account balance" << endl;
    else {
            addBalance( - takeMoney);
        if(getBalance() - fee < 0) {
                cout << "Transaction fee exceeded account balance while debiting" << endl;
                addBalance(takeMoney);
        }
        else addBalance(- fee);
    }
}

int main() {
    Account *accounts[3];
    accounts[0] = new SavingsAccount(100, 3);
    accounts[1] = new CheckingAccount(100, 5);
    accounts[2] = new CheckingAccount(50, 5);
    for (int i = 0; i < 3; i++) {
        cout << "第" << i + 1 << "次循环的结果： " << endl;
        accounts[i]->debit(200); //借款200元
        accounts[i]->debit(40);
        accounts[i]->credit(50); //存款50元
        accounts[i]->debit(49);
        accounts[i]->debit(43);
        accounts[i]->credit(1);
        //将Account指针强制转换为SavingAccount指针
        SavingsAccount *derivedPtr =
        dynamic_cast <SavingsAccount *> (accounts[i]);
        if(derivedPtr != NULL) //如果类型兼容，转换成功
        derivedPtr->credit(derivedPtr->calculateInterest());
        cout << fixed << setprecision(2); //使用定点数格式， 2位小数部分
        cout << "账户的余额为： " << accounts[i]->getBalance() << endl;
    }
}



