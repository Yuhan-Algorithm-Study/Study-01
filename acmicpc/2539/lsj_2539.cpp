#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // ����ȭ �ڵ�
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    // ��, ��, ������ �ִ� ����, �߸� ĥ���� ĭ ����
    int row, col, maxPaper, wrong;

    cin >> row >> col;
    cin >> maxPaper;
    cin >> wrong;

    // �߸� ĥ���� ĭ�� ��ǥ�� �Է�
    int maxH = 0;
    vector<int> wrongPoint;
    for (int i = 0; i < wrong; i++) {
        int x, y;
        cin >> x >> y;
        // ���⼭ �ִ� ���̸� ����ϴ� ����
        // 1. �����̴� ���簢���̴�.
        // 2. �����̴� �ݵ�� ��ȭ���� �غ��� ���߾� ���δ�.
        // �̸� �̿��Ͽ� ������ ������ �ּҰ��� ���� �� �ִ�.
        maxH = max(maxH, x);
        wrongPoint.push_back(y);
    }
    // �̺�Ž���� ���� ��ǥ���� ������������ ����
    sort(wrongPoint.begin(), wrongPoint.end());

    // �̺�Ž�� ���� ����
    // left:  �������� �ּ� ũ��, right: �������� �ִ� ũ��
    // mid: ���� �˻��ϰ� �ִ� �������� ũ��
    // ans: ������ ũ���� �ּҰ�(�ʱⰪ�� �ִ� ũ��� ��´�.) 
    int left = maxH, right = col;
    int mid;
    int ans = right;

    // �̺�Ž�� ����
    while (left <= right) {
        // Ž���� �������� ũ��� �ּҰ��� �Ҵ��� �߰���
        mid = (left + right) / 2;
        // ����� �������� ����
        int paperUse = 1;
        // ���� �� ��ȣ
        int columnStart = wrongPoint[0];

        for (int i = 1; i < wrong; i++) {
            // �߸��� ��ǥ���� �ش� �����̷� ���� �� ���� ��쿡��
            // 1. ����� �������� ������ 1 ���� ��Ų��.
            // 2. ���ο� �������� ���� ���� ���� ĭ�� �� ��ȣ�� �����Ѵ�.
            if (wrongPoint[i] > columnStart + mid - 1) {
                paperUse++;
                columnStart = wrongPoint[i];
            }
        }

        // �߸�ĥ���� ĭ�� �ش� ũ���� �����̸� �̿��ؼ� �ִ� ������ �����ϸ� ä�� �� �ִٸ�
        // 1. ������ ũ���� �ּҰ��� ����
        // 2. �������� ũ�� ������ ���δ�. (�� Ž�� ������ ������.)
        if (paperUse <= maxPaper) {
            ans = mid;
            right = mid - 1;
        }
        // �׷��� �ʴٸ�
        // 1. �������� ũ�� ������ �ø���. (�� Ž�� ������ ������.)
        else {
            left = mid + 1;
        }
    }
    cout << ans;
}