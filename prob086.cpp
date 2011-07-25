#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
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
#include <utility>
#include <vector>
using namespace std;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)

int max_intrest(int cap, vector< pair<int, int> > &obl)
{
    int dp[cap+1];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= cap; i++) {
        int curr = 1;
        tr (obl, it) {
            int val = it->first, intr = it->second;
            if (i >= val)
                dp[i] = max(dp[i], dp[i-val] + intr);
            curr++;
        }
    }
    return dp[cap];
}

int main()
{
    int num;
    cin >> num;

    while (num--) {
        int cap, years, nobl;
        cin >> cap >> years >> nobl;
        vector< pair<int, int> > obl;

        while (nobl--) {
            int cost, intr;
            cin >> cost >> intr;
            obl.pb(make_pair(cost / 1000, intr));
        }

        while (years--)
            cap += max_intrest(cap / 1000, obl);

        cout << cap << endl;
    }

    return 0;
}
