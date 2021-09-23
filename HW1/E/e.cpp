#include <iostream>
#include <cmath>

using namespace std;

int     main(void) {
    int d, xX, yX;

    cin >> d >> xX >> yX;

    if (xX >= 0 && yX >= 0 && (xX + yX <= d)) {
        cout << 0;
    } else {
        double toA = sqrt(pow(xX - 0, 2) + pow(yX - 0, 2));
        double toB = sqrt(pow(xX - d, 2) + pow(yX - 0, 2));
        double toC = sqrt(pow(xX - 0, 2) + pow(yX - d, 2));
        if (toA <= toB && toA <= toC) {
            cout << 1;
        } else if (toB < toA && toB <= toC) {
            cout << 2;
        } else {
            cout << 3;
        }
    }

    return 0;
}