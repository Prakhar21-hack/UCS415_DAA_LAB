#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<int>& val, vector<int>& wt, int n) {
    vector<Item> items(n);
    for (int i = 0; i < n; i++) {
        items[i].value = val[i];
        items[i].weight = wt[i];
    }

    sort(items.begin(), items.end(), compare);

    int curWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++) {
        if (curWeight + items[i].weight <= W) {
            curWeight += items[i].weight;
            finalValue += items[i].value;
        }
        else {
            int remain = W - curWeight;
            finalValue += items[i].value * ((double)remain / items[i].weight);
            break;
        }
    }

    return finalValue;
}

int main() {
    int N = 3;
    vector<int> value = {100, 60, 120};
    vector<int> weight = {20, 10, 40};
    int W = 50;

    double maxVal = fractionalKnapsack(W, value, weight, N);

    cout << "Maximum value = " << maxVal << endl;

    return 0;
}