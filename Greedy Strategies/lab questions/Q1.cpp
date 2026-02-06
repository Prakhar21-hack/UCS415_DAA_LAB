#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Activity {
    int start;
    int finish;
};

bool compareActivities(Activity a1, Activity a2) {
    return a1.finish < a2.finish;
}

void printMaxActivities(vector<int>& s, vector<int>& f, int n) {
    vector<Activity> activities(n);
    for(int i = 0; i < n; i++) {
        activities[i].start = s[i];
        activities[i].finish = f[i];
    }

    sort(activities.begin(), activities.end(), compareActivities);

    vector<Activity> selected;
    
    int i = 0;
    selected.push_back(activities[i]);

    for(int j = 1; j < n; j++) {
        if(activities[j].start >= activities[i].finish) {
            selected.push_back(activities[j]);
            i = j;
        }
    }

    cout << "Maximum number of activities = " << selected.size() << endl;
    cout << "Selected activities: ";
    
    for(int k = 0; k < selected.size(); k++) {
        cout << "(" << selected[k].start << ", " << selected[k].finish << ")";
        if(k < selected.size() - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

int main() {
    int N = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> finish = {2, 4, 6, 7, 9, 9};

    printMaxActivities(start, finish, N);

    return 0;
}