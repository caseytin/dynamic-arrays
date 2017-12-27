
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/********************************************************************/
/*    A program created to learn more about dynamic arrays          */
/********************************************************************/


int main(){
	int i = 0;
	srand(time(NULL));
	printf("\t-----------------------------------\n");
	printf("\t-           Dynamic Arrays        -\n");
	printf("\t-----------------------------------\n");
	printf("\n\t========= After each test you should print our your array using a loop ===========\n\n");
	printf("\n\t========= Your loops should ONLY use pointer arithmetic to iterate ===========\n\n");

	printf("\n\t=========Test #1: Create an integer array of Size 20===========\n\n");
	printf("\n\t=========Test #1: Using a Loop, insert 20 random values into your Array===========\n\n");

	int* array = (int *)malloc(sizeof(int)*20);
	int* a;
	for(a = array; a < array+20; a++){
		*a = (rand() % 20)+1;
		printf("%d\n",*a);
	}


	printf("\n\t=========Test #2: 'Grow' the array by 1, and insert a value at the end ===========\n\n");

	int* arrayTwo = (int *)malloc(sizeof(int)*21);
	int b = 0;
	for(a = arrayTwo; a < arrayTwo+21; a++){
		*a = *(array+ b++);
		printf("%d\n", *a);
	}




	printf("\n\t=========Test #3: Produce a Random Number between 1 and 20, and increase the current size of your array by that much ===========\n\n");
	printf("\n\t=========Test #3: Attempt to insert a value into your array at index 40===========\n\n");
	printf("\n\t=========Test #3: Expand the array, only if needed, to allow inserting the data===========\n\n");

	int randomNumber = (rand() % 20)+1;
	arrayTwo = (int *)realloc(arrayTwo, randomNumber);
	if(randomNumber+21 == 39){
		a = arrayTwo + 39;
		*a = 55;
	}
	else{
		int difference = 40 -(21 + randomNumber);
		arrayTwo = (int *)realloc(arrayTwo, difference);
		a = arrayTwo + 39;
		*a = 55;
	}
	b = 0;
	for(a = arrayTwo; a < arrayTwo + 40; a++){
		printf("%d\t%d\n", *a,++b);
	}

	printf("\n\t=========Test #4: Reduce the size of the array by half ===========\n\n");
	printf("\n\t=========Test #4: Use integer division to determine the new size of the array ===========\n\n");

	int half = b/2;
	int * arrayFour = (int *)malloc(sizeof(int)*half);
	b = 0;
	for(a = array; a < array + 20; a++){
		*a = *(array+ b++);
		printf("%d\n", *a);
	}

	printf("\n\t=========Test #5: Remove a random element from your array ===========\n\n");
	printf("\n\t=========Test #5: The array size should shrink by exactly 1 ===========\n\n");



	printf("\n\t=========Run your code with valgrind to ensure there are no errors ===========\n\n");

	return 0;
}
