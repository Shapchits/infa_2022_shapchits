#include <iostream>

bool isPrime(int n){
    if (n >= 1){
        if (n == 1)
            return true;
        else{
            for (int i = 2; i < n; i++)
                if (n % i == 0)
                    return false;
            return true;
        }
    }
    else
        return false;
}

bool isPalindrome(int n){
    if (n >= 0){
        int m = n;
        int rev = 0;
        int rem;
        while (m != 0){
            rem = m % 10;
            rev = rev * 10 + rem;
            m = m / 10;
        }
        if (n == rev)
            return true;
        else
            return false;

    }
    else
        return false;
}

int main() {
    int n, l;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        std::cin >> l;
        if (isPrime(l)) {
            std::cout << l << " is prime. ";
        } else {
            std::cout << l << " is not prime. ";
        }
        if (isPalindrome(l)) {
            std::cout << l << " is palindrome. ";
        } else {
            std::cout << l << " is not palindrome. ";
        }
    }
}
