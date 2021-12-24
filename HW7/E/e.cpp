#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

int     main(void) {
    int                              N;
    double                           res, max_r1, min_r2;
    vector<tuple<double, bool, int>> events;

    cin >> N;
    max_r1 = 0;
    min_r2 = 1000000;
    for (int i = 0; i < N; ++i) {;
        double r1, r2, phi1, phi2;
        cin >> r1 >> r2 >> phi1 >> phi2;
        max_r1 = max(max_r1, r1);
        min_r2 = min(min_r2, r2);
        events.push_back(make_tuple(phi1, true, i));
        events.push_back(make_tuple(phi2, false, i));
    }
    sort(events.begin(), events.end());

    set<int> used_ranges;
    int count = 0;
    for (int i = 0; i < events.size(); ++i) {
        if (get<1>(events[i])) {
            ++count;
            used_ranges.insert(get<2>(events[i]));
        } else if (used_ranges.count(get<2>(events[i])) != 0) {
            --count;
        }
    }

    res = 0;
    for (int i = 0; i < events.size(); ++i) {
        if (get<1>(events[i]))
            ++count;
        else
            --count;

        if (count == N) {
            if (i < events.size() - 1)
                res += (get<0>(events[i + 1]) - get<0>(events[i])) / 2 * (min_r2 * min_r2 - max_r1 * max_r1);
            else
                res += (get<0>(events[0]) - get<0>(events[i]) + 2 * M_PI) / 2 * (min_r2 * min_r2 - max_r1 * max_r1);
        }
    }

    cout << fixed << setprecision(6) << res << endl;

    return 0;
}