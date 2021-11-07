#include <iostream>
#include <vector>

using namespace std;

int     main(void) {
    int                     n;
    long long int           max_sum, min_elem;

    cin >> n;
    vector<long long int>   a_prefix_sum(n + 1, 0); 
    for (int i = 1; i < n + 1; ++i) {
        long long int ai;
        cin >> ai;
        a_prefix_sum[i] = a_prefix_sum[i - 1] + ai;
    }

    max_sum = a_prefix_sum[1];
    min_elem = a_prefix_sum[0];
    for (int i = 1; i < n + 1; ++i) {
        if (a_prefix_sum[i] - min_elem > max_sum)
            max_sum = a_prefix_sum[i] - min_elem;
        if (a_prefix_sum[i] < min_elem)
            min_elem = a_prefix_sum[i];
    }
    cout << max_sum << endl;

    return 0;
}