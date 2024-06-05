#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int n, m;
vector<int> card;

bool isOk(int mid)
{
	int groupCnt = 0;

	unordered_map<int, int> cardGroupMap;
	queue<int> cardGroupQueue;

	for (int idx = 0; idx < n; idx++)
	{
		int cardNum = card[idx];

		if (cardGroupMap.find(cardNum) != cardGroupMap.end())
		{
			int firstCard;
			do
			{
				firstCard = cardGroupQueue.front();

				cardGroupMap.erase(firstCard);
				cardGroupQueue.pop();

			} while (firstCard != cardNum);
		}

		cardGroupMap[cardNum]++;
		cardGroupQueue.push(cardNum);

		if (cardGroupMap.size() == mid)
		{
			cardGroupMap.clear();
			cardGroupQueue = queue<int>();

			if (++groupCnt == m)
			{
				return true;
			}
		}
	}

	return false;
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		int num;	cin >> num;
		card.push_back(num);
	}

	int left = 0;
	int right = n / m + 1;

	while (left + 1 < right)
	{
		int mid = (left + right) / 2;

		if (isOk(mid) == true)
		{
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	cout << left;
}