#pragma once
#include "options.h"

void* createAlphas(Matrix matrix1, int numStr)
{

	Mtype mType;
	int row, col;
	row = matrix1.row;
	col = matrix1.col;
	mType = matrix1.mType;
	void* alphas;

	int typesize;
	switch (mType)
	{
	case INT:
		typesize = sizeof(int);
		break;
	case DOUBLE:
		typesize = sizeof(double);
		break;
	default:
		break;
	}

	alphas = malloc(col * typesize);

	printf(" Wrine the alphas for the other strings:\n");
	if (matrix1.mType == INT)
	{
		int al;
		al = 0;
		for (int k = 0; k < col; k++)
		{
			scanf_s("%d", &al);
			((int*)alphas)[k] = al;
		}
	}

	else if (matrix1.mType == DOUBLE)
	{
		double al;
		al = 0;
		for (int k = 0; k < col; k++)
		{
			scanf_s("%lf", &al);
			((double*)alphas)[k] = al;
		}
	}
	return alphas;
}



Matrix createMatrix(Mtype mType, int row, int col)
{
	Matrix matrix;

	matrix.mType = mType;
	matrix.col = col;
	matrix.row = row;

	int typesize;
	switch (mType)
	{
	case INT:
		typesize = sizeof(int);
		break;
	case DOUBLE:
		typesize = sizeof(double);
		break;
	default:
		break;
	}

	matrix.values = calloc(row, sizeof(void*));

	for (int i = 0; i < row; i++)
	{
		matrix.values[i] = calloc(col * row, typesize);
	}

	return matrix;
}


Matrix fullfillMat()
{

	printf("type of matrix:\n1. int\n2. double\n");
	int type;
	scanf_s("%d", &type); printf("\n");

	printf("columns of matrix:\n");
	int col;
	scanf_s("%d", &col);
	printf("\n");

	printf("rows of matrix:\n");
	int row;
	scanf_s("%d", &row);
	printf("\n");

	Mtype mType;
	if (type == 1) mType = INT;
	else if (type == 2) mType = DOUBLE;

	Matrix matrix;
	matrix = createMatrix(mType, row, col);

	if (mType == INT)
	{
		printf("elements of matrix:\n");

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				scanf_s("%d", &(((int**)matrix.values)[i][j]));
			}
		printf("\n");
	}

	else if (mType == DOUBLE)
	{
		printf("elements of matrix:\n");

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				scanf_s("%lf", &(((double**)matrix.values)[i][j]));
			}
		printf("\n");
	}

	return matrix;
}


Matrix addMat(Matrix matrix1, Matrix matrix2)
{
	Mtype mType;
	int col, row;
	mType = matrix1.mType;
	col = matrix1.col;
	row = matrix1.row;
	Matrix resMatrix = createMatrix(mType, row, col);

	if (matrix1.mType != matrix2.mType || matrix1.col != matrix2.col || matrix1.row != matrix2.row)
	{
		printf(" Addition is not possible");
		exit(1);
	}

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (matrix1.mType == INT)
			{
		((int**)resMatrix.values)[i][j] = ((int**)matrix1.values)[i][j] + ((int**)matrix2.values)[i][j];
			}
			else if (matrix1.mType == DOUBLE)
			{
				((double**)resMatrix.values)[i][j] = ((double**)matrix1.values)[i][j] + ((double**)matrix2.values)[i][j];
			}

		}
	return resMatrix;
}


