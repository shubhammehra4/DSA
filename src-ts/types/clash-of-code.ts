/* eslint-disable @typescript-eslint/no-unused-vars */
/*
type InvertBinString<
  I extends string,
  R extends string = ''
> = I extends `${infer Head}${infer Tail}`
  ? InvertBinString<Tail, `${R}${Head extends '0' ? '1' : '0'}`>
  : R;

type Problem1 = InvertBinString<'00100'>;
*/
//
/*
type WrapLine<I, R extends string = ''> = I extends `${infer _Head}${infer Tail}`
  ? WrapLine<Tail, `${R}*`>
  : R;

type Wrap<I extends string> = `**${WrapLine<I>}**
* ${I} *
**${WrapLine<I>}**`;

type Problem2 = Wrap<'Hello How Are You!'>;
*/
//
/*
type WordCount<I, R extends 0[] = [0]> = I extends `${infer _Head} ${infer Tail}`
  ? WordCount<Tail, [...R, 0]>
  : R['length'];

type Problem3 = WordCount<'Hi How Are You'>;
*/
//
/*
type DrawLine<I, S extends 0[] = [], R extends string = ''> = S['length'] extends I
  ? R
  : DrawLine<I, [...S, 0], `${R}*`>;

type Draw<I, S extends 0[] = [], R extends string = ''> = S['length'] extends I
  ? R
  : Draw<I, [...S, 0], `${R}\n${DrawLine<I>}`>;

type Problem4 = Draw<3>;
*/
//
/*
type Min<A, B, C extends 0[] = []> = C['length'] extends A
  ? A
  : C['length'] extends B
  ? B
  : Min<A, B, [...C, 0]>;

type Max<A, B, C extends 0[] = []> = C['length'] extends A
  ? B
  : C['length'] extends B
  ? A
  : Max<A, B, [...C, 0]>;

type Problem5p1 = Min<3, 5>;

type Problem5p2 = Max<10, 5>;
*/
//
/*
type Count<I, S extends 0[] = []> = I extends S['length'] ? S : Count<I, [...S, 0]>;
type Inc<A> = [...Count<A>, 0]['length'];
type Dec<A> = Count<A> extends [infer _Head, ...infer Tail] ? Tail['length'] : 0;

type Add<A, B> = B extends 0 ? A : Add<Inc<A>, Dec<B>>;
type Sub<A, B> = B extends 0 ? A : Sub<Dec<A>, Dec<B>>;
type Mul<A, B, R = 0> = B extends 0 ? R : Mul<A, Dec<B>, Add<R, A>>;
type Div<A, B, R = 0> = A extends 0 ? R : Div<Sub<A, B>, B, Inc<R>>;
type DivFloor<A, B> = Mul<B, Div<A, B>> extends A ? Div<A, B> : Dec<Div<A, B>>;
type Mod<A, B> = Sub<A, Mul<B, DivFloor<A, B>>>;
*/
// type Cnt5 = Count<5>;
// type Inc3 = Inc<3>;
// type Dec3 = Dec<3>;
// type Res5 = Add<2, 3>;
// type Res1 = Sub<3, 2>;
// type Res15 = Mul<3, 5>;
// type Res6 = Div<12, 2>;
// type Res3 = DivFloor<10, 3>;
// type Res0 = Mod<7, 2>;
