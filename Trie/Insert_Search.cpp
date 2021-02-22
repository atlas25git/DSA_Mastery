 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	
	bool isEndOfWord; 
}; 


struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 


void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 

		pCrawl = pCrawl->children[index]; 
	} 

	 
	pCrawl->isEndOfWord = true; 
} 


bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
 
int main()
{ 
	
	string keys[] = {"bad", "bat", "geeks", "geeks", "cat", "cut"}; 
	
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	
	search(root, "bat")? cout << "Yes\n" : 
						cout << "No\n"; 
	search(root, "gee")? cout << "Yes\n" : 
						cout << "No\n"; 
	return 0; 
} 