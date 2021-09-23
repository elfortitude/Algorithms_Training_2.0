#include <iostream>

using namespace std;

int     main(int argc, char **argv) {
    int N, i, j;

    cin >> N >> i >> j;

    if (abs(i - j) <= (min(i, j) + (N - max(i, j)))) {
        cout << abs(i - j) - 1;
    } else {
        cout << min(i, j) + (N - max(i, j)) - 1;
    }

    return 0;
}