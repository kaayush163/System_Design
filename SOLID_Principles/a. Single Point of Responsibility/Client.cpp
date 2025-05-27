#include <iostream>
using namespace std;


// class User {
// public:
//     void login() {
//         cout << "User logged in" << endl;
//     }
//     void logout() {
//         cout << "User logged out" << endl;
//     }
//     void printUserInfo(string username) {
//         cout << "Username: " << username << endl;
//     }
// };

//  it has multiple responsibilities i.e authentication (login and logout) and printing the information of the user.
// For the above class, there can be two reasons for which implementation of class can change which is change in authentication or change in printing the user information.
// We can see that both the logic are independent to each other. We can move these two responsibilities into two different classes which will contain the logic of Authentication and printing user information.

class UserInfo {
public:
    void printUserInfo(string username) {
        cout << "Username: " << username << endl;
    }
};
class Authentication {
public:
    void login() {
        cout << "User logged in" << endl;
    }
    void logout() {
        cout << "User logged out" << endl;
    }
};


class User : public Authentication, public UserInfo {
};

int main() {
    User user;
    user.login();
    user.printUserInfo("Aayush");
    user.logout();
    return 0;
}
