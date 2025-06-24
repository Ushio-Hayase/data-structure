#include <map>
#include <string>

class TrieNode
{
   public:
    TrieNode(char v) : value(v) {}

    void insert(std::string& str, size_t idx)
    {
        if (idx == str.size() - 1) is_finish = true;

        char current_char = str[idx];

        if (node[current_char] == 0)
        {
            node[current_char] = new TrieNode(current_char);
        }

        if (!is_finish) node[current_char]->insert(str, idx + 1);
    }

    bool find(std::string str, size_t idx)
    {
        if (idx == str.size() - 1) return is_finish;

        char current_char = str[idx];
        if (node[current_char] == 0) return false;

        return node[current_char]->find(str, idx + 1);
    }

   private:
    std::map<char, TrieNode*> node;
    char value;
    bool is_finish = false;
};

class Trie
{
   public:
    Trie() : root(' ') {}

    void insert(std::string str) { root.insert(str, 0); }

    bool find(std::string str) { return root.find(str, 0); }

   private:
    TrieNode root;
};