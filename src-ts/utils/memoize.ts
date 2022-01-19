export const memoize = <T extends (...args: any[]) => any>(func: T) => {
  const cache: { [key: string]: ReturnType<T> } = {};

  return (...args: Parameters<T>) => {
    const key = JSON.stringify(args);

    if (cache[key] !== undefined) {
      return cache[key];
    }
    cache[key] = func(...args);

    return cache[key];
  };
};

type PrimitiveTypes = number | string | boolean;
export const memoizeArity2 = <T extends (a: PrimitiveTypes, b: PrimitiveTypes) => any>(func: T) => {
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

export const memoizeArity3 = <
  T extends (a: PrimitiveTypes, b: PrimitiveTypes, c: PrimitiveTypes) => any
>(
  func: T
) => {
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

export const dependencyMemoize = <T extends (...args: any[]) => any>(
  func: T,
  getDependecy: (...args: Parameters<T>) => string
) => {
  const cache: { [key: string]: ReturnType<T> } = {};

  return (...args: Parameters<T>) => {
    const key = getDependecy(...args);

    if (cache[key] !== undefined) {
      return cache[key];
    }
    cache[key] = func(...args);

    return cache[key];
  };
};
