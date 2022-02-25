function compareVersion(version1: string, version2: string): number {
  const v1 = version1.split('.');
  const v2 = version2.split('.');
  const n = Math.max(v1.length, v2.length);

  for (let i = 0; i < n; i++) {
    const a = Number(v1[i]) || 0;
    const b = Number(v2[i]) || 0;

    if (a < b) return -1;

    if (a > b) return 1;
  }

  return 0;
}
