// STRING PATTERN MATCHING USING TRIE
#include <bits/stdc++.h>
using namespace std;

string brute_force(string text,string pat) {
    int n = text.size();
    int m = pat.size();
    for(int i=0; i+m<n;i++) {
        if(text.substr(i,m) == pat) {
            return "FOUND AT INDEX " + to_string(i);
        }
    }
    return "NOT FOUND";
}

struct trie {
    // for small letters only
    trie *nxt[26];
    trie() {
        for(int i=0;i<26;i++) nxt[i] = NULL;
    }
};
trie *root;
void insert(string s) {
    trie *cur = root;
    for(int i=0;i<s.size();i++) {
        if(cur->nxt[s[i] - 'a'] == NULL) cur->nxt[s[i] - 'a'] = new trie();
        cur = cur->nxt[s[i] - 'a'];
    }
    // cur pointer will be on last node
}

bool find(string s) {
    trie *cur = root;
    for(int i=0;i<s.size();i++) {
        if(cur->nxt[s[i] - 'a'] == NULL) return false;
        cur = cur->nxt[s[i] - 'a'];
    }
    return true;
}

int main() {
    root = new trie();
    string text,pat;
    cin >> text >> pat;
    // Brute Force
    // cout << brute_force(text,pat) << endl;
    int n = text.size();
    int m = pat.size();
    // inserting all prefixes of text into the trie
    for(int i=0;i<n;i++) {
        insert(text.substr(i));
    }
    // matching the pattern
    if(find(pat)) {
        cout << "FOUND";
    } else {
        cout << "NOT FOUND";
    }
    return 0;
}
