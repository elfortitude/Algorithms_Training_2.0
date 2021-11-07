#include <iostream>
#include <vector>

using namespace std;

int     main(void) {
    int                     n, q;
    vector<long long int>   nums;

    cin >> n >> q;
    for (int i = 0; i < n; ++i) {
        long long int num;
        cin >> num;
        nums.push_back(num);
    }

    vector<long long int>   prefix_sums(nums.size() + 1, 0);
    for (int i = 1; i < prefix_sums.size(); ++i) {
        prefix_sums[i] += prefix_sums[i - 1] + nums[i - 1];
    }

    for (int i = 0; i < q; ++i) {
        int l, r;
        cin >> l >> r;
        cout << prefix_sums[r] - prefix_sums[l - 1] << endl;
    }

    return 0;
}