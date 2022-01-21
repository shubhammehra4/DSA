export type Iterableify<T> = { [K in keyof T]: Iterable<T[K]> };

// examples
type T1 = Iterableify<string[]>; // Iterable<string>[]
type T2 = Iterableify<{ a: number; b: string }>; // {a: Iterable<number>, b: Iterable<string>}
type T3 = Iterableify<[number, string][]>; // Iterable<[number, string]>[]
