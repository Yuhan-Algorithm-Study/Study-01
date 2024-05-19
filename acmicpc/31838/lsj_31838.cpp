#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    // ����ȭ �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ������ ������ ���� ���� �Է�
    int N, K;
    cin >> N >> K;

    // ������ �Է�
    vector<int> item(N + 1);
    for (int i = 0; i < N; i++) {
        cin >> item[i];
    }

    // dp, ������ ���� ���� �� �ʱ�ȭ
    vector<long long> dp(K + 1, 0);
    vector<long long> value_Sum(K + 1, 0);

    // ������ ���
    for (int i = 1; i < K; i++) {
        value_Sum[i] = value_Sum[i - 1] + item[i];
    }

    // �ִ� ��ġ
    long long max_value = 0;

    return 0;
}
