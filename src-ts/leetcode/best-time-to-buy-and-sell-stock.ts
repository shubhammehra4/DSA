function maxProfit(prices: number[]): number {
  let minPrice = INT_MAX;
  let profit = 0;

  for (const price of prices) {
    minPrice = Math.min(minPrice, price);
    profit = Math.max(profit, price - minPrice);
  }

  return profit;
}

// Alternative

function maxProfitAlter(prices: number[]): number {
  let maxProfitSoFar = 0;
  let currProfit = 0;

  for (let i = 1; i < prices.length; i += 1) {
    currProfit = Math.max(0, currProfit + (prices[i] - prices[i - 1]));

    maxProfitSoFar = Math.max(maxProfitSoFar, currProfit);
  }

  return maxProfitSoFar;
}
