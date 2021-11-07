#include <iostream>
#include <vector>
#include <map>

using namespace std;

int     main(void) {
    int N, M;
    int res;

    cin >> N >> M;
    vector<int> res_array(N, 0);
    vector<pair<int, int>>  groups;
    for (int i = 0; i < N; ++i) {
        int n;
        cin >> n;
        groups.push_back(make_pair(n, i));
    }

    vector<pair<int, int>>  classrooms;
    for (int i = 0; i < M; ++i) {
        int m;
        cin >> m;
        classrooms.push_back(make_pair(m, i + 1));
    }

    sort(groups.begin(), groups.end());
    sort(classrooms.begin(), classrooms.end());

    res = 0;
    int j = 0;
    for (int i = 0; i < N; ++i) {
        while (j < M && classrooms[j].first < groups[i].first + 1)
            ++j;
        if (j < M) {
            ++res;
            res_array[groups[i].second] = classrooms[j].second;
            ++j;
        }
    }

    cout << res << endl;
    for (auto i : res_array)
        cout << i << " ";
    cout << endl;

    return 0;
}