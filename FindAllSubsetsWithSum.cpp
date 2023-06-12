#include <iostream>
#include <vector>

void subsetSum(std::vector<int>& nums, int target) {
  int n = nums.size();
  int subsetCount = 1 << n;

  for (int i = 0; i < subsetCount; ++i) {
    int currentSum = 0;
    std::vector<int> currentSubset;

    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) {
        currentSum += nums[j];
        currentSubset.push_back(nums[j]);
      }
    }

    if (currentSum == target) {
      // Found a subset with the target sum
      std::cout << "Subset with sum " << target << ": ";
      for (int num : currentSubset) {
        std::cout << num << " ";
      }
      std::cout << std::endl;
    }
  }
}

int main() {
  std::vector<int> nums = {1, 2, 3, 4, 5, 8,9,3,5};
  int target = 10;

  subsetSum(nums, target);

  return 0;
}

