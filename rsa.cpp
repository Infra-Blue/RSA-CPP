#include <utility>

std::pair<int, int> extended_eucledian(int e, int totient)
{
    if (totient == 1)
        return {0, 1};
    auto res(extended_eucledian(totient, e % totient));
    return {res.second, res.first - (e / totient) * res.second};
}


int modular_inverse(int e, int totient)
{
    int res = extended_eucledian(e, totient).first;
    return res < 0 ? totient + res : res;
}


unsigned long modular_exp(const int &base, int pow, const int &mod) 
{
    static const int base_mod = base % mod;
    if (pow == 1)
        return base_mod;
    unsigned long half_compute, res;
    half_compute = modular_exp(base, pow >> 1, mod);
    res = (half_compute * half_compute) % mod; 
    return pow & 1 ? (base_mod * res) % mod : res % mod;
}


