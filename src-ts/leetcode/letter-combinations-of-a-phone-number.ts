const telepad = ['abc', 'def', 'ghi', 'jkl', 'mno', 'pqrs', 'tuv', 'wxyz'];

// iterative
function letterCombinations(digits: string): string[] {
  if (digits.length === 0) return [];

  let res: string[] = [''];

  for (const digit of digits) {
    const nextRes: string[] = [];

    for (const char of telepad[Number(digit) - 2]) {
      // build next combinations using prev result
      for (const str of res) {
        nextRes.push(str + char);
      }
    }

    res = nextRes;
  }

  return res;
}

// recursive
function letterCombinations(digits: string): string[] {
  if (digits.length === 0) return [];

  const res: string[] = [];

  const helper = (index: number, combination: string) => {
    if (index === digits.length) {
      res.push(combination);
      return;
    }

    for (const char of telepad[Number(digits[index]) - 2]) {
      helper(index + 1, combination + char);
    }
  };

  helper(0, '');

  return res;
}
