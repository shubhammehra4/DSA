function minimumTotal(triangle: number[][]): number {
  const n = triangle.length;
  const dp = triangle[n - 1];

  for (let depth = n - 2; depth >= 0; depth--) {
    for (let i = 0; i <= depth; i++) {
      dp[i] = triangle[depth][i] + Math.min(dp[i], dp[i + 1]);
    }
  }

  return dp[0];
}

// recursive
const memoizeMinimumTotal = (fn: (d: number, i: number) => number) => {
  const memo: { [key: string]: number } = {};

  return (d: number, i: number) => {
    const key = `${d}|${i}`;

    if (memo[key] !== undefined) return memo[key];

    memo[key] = fn(d, i);

    return memo[key];
  };
};

function minimumTotalRec(triangle: number[][]): number {
  const n = triangle.length;

  const minimumTotalUtil = memoizeMinimumTotal((depth: number, i: number): number => {
    if (depth >= n) return 0;

    if (i >= depth + 1) return Infinity;

    return (
      triangle[depth][i] +
      Math.min(minimumTotalUtil(depth + 1, i), minimumTotalUtil(depth + 1, i + 1))
    );
  });

  return minimumTotalUtil(0, 0);
}
