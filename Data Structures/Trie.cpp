/*
 * Biborno
 * fb.com/mfmejbah
 * fmejbah@gmail.com
 *
 * Trie or Prefix Tree or Radix Tree.cpp
 * Date: 29 Jan 2017
 */

#include <bits/stdc++.h>

using namespace std;

struct node {
	bool endMark;
	node *next[27];
	node() {
		endMark = false;
		for (int i = 0; i < 27; i++)
			next[i] = NULL;
	}
}*root;

void insert(char *str, int len) {
	node *curr = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (curr->next[id] == NULL)
			curr->next[id] = new node();
		curr = curr->next[id];
	}
	cutt->endMard = true;
}

bool search(char *str, int len) {
	node *curr = root;
	for (int i = 0; i < len; i++) {
		int id = str[i] - 'a';
		if (curr->next[id] == NULL)
			return false;
		curr = curr->next[id];
	}
	return curr->endMark;
}

void clearMemory(node *curr) {
	for (int i = 0; i < 27; i++)
		if (curr->next[i])
			clearMemory(curr->next[i]);
	delete(curr);
}

int main() {
	root = new node();
}
