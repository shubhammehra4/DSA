function maxArea(height: number[]): number {
  let maxA = -Infinity;
  const n = height.length;

  let i = 0;
  let j = n - 1;

  while (i < j) {
    const h = Math.min(height[i], height[j]);

    maxA = Math.max(maxA, h * (j - i));

    while (height[i] <= h && i < j) {
      i += 1;
    }

    while (height[j] <= h && i < j) {
      j -= 1;
    }
  }

  return maxA;
}
