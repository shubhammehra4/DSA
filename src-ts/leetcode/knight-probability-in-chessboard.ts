/* eslint-disable sonarjs/cognitive-complexity */
/* eslint-disable no-restricted-syntax */
const directions = [
  [-2, -1],
  [-1, -2],
  [1, -2],
  [2, -1],
  [2, 1],
  [1, 2],
  [-1, 2],
  [-2, 1],
];
const memoizeProbability = <T extends (a: any, b: any, c: any) => any>(func: T) => {
  const cache: { [key: string]: ReturnType<T> } = {};

  return (a: Parameters<T>[0], b: Parameters<T>[1], c: Parameters<T>[2]) => {
    const key = `${a}|${b}|${c}`;

    if (cache[key] !== undefined) {
      return cache[key];
    }
    cache[key] = func(a, b, c);

    return cache[key];
  };
};

const knightProbability = (n: number, k: number, r: number, c: number): number => {
  const calculateProbability = memoizeProbability(
    (movesLeft: number, row: number, col: number): number => {
      if (row < 0 || col < 0 || row >= n || col >= n) return 0;

      if (movesLeft === 0) return 1;

      let ans = 0;
      for (const [x, y] of directions) {
        ans += calculateProbability(movesLeft - 1, row + x, col + y);
      }

      return ans / 8;
    }
  );

  return calculateProbability(k, r, c);
};

/*
const getDirections = ([i, j]: [number, number]): [number, number][] => [
  [i - 2, j - 1],
  [i - 2, j + 1],
  [i - 1, j - 2],
  [i - 1, j + 2],
  [i + 1, j - 2],
  [i + 1, j + 2],
  [i + 2, j - 1],
  [i + 2, j + 1],
];

const memoizeProbability = <T extends (a: any, b: any) => any>(func: T) => {
  const cache: { [key: string]: ReturnType<T> } = {};

  return (a: Parameters<T>[0], b: Parameters<T>[1]) => {
    const key = `${a}|${b}`;
    if (cache[key] !== undefined) {
      return cache[key];
    }
    cache[key] = func(a, b);

    return cache[key];
  };
};

const knightProbability = (n: number, k: number, r: number, c: number): number => {
  const isOutOfBounds = ([i, j]: [number, number]) => i < 0 || j < 0 || i >= n || j >= n;

  const calculateProbability = memoizeProbability(
    (movesLeft: number, pos: [number, number]): number => {
      if (isOutOfBounds(pos)) return 0;

      if (movesLeft === 0) return 1;

      let ans = 0;
      for (const next of getDirections(pos)) {
        ans += calculateProbability(movesLeft - 1, next);
      }

      return ans / 8;
    }
  );

  return calculateProbability(k, [r, c]);
};
*/

function knightProbabilityIter(n: number, k: number, row: number, column: number) {
  let probBoard = Array(n)
    .fill(0)
    .map(() => Array<number>(n).fill(1));

  let nextProbBoard = Array(n)
    .fill(0)
    .map(() => Array<number>(n).fill(0));

  const isOutOfBounds = ([i, j]: [number, number]) => i < 0 || j < 0 || i >= n || j >= n;

  for (let step = 0; step < k; step++) {
    for (let r = 0; r < n; r++) {
      for (let c = 0; c < n; c++) {
        let probs = 0;
        for (const [x, y] of directions) {
          if (!isOutOfBounds([r + x, c + y])) {
            probs += probBoard[r + x][c + y];
          }
        }
        nextProbBoard[r][c] = probs / 8;
      }
    }

    [probBoard, nextProbBoard] = [nextProbBoard, probBoard];
  }

  return probBoard[row][column];
}
