function maxProfit(prices: number[]): number {
  return prices
    .slice(1)
    .reduce(
      ([prevPrice, profit], price) =>
        prevPrice < price ? [price, profit + price - prevPrice] : [price, profit],
      [prices[0], 0]
    )[1];
}

// Alternative

function maxProfitAlter(prices: number[]): number {
  return prices.reduce(
    ([prevPrice, profit], price, idx) =>
      idx !== 0 && prevPrice < price ? [price, profit + price - prevPrice] : [price, profit],
    [0, 0]
  )[1];
}
