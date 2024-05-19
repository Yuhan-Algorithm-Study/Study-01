#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // 최적화 코드
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 아이템 개수와 집게 길이 입력
    int N, K;
    cin >> N >> K;

    // 아이템 입력
    vector<int> item(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> item[i];
    }

    // dp, 누적합 벡터 선언 및 초기화
    vector<long long> dp(K + 1, 0);
    vector<long long> value_Sum(K + 1, 0);

    // 누적합 계산
    for (int i = 1; i < K; i++) {
        value_Sum[i] = value_Sum[i - 1] + item[i];
    }

    // 최대 가치
    long long max_value = 0;

    return 0;
}
