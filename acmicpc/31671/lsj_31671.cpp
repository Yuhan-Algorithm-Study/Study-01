#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    // 최적화 코드
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    // 오름의 높이와 선생님 수 입력
    int N, M;
    cin >> N >> M;

    // 오름의 선생님 존재 여부와 방문 여부를 확인 할 2차원 벡터 선언
    vector<vector<char>> Oreum(N + 1, vector<char>(2 * N + 1, '0'));
    vector<vector<bool>> Visited(N + 1, vector<bool>(2 * N + 1, false));

    // 선생님 위치 입력(X : 선생님 위치)
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Oreum[b][a] = 'X';
    }

    // 시작 위치와 최대 높이 기본값 설정
    queue<pair<int, int>> queue;
    queue.push({ 0, 0 });
    Visited[0][0] = true;
    int max_height = 0;

    // BFS 실행
    while (!queue.empty()) {
        // 현재 좌표값
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();

        // 이동 가능한 방향 (x + 1, y + 1) or (x + 1, y - 1)
        vector<pair<int, int>> moves = { {1, 1}, {1, -1} };

        for (pair<int, int> move : moves) {
            int nx = x + move.first;
            int ny = y + move.second;

            // 좌표값 범위 검사
            if (nx > (2 * N) || ny > N || nx < 0 || ny < 0)
                continue;

            // 삼각형 범위 안에 있는지 검사
            if (nx < ny || nx > (2 * N - ny))
                continue;

            // 선생님이 위치해있거나 이미 방문했는지 검사
            if (Oreum[ny][nx] == 'X' || Visited[ny][nx])
                continue;

            // 큐에 추가 후 방문 여부 체크
            queue.push({ ny, nx });
            Visited[ny][nx] = true;

            // 최대 높이 갱신
            max_height = max(ny, max_height);
        }
    }

    // 도착 지점(2 * N, 0)에 방문한 적 있는지 확인
    if (!Visited[0][2 * N]) {
        cout << -1;
    }
    else {
        cout << max_height;
    }

    return 0;
}
