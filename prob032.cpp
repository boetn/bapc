#include <iostream>
#include <string>
using namespace std;

#define MAX 100

//match[i] contains number of matches needed to form i
int match[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

//compare numbers saved as strings
int mycmp(string s1, string s2)
{
    int n = (int)s1.length();
    int m = (int)s2.length();
    if (n != m)
        return n - m;
    else
        return s1.compare(s2);
}

int main()
{
    string mi[MAX+1], ma[MAX+1];
    mi[0] = ma[0] = "";
    ma[1] = string(MAX, '9');
    for (int i = 1; i <= MAX; i++) {
        mi[i] = string(MAX, '9'); // ~infinity
        ma[i] = "";
    }

    //use previous answers to find an optimal one with i matchsticks
    for (int i = 2; i <= MAX; i++) { // matchsticks
        for (int j = 0; j < 10; j++) { // numbers
            int prev = i - match[j];
            if (prev < 0 || (!prev && !j))
                continue;
            //minimum
            string cand = mi[prev] + char(j+'0');
            if (mycmp(cand, mi[i]) < 0)
                mi[i] = cand;
            //maximum
            cand = ma[prev] + char(j+'0');
            if (mycmp(cand, ma[i]) > 0)
                ma[i] = cand;
        }
    }

    int n;
    cin >> n;
    while (n--) {
        int num;
        cin >> num;
        cout << mi[num] << " " << ma[num] << endl;
    }

    return 0;
}
