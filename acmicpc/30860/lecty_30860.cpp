
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	vector<pair<int,int>> stores(n,{0,0});

	for(int i=0;i<n;i++){
		cin >> stores[i].first>>stores[i].second;
	}

	int res=1;
	int min_v = stores[0].first;

	for(int i=1;i<n;i++)
	{
		if(stores[i].second<min_v)
		{
			res++;
			min_v = stores[i].first;
		}
		else
		{
			min_v = max(min_v,stores[i].first);
		}

	}

	cout << res;
}
