#include <stdio.h>

int convertToDecimal(void); // Converts a roman numeral to an integer number
void arithmeticOperation(int, int); // Reads an arithmetic operation and checks if it's valid
void convertToRoman(int); // Converts a decimal number to a roman numeral

int main(){
	
	int num1, num2;
	printf("Enter the first number:\n");
	num1 = convertToDecimal();
	printf("The first number is %d\n", num1);
	printf("Enter the second number:\n");
	num2 = convertToDecimal();
	printf("The second number is %d\n", num2);
	printf("Enter the desired arithmetic operation:\n");
	arithmeticOperation(num1, num2);
	system("pause");
	return 0;
	
}

int convertToDecimal(void){
	
	int rn, M = 0, D = 0, C = 0, L = 0, X = 0, V = 0, I = 0, num, count = 0; 
	
	/* During the loop, in each case the program will check 
	if the user has entered the correct format of a roman numeral.
	Roman numerals must be followed: M -> D -> C -> L -> X -> V -> I. 
	Only I, X, C and M can be replaced.
	Maximum number of roman numerals: D:1, C:4, L:1, X:4, V:1, I:4 */
	
	while ((rn = getchar()) != '\n'){
		
		switch(rn){
			
			case 'M':
				M += 1000;
				if (D != 0 || C != 0 || L != 0 || X != 0 || V != 0 || I != 0)
					count++;
				break;
			
			case 'D':
				D += 500;
				if (C != 0 || L != 0 || X != 0 || V != 0 || I != 0)
					count++;				
				break;
			
			case 'C':
				C += 100;
				if (L != 0 || X != 0 || V != 0 || I != 0)
					count++;
				break;
			
			case 'L':
				L += 50;
				if (X != 0 || V != 0 || I != 0)
					count++;				
				break;
			
			case 'X':
				X += 10;
				if (V != 0 || I != 0)
					count++;					
				break;
			
			case 'V':
				V += 5;
				if (I != 0)
					count++;				
				break;
		
			case 'I':
				I += 1;
				break;
			
			default:
				count++;
				break;
				
		}
		
	}
	
	num = M + D + C + L + X + V + I; 
	
	if (count != 0 || D > 500 || C > 400 || L > 50 || X > 40 || V > 5 || I > 4){
		printf("Incorrect roman numeral entered.\nEnter the number again:\n");
		num = convertToDecimal(); 
		// Calling the function again to get new roman numerals
	}
	
	return num;
	
}

void arithmeticOperation(int a, int b){
	
	/*Checks the arithmetic operation given by the user if it's valid
	and then prints the result, which depends on the input given.
	If the arithmetic operation was incorrect, it must be re-entered.
	*/
	
	char arOp;
	int result, count;
	
	do {
		
		count = 0;
		scanf(" %c", &arOp);
		
		if (arOp == '+'){
			result = a + b;
			printf("The sum of ");
		}
			
		else if (arOp == '-'){
			result = a - b;
			printf("The difference of ");
		}	
		
		else if (arOp == '*'){
			result = a * b;
			printf("The product of ");
		}
		
		else if (arOp == '/'){
			result = a / b;
			printf("The quotient of ");
		}
		
		else {
			printf("Incorrect arithemic operation entered.\nEnter again:\n");
			count++;
		}
		
	} while(count != 0);
	
	convertToRoman(a);
	printf(" and ");
	convertToRoman(b);
	printf(" is ");
	convertToRoman(result);
	printf(" (%d)\n", result);
	
}

void convertToRoman(int num){
	
	/* Uses each digit of the integer number to
	check how many times it needs to print each character */
	
	char rn;
	int i;
	
	for (i = 1; i <= num / 1000; i++)
		rn = putchar('M');
		
	if (num % 1000 / 100 >= 5)
		rn = putchar('D');
	
	for (i = 1; i <= num % 1000 / 100 % 5; i++)
		rn = putchar('C');
		
	if (num % 1000 % 100 / 10 >= 5)
		rn = putchar('L');
	
	for (i = 1; i <= num % 1000 % 100 / 10 % 5; i++)
		rn = putchar('X');
		
	if (num % 10 >= 5)
		rn = putchar('V');
		
	for (i = 1; i <= num % 10 % 5; i++)
		rn = putchar('I');
		
}
