#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

multiset<int> rel;

int solve()
{
    int best = INT_MAX;
    int n = sz(rel);
    int l = 0, r = n;
    int distl = 0, distr = accumulate(all(rel), 0); 
    int pos = 0; 
    set<int>::iterator curr = rel.begin();

    while (curr != rel.end()) {
        pos++;
        distr -= r;
        distl += l;

        while (curr != rel.end() && pos == *curr) {
            l++;
            r--;
            curr++;
        } 

        best = min(best, distl + distr);
    }

    return best;
}

int main()
{
    int num;
    cin >> num;
    while (num--) {
        int n;
        cin >> n;
        rel.clear();
        while (n--) {
            int pos;
            cin >> pos;
            rel.insert(pos);
        }

        cout << solve() << endl;
    }

    return 0;
}
