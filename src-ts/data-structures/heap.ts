const Heap = <T>(comparator = (a: T, b: T) => Number(a) - Number(b)) => {
  const heap: T[] = [];

  /* Utility */

  const compare = (idx1: number, idx2: number) => comparator(heap[idx1], heap[idx2]);

  const swap = (idx1: number, idx2: number) => {
    [heap[idx1], heap[idx2]] = [heap[idx2], heap[idx1]];
  };

  const parent = (i: number) => Math.ceil(i / 2 - 1);

  const left = (i: number) => 2 * i + 1;

  const right = (i: number) => 2 * i + 2;

  const isLeaf = (i: number) => left(i) > heap.length;

  const getChildToSwap = (i: number) =>
    right(i) < heap.length && compare(left(i), right(i)) > 0 ? right(i) : left(i);

  /* Utility */

  /**
   * Get head
   * @runtime O(1)
   */
  const head = (): T => heap[heap.length - 1];

  /**
   * Is heap empty
   * @runtime O(1)
   */
  const isEmpty = () => heap.length === 0;

  /**
   * Size of heap
   * @runtime O(1)
   */
  const size = () => heap.length;

  const bubbleUp = () => {
    let idx = heap.length - 1;

    while (parent(idx) >= 0 && compare(parent(idx), idx) > 0) {
      swap(parent(idx), idx);
      idx = parent(idx);
    }
  };

  /**
   * Insert element
   * @runtime O(log n)
   */
  const add = (val: T): number => {
    heap.push(val);
    bubbleUp();
    return heap.length;
  };

  const bubbleDown = (index = 0) => {
    let curr = index;

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
  const remove = (index = 0): T | undefined => {
    if (!heap.length) return undefined;

    swap(index, heap.length - 1);
    const value = heap.pop();
    bubbleDown(index);

    return value;
  };

  return { head, add, remove, size, isEmpty };
};

const minNumHeap = Heap<number>((a, b) => a - b);
minNumHeap.add(1);
minNumHeap.add(3);
minNumHeap.add(9);
minNumHeap.add(2);
minNumHeap.add(4);
console.log(minNumHeap.head());
minNumHeap.remove();
console.log(minNumHeap.head());
