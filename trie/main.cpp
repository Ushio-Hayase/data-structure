#include <iostream>

#include "trie.cpp"

int main()
{
    Trie trie;
    std::string str[4];
    str[0] = "ABC";
    str[1] = "BDs";
    str[2] = "asd";
    str[3] = "asfds";

    for (int i = 0; i < 3; ++i) trie.insert(str[i]);

    for (int i = 0; i < 4; ++i)
    {
        std::cout << (trie.find(str[i]) ? "true" : "false") << '\n';
    }
}