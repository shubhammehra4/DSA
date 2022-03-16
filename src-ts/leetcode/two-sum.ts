// 1 pass
function twoSum(nums: number[], target: number): number[] {
  const map: { [key: number]: number } = {}; // idx->num

  for (const [index, num] of nums.entries()) {
    if (map[target - num] !== undefined) {
      return [map[target - num], index];
    }

    map[num] = index;
  }

  return [];
}
