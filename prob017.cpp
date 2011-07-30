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
#define best(a,b,c) min((a), min((b), (c)))

#define REP 5
#define INS 4
#define DEL 2

inline int rare(string s)
{
    return s == "Lys" || s == "Val" || s == "Arg" || s == "His";
}

int main()
{
    //freopen("in.txt", "r", stdin);

    int num;
    cin >> num;

    while (num--) {
        int n, m;
        cin >> n;
        string from[n];
        for (int i = 0; i < n; i++)
            cin >> from[i];
        cin >> m;
        string to[m];
        for (int i = 0; i < m; i++)
            cin >> to[i];

        int dp[m+1][n+1];
        dp[0][0] = 0;

        for (int i = 1; i <= n; i++)
            dp[0][i] = dp[0][i-1] + DEL;

        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i-1][0] + INS + rare(to[i-1]);

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (from[j-1] == to[i-1])
                    dp[i][j] = dp[i-1][j-1]; //keep
                else {
                    dp[i][j] = best( dp[i-1][j-1] + REP + rare(to[i-1]), //replace
                                     dp[i-1][j] + INS + rare(to[i-1]),   //insert
                                     dp[i][j-1] + DEL);                  //delete
                }
            }
        }

        cout << dp[m][n] << endl;
    }

    return 0;
}
