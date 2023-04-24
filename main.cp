#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool checkPattern(string password) {
    // Check for patterns of repeating character types
    for (int i = 0; i <= password.length() - 6; i++) {
        if ((islower(password[i]) && islower(password[i+1]) && islower(password[i+2]) && 
             isupper(password[i+3]) && isdigit(password[i+4]) && isdigit(password[i+5])) ||
            (isdigit(password[i]) && isdigit(password[i+1]) && isdigit(password[i+2]) && 
             isupper(password[i+3]) && islower(password[i+4]) && islower(password[i+5]))) {
            return true;
        }
    }
    
    // Check for patterns of same starting sequence
    if ((isupper(password[0]) && islower(password[1]) && isdigit(password[2])) ||
        (islower(password[0]) && isupper(password[1]) && isdigit(password[2])) ||
        (isdigit(password[0]) && isupper(password[1]) && islower(password[2]))) {
        for (int i = 3; i < password.length() - 2; i += 3) {
            if ((isupper(password[i]) && islower(password[i+1]) && isdigit(password[i+2])) ||
                (islower(password[i]) && isupper(password[i+1]) && isdigit(password[i+2])) ||
                (isdigit(password[i]) && isupper(password[i+1]) && islower(password[i+2]))) {
                return true;
            }
        }
    }
    
    return false;
}

string genPassword() {
    string password = "";
    bool hasDigit = false;
    bool hasUpper = false;
    bool hasLower = false;
    
    while (password.length() < 10 || password.length() > 16 || 
           !hasDigit || !hasUpper || !hasLower || checkPattern(password)) {
        password = "";
        hasDigit = false;
        hasUpper = false;
        hasLower = false;
        int length = rand() % 7 + 10;  // Generate length between 10 and 16
        for (int i = 0; i < length; i++) {
            int type = rand() % 3;
            char c;
            if (type == 0) {  // Generate digit
                c = rand() % 10 + '0';
                hasDigit = true;
            } else if (type == 1) {  // Generate uppercase letter
                c = rand() % 26 + 'A';
                hasUpper = true;
            } else {  // Generate lowercase letter
                c = rand() % 26 + 'a';
                hasLower = true;
            }
            if (i > 0 && (c == password[i-1] || c == password[i-1] + 32 || c == password[i-1] - 32)) {
                i--;
            } else {
                password += c;
            }
        }
    }
    
    return password;
}

int main() {
    srand(time(NULL));  // Initialize random seed
    for (int i = 0; i < 20; i++) {
        cout << genPassword() << endl;
    }
    return 0;
}
