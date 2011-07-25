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

int main()
{
    int n;
    cin >> n;

    while (n--) {
        vector<string> res;
        set<string> lost;
        set<string> teams;

        for (int i = 0; i < 16; i++) {
            string t1, t2;
            int g1, g2;
            cin >> t1 >> t2 >> g1 >> g2;

            lost.insert(g1 < g2 ? t1 : t2);
            teams.insert(t1);
            teams.insert(t2);
        }

        //enige ploeg die niet in beide sets zit is de ploeg die nog nooit verloor
        set_symmetric_difference(all(lost), all(teams), back_inserter(res));
        cout << res[0] << endl;
    }

    return 0;
}
