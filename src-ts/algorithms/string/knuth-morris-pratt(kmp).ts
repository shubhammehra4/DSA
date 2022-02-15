function buildLPSTable(pattern: string): number[] {
  const lpsTable = Array<number>(pattern.length).fill(0);
  let prefixIdx = 0;
  let suffixIdx = 1;

  while (suffixIdx < pattern.length) {
    if (pattern[prefixIdx] === pattern[suffixIdx]) {
      lpsTable[suffixIdx] = prefixIdx + 1;
      prefixIdx += 1;
      suffixIdx += 1;
    } else if (prefixIdx === 0) {
      lpsTable[suffixIdx] = 0;
      suffixIdx += 1;
    } else {
      prefixIdx = lpsTable[prefixIdx - 1];
    }
  }

  return lpsTable;
}

// Pattern Matching
function knuthMorrisPratt(text: string, pattern: string): number {
  if (pattern.length === 0) return 0;

  const n = text.length;
  const m = pattern.length;
  let textIdx = 0;
  let patternIdx = 0;
  const lpsTable = buildLPSTable(pattern);

  while (textIdx < n) {
    if (text[textIdx] === pattern[patternIdx]) {
      if (patternIdx === m - 1) {
        return textIdx - m + 1;
      }
      patternIdx += 1;
      textIdx += 1;
    } else if (patternIdx > 0) {
      patternIdx = lpsTable[patternIdx - 1];
    } else {
      textIdx += 1;
    }
  }

  return -1;
}
