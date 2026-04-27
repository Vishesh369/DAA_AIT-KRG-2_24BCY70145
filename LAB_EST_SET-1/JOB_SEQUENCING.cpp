#include <bits/stdc++.h>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

class Solution {
    vector<int> parent;

public:

    int findSlot(int t) {
        if (t == parent[t]) return t;
        return parent[t] = findSlot(parent[t]);
    }

    vector<int> jobSequencing(vector<int>& deadline, vector<int>& profit) {
        int n = deadline.size();
        vector<Job> jobList(n);
        int maxDeadline = 0;

        for (int i = 0; i < n; i++) {
            jobList[i] = {deadline[i], profit[i]};
            maxDeadline = max(maxDeadline, deadline[i]);
        }


        sort(jobList.begin(), jobList.end(), [](const Job& a, const Job& b) {
            return a.profit > b.profit;
        });

        parent.resize(maxDeadline + 1);
        iota(parent.begin(), parent.end(), 0); 

        int jobsCount = 0;
        int totalProfit = 0;

        for (int i = 0; i < n; i++) {
            int availableSlot = findSlot(jobList[i].deadline);

            if (availableSlot > 0) {
                parent[availableSlot] = findSlot(availableSlot - 1);
                
                jobsCount++;
                totalProfit += jobList[i].profit;
            }
        }

        return {jobsCount, totalProfit};
    }
};