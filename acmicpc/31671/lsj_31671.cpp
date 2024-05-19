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

    // 오름을 2차원 벡터 선언
    vector<vector<int>> Oreum(N + 1, vector<int>(2 * N + 1, 3));

    // 선생님 위치 입력(2 : 선생님 위치)
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        Oreum[N - b][a] = 2;
    }

    // 이동 가능한 방향 (x + 1, y + 1) or (x + 1, y - 1)
    pair<int, int> moves[2][2] = { {{-1, -1}, {1, -1}}, {{-1, 1}, {1, 1}} };

    // 시작 위치 기본값 설정
    queue<pair<int, int>> queue;
    queue.push({N, 2 * N});
    Oreum[N][2 * N] = 0;

    // BFS 실행 1차
    while (!queue.empty()) {
        // 현재 좌표값
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();


        for (auto& move : moves[0]) {
            int ny = y + move.first;
            int nx = x + move.second;

            // 좌표값 범위 검사
            if (ny < 0 || nx < 0 || ny >= N + 1 || nx >= 2 * N + 1) {
                continue;
            }
            // 삼각형 범위 안에 있는지 검사
            if (N - ny > nx) {
                continue;
            }
            // 선생님이 위치해있거나 이미 방문했는지 검사
            if (Oreum[ny][nx] == 2 || Oreum[ny][nx] == 0) {
                continue;
            }
            // 큐에 추가 후 방문 여부 체크
            queue.push({ ny, nx });
            Oreum[ny][nx] = 0;
        }
    }

    // 시작 위치, 최대 높이 기본값 설정
    int max_height = -1;
    queue.push({N, 0});
    Oreum[N][0] = true;

    // BFS 실행 2차
    while (!queue.empty()) {
        // 현재 좌표값
        pair<int, int> position = queue.front();
        int y = position.first;
        int x = position.second;
        queue.pop();


        for (auto& move : moves[1]) {
            int ny = y + move.first;
            int nx = x + move.second;

            // 좌표값 범위 검사
            if (ny < 0 || nx < 0 || ny >= N + 1 || nx >= 2 * N + 1) {
                continue;
            }
            // 삼각형 범위 안에 있는지 검사
            if (N - ny > 2 * N - nx) {
                continue;
            }
            // 선생님이 위치해있거나 1차 BFS에서 방문하지 않았는지 체크
            if (Oreum[ny][nx] > 0) {
                continue;
            }
            // 큐에 추가 후 방문 여부 체크
            queue.push({ ny, nx });
            Oreum[ny][nx] = 1;

            // 아름다움 값 갱신
            max_height = max(max_height, N - ny);

        }
    }


    // 도착 지점(2 * N, 0)에 방문한 적 있는지 확인
    if (!Oreum[0][2 * N]) {
        cout << -1;
    }
    else {
        cout << max_height;
    }

    return 0;
}
