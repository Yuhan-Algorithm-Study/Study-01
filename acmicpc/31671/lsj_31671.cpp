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

    // ������ ������ ���� ���ο� �湮 ���θ� Ȯ�� �� 2���� ���� ����
    vector<vector<char>> Oreum(N + 1, vector<char>(2 * N + 1, '0'));
    vector<vector<bool>> Visited(N + 1, vector<bool>(2 * N + 1, false));

    // ������ ��ġ �Է�(X : ������ ��ġ)
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Oreum[b][a] = 'X';
    }

    // ���� ��ġ�� �ִ� ���� �⺻�� ����
    queue<pair<int, int>> queue;
    queue.push({ 0, 0 });
    Visited[0][0] = true;
    int max_height = 0;

    // BFS ����
    while (!queue.empty()) {
        // ���� ��ǥ��
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();

        // �̵� ������ ���� (x + 1, y + 1) or (x + 1, y - 1)
        vector<pair<int, int>> moves = { {1, 1}, {1, -1} };

        for (pair<int, int> move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            // ��ǥ�� ���� �˻�
            if (nx > (2 * N) || ny > N || nx < 0 || ny < 0)
                continue;

            // �ﰢ�� ���� �ȿ� �ִ��� �˻�
            if (nx < ny || nx > (2 * N - ny))
                continue;

            // �������� ��ġ���ְų� �̹� �湮�ߴ��� �˻�
            if (Oreum[ny][nx] == 'X' || Visited[ny][nx])
                continue;

            // ť�� �߰� �� �湮 ���� üũ
            queue.push({ ny, nx });
            Visited[ny][nx] = true;

            // �ִ� ���� ����
            max_height = max(ny, max_height);
        }
    }

    // ���� ����(2 * N, 0)�� �湮�� �� �ִ��� Ȯ��
    if (!Visited[0][2 * N]) {
        cout << -1;
    }
    else {
        cout << max_height;
    }

    return 0;
}
