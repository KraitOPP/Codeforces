#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if a given permutation has any subarray sum divisible by n + 1
bool isValidPermutation(const vector<int>& perm, int n) {
    int mod = n + 1;
    for (int i = 0; i < perm.size(); i++) {
        int sum = 0;
        for (int j = i; j < perm.size(); j++) {
            sum += perm[j];
            if (sum % mod == 0) {
                return false; // Found a subarray sum divisible by n + 1
            }
        }
    }
    return true;
}

// Main function to generate all permutations and filter valid ones
void generatePermutations(int n) {
    vector<int> nums;

    // Initialize the array with numbers from 1 to n
    for (int i = 1; i <= n; i++) {
        nums.push_back(i);
    }

    // Generate all permutations using std::next_permutation
    do {
        if (isValidPermutation(nums, n)) {
            // Print the valid permutation
            for (int num : nums) {
                cout << num << " ";
            }
            cout << endl;
        }
    } while (next_permutation(nums.begin(), nums.end()));
}

int main() {
    int n;
    cout << "Enter the length of the permutation (n): ";
    cin >> n;

    cout << "Permutations of length " << n << " without any subarray sum divisible by " << n + 1 << ":\n";
    generatePermutations(n);

    return 0;
}
