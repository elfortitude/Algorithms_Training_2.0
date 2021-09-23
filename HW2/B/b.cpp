#include <iostream>
#include <vector>

using namespace std;

int     main(void) {
    vector<int>     builds(10);
    int             res;

    res = 0;
    for (int i = 0; i < builds.size(); ++i)
        cin >> builds[i];
    for (int i = 0; i < builds.size(); ++i) {
        if (builds[i] == 1) {
            int j = 0;
            int minJ = 10;
            while (i - j >= 0) {
                if (builds[i - j] == 2) {
                    minJ = j;
                    break;
                }
                ++j;
            } 
            int k = 0;
            int minK = 10;
            while (i + k < builds.size()) {
                if (builds[i + k] == 2) {
                    minK = k;
                    break;
                }
                ++k;
            }
            if (min(minJ, minK) > res)
                res = min(minJ, minK);
        }
    }
    cout << res << endl;

    return 0;
}