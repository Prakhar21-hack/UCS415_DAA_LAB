#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

long long boardCutting(vector<int> cost_y, vector<int> cost_x) {
    sort(cost_y.begin(), cost_y.end(), greater<int>());
    sort(cost_x.begin(), cost_x.end(), greater<int>());

    long long total_cost = 0;
    int horizontal_segments = 1;
    int vertical_segments = 1;

    int i = 0; 
    int j = 0; 

    while (i < cost_y.size() && j < cost_x.size()) {
        if (cost_y[i] >= cost_x[j]) {
            total_cost += (long long)cost_y[i] * vertical_segments;
            horizontal_segments++;
            i++;
        } else {
            total_cost += (long long)cost_x[j] * horizontal_segments;
            vertical_segments++;
            j++;
        }
    }

    while (i < cost_y.size()) {
        total_cost += (long long)cost_y[i] * vertical_segments;
        i++;
    }

    while (j < cost_x.size()) {
        total_cost += (long long)cost_x[j] * horizontal_segments;
        j++;
    }

    return total_cost;
}

int main() {
    int m = 3; 
    int n = 3; 
    
    vector<int> y = {2, 1}; 
    vector<int> x = {3, 1}; 

    cout << "Minimum total cost = " << boardCutting(y, x) << endl;

    return 0;
}