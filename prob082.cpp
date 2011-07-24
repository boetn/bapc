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

void solve(int n, set< pair<int, int> > &hatches)
{
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (hatches.find(make_pair(x, y)) != hatches.end())
                continue;
            bool good = 1;
            tr (hatches, h) {
                double dist = sqrt(pow(x - h->first, 2) + pow(y - h->second, 2));
                if (x - dist < 0 || x + dist > n || y - dist < 0 || y + dist > n) {
                    good = 0;
                    break;
                }
            }
            if (good) {
                cout << x << " " << y << endl;
                return;
            }
        }
    }
    cout << "poodle" << endl;
}

int main()
{
    int n;
    cin >> n;

    while (n--) {
        int S, H;
        set< pair<int, int> > hatches;
        cin >> S >> H;

        while (H--) {
            int x, y;
            cin >> x >> y;
            hatches.insert(make_pair(x, y));
        }

        solve(S, hatches);
    }

    return 0;
}
