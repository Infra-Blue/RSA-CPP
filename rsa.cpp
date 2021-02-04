#include <utility>
#include <iostream>

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


unsigned long modular_exp(int &base, int pow, const int &mod) 
{
    if (pow == 1)
        return base = base % mod;
    unsigned long half_compute, res;
    half_compute = modular_exp(base, pow >> 1, mod);
    res = (half_compute * half_compute) % mod; 
    return pow & 1 ? (base * res) % mod : res % mod;
}


int main()
{
    int p = 61, 
        q = 53, 
        n = p * q,  // 3233
        totient = (p - 1) * (q - 1),  // 3120 
        e = 17,  //  e > 1, co-prime to totient
        d = modular_inverse(e, totient), 
        message = 123;

    
    /// ENCRYPTION ///
    int cipher = modular_exp(message, d, n);
    std::cout << "Cipher Text : " << cipher << std::endl;


    /// DECRYPTION ///
    message = modular_exp(cipher, e, n);
    std::cout << "Plain Text : " << message << std::endl;
}


