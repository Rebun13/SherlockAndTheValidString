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
    int n1 = 0, c1 = 0;
    int n2 = 0, c2 = 0;
    // n1 is the HIGHER number of occurences of a character, and c1 the counter of different characters with n1 occurences
    // n2 is the LOWER number of occurences of a character, and c2 the counter of different characters with n2 occurences
    for(char c : s) {
        if(c >= 'a' && c <= 'z') letterCounter[tolower(c) - 'a'] += 1;
    }
    string abc = "abcdefghijklmnopqrstuvwxyz";
    int i = 0;
    for(int x : letterCounter) {
        cout << abc[i++] << " -> " << x << endl;
        if(x != 0) {
            if(n1 == 0) { // NEW N1
                n1 = x;
                c1 ++;
            } else if(x == n1) { // count for N1 into C1
                c1 ++;
            } else if(n2 == 0) { // NEW N2
                if(x > n1) { // if n2 would be higher than n1, swap them and their counters
                    n2 = n1;
                    n1 = x;
                    c2 = c1;
                    c1 = 1;
                } else {
                    n2 = x;
                    c2 ++;
                }
            } else if(x == n2) { // count for N1 into C1
                c2 ++;
            } else { // too many N's
                // cout << "More than three occurence frequencies: " << n1 << " != " << n2 << " != " << x << endl;
                return "NO";
            }
        }
        if(
            (n1 - n2 > 1 && n1 > 1 && n2 > 1) || //invalid values of n1 and n2
            (c1 > 1 && c2 > 1)  || // invalid values of c1 and c2
            (n2 == 1 && c2 > 1) // need to delete more than one when n2 = 1
        ) { 
            // cout << n1 << " differs by more than 1 with " << x << endl;
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
