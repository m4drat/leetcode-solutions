/*
 * 3Sum problem.
 *   Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]]
 *   such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
 * Example: 
 *   Input: nums = [-1,0,1,2,-1,-4]
 *   Output: [[-1,-1,2],[-1,0,1]]
 * The main idea for the solution is taken from here: 
 *   https://www.youtube.com/watch?v=qJSPYnS35SE&ab_channel=NickWhite
 */

#include <iostream>
#include <utility>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<int32_t>> threeSum(std::vector<int32_t>& nums) 
{
    std::vector<std::vector<int32_t>> solution {};
    
    if (nums.size() <= 2) {
        return std::move(solution);
    }
    
    solution.reserve(33);        
    std::sort(nums.begin(), nums.end());
    
    for (uint32_t current_num_idx = 0; current_num_idx < nums.size() - 2; current_num_idx++) {
        // Filter duplicates
        // [-1, -1, 0, ...]
        if (current_num_idx > 0 && nums[current_num_idx] == nums[current_num_idx - 1]) {
            continue;
        }

        uint32_t low_idx = current_num_idx + 1;
        uint32_t high_idx = nums.size() - 1;

        while (low_idx < high_idx) {
            if (nums[low_idx] + nums[high_idx] + nums[current_num_idx] == 0) {
                solution.emplace_back(std::vector<int32_t>{nums[current_num_idx], nums[low_idx], nums[high_idx]});
                while (low_idx < high_idx && nums[low_idx] == nums.at(low_idx + 1)) low_idx++;
                while (low_idx < high_idx && nums[high_idx] == nums.at(high_idx - 1)) high_idx--;
                low_idx++;
                high_idx--;
            } else if (nums[low_idx] + nums[high_idx] + nums[current_num_idx] < 0) {
                low_idx++;
            } else if (nums[low_idx] + nums[high_idx] + nums[current_num_idx] > 0) {
                high_idx--;
            }
        }
    }

    return std::move(solution);

    // std::unordered_map<int32_t, bool> seen_numbers {};

    // for (auto current_number_iter = nums.begin(); current_number_iter != (nums.end() - 2); ++current_number_iter) {
    //     // We have already seen this number
    //     if (seen_numbers.find(*current_number_iter) != seen_numbers.end()) {
    //         continue;
    //     } else { // We haven't seen this number, process it now
    //         seen_numbers.insert(std::make_pair(*current_number_iter, true));
    //     }

    //     auto left = current_number_iter+1;
    //     auto right = --nums.end();

    //     while (left != nums.end() && right != nums.begin()) {
    //         if (left == right) {
    //             // No solution for the current_number
    //             break;
    //         } else if (left == current_number_iter) {
    //             ++left;
    //             continue;
    //         } else if (right == current_number_iter) {
    //             --right;
    //             continue;
    //         }

    //         // We want to find such a pair that: *current_number_iter + (*left + *right) == 0
    //         // => *left + *right = -(*current_number_iter)
    //         if (*left + *right == -(*current_number_iter)) {
    //             // The solution is found
    //             solution.emplace_back(std::vector<int32_t>{*current_number_iter, *left, *right});
    //             left++;
    //         } else if (*left + *right + *current_number_iter < 0) { 
    //             left++;
    //         } else if (*left + *right + *current_number_iter > 0) {
    //             right--;
    //         }
    //     }

    // }
}

int main(int argc, char* argv[])
{
    std::vector<int32_t> task { -1, 0, 1, 2, -1, -4 };
    auto solution = threeSum(task);
    /* 
     * -1, 0, 1
     * -1, -1, 2
     */

    for (const auto& vec : solution) {
        for (const auto& number : vec) {
            std::cout << number << ", ";
        }
        std::cout << std::endl;
    }

    // task = { -1, -1, 1, 2, -1, -4 };
    // solution = threeSum(task);
    // for (const auto& vec : solution) {
    //     for (const auto& number : vec) {
    //         std::cout << number << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    // task = { 0, 0, 0, 0, 0 };
    // solution = threeSum(task);
    // for (const auto& vec : solution) {
    //     for (const auto& number : vec) {
    //         std::cout << number << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    // task = { 1, 2, -1, -2, 1 };
    // solution = threeSum(task);
    // for (const auto& vec : solution) {
    //     for (const auto& number : vec) {
    //         std::cout << number << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    return 0;
}