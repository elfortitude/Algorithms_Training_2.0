#include <iostream>
#include <vector>

using namespace std;

int         main(void) {
    int     N;

    cin >> N;
    vector<int>     pupils(N);
    for (int i = 0; i < N; ++i) {
        cin >> pupils[i];
    }
    cout << pupils[N / 2];

    return 0;
}