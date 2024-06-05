
/*

*/

#include <iostream>
#include <vector>
#include <set>
using namespace std;
int N, M;
vector<int> v;
int getResult();
bool twoP(int size);
int main()
{
    cin >> N >> M;

    v.reserve(N);
    for (int i = 0; i < N; i++) {
        int t;
        cin >> t;
        v.push_back(t);
    }


    cout << getResult() << endl;
}

//이분탐색
int getResult() {
    int left = 1;
    int right = N;
    int answer = 1;
    while (left <= right) {
        int center = (left + right) / 2;
        if (twoP(center)) {
            answer = max(answer, center);
            left = center + 1;
        }
        else {
            right = center - 1;
        }
    }
    return answer;
}

//투포인터
bool twoP(int size) {
    int left = 0;
    int right = 0;
    int count = 0;
    int cardSize = 0;
    set<int> s;
    while (right < N) {
        int card = v[right];

        //찾았을 경우
        if (s.find(card) != s.end()) {
            while (v[left] != card) {
                left++;
            }
            left++;
            right = left;
            count = 0;
            s.clear();
        }
        else {
            count++;
            right++;
            s.insert(card);
        }

        if (count == size) {
            cardSize++;
            count = 0;
            left = right;
            count = 0;
            s.clear();
        }

        if (cardSize == M) {
            return true;
        }


    }

    return false;
}