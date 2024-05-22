// ConsoleApplication1.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
vector<int> v1;
bool getHap(int value);
int MAX_VALUE = 0;
int main()
{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int i = 0; i < T; i++) {
        int M;
        cin >> M;
        v1.clear();

        for (int j = 0; j < M; j++) {
            int t;
            cin >> t;
            v1.push_back(t);
        }

        vector<int> v2;
        int hap = 0;
        for (auto it = v1.begin(); it != v1.end(); it++) {
            hap += *it;
            v2.push_back(hap);
        }

        for (auto it = v2.begin(); it != v2.end(); it++) {
            if (getHap(*it)) {
                cout << MAX_VALUE << endl;
                break;
            }
        }


    }
}

bool getHap(int value) {

    int curr = 0;

    for (auto it = v1.begin(); it != v1.end(); it++) {
        curr += *it;
        if (value == curr) {
            curr = 0;
        }

        if (value < curr) {
            return false;
        }
    }
    if (curr == 0) {
        MAX_VALUE = value;
        return true;
    }
    else {
        return false;
    }

}