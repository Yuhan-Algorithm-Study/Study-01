
// solved1
/*
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--)
    {
        int m; cin >> m;
        vector<int> sum(m + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            int num; cin >> num;
            sum[i] = sum[i - 1] + num;
        }

        int end = 1;
        int ans = sum[m];
        int value = sum[end] - sum[0];

        int temp_end = 0;
        int temp_start = 0;

        while (end <= m)
        {

            int left = temp_end;
            int right = m;
            while (left < right)
            {
                int mid = (left + right) / 2;
                if (sum[mid] - sum[temp_start] < value)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid;
                }
            }

            temp_end = left;

            int temp_sum = (temp_end <= m) ? sum[temp_end] - sum[temp_start] : 0;

            if (temp_sum == value)
            {
                if (temp_end == m)
                {
                    ans = min(ans, value);
                    break;
                }
                temp_start = temp_end;
            }
            else
            {
                if (++end > m) break;
                temp_end = end;
                temp_start = temp_end;
                value = sum[end] - sum[0];
            }
        }

        cout << ans << "\n";
    }
}

*/

// solved2
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int t; cin >> t;

    while (t--)
    {
        int m; cin >> m;
        vector<int> sum(m + 1, 0);

        for (int i = 1; i <= m; i++)
        {
            int num; cin >> num;
            sum[i] = sum[i - 1] + num;
        }

        int value = 0;
        int preValue = -1;

        int start = 0;
        int end = 1;
        int point = 1;
        while (end <= m)
        {
            value = sum[end] - sum[start];

            if (value < preValue)
            {
                end++;
            }
            else if (sum[m] % value == 0 && (preValue == value || preValue == -1))
            {
                preValue = value;
                start = end;
                end++;
            }
            else
            {
                start = 0;
                end = ++point;

                preValue = -1;
            }
        }

        cout << value << "\n";
    }
}