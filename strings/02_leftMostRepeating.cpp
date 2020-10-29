// CPP program to find first repeating 
// character 
#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 

/* The function returns index of the first 
repeating character in a string. If 
all characters are repeating then 
returns -1 */
int firstRepeating(string& str) 
{ 
	// Initialize leftmost index of every 
	// character as -1. 
	int firstIndex[NO_OF_CHARS]; 
	for (int i = 0; i < NO_OF_CHARS; i++) 
		firstIndex[i] = -1; 

	// Traverse from left and update result 
	// if we see a repeating character whose 
	// first index is smaller than current 
	// result. 
	int res = INT_MAX; 
	for (int i = 0; i < str.length(); i++) { 
		if (firstIndex[str[i]] == -1) 
		firstIndex[str[i]] = i; 
		else
		res = min(res, firstIndex[str[i]]); 
	} 

	return (res == INT_MAX) ? -1 : res; 
} 

/* Driver program to test above function */
int main() 
{ 
	string str = "adbbdc"; 
	int index = firstRepeating(str); 
	if (index == -1) 
		printf("Either all characters are "
			"distinct or string is empty"); 
	else
		printf("First Repeating character"
			" is %c", 
			str[index]); 
	return 0; 
} 
