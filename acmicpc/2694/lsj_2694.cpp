#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ����ȭ �ڵ�
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // �׽�Ʈ ���̽� �� �Է�
    int T;
    cin >> T;

    // �׽�Ʈ ���̽� �� ��ŭ �ݺ�
    while (T--) {
        // ���� �Է�
        int M;
        cin >> M;
        vector<int> sequence(M);
        for (int i = 0; i < M; ++i) {
            cin >> sequence[i];
        }

        // ������ ���
        vector<int> prefix_sum(sequence.size() + 1, 0);
        for (int i = 0; i < sequence.size(); ++i) {
            prefix_sum[i + 1] = prefix_sum[i] + sequence[i];
        }

        // �� �հ� �ּ� �� ����
        int total_sum = prefix_sum.back();
        int min_sum = total_sum;

        // ��� ���ϱ�
        vector<int> divisors;
        for (int i = 1; i * i <= total_sum; ++i) {
            if (total_sum % i == 0) {
                divisors.push_back(i);
                if (i != total_sum / i) {
                    divisors.push_back(total_sum / i);
                }
            }
        }
        // ��� ���͸� �������� ����
        sort(divisors.begin(), divisors.end());

        // ����� ���� ��ŭ �ݺ�
        for (int target_sum : divisors) {
            bool is_Valid = true;
            int last_index = 0;

            // �ش� ����� �κ� ������ ���� �� �ִ��� �˻�
            for (int i = 1; i <= sequence.size(); ++i) {
                if (prefix_sum[i] - prefix_sum[last_index] == target_sum) {
                    last_index = i;
                }
                else if (prefix_sum[i] - prefix_sum[last_index] > target_sum) {
                    is_Valid = false;
                    break;
                }
            }

            // �κ����� ���� �� �ִ��� ���ο� ��� ����� üũ �ߴ��� Ȯ��
            if (is_Valid && last_index == sequence.size()) {
                min_sum = target_sum;
                break;
            }
        }

        // �κ� ������ �ּ� ���� ���
        cout << min_sum << endl;

    }

    return 0;
}
