#include <iostream>
#include <vector>

using namespace std;

int     first_in_search(vector<int> *nums, int n) {
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

int     last_in_searh(vector<int> *nums, int n) {
    int l = 0;
    int r = nums->size() - 1;

    while (l < r) {
        int m = (l + r + 1) / 2;
        if ((*nums)[m] <= n)
            l = m;
        else
            r = m - 1;
    }
    
    return r;
}

int         main(void) {
    int                     N, M;
    vector<int>             nums;
    vector<pair<int, int>>  res;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        nums.push_back(n);
    }

    cin >> M;
    for (int i = 0; i < M; ++i) {
        int m;
        cin >> m;
        int l = first_in_search(&nums, m);
        int r = last_in_searh(&nums, m);
        if ((l == nums.size() - 1 && nums[l] != m) || (r == 0 && nums[r] != m) || r < l)
            res.push_back(make_pair(0, 0));
        else
            res.push_back(make_pair(l + 1, r + 1));
    }

    for (auto i : res)
        cout << i.first << " " << i.second << endl;

    return 0;
}