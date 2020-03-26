#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include "options.h"
#include "test.h"


void interface()
{
	Matrix a = createMatrix(INT, 0, 0);
	Matrix b = createMatrix(INT, 0, 0);
	Matrix resMatrix = createMatrix(INT, 0, 0);


	printf(" Choose the operation:\n"
		"1. get matrix A + matrix B\n"
		"2. get matrix A * matrix B\n"
		"3. get n * matrix A\n"
		"4. get transposition of matrix A\n"
		"5. get linear combination of matrix A\n"
		"6. get the test\n"
		"7. exit\n");

	int choice = 0;

	scanf_s("%d", &choice);
	switch (choice)
	{
	case 1:
		freeMat(a);
		a = fullfillMat();
		freeMat(b);
		b = fullfillMat();
		resMatrix = addMat(a, b);
		printAnsMat(resMatrix);
		break;

	case 2:
		freeMat(a);
		a = fullfillMat();
		freeMat(b);
		b = fullfillMat();
		freeMat(resMatrix);
		resMatrix = multipyMat(a, b);
		printAnsMat(resMatrix);
		break;

	case 3:
		freeMat(a);
		a = fullfillMat();
		freeMat(resMatrix);

		double n = 0;

		printf("write the scalar ");
		
		scanf("%lf", &n);
		printf("\n");


		resMatrix = scalMultipyMat(a, n);
		printAnsMat(resMatrix);
		break;

	case 4:
		freeMat(a);
		a = fullfillMat();
		freeMat(resMatrix);
		resMatrix = transMat(a);
		printAnsMat(resMatrix);
		break;

	case 5:
		freeMat(a);
		a = fullfillMat();
		freeMat(resMatrix);

		printf(" Write the number of string:\n");
		int numStr = 0;
		scanf("%d", &numStr);

		void* alphas;
		alphas = createAlphas(a, numStr);

		resMatrix = addLinearCombMat(a, numStr, alphas);
		printAnsMat(resMatrix);
		break;

	case 6:
		Test();
		break;

	case 7:
		return;
	default:
		exit(1);
		break;
	}

	freeMat(resMatrix);
}	


int main(int argc, char** argv)
{
	interface();

	return 0;
}













