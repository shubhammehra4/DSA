// iterative
function rob(nums: number[]): number {
  let a = 0;
  let b = 0;

  for (const num of nums) {
    [a, b] = [Math.max(b + num, a), a];
  }

  return a;
}

// recursive memo
function robMemo(nums: number[]): number {
  const memoize = (fn: (a: number) => number) => {
    const memo: { [key: number]: number } = {};

    return (i: number) => {
      if (memo[i] !== undefined) return memo[i];

      memo[i] = fn(i);
      return memo[i];
    };
  };

  const robUtilMemo = memoize((i: number): number => {
    if (i < 0) return 0;

    return Math.max(robUtilMemo(i - 2) + nums[i], robUtilMemo(i - 1));
  });

  return robUtilMemo(nums.length - 1);
}

// naive
function robNaive(nums: number[]): number {
  function robUtil(i: number): number {
    if (i < 0) return 0;

    return Math.max(robUtil(i - 2) + nums[i], robUtil(i - 1));
  }

  return robUtil(nums.length - 1);
}
