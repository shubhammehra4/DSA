/* eslint-disable prefer-template */
function simplifyPath(path: string): string {
  return (
    '/' +
    path
      .split('/')
      .reduce<string[]>((acc, token) => {
        if (token === '.' || token === '') return acc;

        if (token !== '..') acc.push(token);
        else if (acc.length > 0) acc.pop();

        return acc;
      }, [])
      .join('/')
  );
}
