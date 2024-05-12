#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
pair<int, int> directions[2][2] = { { {-1, -1}, {1, -1} }, { {-1, 1}, {1, 1} } };

int bfs(vector<vector<int>>& map)
{
	queue<pair<int, int>> q;

	// step1
	q.push({ n, 2 * n });
	map[n][2 * n] = 0;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		for (const auto& dir : directions[0])
		{
			int ny = curr.first + dir.first;
			int nx = curr.second + dir.second;

			if (ny < 0 || nx < 0 || ny >= n + 1 || nx >= 2 * n + 1) continue;
			if (map[ny][nx] == 2 || map[ny][nx] == 0)				continue;
			if (n - ny > nx)										continue;

			q.push({ ny, nx });
			map[ny][nx] = 0;
		}
	}

	// step2
	int ans = -1;

	q.push({ n, 0 });
	map[n][0] = 1;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		for (const auto& dir : directions[1])
		{
			int ny = curr.first + dir.first;
			int nx = curr.second + dir.second;

			if (ny < 0 || nx < 0 || ny >= n + 1 || nx >= 2 * n + 1) continue;
			if (map[ny][nx] > 0)									continue;
			if (n - ny > 2 * n - nx)								continue;

			q.push({ ny, nx });
			map[ny][nx] = 1;

			ans = max(ans, n - ny);
		}
	}

	return map[n][2 * n] != 1 ? -1 : ans;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	vector<vector<int>> map(n + 1, vector<int>(2 * n + 1, 3));

	for (int i = 0; i < m; i++)
	{
		int x, y;	cin >> x >> y;
		map[n - y][x] = 2;
	}

	cout << bfs(map);

}

/*
4 3
2 2
4 0
6 2

ans: 2

1000 1
2000 0

ans: -1
*/