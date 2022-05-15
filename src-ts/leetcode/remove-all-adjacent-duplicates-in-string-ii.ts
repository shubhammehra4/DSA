function removeDuplicates(s: string, k: number): string {
    const stack: [string, number][] = [];

    for (let c of s) {
        const back = stack.at(-1);
        if (back && back[0] === c) {
            back[1] += 1;
            if (back[1] == k)
                stack.pop();
        } else stack.push([c, 1]);

    }

    let res = "";
    for (let [c, count] of stack)
        res += c.repeat(count);

    return res;
};



function removeDuplicates(s: string, k: number): string {
    return s.split('').reduce<[string, number][]>((acc, c) => {
        const back = acc.at(-1);

        if (back && back[0] == c) {
            back[1]++;

            if (back[1] == k) acc.pop();
        } else acc.push([c, 1]);

        return acc;
    }, [])
        .reduce((res, [c, count]) => res + c.repeat(count), "");
};
