#if  0 
Roy wanted to increase his typing speed for programming contests. So, his friend advised him to type the sentence "The quick brown fox jumps over the lazy dog" repeatedly, because it is a pangram. (Pangrams are sentences constructed by using every letter of the alphabet at least once.)

After typing the sentence several times, Roy became bored with it. So he started to look for other pangrams.

Given a sentence , tell Roy if it is a pangram or not.

Input Format

Input consists of a string .

Constraints 
Length of  can be at most   and it may contain spaces, lower case and upper case letters. Lower-case and upper-case instances of a letter are considered the same.

Output Format

Output a line containing pangram if  is a pangram, otherwise output not pangram.

Sample Input

Input #1

We promptly judged antique ivory buckles for the next prize    
Input #2

We promptly judged antique ivory buckles for the prize    
Sample Output

Output #1

pangram
Output #2

not pangram
#endif  
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define LETTER 26 
#define BYTES ((LETTER+7)/8) 
#define SET_BIT(a, i) ((a[(i)/8]) |= (1<<((i)%8)))
#define CHECK_BIT(a,i) (a[(i)/8] &(1<<((i)%8)))
int main() {
    char *string, *s,c='a';
    int pos=-1;
    int pangram=1, i=0;
    string = malloc(1000*sizeof(char)); 
    if (!string) 
            return 0; 
    #if 0
    while (scanf("%c", &c) && ((c!='\n') || (c!='\0')))
            string[i++] = c;
    string[i]='\0';
    #else 
    scanf("%[^\t\n]s", string);
    #endif
    //printf ("\n INput %s ", string);
    s=string;
    unsigned char bitmask[BYTES]={0};
    while (*s!='\0') 
    { 
            char c = *s; 
            pos=-1;
            if ((c>='A') &&( c<='Z'))
                    pos= c-'A';
            if ((c>='a') &&( c<='z'))
                    pos= c-'a';
            if (pos>=0) {
                    SET_BIT(bitmask, pos);
            }
            s++;
    } 
    pos =0;
    while (pos < LETTER) 
    {
            if (!CHECK_BIT(bitmask, pos)) {
               pangram=0;
            }
           pos++;
    }
    printf ("%spangram",(pangram)?"":"not ");
    free(string);
    return 0;
}

