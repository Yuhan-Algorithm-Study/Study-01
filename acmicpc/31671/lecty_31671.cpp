#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
using namespace std;
int M,N;
vector<pair<int,int>> teacher;
int bfs();
bool availableLine(int x, int y);
bool isTeacher(int x,int y);

int** dp;

int main()
{
	cin>>N>>M;
	teacher.resize(M);
	dp = new int*[2*N];
	for(int i=0;i<2*N;i++)
		dp[i] = new int[N];
	for(int i=0;i<2*N;i++)
		for(int j=0;j<N;j++)
			dp[i][j]=0;
	for(int i=0;i<M;i++)
	{
		cin >> teacher[i].first>>teacher[i].second;
	}

	cout << bfs();
}

int bfs()
{
	int res=0;
	deque<pair<int,int>> dq;
	dq.push_back({0,0});
	while(!dq.empty())
	{
		
		pair<int,int> p = dq.front();
		dq.pop_front();
		if(p.first==2*N)
			return res;
		if(dp[p.first][p.second]==1)
			continue;


		res = max(res,p.second);
		int dx = p.first+1;
		int dy = p.second+1;
		if(availableLine(dx,dy))
		{
			if(!isTeacher(dx,dy))
					dq.push_back({dx,dy});
		}
		dy = p.second-1;
		if(availableLine(dx,dy))
		{
			if(!isTeacher(dx,dy))
					dq.push_back({dx,dy});
		}

	}
	return -1;
}

bool availableLine(int x,int y)
{
	if(y<0||y>N||x>2*N)
		return false;
	
	if(x+y>2*N)
		return false;

	return true;
}

bool isTeacher(int x,int y)
{
	int i=0;
	for(i=0;i<teacher.size();++i)
	{
		if(teacher[i].first==x&&teacher[i].second==y)
			return true;
	}
	return false;
}
