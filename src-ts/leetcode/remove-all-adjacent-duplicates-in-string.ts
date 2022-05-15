function removeDuplicates(s: string): string {
  return s
    .split('')
    .reduce<string[]>((acc, char) => {
      if (acc[acc.length - 1] === char) {
        acc.pop();
      } else {
        acc.push(char);
      }

      return acc;
    }, [])
    .join('');
}
