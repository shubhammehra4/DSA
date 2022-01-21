type Iterableify<T> = { [K in keyof T]: Iterable<T[K]> };

function* zipLongest<T extends Array<any>>(...toZip: Iterableify<T>): Generator<Partial<T>> {
  const iterators = toZip.map((i) => i[Symbol.iterator]());

  while (true) {
    const results = iterators.map((i) => i.next());

    if (results.every(({ done }) => done)) {
      break;
    }

    yield results.map(({ value }) => value || ' ') as Partial<T>;
  }
}

// const concatenate = (a: string, b: string | undefined) => a + (b || ' ');
function printVertically(s: string): string[] {
  const stringArray = s.split(' ').map((a) => a.split(''));
  const t: string[] = [];

  for (const iter of zipLongest(...stringArray)) {
    // t.push(iter.reduce(concatenate, '').trimEnd());
    t.push(iter.join('').trimEnd());
  }

  return t;
}
