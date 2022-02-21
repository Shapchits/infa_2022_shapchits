#include <iostream>
#include <random>

void move(int *x, int *arr) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, 1);
    int opt = dist(rng);
    switch (opt) {
        case 0:
            arr[*x - 1] = 1;
            arr[*x] = 0;
            *x = *x - 1;
        case 1:
            arr[*x + 1] = 1;
            arr[*x] = 0;
            *x = *x + 1;
    }
}

int test(int n) {
    int *arr;
    arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<int> dist(0, n - 1);
    int x;
    int time = 0;
    x = dist(rng);
    arr[x] = 1;
    while (x > 0 && x < n - 1) {
        move(&x, arr);
        time++;
    }
    delete[] arr;
    return time;
}

int main() {
    const int n = 100;
    const int attempts = 20;
    int average = 0;
    for (int i = 5; i <= n; i += 5) {
        for (int j = 0; j < attempts; j++) {
            average += test(i);
        }
        average /= attempts;
        std::cout << i << " ";
        std::cout << average << '\n';
        average = 0;
    }
}
