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

int main()
{
    //freopen("in.txt", "r", stdin);

    int n;
    cin >> n;

    while (n--) {
        string s, bad;
        cin >> bad;

        s = bad;
        sort(all(s));

        int i=0;
        do {
            if (s == bad) break;
            i++;
        } while (next_permutation(all(s)));

        cout << i << endl;
    }

    return 0;
}
