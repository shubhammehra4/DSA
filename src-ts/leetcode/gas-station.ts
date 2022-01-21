function canCompleteCircuit(gas: number[], cost: number[]): number {
  let gasTank = 0;
  let total = 0;
  let start = 0;

  for (let stationIdx = 0; stationIdx < gas.length; stationIdx++) {
    const consume = gas[stationIdx] - cost[stationIdx];
    gasTank += consume;
    total += consume;
    if (gasTank < 0) {
      start = stationIdx + 1;
      gasTank = 0;
    }
  }

  return total < 0 ? -1 : start;
}

const add = (a: number, b: number) => a + b;
function canCompleteCircuitAlter(gas: number[], cost: number[]): number {
  const gasSum = gas.reduce(add);
  const costSum = cost.reduce(add);

  if (gasSum < costSum) return -1;

  let start = 0;
  let gasTank = 0;

  for (let stationIdx = 0; stationIdx < gas.length; stationIdx++) {
    gasTank += gas[stationIdx] - cost[stationIdx];

    if (gasTank < 0) {
      start = stationIdx + 1;
      gasTank = 0;
    }
  }

  return start;
}

function canCompleteCircuitBF(gas: number[], cost: number[]): number {
  const n = gas.length;

  for (let start = 0; start < n; start++) {
    let gasTank = 0;
    let station = start;
    for (station = start; station < n + start; station++) {
      gasTank += gas[station % n] - cost[station % n];

      if (gasTank < 0) break;
    }

    if (station === n + start && gasTank >= 0) return start;
  }

  return -1;
}
