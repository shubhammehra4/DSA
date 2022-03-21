function containsDuplicate(nums: number[]): boolean {
  const map: { [key: number]: true | undefined } = {};

  return nums.some((num) => {
    if (map[num]) {
      return true;
    }

    map[num] = true;
    return false;
  });
}