Matrix multipyMat(Matrix matrix1, Matrix matrix2)
{
	if (matrix1.mType != matrix2.mType || matrix1.col != matrix2.row)
	{
		printf(" Multiply is not possible");
		exit(1);
	}

	Mtype mType;
	int col, row, col2;
	mType = matrix1.mType;
	col = matrix2.col;
	row = matrix1.row;
	col2 = matrix1.col;
	Matrix resMatrix = createMatrix(mType, row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{

			if (matrix1.mType == INT)
			{
				int sum = 0;
				for (int k = 0; k < col2; k++)
				{
					sum += ((int**)matrix1.values)[i][k] * ((int**)matrix2.values)[k][j];
				}

				((int**)resMatrix.values)[i][j] = sum;
			}

			else if (matrix1.mType == DOUBLE)
			{
				double sum = 0;
				for (int k = 0; k < row; k++)
				{
					sum += ((double**)matrix1.values)[i][k] * ((double**)matrix2.values)[k][j];
				}

				((double**)resMatrix.values)[i][j] = sum;
			}
		}

	return resMatrix;

}

Matrix scalMultipyMat(Matrix matrix1, double n)
{

	int m = 0;
	if (matrix1.mType == INT)
		m = (int)n;

	Mtype mType;
	int col, row;
	mType = matrix1.mType;
	col = matrix1.col;
	row = matrix1.row;
	Matrix resMatrix = createMatrix(mType, row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (matrix1.mType == INT)
			{
				((int**)resMatrix.values)[i][j] = m * ((int**)matrix1.values)[i][j];
			}

			else if (matrix1.mType == DOUBLE)
			{
				((double**)resMatrix.values)[i][j] = n * ((double**)matrix1.values)[i][j];
			}
		}
	return resMatrix;
}


Matrix transMat(Matrix matrix1)
{
	Mtype mType;
	int col, row;
	mType = matrix1.mType;
	col = matrix1.row;
	row = matrix1.col;
	Matrix resMatrix = createMatrix(mType, row, col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			if (matrix1.mType == INT)
			{
				((int**)resMatrix.values)[i][j] = ((int**)matrix1.values)[j][i];
			}

			else if (matrix1.mType == DOUBLE)
			{
				((double**)resMatrix.values)[i][j] = ((double**)matrix1.values)[j][i];
			}
		}
	return resMatrix;
}

void printAnsMat(Matrix resMatrix)
{
	int col = resMatrix.col;
	int row = resMatrix.row;

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (resMatrix.mType == INT)
			{
				printf("%d ", ((int**)resMatrix.values)[i][j]);
			}

			else if (resMatrix.mType == DOUBLE)
			{
				printf("%lf ", ((double**)resMatrix.values)[i][j]);

			}
		}
		printf("\n");
	}
}

Matrix addLinearCombMat(Matrix matrix1, int numStr, void* alphas)
{

	int row, col;
	Mtype mType;
	row = matrix1.row;
	col = matrix1.col;
	mType = matrix1.mType;
	Matrix resMatrix = createMatrix(mType, row, col);

	if (matrix1.mType == INT)
	{
		for (int i = 0; i < row; i++)
		{
			if (i == numStr) continue;

			for (int j = 0; j < col; j++)
			{
				((int**)resMatrix.values)[numStr][j] += ((int**)matrix1.values)[i][j] * ((int*)alphas)[j];
				((int**)resMatrix.values)[i][j] = ((int**)matrix1.values)[i][j];
			}
			for (int j = 0; j < col; j++)
			{
				((int**)resMatrix.values)[numStr][j] += ((int**)matrix1.values)[numStr][j];
			}
		}
	}

	else if (matrix1.mType == DOUBLE)
	{
		for (int i = 0; i < row; i++)
		{
			if (i == numStr) continue;

			for (int j = 0; j < col; j++)
			{
				((double**)resMatrix.values)[numStr][j] = ((double**)matrix1.values)[i][j] * ((double*)alphas)[j];
				((double**)resMatrix.values)[i][j] = ((double**)matrix1.values)[i][j];
			}
			for (int j = 0; j < col; j++)
			{
				((double**)resMatrix.values)[numStr][j] += ((double**)matrix1.values)[numStr][j];
			}
		}
	}
	return resMatrix;
}

void freeMat(Matrix matrix1)
{
	if (matrix1.col == 0 || matrix1.row == 0) return;

	for (int i = 0; i < matrix1.row; i++)
		free(matrix1.values[i]);

	free(matrix1.values);

	matrix1.col = 0;
	matrix1.row = 0;
}