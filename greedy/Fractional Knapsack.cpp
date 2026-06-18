class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {

        int n = val.size();

        // {ratio, index}
        vector<pair<double, int>> items;

        for (int i = 0; i < n; i++) {
            items.push_back({(double)val[i] / wt[i], i});
        }

        // Sort by ratio in descending order
        sort(items.begin(), items.end(), greater<pair<double, int>>());

        double sum = 0.0;

        for (int i = 0; i < n; i++) {
            int idx = items[i].second;

            if (wt[idx] <= capacity) {
                sum += val[idx];
                capacity -= wt[idx];
            } else {
                sum += ((double)capacity / wt[idx]) * val[idx];
                break;
            }
        }

        return sum;
    }
};
