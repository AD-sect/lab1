#pragma once
typedef enum
{
	INT, DOUBLE
} Mtype;


typedef struct
{
	Mtype mType;
	int col;
	int row;
	void** values;

} Matrix;


void* createAlphas(Matrix matrix1, int numStr);
Matrix createMatrix(Mtype mType, int row, int col);
Matrix fullfillMat();
Matrix addMat(Matrix matrix1, Matrix matrix2);
Matrix multipyMat(Matrix matrix1, Matrix matrix2);
Matrix scalMultipyMat(Matrix matrix1, double n);
Matrix transMat(Matrix matrix1);
void printAnsMat(Matrix resMatrix);
Matrix addLinearCombMat(Matrix matrix1, int numStr, void* alphas);
void freeMat(Matrix matrix1);