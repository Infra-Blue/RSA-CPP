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