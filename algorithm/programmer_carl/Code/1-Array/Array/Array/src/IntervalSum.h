#pragma once
#include <vector>
#include <array>

class Solution
{
public:
	std::vector<int> IntervalSum(const std::vector<int>& nums, std::vector<std::array<int, 2>>& intervals)
	{
		int size = intervals.size();
		std::vector<int> preSum;
		preSum.reserve(size);
		preSum[0] = nums[0];
		for (int i = 1; i < size; i++)
			preSum[i] = preSum[i - 1] + nums[i];
		std::vector<int> result;
		result.reserve(size);
		std::cout << preSum[1] << std::endl;
		std::cout << preSum[3] << std::endl;

		for (auto& interval : intervals)
		{
			if (interval[0] == 0)
				result.push_back(preSum[interval[1]]);
			else
				result.push_back(preSum[interval[1]] - preSum[interval[0] - 1]);
		}
		return result;
	}
};