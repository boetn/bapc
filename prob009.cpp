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

#define MAX 10000000
bitset<MAX> sieve;

int curr;
int digits[10];
set<int> found;

void fillsieve()
{
    sieve.set();
    sieve.set(0, 0);
    sieve.set(1, 0);

    for (int i = 4; i < MAX; i += 2)
        sieve.set(i, 0); //even getallen

    for (int i = 3; i <= ceil(sqrt(MAX)); i += 2)
        if (sieve.test(i))
            for (int j = 2 * i; j < MAX; j += i)
                sieve.set(j, 0);
}

void numgen()
{
    if (sieve.test(curr))
        found.insert(curr);
    for (int i = 0; i < 10; i++)
        if (digits[i]) {
            digits[i]--;
            curr = curr * 10 + i;
            numgen();
            digits[i]++;
            curr /= 10;
        }
}

int main()
{
    fillsieve();

    int n;
    cin >> n;

    while (n--) {
        string num;
        cin >> num;

        memset(digits, 0, sizeof(digits));
        for (int i = 0; i < sz(num); i++)
            digits[num[i] - '0']++;

        curr = 0;
        found.clear();
        numgen();

        cout << found.size() << endl;
    }

    return 0;
}
