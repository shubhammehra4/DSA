function coinChange(coins: number[], amount: number): number {
  const upperLimit = amount + 1;
  const memo: number[] = Array(upperLimit).fill(upperLimit);
  memo[0] = 0;

  for (const coin of coins) {
    for (let currAmount = coin; currAmount < upperLimit; currAmount += 1) {
      memo[currAmount] = Math.min(memo[currAmount], memo[currAmount - coin] + 1);
    }
  }

  return memo[amount] === upperLimit ? -1 : memo[amount];
}
