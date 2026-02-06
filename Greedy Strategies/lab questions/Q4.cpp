#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Job {
    string id;
    int deadline;
    int profit;
};

bool compareJobs(Job a, Job b) {
    return a.profit > b.profit;
}

bool compareIds(string a, string b) {
    int numA = stoi(a.substr(1));
    int numB = stoi(b.substr(1));
    return numA < numB;
}

void scheduleJobs(vector<string>& ids, vector<int>& deadlines, vector<int>& profits, int n) {
    vector<Job> jobs(n);
    int max_deadline = 0;

    for (int i = 0; i < n; i++) {
        jobs[i].id = ids[i];
        jobs[i].deadline = deadlines[i];
        jobs[i].profit = profits[i];
        if (deadlines[i] > max_deadline) {
            max_deadline = deadlines[i];
        }
    }

    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<string> result(max_deadline, "");
    vector<bool> slot(max_deadline, false);
    int total_profit = 0;
    vector<string> selected_jobs;

    for (int i = 0; i < n; i++) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; j--) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                total_profit += jobs[i].profit;
                selected_jobs.push_back(jobs[i].id);
                break;
            }
        }
    }

    sort(selected_jobs.begin(), selected_jobs.end(), compareIds);

    cout << "Selected Jobs: [";
    for (int i = 0; i < selected_jobs.size(); i++) {
        cout << selected_jobs[i];
        if (i < selected_jobs.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
    cout << "Maximum Profit = " << total_profit << endl;
}

int main() {
    int N = 5;
    vector<string> jobs = {"J1", "J2", "J3", "J4", "J5"};
    vector<int> deadline = {2, 1, 2, 1, 3};
    vector<int> profit = {100, 19, 27, 25, 15};

    scheduleJobs(jobs, deadline, profit, N);

    return 0;
}