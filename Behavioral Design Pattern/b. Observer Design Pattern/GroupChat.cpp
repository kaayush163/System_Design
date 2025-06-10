#include<bits/stdc++.h>
using namespace std;
class Observer {
public:
    virtual ~Observer() = default;
    virtual void update(const string& newMessage) = 0;
};

// Subject interface
class Subject {
public:
    virtual ~Subject() = default;
    virtual void subscribe(Observer* observer) = 0;
    virtual void unsubscribe(Observer* observer) = 0;
    virtual void notify() = 0;
};

// Concrete Subject class
class GroupChat : public Subject {
private:
    vector<Observer*> observers;
    vector<string> messages;
public:
    void subscribe(Observer* observer) override {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) override {
        auto it = find(observers.begin(), observers.end(), observer);
        if (it != observers.end()) {
            observers.erase(it);
        }
    }

    void notify() override {
        for (Observer* observer : observers) {
            observer->update(messages.back());
        }
    }

    void sendMessage(const string& msg) {
        messages.push_back(msg);
        notify();
    }
};

// Concrete Observer class
class Friend : public Observer {
private:
    string name;
public:
    Friend(const string& n) : name(n) {}

    void update(const string& newMessage) override {
        cout << name << " received a message: " << newMessage << endl;
    }
};

int main() {
    GroupChat chat;

    Friend friend1("Aayush");
    Friend friend2("Shanu");
    Friend friend3("Gaurang");

    chat.subscribe(&friend1);
    chat.subscribe(&friend2);
    chat.subscribe(&friend3);

    chat.sendMessage("Hey everyone, let's play a trip together!");

    return 0;
}
