function spiralOrder(arr: number[][]) {
  const res: number[] = [];

  let n = arr.length - 1;
  let m = arr[0].length - 1;
  let row = 0;
  let col = 0;
  let dir = 0;

  while (row <= n && col <= m) {
    switch (dir) {
      case 0: // l->r
        for (let c = col; c <= m; c++) res.push(arr[row][c]);
        row++;
        break;

      case 1: // u->d
        for (let r = row; r <= n; r++) res.push(arr[r][m]);
        m--;
        break;

      case 2: // r->l
        for (let c = m; c >= col; c--) res.push(arr[row][c]);
        n--;
        break;

      case 3: // d->u
        for (let r = n; r >= row; r--) res.push(arr[r][col]);
        col++;
        break;

      default:
        break;
    }

    dir = (dir + 1) % 4;
  }

  return res;
}
