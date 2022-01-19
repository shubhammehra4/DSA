const mostPoints = (questions: number[][]): number => {
  const n = questions.length;

  const memoizeQuestions = <T extends (a: any) => any>(func: T) => {
    const cache: { [key: string]: ReturnType<T> } = {};

    return (a: Parameters<T>[0]) => {
      if (cache[a] !== undefined) {
        return cache[a];
      }
      cache[a] = func(a);

      return cache[a];
    };
  };

  const solveQuestions = memoizeQuestions((index): number => {
    if (index >= n) return 0;

    const [points, power] = questions[index];

    return Math.max(points + solveQuestions(index + 1 + power), solveQuestions(index + 1));
  });

  return solveQuestions(0);
};

const mostPointsIter = (questions: number[][]): number => {
  const n = questions.length;
  const memo = new Array(n + 1).fill(0);
  memo[n] = 0;

  for (let idx = n - 1; idx >= 0; idx--) {
    const [points, power] = questions[idx];

    const solveQuestion = points + (idx + 1 + power <= n ? memo[idx + 1 + power] : 0);
    const leaveQuestion = memo[idx + 1];
    memo[idx] = Math.max(solveQuestion, leaveQuestion);
  }

  return memo[0];
};
