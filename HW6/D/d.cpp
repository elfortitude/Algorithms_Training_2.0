#include <iostream>
#include <cmath>

using namespace std;

int     main(void) {
    unsigned long long A, K, B, M, X;

    cin >> A >> K >> B >> M >> X;

    unsigned long long l = 0;
    unsigned long long r = 2 * X / A + 1;
    while (l < r) {
        unsigned long long m =  (l + r) / 2;
        if (((m - (m / K)) * A) + ((m - (m / M)) * B) >= X)
            r = m;
        else
            l = m + 1;
    }

    cout << l << endl;

    return 0;
}