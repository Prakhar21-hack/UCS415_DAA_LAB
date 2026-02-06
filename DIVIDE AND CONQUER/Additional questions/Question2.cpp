#include <iostream>
#include <algorithm>
using namespace std;

int maxGoodSubsequence(int A[], int N) {
    sort(A, A + N);

    int left = 0, maxLen = 0;

    for (int right = 0; right < N; right++) {
        while (A[right] - A[left] > 10) {
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
    }

    return maxLen;
}

int main() {
    int A[] = {4, 5, 10, 101, 2, 129, 131, 130, 118, 14};
    int N = sizeof(A)/sizeof(A[0]);

    cout << "Maximum length = "
         << maxGoodSubsequence(A, N);

    return 0;
}
