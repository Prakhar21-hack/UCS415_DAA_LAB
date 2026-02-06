#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int median(vector<int> v) {
    sort(v.begin(), v.end());
    return v[v.size()/2];
}

int main() {
    vector<int> A = {1,2,3,4};

    int ops = A.size() - 2;

    while (ops--) {
        vector<int> medians;

        for (int len = 3; len <= A.size(); len += 2) {
            for (int i = 0; i + len <= A.size(); i++) {
                vector<int> sub(A.begin()+i, A.begin()+i+len);
                medians.push_back(median(sub));
            }
        }

        int minMed = *min_element(medians.begin(), medians.end());

        auto it = find(A.begin(), A.end(), minMed);
        if (it != A.end()) A.erase(it);
    }

    cout << A[0] + A[1];
}
