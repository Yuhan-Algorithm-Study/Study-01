#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;

long long dp(vector<long long>& vec)
{
	vector<long long> dp(k + 1, 0);
	vector<long long> sum(k + 1, 0);

	long long res = vec[0];

	for (int i = 1; i < k + 1; i++)
	{
		sum[i] += sum[i - 1] + vec[i];
	}

	long long ans = 0;
	for (int idx = 1; idx < k + 1; idx++)
	{
		if (sum[idx] > res + sum[idx + n <= k ? idx + n : k] - sum[idx - 1])
		{
			dp[idx] = sum[idx];
			res = max(res, dp[idx]);
		}
		else
		{
			dp[idx] = res + sum[idx + n <= k ? idx + n : k] - sum[idx - 1];
		}

		ans = max(dp[idx], ans);
	}

	return ans;
}

int main()
{
	cin >> k >> n;

	vector<long long> vec(k + 1, 0);

	for (int i = 1; i < k + 1; i++)
	{
		cin >> vec[i];
	}

	cout << dp(vec);

}

/*
6 5
1 -10 -10 -10 1 1
*/