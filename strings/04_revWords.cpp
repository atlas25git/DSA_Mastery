#include<stdio.h>
#include<bits/stdc++.h>
 using namespace std;

void reverse(char *begin, char *end);
 
/*Function to reverse words*/
void reverseWords(char *s)
{
  char *word_begin = s;
  char *temp = s; /* temp is for word boundry */
 
  /*STEP 1 of the above algorithm */
  while( *temp )
  {
    temp++;
    if (*temp == '\0')
    {
      reverse(word_begin, temp-1);
    }
    else if(*temp == '.')
    {
      reverse(word_begin, temp-1);
      word_begin = temp+1;
    }
  } /* End of while */
 
   /*STEP 2 of the above algorithm */
  reverse(s, temp-1);
}
 
/* UTILITY FUNCTIONS */
/*Function to reverse any sequence starting with pointer
  begin and ending with pointer end  */
void reverse(char *begin, char *end)
{
//   Increment: It is a condition that also comes under addition. When a pointer is incremented, 
//   it actually increments by the number equal to the size of the data type for which it is a pointer.
// For Example:
// If an integer pointer that stores address 1000 is incremented, then it will increment by 2(size of an int) and
//  the new address it will points to 1002.
//  While if a float type pointer is incremented then it will increment by 4(size of a float) and the new address will be 1004.
  char temp;
  while (begin < end)
  {
    temp = *begin;
    *begin++ = *end;
    *end-- = temp;
  }
}
 
/* Driver function to test above functions */
int main()
{
  freopen("input.txt","r",stdin);
  int t;
  cin>>t;
  while(t--)
  {
  char s[100];
  cin>>s;
  reverseWords(s);
  cout<<s<<endl;
  }

}