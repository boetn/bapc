#include <iostream>
#include <string>
using namespace std;

#define MAX 20 //should be 100

//match[i] contains number of matches needed to form i
int match[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
string mi[MAX+1], ma[MAX+1];
char curr[MAX+1] = "";

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

//i is the current digit, used are the number of matchsticks so far
void fill(int i, int used)
{
    //check for smaller and bigger values
    if (mycmp(curr, mi[used]) < 0) mi[used] = curr;
    if (mycmp(curr, ma[used]) > 0) ma[used] = curr;

    //recurse further, don't start numbers with a zero
    for (int a = i ? '0' : '1'; a <= '9'; a++) {
        int next = used + match[a-'0'];
        if (next <= MAX) {
            curr[i] = a;
            curr[i+1] = '\0';
            fill(i + 1, next);
        }
    }
}

int main()
{
    //initialise 
    for (int i = 0; i <= MAX; i++) {
        mi[i] = string(MAX, '9');
        ma[i] = "0";
    }

    //precalculate the values
    fill(0, 0);

    int n;
    cin >> n;

    //print those that were asked
    while (n--) {
        int num;
        cin >> num;
        cout << mi[num] << " " << ma[num] << endl;
    }

    return 0;
}
