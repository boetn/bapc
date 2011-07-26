#include <algorithm>
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

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;

        int p = a * b;
        float ans = p;

        //bij oneven aantal nodes: schuine edge om te fixen
        if (p % 2 != 0)
            ans += sqrt(2) - 1;

        cout << "Scenario #" << i << ":" << endl;
        printf("%.2f\n\n", ans);
    }

    return 0;
}
