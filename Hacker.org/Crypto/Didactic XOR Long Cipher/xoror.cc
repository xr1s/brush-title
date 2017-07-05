#include <iostream>
#include <vector>

using namespace std::string_literals;

using byte = unsigned char;

bool ishex(char c) {
    return '0' <= c && c <= '9' || 'a' <= c && c <= 'f' || 'A' <= c && c <= 'F';
}

std::string unhexlify(const std::string &hex) {
    std::string unhex = ""s;
    std::string::const_iterator it = hex.cbegin();
    if (hex.front() == '0' && (hex[1] == 'x' || hex[1] == 'X')) it += 2;
    if (hex.length() & 1) {
        char chr = '\x00';
        if (isdigit(*it)) chr = *it - '0';
        else if (islower(*it)) chr = (char)(*it - 'a' + 10);
        else if (isupper(*it)) chr = (char)(*it - 'A' + 10);
        ++it;
        unhex.push_back(chr);
    }
    for (; it != hex.cend(); ++it) {
        if (!ishex(*it) || !ishex(*(it + 1)))
            throw std::invalid_argument("Non-hexadecimal digit found"s);
        char chr = '\x00';
        if (isdigit(*it)) chr = *it - '0' << 4;
        else if (islower(*it)) chr = (char)(*it - 'a' + 10 << 4);
        else if (isupper(*it)) chr = (char)(*it - 'A' + 10 << 4);
        ++it;
        if (isdigit(*it)) chr += *it - '0';
        else if (islower(*it)) chr += (char)(*it - 'a' + 10);
        else if (isupper(*it)) chr += (char)(*it - 'A' + 10);
        unhex.push_back(chr);
    }
    return unhex;
}

bool check_valid(byte key, const std::string &cipher, std::size_t start, std::size_t step) {
    std::size_t length = cipher.length();
    for (std::size_t i = start; i < length; i += step) {
        char chr = (byte)(cipher[i]) ^ key;
        if (!isprint(chr)) return false;
    }
    return true;
}

std::string decrypt(std::string cipher, byte key[], std::size_t keynum) {
    std::size_t length = cipher.length();
    for (std::size_t i = 0; i != length; ++i)
        cipher[i] = (byte)(cipher[i]) ^ key[i % keynum];
    return cipher;
}

std::string cipher = "8776459cf37d459fbb7b5ecfbb7f5fcfb23e478aaa3e4389f378439aa13e4e96a77b5fc1f358439df36a4486a03e4381b"
        "63e5580a66c0c8ebd6d5b8aa13e459cf34e4d9fa67f02cf90714288a17f589abf7f5886bc705fcfbc700c96bc6b5ecfb7775f8cbc68499"
        "daa3f"s;

int main() {
    cipher = unhexlify(cipher);
    std::vector<int> key[4];
    for (std::size_t i = 0; i != 4; ++i)
        for (int k = 0; k != 256; ++k)
            if (check_valid((byte)k, cipher, i, 4)) key[i].push_back(k);
    for (auto k0: key[0])
        for (auto k1: key[1])
            for (auto k2: key[2])
                for (auto k3: key[3]) {
                    byte keys[4] = {(byte)k0, (byte)k1, (byte)k2, (byte)k3};
                    std::string answer = decrypt(cipher, keys, 4);
                    if (answer.find("answer"s) != -1) std::cout << answer << '\n';
                }
    return 0;
}

