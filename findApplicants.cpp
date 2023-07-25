#include <iostream>
#include <vector>
#include <algorithm>
//i hated this

using namespace std;

typedef pair<float, float> Applicant;

bool isBetter(const Applicant &a, const Applicant &b) {
    if (a.first > b.first && a.second < b.second) // applicant a has a higher WPM and a lower IPM, then a is better
        return true;
    else if (b.first > a.first && b.second < a.second) // b has a higher WPM and a lower IPM, then b is better
        return false;
    else if (a.first == b.first && a.second < b.second) // applicants have the same WPM, then compare IPM
        return true;
    else if (b.first == a.first && b.second < a.second) //applicants have the same WPM and IPM, then they are the same
        return false;
    else
        return false;
}

vector<int> recursiveBestApplicant(const vector<Applicant>& applicant, int start, int end) {
    vector<int> eligible;
    if (start == end) {
        eligible.push_back(start);
        return eligible;
    }

    int middle = start + (end - start) / 2;
    vector<int> left = recursiveBestApplicant(applicant, start, middle);
    vector<int> right = recursiveBestApplicant(applicant, middle + 1, end);

    for (auto i : left) {
        bool flag = true;
        for (auto j : right) {
            if (isBetter(applicant[j], applicant[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            eligible.push_back(i);
        }
    }

    for (auto i : right) {
        bool flag = true;
        for (auto j : left) {
            if (isBetter(applicant[j], applicant[i])) {
                flag = false;
                break;
            }
        }
        if (flag) {
            eligible.push_back(i);
        }
    }
    return eligible;
}

std::vector<int> BestApplicants(const vector<Applicant>& applicants){
    int n = static_cast<int>(applicants.size() - 1);
    vector<int> eligible = recursiveBestApplicant(applicants, 0, n - 1);
    return eligible;
}