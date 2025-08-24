#include <bits/stdc++.h>
using namespace std;

void findSubsets(int index, int currentSum, int targetSum, vector<int>& numbers, vector<int>& subset) {
    // If the current sum equals the target sum, we found a valid subset
    if (currentSum == targetSum) {
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
        return;
    }

    // If we have processed all numbers or currentSum exceeds targetSum, return
    if (index >= numbers.size() || currentSum > targetSum) {
        return;
    }

    // Include the current number in the subset
    subset.push_back(numbers[index]);
    findSubsets(index + 1, currentSum + numbers[index], targetSum, numbers, subset);

    // Exclude the current number from the subset (backtracking)
    subset.pop_back();
    findSubsets(index + 1, currentSum, targetSum, numbers, subset);
}

int main() {
    int n, targetSum;
    cout << "Enter the number of elements: ";
    cin >> n;

    vector<int> numbers(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cout << "Enter the target sum: ";
    cin >> targetSum;

    vector<int> subset;
    cout << "Subsets that sum to " << targetSum << " are:" << endl;
    findSubsets(0, 0, targetSum, numbers, subset);

    return 0;
}