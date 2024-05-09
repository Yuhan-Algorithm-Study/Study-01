#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n;  cin >> n;
    vector<pair<int, int>> stores(n, { 0, 0 });

    for (int idx = 0; idx < n; idx++)
    {
        cin >> stores[idx].first >> stores[idx].second;
    }

    int res = 1;
    int min_v = stores[0].first;

    for (int idx = 1; idx < n; idx++)
    {
        if (stores[idx].second < min_v)
        {
            res++;

            min_v = stores[idx].first;
        }
        else
        {
            min_v = max(min_v, stores[idx].first);
        }
    }

    cout << res;
}
