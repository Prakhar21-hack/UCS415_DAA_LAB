#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isPowerOfTwo(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

string lexicographicallySmallest(string s, int k) {
    int n = s.length();
    
    if (isPowerOfTwo(n)) {
        k = k / 2;
    } else {
        k = 2 * k;
    }

    if (k >= n) {
        return "";
    }

    string result = "";
    
    for (char c : s) {
        while (k > 0 && !result.empty() && result.back() > c) {
            result.pop_back();
            k--;
        }
        result.push_back(c);
    }
    
    while (k > 0) {
        result.pop_back();
        k--;
    }

    return result;
}

int main() {
    string S = "fooland";
    int k = 2;

    string result = lexicographicallySmallest(S, k);

    cout << "Output: " << "\"" << result << "\"" << endl;

    return 0;
}