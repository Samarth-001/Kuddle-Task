#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
    int test;
    cin >> test;
    
    while (test--) {
        int n, k;
        cin >> n >> k;
        
        vector<int> categories(n);
        vector<int> cooking_times(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> categories[i];
        }
        
        for (int i = 0; i < n; ++i) {
            cin >> cooking_times[i];
        }
        
        // Use a map to store the minimum cooking time for each category
        unordered_map<int, int> min_time_per_category;
        
        for (int i = 0; i < n; ++i) {
            int category = categories[i];
            int time = cooking_times[i];
            
            if (min_time_per_category.find(category) == min_time_per_category.end() ||
                time < min_time_per_category[category]) {
                min_time_per_category[category] = time;
            }
        }
        
        // If the number of distinct categories is less than k, it's not possible to have a complete meal
        if (min_time_per_category.size() < k) {
            cout << -1 << endl;
            continue;
        }
        
        // Collect all minimum times in a vector and sort it
        vector<int> min_times;
        for (auto it = min_time_per_category.begin(); it != min_time_per_category.end(); ++it) {
            min_times.push_back(it->second);
        }
        
        sort(min_times.begin(), min_times.end());
        
        // Sum up the smallest k times
        int total_time = 0;
        for (int i = 0; i < k; ++i) {
            total_time += min_times[i];
        }
        
        cout << total_time << endl;
    }
    
    return 0;
}
