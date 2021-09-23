#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <string>

using namespace std;

int                 main(void) {
    int                 M;
    int                 N;
    int                 max;
    vector<string>      witnesses;
    map<string, int>    car_numbers;
    vector<string>      car_numbers_vector;

    cin >> M;
    for (int i = 0; i < M; ++i) {
        string number;
        cin >> number;
        witnesses.push_back(number);
    }
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string number;
        cin >> number;
        car_numbers[number] = 0;
        car_numbers_vector.push_back(number);
    }

    max = 0;
    for (auto& number : car_numbers) {
        for (int i = 0; i < M; ++i) {
            int count_matches = witnesses[i].size();
            for (int j = 0; j < witnesses[i].size(); ++j) {
                if (number.first.find(witnesses[i][j]) != -1)
                    --count_matches;
            }
            if (count_matches == 0)
                ++number.second;
        }
        if (number.second > max)
            max = number.second;
    }

    for (int i = 0; i < N; ++i) {
        if (car_numbers[car_numbers_vector[i]] == max)
            cout << car_numbers_vector[i] << endl;
    }

    return 0;
}