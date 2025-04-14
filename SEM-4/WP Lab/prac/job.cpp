#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Job structure
struct Job {
    char id;        // Job identifier
    int deadline;   // Deadline of job
    int profit;     // Profit earned if job is completed before deadline
};

// Function to schedule jobs to maximize profit
void jobScheduling(vector<Job>& jobs) {
    // Sort jobs in decreasing order of profit
    sort(jobs.begin(), jobs.end(), [](Job a, Job b) {
        return a.profit > b.profit;
    });

    // Find the maximum deadline among all jobs
    int maxDeadline = 0;
    for (const Job& job : jobs) {
        maxDeadline = max(maxDeadline, job.deadline);
    }

    // Initialize result array and slot array
    vector<char> result(maxDeadline, '-');
    vector<bool> slot(maxDeadline, false);

    // Assign jobs to slots
    for (const Job& job : jobs) {
        // Find a free slot for this job
        for (int j = min(maxDeadline - 1, job.deadline - 1); j >= 0; j--) {
            // If free slot found, assign job to it
            if (!slot[j]) {
                result[j] = job.id;
                slot[j] = true;
                break;
            }
        }
    }

        // Print the scheduled jobs
        cout << "Scheduled Jobs: ";
        for (int i = 0; i < maxDeadline; i++) {
            if (slot[i]) {
                cout << result[i] << " ";
            }
        }
        cout << endl;
    }
    
    int main() {
        vector<Job> jobs = {
            {'a', 2, 100},
            {'b', 1, 19},
            {'c', 2, 27},
            {'d', 1, 25},
            {'e', 3, 15}
        };
        
        cout << "Job Scheduling to maximize profit:" << endl;
        jobScheduling(jobs);
        
        return 0;
    }

