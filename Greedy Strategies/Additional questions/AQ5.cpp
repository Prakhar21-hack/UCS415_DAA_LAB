#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Course {
    int id;
    int start;
    int end;
};

bool compareCourses(Course a, Course b) {
    return a.end < b.end;
}

int solveQuery(int plan_start, int plan_end, const vector<Course>& all_courses) {
    vector<Course> valid_courses;
    
    for (const auto& course : all_courses) {
        if (course.start >= plan_start && course.end <= plan_end) {
            valid_courses.push_back(course);
        }
    }
    
    if (valid_courses.empty()) {
        return 0;
    }
    
    sort(valid_courses.begin(), valid_courses.end(), compareCourses);
    
    int count = 0;
    int last_end_time = -1;
    
    for (const auto& course : valid_courses) {
        if (course.start > last_end_time) {
            count++;
            last_end_time = course.end;
        }
    }
    
    return count;
}

int main() {
    int N = 6;
    vector<int> St_i = {1, 2, 4, 6, 5, 8};
    vector<int> End_i = {3, 5, 6, 7, 9, 10};
    
    vector<Course> courses;
    for (int i = 0; i < N; i++) {
        courses.push_back({i, St_i[i], End_i[i]});
    }
    
    int Q = 3;
    vector<int> Plan_st_j = {1, 2, 4};
    vector<int> Plan_end_j = {6, 7, 10};
    
    cout << "Maximum number of courses for each plan:" << endl;
    
    for (int j = 0; j < Q; j++) {
        int result = solveQuery(Plan_st_j[j], Plan_end_j[j], courses);
        cout << "Plan " << (j + 1) << " (" << Plan_st_j[j] << " to " << Plan_end_j[j] << "): " << result << endl;
    }

    return 0;
}