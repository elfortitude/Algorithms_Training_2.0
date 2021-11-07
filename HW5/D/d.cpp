#include <iostream>
#include <string>

using namespace std;

int     main(void) {
    string  line;
    int     closedBrackets;
    int     openedBrackets;

    cin >> line;
    closedBrackets = 0;
    openedBrackets = 0;
    for (int i = 0; i < line.size(); ++i) {
        if (line[i] == '(') {
            ++openedBrackets;
        } else if (line[i] == ')') {
            ++closedBrackets;
        }
        if (closedBrackets > openedBrackets)
            break;
    }
    if (openedBrackets == closedBrackets)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}