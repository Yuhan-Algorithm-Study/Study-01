#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

static bool comp(pair<long long, int>& a, pair<long long, int>& b) {
    return a.second > b.second;
}

bool solve(int type, int value1, int value2, int value3, vector<pair<long long, long long>> vec);

int main() {
    int N;
    cin >> N;

    vector<pair<long long, long long>> v1;
    unordered_map<long long, int> x1;
    unordered_map<long long, int> y1;
    for (int i = 0; i < N; i++) {
        long long n, m;
        cin >> n >> m;
        v1.push_back({ n, m });

        x1[n]++;
        y1[m]++;
    }

    vector<pair<long long, int>> vx1(x1.begin(), x1.end());
    sort(vx1.begin(), vx1.end(), comp);
    vector<pair<long long, int>> vy1(y1.begin(), y1.end());
    sort(vy1.begin(), vy1.end(), comp);

    long long firstX = vx1[0].first, secondX = vx1[1].first, thirdX = vx1[2].first;
    long long firstY = vy1[0].first, secondY = vy1[1].first, thirdY = vy1[2].first;

    if (solve(0, firstX, secondX, thirdX, v1) || solve(1, firstX, secondX, firstY, v1) || solve(2, firstX, firstY, secondY, v1) || solve(3, firstY, secondY, thirdY, v1)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
}

bool solve(int type, int value1, int value2, int value3, vector<pair<long long, long long>> vec) {
    set<int> set;

    if (type == 0) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == value1 || vec[i].first == value2 || vec[i].first == value3) {
                set.insert(i);
            }
        }
    }
    else if (type == 1) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == value1 || vec[i].first == value2 || vec[i].second == value3) {
                set.insert(i);
            }
        }
    }
    else if (type == 2) {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].first == value1 || vec[i].second == value2 || vec[i].second == value3) {
                set.insert(i);
            }
        }
    }
    else {
        for (int i = 0; i < vec.size(); i++) {
            if (vec[i].second == value1 || vec[i].second == value2 || vec[i].second == value3) {
                set.insert(i);
            }
        }
    }

    return set.size() == vec.size();
}
