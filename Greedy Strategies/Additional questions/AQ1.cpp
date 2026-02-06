#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Customer {
    string id;
    int arrival;
    int departure;
    int preferred;
};

bool compareCustomers(Customer a, Customer b) {
    return a.departure < b.departure;
}

int solve(int K, vector<Customer>& customers) {
    vector<vector<Customer>> compartments(K + 1);

    for (int i = 0; i < customers.size(); i++) {
        compartments[customers[i].preferred].push_back(customers[i]);
    }

    int total_customers = 0;

    for (int i = 1; i <= K; i++) {
        if (compartments[i].empty()) continue;

        sort(compartments[i].begin(), compartments[i].end(), compareCustomers);

        int count = 0;
        int last_end_time = -1;

        for (int j = 0; j < compartments[i].size(); j++) {
            if (compartments[i][j].arrival >= last_end_time) {
                count++;
                last_end_time = compartments[i][j].departure;
            }
        }
        total_customers += count;
    }

    return total_customers;
}

int main() {
    int K = 3;
    int N = 6;
    vector<string> ids = {"C1", "C2", "C3", "C4", "C5", "C6"};
    vector<int> arrival = {1, 2, 3, 5, 4, 6};
    vector<int> departure = {4, 5, 6, 7, 8, 9};
    vector<int> preferred = {1, 1, 2, 1, 2, 3};

    vector<Customer> customers(N);
    for (int i = 0; i < N; i++) {
        customers[i].id = ids[i];
        customers[i].arrival = arrival[i];
        customers[i].departure = departure[i];
        customers[i].preferred = preferred[i];
    }

    cout << "Maximum number of customers that can dine = " << solve(K, customers) << endl;

    return 0;
}