import { Iterableify } from '../types/Iterablify';

export function* zip<T extends any[]>(...toZip: Iterableify<T>): Generator<T> {
  const iterators = toZip.map((i) => i[Symbol.iterator]());

  while (true) {
    const results = iterators.map((i) => i.next());

    // If any of the iterators are done, we should stop.
    if (results.some(({ done }) => done)) {
      break;
    }

    yield results.map(({ value }) => value) as T;
  }
}

export function* zipLong<T extends any[]>(...toZip: Iterableify<T>): Generator<T> {
  const iterators = toZip.map((i) => i[Symbol.iterator]());

  while (true) {
    const results = iterators.map((i) => i.next());

    if (!results.some(({ done }) => done)) {
      break;
    }

    yield results.map(({ value }) => value) as T;
  }
}
