function maxSubArray(nums: number[]): number {
  return nums.reduce(
    ([maxSum, currMaxSum], num) => [
      Math.max(maxSum, currMaxSum + num),
      currMaxSum + num < 0 ? 0 : currMaxSum + num,
    ],
    [-Infinity, 0]
  )[0];
}

// alter
function maxSubArrayAlter(nums: number[]): number {
  let maxSum = -Infinity;
  let currMaxSum = 0;

  for (const num of nums) {
    currMaxSum += num;
    maxSum = Math.max(maxSum, currMaxSum);

    if (currMaxSum < 0) {
      currMaxSum = 0;
    }
  }

  return maxSum;
}
