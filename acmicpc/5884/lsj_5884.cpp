#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    // 최적화 코드
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 소의 수를 입력
    int N;
    cin >> N;

    // 각 소의 좌표값 입력
    vector<pair<int, int>> cows(N);
    for (int i = 0; i < N; ++i) {
        cin >> cows[i].first >> cows[i].second;
    }

    // 최대 세 번 반복 (최대 세 개의 선분으로 커버 가능)
    int cnt = 0;
    while (cnt < 3) {
        bool max_xy = false;  // true : x, false : y
        int max_val = 0; // 최대 빈도수
        int max_idx = 0; // 최대 빈도를 가진 좌표값
        unordered_map<int, int> dict_x; // x좌표의 빈도
        unordered_map<int, int> dict_y; // y좌표의 빈도

        // 각 소의 x좌표와 y좌표의 빈도를 계산
        for (const auto& cow : cows) {
            // x좌표
            dict_x[cow.first]++;
            if (dict_x[cow.first] > max_val) {
                max_val = dict_x[cow.first];
                max_xy = true;
                max_idx = cow.first;
            }
            // y좌표
            dict_y[cow.second]++;
            if (dict_y[cow.second] > max_val) {
                max_val = dict_y[cow.second];
                max_xy = false;
                max_idx = cow.second;
            }
        }

        vector<pair<int, int>> new_cows;
        // 최대 빈도 좌표가 x좌표인 경우
        if (max_xy) {
            // 해당 x좌표의 소들을 제거
            for (const auto& cow : cows) {
                if (cow.first != max_idx) {
                    new_cows.push_back(cow);
                }
            }
            cows = new_cows;
        }
        // 최대 빈도 좌표가 y좌표인 경우
        else {
            // 해당 y좌표의 소들을 제거
            for (const auto& cow : cows) {
                if (cow.second != max_idx) {
                    new_cows.push_back(cow);
                }
            }
            cows = new_cows;
        }

        // 모든 소를 제거했다면
        if (cows.empty()) {
            break;
        }

        cnt++;
    }

    // 모든 소를 감시할 수 있다면
    if (cows.empty()) {
        cout << 1 << endl;
    }
    // 없다면
    else {
        cout << 0 << endl;
    }

    return 0;
}
