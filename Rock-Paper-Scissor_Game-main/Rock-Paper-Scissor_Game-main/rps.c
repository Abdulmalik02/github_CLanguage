/*	 This project is designed by QAZI SHUAIB
	 Description of this program:

	 This is a game of Rock, paper, scissors.
	 It generates a random no. from 1 to 3 and then uses it to get Rock, Paper and Scissors
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
char win(int u, int c)
{
	if(u>c && u-c==1)
	return 'u';
	if(c>u && c-u==1)
	return 'c';
	if(u>c && u-c==2)
	return 'c';
	if(c>u && c-u==2)
	return 'u';
	else
	return 'e';
}

void main()
{
	printf("This program is a game of rock, paper or scissor, consisting of three rounds. \nThe Player on the other side is a bot- \'Moon\'.\n");
	printf("\nYou will have to enter your choice, Moon will choose its own choice.\nAnd, then the winner will be announced.\nYou will have to play a Match of 3 rounds, winner will be announced from the best of three.");
	printf("\n\nBy the way, Moon is very friendly and cool. Go on! you can make friends with him.\n\nBut for now! Enter your name \n");
	char user[100];   // user's name
	 gets(user);
	int i, j, rno, sum=0; // loop variable
	char uche[3][10], curr[10];
	char winner;
	int  uch[3], cch[3], winarr[3];  		// internal user's choice, stores 0 for 'r', 1 for 'p', 2 for 's'
	
	for(i=1;i<=3;i++)
	{
		printf("Enter %s's choice in rock, paper or scissor  \n", user);
		gets(uche[i-1]);
		strcpy(curr, uche[i-1]);
		if(curr[0]== 'r' || curr[0]== 'R')
		uch[i-1]=0;	
		if(curr[0]== 'p' || curr[0]== 'P')
		uch[i-1]= 1;
		if(curr[0]== 's' || curr[0]== 'S')
		uch[i-1]= 2;

		srand(time(NULL));
		rno= rand() %3;
		j=1;
		// The following loop makes sure that, 
		//the user and bot dosn't choose the same object .
		while(j!=0)
		{
			if(rno!=uch[i-1]){
			break;
			}
			else
			{
				srand(time(NULL));
				rno=rand()%3;
				continue;
			}
		}
		cch[i-1]= rno;

		printf("Moon chooses: ");
		if(cch[i-1] == 0)
		printf("Rock\n");
		else if(cch[i-1] == 1)
		printf("Paper\n");		
		else if(cch[i-1] == 2)
		printf("Scissor\n");

		//printf("%d \n", cch [i-1]);
		winner= win(uch[i-1], cch[i-1]);

		if(winner== 'u'){
		printf("%s win \n", user);
		winarr[i-1]= 0; 
		}
		else if(winner== 'c')
		{
		printf("Moon win \n");
		winarr[i-1]= 1;
		}
		else if(winner== 'e')
		printf("Invalid \n");	

		sum+=winarr[i-1];	
	
	}
	
	if(sum>=2)
	printf("\n\nMoon Wins the Match\n\n");
	else
	printf("\n\n%s Wins the Match\n\n", user);
}