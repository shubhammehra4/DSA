function findMin(nums: number[]): number {
  let l = 0;
  let r = nums.length - 1;

  while (l < r) {
    const mid = l + Math.trunc((r - l) / 2);

    if (nums[mid] > nums[r]) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }

  return nums[l] ?? -1;
}
