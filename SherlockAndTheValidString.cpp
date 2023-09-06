#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/*
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string isValid(string s) {
    vector<int> letterCounter('z' - 'a' + 1, 0);
    int c1 = 0, n1 = 0;
    int c2 = 0, n2 = 0;
    for(char c : s) {
        if(c >= 'a' && c <= 'z') letterCounter[tolower(c) - 'a'] += 1;
    }
    string abc = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    for(int x : letterCounter) {
        cout << abc[i++] << " -> " << x << endl;
        if(x != 0) {
            if(n1 == 0) {
                n1 = x;
                c1 ++;
            }
            else if(x == n1) {
                c1 ++;
            } else if(n2 == 0) {
                if(abs(n1 - x) > 1 ) { //|| (c1 != 1 && x != 1) corrects 7 and 13, drops 5
                    cout << n1 << " differs by more than 1 with " << x << endl;
                    return "NO";
                }
                n2 = x;
                c2 ++;
            } else if(x == n2) {
                c2 ++;
            } else {
                cout << "More than three occurence frequencies: " << n1 << " != " << n2 << " != " << x << endl;
                return "NO";
            }
        }
        if(
            (c1 > 1 && c2 > 1)
        ) { // TODO Test case 5, 7 and 13
            cout << "Must remove more than 1 character: " << c1 << " / " << c2 << endl;
            return "NO";
        }
    }
    return "YES";
}

int main()
{
    string s;
    getline(cin, s);

    string result = isValid(s);

    cout << result << "\n";

    return 0;
}
