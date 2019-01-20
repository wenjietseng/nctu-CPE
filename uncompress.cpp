// uncompress uva 245
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;

struct Node {
    string word;
    Node *next;
};

bool is_number (char ch) {
    return ch >= '0' && ch <= '9';
}

bool is_alphabet(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main() {
    Node *head = NULL;
    char input;
    input = getchar();
    while (1) { // alphabet, number, and others
        if (is_alphabet(input)) {
            // alphabets, save as string and add to linked list
            string output;
            while (is_alphabet(input)) {
                output += input;
                input = getchar();
            }
            cout << output;
            Node *tmp = new Node;
            tmp->word = output;
            tmp->next = head;
            head = tmp;
            // delete tmp;
            // Node *traverse = head;
            // while(traverse->next != NULL) {
            //     cout << traverse->word;
            //     traverse = traverse->next;
            //     cout << " ";
            // }
            // cout << endl;
        }
        else if (is_number(input)) {
            // numbers, find list output, the found string should be at the front
            if (input == '0') {
                break;
            }
            int num = 0;
            while (is_number(input)) {
                num = num * 10 + (input - '0');
                input = getchar();
            }
            Node *now = head;
            Node *prev = NULL;

            for (int i = 1; i < num; i++) {// find the output word
                prev = now;
                now = now->next;
            }
            cout << now->word;

            if (now != head) { // if not first one, change it to the first one
                prev->next = now->next;
                now->next = head;
                head = now;
            }

        }
        else {
            putchar(input);
            input = getchar();
        }
    }
    return 0;
}