#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 카데인 알고리즘

int main() 
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N, K;   cin >> N >> K;
    vector<int> seq(N);

    for (int i = 0; i < N; ++i) 
    {
        cin >> seq[i];
    }

    int max_NS_sum = -2147483647 - 1;
    int max_SN_sum = -2147483647 - 1;

    int current_NS_sum = 0;
    int current_SN_sum = 0;

    for (int i = 1; i < N; ++i) 
    {
        int ns_diff = seq[i] - seq[i - 1] - K;
        int sn_diff = seq[i - 1] - seq[i] - K;

        current_NS_sum = max(0, current_NS_sum) + ns_diff;
        current_SN_sum = max(0, current_SN_sum) + sn_diff;

        max_NS_sum = max(max_NS_sum, current_NS_sum);
        max_SN_sum = max(max_SN_sum, current_SN_sum);
    }

    cout << max(max_NS_sum, max_SN_sum);
}
