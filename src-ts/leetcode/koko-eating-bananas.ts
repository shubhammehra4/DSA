/* eslint-disable no-restricted-syntax */
function minEatingSpeed(piles: number[], h: number): number {
  let start = 0;
  let end = Math.max(...piles);

  // const getHoursSpent = (rate: number) =>
  //   piles.reduce((hours, pile) => hours + Math.ceil(pile / rate), 0);

  const getHoursSpent = (rate: number) => {
    let hours = 0;
    for (const pile of piles) hours += Math.ceil(pile / rate);

    return hours;
  };

  while (start < end) {
    const rate = Math.floor((start + end) / 2);

    if (getHoursSpent(rate) <= h) {
      end = rate;
    } else {
      start = rate + 1;
    }
  }

  return end;
}
