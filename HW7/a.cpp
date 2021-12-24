#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int     main(void) {
    int                             N, count, start;
    long long                       res;
    vector<pair<long long, bool>>   ranges;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        long long l, r;
        cin >> l >> r;
        ranges.push_back(make_pair(l, true));
        ranges.push_back(make_pair(r, false));
    }
    sort(ranges.begin(), ranges.end());

    res = 0;
    count = 0;
    start = 0;
    for (auto range : ranges) {
        if (range.second) {
            if (count == 0)
                start = range.first;
            ++count;
        } else {
            --count;
            if (count == 0)
                res += range.first - start;
        }
    }

    cout << res << endl;

    return 0;
}