function networkDelayTime(times: number[][], n: number, k: number): number {
  const time: number[] = Array(n + 1).fill(Infinity);
  time[0] = -1;
  time[k] = 0;

  for (let i = 0; i < n; i += 1) {
    let shouldExit = true;

    for (const [u, v, t] of times) {
      if (time[u] !== Infinity && time[v] > time[u] + t) {
        time[v] = time[u] + t;
        shouldExit = false;
      }
    }

    if (shouldExit) break;
  }

  const res = Math.max(...time);

  return res === Infinity ? -1 : res;
}
