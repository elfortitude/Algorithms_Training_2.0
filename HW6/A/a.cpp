#include <iostream>
#include <vector>

using namespace std;

int     left_bin_search(vector<int> *nums, int n) {
    int l = 0;
    int r = nums->size() - 1;
    
    while (l < r) {
        int m = (l + r) / 2;
        
        if ((*nums)[m] >= n)
            r = m;
        else
            l = m + 1;
    }
    
    return l;
}

int     right_bin_search(vector<int> *nums, int n) {
    int l = 0;
    int r = nums->size() - 1;

    while (l < r) {
        int m = (l + r + 1) / 2;

        if ((*nums)[m] <= n)
            l = m;
        else
            r = m - 1;
    }

    return l;
}

int     main(void) {
    int                     N, K;
    vector<int>             nums;
    vector<int>             res;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tmp;
        cin >> tmp;
        nums.push_back(tmp);
    }

    sort(nums.begin(), nums.end());

    cin >> K;
    for (int i = 0; i < K; ++i) {
        int L, R;
        cin >> L >> R;

        int l = left_bin_search(&nums, L);
        int r = right_bin_search(&nums, R);

        if (L > nums[nums.size() - 1] || R < nums[0])
            res.push_back(0);
        else
            res.push_back(r - l + 1);
    }
    
    for (auto i : res)
        cout << i << " ";
    cout << endl;

    return 0;
}