#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int                 main(void) {
    int                        s;
    int                        num;
    map<int, int>              A;
    map<int, int>              B;
    vector<pair<int, int>>     C;
    set<int>                   C_set;

    cin >> s;
    for (int i = 0; i < 3; ++i) {
        cin >> num;
        for (int j = 0; j < num; ++j) {
            int tmp;
            cin >> tmp;
            if (i == 0) {
                if (!A.contains(tmp))
                    A[tmp] = j;
            } else if (i == 1) {
                if (!B.contains(tmp))
                    B[tmp] = j;
            } else if (i == 2) {
                if (!C_set.contains(tmp)) {
                    C_set.insert(tmp);
                    C.push_back(make_pair(tmp, j));
                }
            }
        }
    }

    sort(C.rbegin(), C.rend());

    vector<tuple<int, int, int>> results;
    for (auto i : A) {
        if (i.first < s) {
            int k = 0;
            for (auto j : B) {
                if ((j.first < s) && (i.first + j.first < s)) {
                    while (i.first + j.first + C[k].first >= s) {
                        if (i.first + j.first + C[k].first == s)
                            results.push_back(make_tuple(i.second, j.second, C[k].second));
                        ++k;
                    }
                }
            }
        }
    }
    
    sort(results.begin(), results.end());
    if (results.size() != 0) {
        cout << get<0>(results[0]) << " " << get<1>(results[0]) << " " << get<2>(results[0]) << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}