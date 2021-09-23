#include <iostream>

using namespace std;

int         main(void) {
    int     x, y, z;

    cin >> x >> y >> z;
    if (x <= 12 && y <= 12 && x != y)
        cout << 0;
    else
        cout << 1;
    
    return 0;
}