function climbStairs(n: number, a = 1, b = 2): number {
  if (n === 1) return a;

  if (n === 2) return b;

  return climbStairs(n - 1, b, a + b);
}

function climbStairsIter(n: number): number {
  let a = 1;
  let b = 1;

  for (let i = 2; i <= n; i += 1) {
    [a, b] = [b, a + b];
  }

  return b;
}
