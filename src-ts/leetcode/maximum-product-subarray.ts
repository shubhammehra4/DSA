function maxProduct(nums: number[]): number {
  if (nums.length === 0) return 0;

  return nums.slice(1).reduce(
    ([maxSoFar, minSoFar, greatestMax], num) => {
      const newMaxSoFar = Math.max(num, maxSoFar * num, minSoFar * num);
      const newMinSoFar = Math.min(num, maxSoFar * num, minSoFar * num);

      return [newMaxSoFar, newMinSoFar, Math.max(greatestMax, newMaxSoFar)];
    },
    [nums[0], nums[0], nums[0]]
  )[2];
}
