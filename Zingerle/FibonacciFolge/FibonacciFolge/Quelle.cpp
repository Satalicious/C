
#include <stdio.h>

void main()

{
	/*1 2 3 5 8 13 21 */
	int vvZ = 0, vZ = 1, n=1, aZ;


	while (vZ <= 500)
	{
		//Berechnung
		aZ = vZ + vvZ;
		//neue Zuweisung
		vvZ = vZ;
		vZ = aZ;
		n += 1;
		printf("%d. Fibonacci Zahl: %d\n",n,aZ);
	}
















}