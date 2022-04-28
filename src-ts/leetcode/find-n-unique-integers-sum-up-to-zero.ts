const sumZero = (n: number): number[] => {
  return new Int16Array(Math.floor(n / 2)).reduce(
    (acc, _, i) => {
      acc.push(i + 1);
      acc.push(-(i + 1));
      return acc;
    },
    n % 2 === 1 ? [0] : []
  );
};

const sumZeroAlter = (n: number): number[] => {
  const ret = [];

  for (let i = 1; i <= Math.floor(n / 2); i += 1) {
    ret.push(i);
    ret.push(-i);
  }

  if (n % 2 !== 0) {
    ret.push(0);
  }

  return ret;
};
