

#include <stdio.h>

/*
void main() 
{


	int countNumInArray(float array[], int, int) {
		
		for (int i = 0; i<sizeof(array);i++)
			printf("%d",array[i])

	}
	int array[] = { 4, 1, 7, 5, 4, 1, 4, 2, 7 }, int count = 0;

	result = countNumInArray(array, 9, 5);
}
*/


void main()
{
	int array[] = { 4, 1, 7, 5, 4, 1, 4, 2, 7 }, count = 1;
	int val1 = 13, val2 = 37;

	for (int i = 0; i < 8; i++) {
		if (array[i] == val1 || array[i] == val2)
			count += 1;
	}
	printf("occurences: %d", count);
	
	

}