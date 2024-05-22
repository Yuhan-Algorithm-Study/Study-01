#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 최적화 코드
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 테스트 케이스 수 입력
    int T;
    cin >> T;

    // 테스트 케이스 수 만큼 반복
    while (T--) {
        // 수열 입력
        int M;
        cin >> M;
        vector<int> sequence(M);
        for (int i = 0; i < M; ++i) {
            cin >> sequence[i];
        }

        // 누적합 계산
        vector<int> prefix_sum(sequence.size() + 1, 0);
        for (int i = 0; i < sequence.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + sequence[i];
        }

        // 총 합과 최소 합 설정
        int total_sum = prefix_sum.back();
        int min_sum = total_sum;

        // 약수 구하기
        vector<int> divisors;
        for (int i = 1; i * i <= total_sum; ++i) {
            if (total_sum % i == 0) {
                divisors.push_back(i);
                if (i != total_sum / i) {
                    divisors.push_back(total_sum / i);
                }
            }
        }
        // 약수 벡터를 오름차순 정렬
        sort(divisors.begin(), divisors.end());

        // 약수의 개수 만큼 반복
        for (int target_sum : divisors) {
            bool is_Valid = true;
            int last_index = 0;

            // 해당 약수로 부분 수열을 만들 수 있는지 검사
            for (int i = 1; i <= sequence.size(); ++i) {
                if (prefix_sum[i] - prefix_sum[last_index] == target_sum) {
                    last_index = i;
                }
                else if (prefix_sum[i] - prefix_sum[last_index] > target_sum) {
                    is_Valid = false;
                    break;
                }
            }

            // 부분합을 만들 수 있는지 여부와 모든 약수를 체크 했는지 확인
            if (is_Valid && last_index == sequence.size()) {
                min_sum = target_sum;
                break;
            }
        }

        // 부분 수열의 최소 합을 출력
        cout << min_sum << endl;

    }

    return 0;
}
