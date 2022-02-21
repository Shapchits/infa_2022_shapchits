#include <iostream>

bool foo(int n){
    std::cin >> n;
    int r, l = 0;
    char q;
    std::cin >> q;
    if (q == ')')
        return false;
    for (int i = 2; i <= n - 1; i++){
        std::cin >> q;
        if (q == ')'){
            r += 1;
        }
        if (q == '('){
            l += 1;
        }
    }
    std::cin >> q;
    if (q == '(')
        return false;
    if (l == r)
        return true;
    else
        return false;
}

int main(){
    int n;
    std::cout << foo(n);
}
