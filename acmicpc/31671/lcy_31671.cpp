#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int n, m;	cin >> n >> m;

	vector<vector<int>> map(n + 1, vector<int>(2 * n + 1, 0));

	for (int i = 0; i < m; i++)
	{
		int x, y;	cin >> x >> y;
		map[n - y][x] = 2;
	}

	queue<pair<int, int>> q;
	vector<pair<int, int>> direct = { { -1, 1}, {1 , 1} };

	q.push({ n, 0 });
	map[n][0] = 1;

	int ans = -1;

	while (!q.empty())
	{
		pair<int, int> curr = q.front();
		q.pop();

		for (int dir = 0; dir < 2; dir++)
		{
			int ny = curr.first + direct[dir].first;
			int nx = curr.second + direct[dir].second;

			if (ny < 0 || nx < 0 || ny >= n + 1 || nx >= 2 * n + 1) continue;
			if (map[ny][nx] > 0)									continue;
			if (n - ny > 2 * n - nx)								continue;

			q.push({ ny, nx });
			map[ny][nx] = 1;

			ans = max(ans, n - ny);
		}
	}

	map[n][2 * n] != 1 ? cout << -1 : cout << ans;

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