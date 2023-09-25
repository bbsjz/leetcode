#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

class Trie
{
    static const int N = 10;
    int son[N][26];
    int cnt[N];
    int idx;
public:
    Trie()
    {
        idx = 0;
        memset(son, 0, sizeof son);
        memset(cnt, 0, sizeof cnt);
    }

    void insert(string word)
    {
        int p = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int u = word.at(i) - 'a';
            if (son[p][u] == 0)
                son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }

    bool search(string word)
    {
        int p = 0;
        for (int i = 0; i < word.size(); i++)
        {
            int u = word.at(i) - 'a';
            if (son[p][u] == 0)
                return false;
            p=son[p][u];
        }
        return cnt[p] != 0;
    }

    bool startsWith(string prefix)
    {
        int p = 0;
        for (int i = 0; i < prefix.size(); i++)
        {
            int u = prefix.at(i) - 'a';
            if (son[p][u] == 0)
                return false;
            p=son[p][u];
        }
        return true;
    }
};

int main()
{
    Trie trie;
    trie.insert("apple");
    cout << trie.search("apple");   // 返回 True
    cout << trie.search("app");     // 返回 False
    cout << trie.startsWith("app"); // 返回 True
    trie.insert("app");
    cout << trie.search("app"); // 返回 True
    return 0;
}