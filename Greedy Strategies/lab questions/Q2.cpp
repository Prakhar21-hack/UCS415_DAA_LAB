#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int convertToMinutes(string time) {
    int h = stoi(time.substr(0, 2));
    int m = stoi(time.substr(3, 2));
    return h * 60 + m;
}

int findMinPlatforms(vector<string>& at_str, vector<string>& dt_str, int n) {
    vector<int> arr(n);
    vector<int> dep(n);

    for(int i = 0; i < n; i++) {
        arr[i] = convertToMinutes(at_str[i]);
        dep[i] = convertToMinutes(dt_str[i]);
    }

    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int platforms_needed = 1;
    int result = 1;
    int i = 1;
    int j = 0;

    while (i < n && j < n) {
        if (arr[i] <= dep[j]) {
            platforms_needed++;
            i++;
        }
        else {
            platforms_needed--;
            j++;
        }

        if (platforms_needed > result)
            result = platforms_needed;
    }

    return result;
}

int main() {
    vector<string> AT = {"09:00", "09:10", "09:20", "11:00", "11:20"};
    vector<string> DT = {"09:40", "12:00", "09:50", "11:30", "11:40"};
    int n = AT.size();

    int min_platforms = findMinPlatforms(AT, DT, n);

    cout << "Minimum number of platforms required = " << min_platforms << endl;

    return 0;
}