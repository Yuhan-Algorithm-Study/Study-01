#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    // 최적화 코드
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    // 행, 열, 색종이 최대 개수, 잘못 칠해진 칸 개수
    int row, col, maxPaper, wrong;

    cin >> row >> col;
    cin >> maxPaper;
    cin >> wrong;

    // 잘못 칠해진 칸의 좌표값 입력
    int maxH = 0;
    vector<int> wrongPoint;
    for (int i = 0; i < wrong; i++) {
        int x, y;
        cin >> x >> y;
        // 여기서 최대 높이를 계산하는 이유
        // 1. 색종이는 정사각형이다.
        // 2. 색종이는 반드시 도화지의 밑변에 맞추어 붙인다.
        // 이를 이용하여 색종이 길이의 최소값을 구할 수 있다.
        maxH = max(maxH, x);
        wrongPoint.push_back(y);
    }
    // 이분탐색을 위해 좌표값을 오름차순으로 정렬
    sort(wrongPoint.begin(), wrongPoint.end());

    // 이분탐색 범위 설정
    // left:  색종이의 최소 크기, right: 색종이의 최대 크기
    // mid: 현재 검사하고 있는 색종이의 크기
    // ans: 색종이 크기의 최소값(초기값은 최대 크기로 잡는다.) 
    int left = maxH, right = col;
    int mid;
    int ans = right;

    // 이분탐색 진행
    while (left <= right) {
        // 탐색할 색종이의 크기는 최소값과 촤댓값의 중간값
        mid = (left + right) / 2;
        // 사용한 색종이의 개수
        int paperUse = 1;
        // 시작 열 번호
        int columnStart = wrongPoint[0];

        for (int i = 1; i < wrong; i++) {
            // 잘못된 좌표값을 해당 색종이로 덮을 수 없는 경우에는
            // 1. 사용한 색종이의 개수를 1 증가 시킨다.
            // 2. 새로운 색종이의 시작 열을 현재 칸의 열 번호로 설정한다.
            if (wrongPoint[i] > columnStart + mid - 1) {
                paperUse++;
                columnStart = wrongPoint[i];
            }
        }

        // 잘못칠해진 칸을 해당 크기의 색종이를 이용해서 최대 개수를 만족하며 채울 수 있다면
        // 1. 색종이 크기의 최소값을 갱신
        // 2. 색종이의 크기 범위를 줄인다. (즉 탐색 범위를 좁힌다.)
        if (paperUse <= maxPaper) {
            ans = mid;
            right = mid - 1;
        }
        // 그렇지 않다면
        // 1. 색종이의 크기 범위를 늘린다. (즉 탐색 범위를 넓힌다.)
        else {
            left = mid + 1;
        }
    }
    cout << ans;
}