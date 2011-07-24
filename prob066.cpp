#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int freq[10];

int checksum(int a, int b, int c, int d)
{
    if (a == b + c + d) return 1;
    if (b == a + c + d) return 1;
    if (c == a + b + d) return 1;
    if (d == a + b + c) return 1;
    if (a + b == c + d) return 1;
    if (a + c == b + d) return 1;
    if (a + d == b + c) return 1;
    return 0;
}

void add(int n, int fix=0)
{
    freq[n%10]++;
    if (fix || n/10) // :)
        freq[n/10]++;
}

int checkfreq()
{
    int prev=0;
    for (int i=0; i<10; i++) {
        if (!freq[i]) continue;
        if (prev) {
            if (freq[i] != prev)
                return 0;
        }
        else
            prev = freq[i];
    }
    return 1;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    int n;
    cin >> n;

    while (n--) {
        int a, b, c, d;
        cin >> a >> b >> c;
        d = c % 100;
        c /= 100;

        for (int i=0; i<10; i++)
            freq[i]=0;
        add(a); add(b); add(c); add(d, 1);
        int nice = checksum(a, b, c, d) && checkfreq();

        if (nice) 
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}
