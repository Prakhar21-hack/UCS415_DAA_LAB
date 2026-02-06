#include <iostream>
using namespace std;

int maxSubarraySum(int arr[], int n) {
    int maxSoFar = arr[0];
    int currentSum = arr[0];

    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSoFar = max(maxSoFar, currentSum);
    }

    return maxSoFar;
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Maximum subarray sum = " << maxSubarraySum(arr, n);

    return 0;
}
