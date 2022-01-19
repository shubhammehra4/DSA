const PriorityQueue = <T>(comparator = (a: T, b: T) => Number(a) - Number(b)) => {
  const queue: T[] = [];

  /* Utility */

  const compare = (idx1: number, idx2: number) => comparator(queue[idx1], queue[idx2]);

  const swap = (idx1: number, idx2: number) => {
    [queue[idx1], queue[idx2]] = [queue[idx2], queue[idx1]];
  };

  const parent = (i: number) => Math.ceil(i / 2 - 1);

  const left = (i: number) => 2 * i + 1;

  const right = (i: number) => 2 * i + 2;

  const isLeaf = (i: number) => left(i) > queue.length;

  const getChildToSwap = (i: number) =>
    right(i) < queue.length && compare(left(i), right(i)) > 0 ? right(i) : left(i);

  /* Utility */

  /**
   * Get head
   * @runtime O(1)
   */
  const top = (): T => queue[queue.length - 1];

  /**
   * Is queue empty
   * @runtime O(1)
   */
  const isEmpty = () => queue.length === 0;

  /**
   * Size of queue
   * @runtime O(1)
   */
  const size = () => queue.length;

  const bubbleUp = () => {
    let idx = queue.length - 1;

    while (parent(idx) >= 0 && compare(parent(idx), idx) > 0) {
      swap(parent(idx), idx);
      idx = parent(idx);
    }
  };

  /**
   * Insert element
   * @runtime O(log n)
   */
  const push = (val: T): number => {
    queue.push(val);
    bubbleUp();
    return queue.length;
  };

  const bubbleDown = () => {
    let curr = 0;

    while (!isLeaf(curr) && compare(curr, getChildToSwap(curr)) > 0) {
      const next = getChildToSwap(curr);
      swap(curr, next);
      curr = next;
    }
  };

  /**
   * Remove element
   * @runtime O(log n)
   */
  const pop = (): T | undefined => {
    if (!queue.length) return undefined;

    swap(0, queue.length - 1);
    const value = queue.pop();
    bubbleDown();

    return value;
  };

  return { top, push, pop, size, isEmpty };
};
