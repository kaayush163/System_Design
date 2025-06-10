#include <bits/stdc++.h>
using namespace std;

class Customer {
public:
    virtual string getName(const int& id) = 0;
};

class RealCustomer: public Customer {
    string name;
public:
    RealCustomer(string n) : name(std::move(n)) {}
    string getName(const int& id) override {
        return name;
    }
};

class NullCustomer: public Customer {
public:
    string getName(const int& id) override {
        return string("Name not available with this id ") + std::to_string(id);
    }
};

class CustomerFactory {
public:
    Customer* getCustomerId(int id) {
        if (id == 123)
            return new RealCustomer("Aayush");
        else
            return new NullCustomer();
    }
};

int main() {
    CustomerFactory factory;
    int id = 122;
    Customer* customer = factory.getCustomerId(id);
    cout << customer->getName(id) << endl;
    delete customer;
    return 0;
}
