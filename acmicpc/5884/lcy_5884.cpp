#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
	return a.second > b.second;
}

vector<pair<int, int>> points;

bool isOk(vector<pair<int, int>>& lines)
{
	for (auto& point : points)
	{
		bool ok = false;
		for (auto& line : lines)
		{
			if (line.first == 0)
			{
				if (point.first == line.second)
				{
					ok = true;
					break;
				}
			}
			else
			{
				if (point.second == line.second)
				{
					ok = true;
					break;
				}
			}
		}

		if (ok == false) return false;
	}

	return true;
}

int main()
{
	int	n;	cin >> n;

	map<int, int> mx, my;

	for (int i = 0; i < n; ++i)
	{
		int x, y;	cin >> x >> y;

		points.push_back({ x,y });

		mx[x]++;
		my[y]++;
	}

	vector<pair<int, int>> vx(mx.begin(), mx.end());
	vector<pair<int, int>> vy(my.begin(), my.end());

	sort(vx.begin(), vx.end(), cmp);
	sort(vy.begin(), vy.end(), cmp);

	int ans = 0;

	vector<pair<int, int>> lines;
	vector<bool> v(6);
	fill(v.end() - 3, v.end(), true);

	do
	{
		lines.clear();
		int vx_count = 0;
		int vy_count = 0;
		for (int i = 0; i < 6; ++i)
		{
			if (v[i] == true)
			{
				if (i < 3)
				{
					lines.push_back({ 0, vx[vx_count++].first });
				}
				else
				{
					lines.push_back({ 1, vy[vy_count++].first });
				}
			}
			else
			{
				if (i < 3)
				{
					vx_count++;
				}
				else
				{
					vy_count++;
				}
			}
		}

		if (lines.size() == 3)
		{
			if (isOk(lines) == true)
			{
				ans = 1;
				break;
			}
		}

	} while (next_permutation(v.begin(), v.end()));

	cout << ans;
}