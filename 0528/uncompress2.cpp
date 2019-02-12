// uva 245 Uncompress
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <iostream>
using namespace std;

struct Node {
    string one_word;
    Node *next;
};

bool is_number(char c) {
    return '0' <= c && c <= '9';
}

bool is_alphabet(char c) {
    return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
}

int main() {
    Node *head = NULL;
    char ch;
    ch = getchar();
    while (1) {
        if (is_alphabet(ch)) {
            string output;
            while (is_alphabet(ch)) {
                output += ch;
                ch = getchar();
            }
            cout << output;
            Node *tmp = new Node;
            tmp->one_word = output;
            tmp->next = head;
            head = tmp;
        }
        else if (is_number(ch)) {
            if (ch == '0') break;
            int num = 0;
            while (is_number(ch)) {
                num = num * 10 + (ch - '0');
                ch = getchar();
            }
            // cout << num;
            Node *now = head;
            Node *prev = NULL;

            for (int i = 1; i < num; i++) {
                prev = now;
                now = now->next;
            }
            cout << now->one_word;

            if (now != head) {
                prev->next = now->next;
                now->next = head;
                head = now;
            }
        }
        else {
            putchar(ch);
            ch = getchar();
        }
    }
    return 0;
}