// Write a non-recursive and recursive program to calculate Fibonacci numbers
// and analyze their time and space complexity.

#include <iostream>
using namespace std;

int fib(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return fib(n - 2) + fib(n - 1);
}

int fibIt(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    n--;
    int fib1 = 1, fib2 = 0;
    while (n--) {
        int fib = fib1 + fib2;
        fib2 = fib1;
        fib1 = fib;
    }
    return fib1;
}

int main() {
    int choice;
    string menu = "1. To find Fibonacci non-recursively. \n2. To find "
                  "Fibonacci recursively. \n3. Exit";
    while (true) {
        cout << endl << menu << endl;
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 1) {
            int n;
            cout << "Enter a number : ";
            cin >> n;
            cout << "Fibonacci of " << n << " is " << fibIt(n) << endl;
        } else if (choice == 2) {
            int n;
            cout << "Enter a number : ";
            cin >> n;
            cout << "Fibonacci of " << n << " is " << fib(n) << endl;
        } else if (choice == 3) {
            cout << "Thank You" << endl;
            break;
        } else {
            cout << "Invalid Input" << endl;
        }
    }
    return 0;
}