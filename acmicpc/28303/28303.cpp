#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;
int N, K;
vector<int> v;

int solve() {
    int ans = (-2147483647 - 1);
    int hap = 0;

    int start = 0;
    int end = 1;

    //Case 1: [N---S]������ �ڼ�
    while (end < v.size()) {
        int first = v[start];
        int second = v[end];

        hap = first - second - (end - start) * K;

        ans = max(ans, hap);

        if (end == v.size() - 1) {
            break;
        }

        int third = v[end + 1];

        //����, first - third - K <hap�̶��,
        // �ڼ��� third - third + 1�� �ű��
        // first - third - K >= hap�̶��,
        //������ �����Ѵ�.

        if (first - third - K < hap) {
            start = end + 1;
            end = end + 2;
        }
        else {
            end = end + 1;
        }
    }

    //Case 2: [S----N]
    start = 0;
    end = 1;
    while (end < v.size()) {
        int first = v[start];
        int second = v[end];

        hap = second - first - (end - start) * K;

        ans = max(ans, hap);

        if (end == v.size() - 1) {
            break;
        }

        int third = v[end + 1];

        //����, third - first - K <hap�̶��,
        // �ڼ��� third - third + 1�� �ű��
        // first - third - K >= hap�̶��,
        //������ �����Ѵ�.

        if (third - first - K < hap) {
            start = end + 1;
            end = end + 2;
        }
        else {
            end = end + 1;
        }
    }


    return ans;
}

int main() {
    cin >> N >> K;
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }

    cout << solve() << endl;


}