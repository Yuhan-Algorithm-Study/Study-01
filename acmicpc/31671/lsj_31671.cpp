#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // ����ȭ �ڵ�
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // ������ ���̿� ������ �� �Է�
    int N, M;
    cin >> N >> M;

    // ������ 2���� ���� ����
    vector<vector<int>> Oreum(N + 1, vector<int>(2 * N + 1, 3));

    // ������ ��ġ �Է�(2 : ������ ��ġ)
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Oreum[N - b][a] = 2;
    }

    // �̵� ������ ���� (x + 1, y + 1) or (x + 1, y - 1)
    pair<int, int> moves[2][2] = { {{-1, -1}, {1, -1}}, {{-1, 1}, {1, 1}} };

    // ���� ��ġ �⺻�� ����
    queue<pair<int, int>> queue;
    queue.push({N, 2 * N});
    Oreum[N][2 * N] = 0;

    // BFS ���� 1��
    while (!queue.empty()) {
        // ���� ��ǥ��
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();


        for (auto& move : moves[0]) {
            int ny = y + move.first;
            int nx = x + move.second;

            // ��ǥ�� ���� �˻�
            if (ny < 0 || nx < 0 || ny >= N + 1 || nx >= 2 * N + 1) {
                continue;
            }
            // �ﰢ�� ���� �ȿ� �ִ��� �˻�
            if (N - ny > nx) {
                continue;
            }
            // �������� ��ġ���ְų� �̹� �湮�ߴ��� �˻�
            if (Oreum[ny][nx] == 2 || Oreum[ny][nx] == 0) {
                continue;
            }
            // ť�� �߰� �� �湮 ���� üũ
            queue.push({ ny, nx });
            Oreum[ny][nx] = 0;
        }
    }

    // ���� ��ġ, �ִ� ���� �⺻�� ����
    int max_height = -1;
    queue.push({N, 0});
    Oreum[N][0] = true;

    // BFS ���� 2��
    while (!queue.empty()) {
        // ���� ��ǥ��
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();


        for (auto& move : moves[1]) {
            int ny = y + move.first;
            int nx = x + move.second;

            // ��ǥ�� ���� �˻�
            if (ny < 0 || nx < 0 || ny >= N + 1 || nx >= 2 * N + 1) {
                continue;
            }
            // �ﰢ�� ���� �ȿ� �ִ��� �˻�
            if (N - ny > 2 * N - nx) {
                continue;
            }
            // �������� ��ġ���ְų� 1�� BFS���� �湮���� �ʾҴ��� üũ
            if (Oreum[ny][nx] > 0) {
                continue;
            }
            // ť�� �߰� �� �湮 ���� üũ
            queue.push({ ny, nx });
            Oreum[ny][nx] = 1;

            // �Ƹ��ٿ� �� ����
            max_height = max(max_height, N - ny);

        }
    }


    // ���� ����(2 * N, 0)�� �湮�� �� �ִ��� Ȯ��
    if (!Oreum[0][2 * N]) {
        cout << -1;
    }
    else {
        cout << max_height;
    }

    return 0;
}
