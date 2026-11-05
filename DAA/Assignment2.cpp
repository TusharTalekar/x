// Write a program to implement Huffman Encoding using a greedy strategy.

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
  public:
    char ch;
    int cnt;
    Node *left;
    Node *right;
    Node(int ch, int cnt) {
        this->ch = ch;
        this->cnt = cnt;
        left = nullptr;
        right = nullptr;
    }
    Node(Node *l, Node *r) {
        ch = ' ';
        cnt = l->cnt + r->cnt;
        left = l;
        right = r;
    }
};

class Compare {
  public:
    bool operator()(Node *a, Node *b) { return a->cnt > b->cnt; }
};

void getCodes(Node *root, vector<string> &ans, string code) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) {
        if (code == "")
            code = "0";
        int idx = root->ch - 'a';
        ans[idx] = code;
    }

    getCodes(root->left, ans, code + "0");
    getCodes(root->right, ans, code + "1");
}

vector<string> huffmanCodes(string s, vector<int> &freq) {
    int n = s.size();
    priority_queue<Node *, vector<Node *>, Compare> pq;
    for (int i = 0; i < n; i++) {
        Node *curr = new Node(s[i], freq[s[i] - 'a']);
        pq.push(curr);
    }

    vector<string> ans(26);
    if (n == 1) {
        ans[s[0] - 'a'] = "0";
        return ans;
    }

    while (pq.size() > 1) {
        Node *r = pq.top();
        pq.pop();
        Node *l = pq.top();
        pq.pop();
        Node *newNode = new Node(l, r);
        pq.push(newNode);
    }
    Node *root = pq.top();
    getCodes(root, ans, "");
    return ans;
}

string getFreq(string str, vector<int> &freq) {
    string s = "";
    for (int i = 0; i < 26; i++) {
        freq[i] = 0;
    }

    for (char c : str) {
        if (freq[c - 'a'] == 0)
            s += c;
        freq[c - 'a']++;
    }
    return s;
}

int main() {
    string menu = "1. Enter/Change string for Huffman Encoding. \n2. Print "
                  "Huffman Codes. \n3. Print frequencies,string. \n4. Exit.";

    string str;
    cout << "Enter string : ";
    cin >> str;
    cout << "String : " << str << endl;
    vector<int> freq(26);
    string s = getFreq(str, freq);

    cout << menu << endl;
    // cout << menu << endl;

    while (true) {
        int choice;
        cout << endl;
        cout << "Enter choice : ";
        cin >> choice;
        if (choice == 1) {
            cout << "Enter string : ";
            cin >> str;
            cout << "String : " << str << endl;
            s = getFreq(str, freq);
        } else if (choice == 2) {
            vector<string> codes = huffmanCodes(s, freq);
            for (int i = 0; i < 26; i++) {
                if (codes[i] != "") {
                    cout << (char)('a' + i) << " => " << codes[i] << endl;
                }
            }
        } else if (choice == 3) {
            cout << "String : " << str << endl;
            cout << "S : " << s << endl;
            for (char ch : s) {
                cout << ch << " " << freq[ch - 'a'] << endl;
            }
        } else if (choice == 4) {
            cout << "Thank You !" << endl;
            break;
        } else {
            cout << "Invalid Choice!" << endl;
        }
    }

    return 0;
}