#include <iostream>
#include <vector>

using namespace std;
// 오름차순 불만족 확인 함수
bool cantSupply(int& standard, pair<int, int>& next) {
    return (next.first < standard && next.second < standard);
}

int main() {
    // 최적화 코드
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 도시의 수 입력
    int n;
    cin >> n;
    // 도시 별 최소, 최대 요구량 입력
    vector<pair<int, int> > needs;
    for (int i = 0; i < n; i++) {
        int min, max;
        cin >> min >> max;
        needs.push_back({min, max});
    }
    // 배송 횟수 초기값 1로 초기화
    int ans = 1;

    // 구간의 최소값을 기준값으로 설정
    int standard = needs[0].first;
    // 구간의 오름차순 만족 여부 확인
    for (int i = 0; i < n; ++i) {
        // 구간이 오름차순을 만족하지 않으면
        if (cantSupply(standard, needs[i])) {
            ans++;
            standard = needs[i].first;
        }
        // 구간이 오름차순을 만족한다면
        else {
            standard = max(standard, needs[i].first);
        }
    }
    // 출력
    cout << ans;

    return 0;
}
