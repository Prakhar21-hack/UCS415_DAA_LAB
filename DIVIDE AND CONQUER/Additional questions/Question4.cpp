#include <iostream>
#include <vector>
using namespace std;

bool isSpecial(vector<int>& A, int idx, int k) {
    int n = A.size();
    int x = A[idx];

    vector<int> B(n);
    for(int i=0;i<n;i++)
        B[i] = (A[i] > x) ? 1 : 0;

    for(int L=0; L<n; L++){
        int sum=0;
        for(int R=L; R<n; R++){
            sum += B[R];

            if(sum == k && L<=idx && idx<=R)
                return true;

            if(sum > k) break;
        }
    }
    return false;
}

int main(){
    vector<int> A = {4,3,2,7,8};
    int k = 2;

    int specialty = 0;

    for(int i=0;i<A.size();i++){
        if(isSpecial(A,i,k))
            specialty += A[i];
    }

    cout<<"Specialty = "<<specialty;
}
