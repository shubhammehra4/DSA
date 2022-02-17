auto setKthBit = [](long long unsigned int num, int k)
{
    return ((1 << k) | num);
};

auto getKthBit = [](long long unsigned int num, int k)
{
    return (num & (1 << k)) == 0 ? 0 : 1;
};