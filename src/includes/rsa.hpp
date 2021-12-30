struct CryptoVar
{
    mpz_class data;
    std::string name;
    char letter;
};

class RSAObject
{
    private:
        CryptoVar _p, _q, _n, _totient, _publicExponent, _privateExponent, _cipher, _message;
        CryptoVar *pArray[8] = { &_p, &_q, &_n, &_totient, &_publicExponent, &_privateExponent, &_cipher, &_message };
        const char cVarChars[8] = { 'P', 'Q', 'N', 'T', 'E', 'D', 'C', 'M'};
        std::string cVarNames[8] = { "P", "Q", "N", "Totient", "Public Key", "Private Key", "Cipher", "Message" };
    public:
        RSAObject(mpz_class data[]);
};