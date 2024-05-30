#include <iostream>
#include <queue>

using namespace std;

bool cmp(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else
	{
		return a.second < b.second;
	}
}

int n, m;
int paperCnt;
int k;

vector<pair<int, int>> wrongPaper;

bool isOk(int mid)
{
	int point = wrongPaper[0].second;
	int cnt = 1;

	for (int idx = 0; idx < k; idx++)
	{
		pair<int, int> curr = wrongPaper[idx];

		if (curr.first > mid)
		{
			return false;
		}

		if (curr.second >= point + mid)
		{
			cnt++;
			point = curr.second;
		}
	}

	return cnt <= paperCnt;
}

int solution()
{
	int left = 0;
	int right = max(n, m) + 1;

	while (left + 1 < right)
	{
		int mid = (left + right) / 2;

		if (isOk(mid) == true)
		{
			right = mid;
		}
		else
		{
			left = mid;
		}
	}

	return right;
}

void input()
{
	cin >> n >> m;

	cin >> paperCnt;

	cin >> k;

	for (int idx = 0; idx < k; idx++)
	{
		int i, j;	cin >> i >> j;
		wrongPaper.push_back({ i, j });
	}

	sort(wrongPaper.begin(), wrongPaper.end(), cmp);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	input();

	cout << solution();
}



/*
14 4
1
1
2 3

ans: 2
*/

/*
4 14
2
2
4 14
1 1

ans: 4
*/

/*
4 14
2
2
1 14
1 2

ans: 1
*/

/*
4 14
1
2
4 14
4 1

ans: 14
*/