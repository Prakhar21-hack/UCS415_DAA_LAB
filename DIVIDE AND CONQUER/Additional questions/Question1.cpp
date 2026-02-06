#include <iostream>
using namespace std;

bool canDivide(int A[], int N, int M, int maxOR) {
    int segments = 1;
    int currOR = 0;

    for (int i = 0; i < N; i++) {
        if ((currOR | A[i]) <= maxOR) {
            currOR |= A[i];
        } else {
            segments++;
            currOR = A[i];

            if (segments > M) return false;
        }
    }
    return true;
}

int minimizeMaxOR(int A[], int N, int M) {
    int low = 0, high = 0;

    for (int i = 0; i < N; i++) {
        low = max(low, A[i]);
        high |= A[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canDivide(A, N, M, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return ans;
}

int main() {
    int A[] = {1, 2, 3, 4};
    int N = 4;
    int M = 2;

    cout << "Minimum possible maximum OR = "
         << minimizeMaxOR(A, N, M);

    return 0;
}
