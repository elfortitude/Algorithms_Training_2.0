#include <iostream>

using namespace std;

int     main(void) {
    int         L, K;

    cin >> L >> K;
    int target = (L - 1) / 2;
    int left = -1, right = -1;
    for (int i = 0; i < K; ++i) {
        int n;
        cin >> n;
        if (n <= target)
            left = n;
        else if (n > target && right == -1)
            right = n;
    }
    
    if (right != -1 && !(L % 2 != 0 && left == target))
        cout << left << right << endl;
    else
        cout << left << endl;

    return 0;
}