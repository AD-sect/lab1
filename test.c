#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "options.h"
#include "test.h"

bool Check(Matrix resMatP, Matrix resMatT)
{
	//printf("%d ", resMatP.col);
	//printf("%d ", resMatT.col);

	if (resMatP.mType != resMatT.mType) return false;
	if (resMatP.col != resMatT.col || resMatP.row != resMatT.row) return false;

	if (resMatT.mType == INT)
	{
		for (int i = 0; i < resMatT.row; i++)
			for (int j = 0; j < resMatT.col; j++)
			{
				if (((int**)resMatP.values)[i][j] != ((int**)resMatT.values)[i][j])
				return false;
			}
	}

	else if (resMatT.mType == DOUBLE)
	{
		for (int i = 0; i < resMatT.row; i++)
			for (int j = 0; j < resMatT.col; j++)
			{
				if ((((double**)resMatT.values)[i][j] - ((double**)resMatP.values)[i][j]) >=  0.00001)

				{
					printf("%lf  ", ((double**)resMatP.values)[i][j]);
					printf("%lf ", ((double**)resMatT.values)[i][j]);
					return false;

				}
			}

	}

	return true;
}

void Test()
{
	Matrix MatrixInt1 = createMatrix(INT, 3, 5);
	Matrix MatrixInt2 = createMatrix(INT, 5, 2);
	Matrix resMatrixI1 = createMatrix(INT, 3, 5);
	Matrix resMatrixI2 = createMatrix(INT, 3, 2);
	Matrix resMatrixI3 = createMatrix(INT, 3, 5);
	Matrix resMatrixI4 = createMatrix(INT, 5, 3);
	Matrix resMatrixI5 = createMatrix(INT, 3, 5);

	Matrix resMatrixI1T = createMatrix(INT, 3, 5);
	Matrix resMatrixI2T = createMatrix(INT, 3, 2);
	Matrix resMatrixI3T = createMatrix(INT, 3, 5);
	Matrix resMatrixI4T = createMatrix(INT, 5, 3);
	Matrix resMatrixI5T = createMatrix(INT, 3, 5);


	Matrix MatrixDouble1 = createMatrix(DOUBLE, 3, 5);
	Matrix MatrixDouble2 = createMatrix(DOUBLE, 5, 2);
	Matrix resMatrixD1 = createMatrix(DOUBLE, 3, 5);
	Matrix resMatrixD2 = createMatrix(DOUBLE, 3, 2);
	Matrix resMatrixD3 = createMatrix(DOUBLE, 3, 5);
	Matrix resMatrixD4 = createMatrix(DOUBLE, 5, 3);
	Matrix resMatrixD5 = createMatrix(DOUBLE, 3, 5);

	Matrix resMatrixD1T = createMatrix(DOUBLE, 3, 5);
	Matrix resMatrixD2T = createMatrix(DOUBLE, 3, 2);
	Matrix resMatrixD3T = createMatrix(DOUBLE, 3, 5);
	Matrix resMatrixD4T = createMatrix(DOUBLE, 5, 3);
	Matrix resMatrixD5T = createMatrix(DOUBLE, 3, 5);


	((int**)MatrixInt1.values)[0][0] = 7;
	((int**)MatrixInt1.values)[0][1] = 12;
	((int**)MatrixInt1.values)[0][2] = 3;
	((int**)MatrixInt1.values)[0][3] = -14;
	((int**)MatrixInt1.values)[0][4] = 5;
	((int**)MatrixInt1.values)[1][0] = 0;
	((int**)MatrixInt1.values)[1][1] = 9;
	((int**)MatrixInt1.values)[1][2] = -39;
	((int**)MatrixInt1.values)[1][3] = 11;
	((int**)MatrixInt1.values)[1][4] = 4;
	((int**)MatrixInt1.values)[2][0] = 8;
	((int**)MatrixInt1.values)[2][1] = 75;
	((int**)MatrixInt1.values)[2][2] = -4;
	((int**)MatrixInt1.values)[2][3] = 26;
	((int**)MatrixInt1.values)[2][4] = 1;

	((int**)MatrixInt2.values)[0][0] = 3;
	((int**)MatrixInt2.values)[0][1] = 7;
	((int**)MatrixInt2.values)[1][0] = 9;
	((int**)MatrixInt2.values)[1][1] = 5;
	((int**)MatrixInt2.values)[2][0] = 4;
	((int**)MatrixInt2.values)[2][1] = -1;
	((int**)MatrixInt2.values)[3][0] = 2;
	((int**)MatrixInt2.values)[3][1] = -2;
	((int**)MatrixInt2.values)[4][0] = 7;
	((int**)MatrixInt2.values)[4][1] = 8;
	
	double n = 3;
	int numStr = 1;
	int alphas[5];
	alphas[0] = 4;
	alphas[1] = 5;
	alphas[2] = 3;
	alphas[3] = 1;
	alphas[4] = 2;

	resMatrixI1 = addMat(MatrixInt1, MatrixInt1);
	resMatrixI2 = multipyMat(MatrixInt1, MatrixInt2);
	resMatrixI3 = scalMultipyMat(MatrixInt1, n);
	resMatrixI4 = transMat(MatrixInt1);
	resMatrixI5 = addLinearCombMat(MatrixInt1, numStr, alphas);

	((int**)resMatrixI1T.values)[0][0] = 14;
	((int**)resMatrixI1T.values)[0][1] = 24;
	((int**)resMatrixI1T.values)[0][2] = 6;
	((int**)resMatrixI1T.values)[0][3] = -28;
	((int**)resMatrixI1T.values)[0][4] = 10;
	((int**)resMatrixI1T.values)[1][0] = 0;
	((int**)resMatrixI1T.values)[1][1] = 18;
	((int**)resMatrixI1T.values)[1][2] = -78;
	((int**)resMatrixI1T.values)[1][3] = 22;
	((int**)resMatrixI1T.values)[1][4] = 8;
	((int**)resMatrixI1T.values)[2][0] = 16;
	((int**)resMatrixI1T.values)[2][1] = 150;
	((int**)resMatrixI1T.values)[2][2] = -8;
	((int**)resMatrixI1T.values)[2][3] = 52;
	((int**)resMatrixI1T.values)[2][4] = 2;

	((int**)resMatrixI2T.values)[0][0] = 148;
	((int**)resMatrixI2T.values)[0][1] = 174;
	((int**)resMatrixI2T.values)[1][0] = -25;
	((int**)resMatrixI2T.values)[1][1] = 94;
	((int**)resMatrixI2T.values)[2][0] = 742;
	((int**)resMatrixI2T.values)[2][1] = 391;

	((int**)resMatrixI3T.values)[0][0] = 21;
	((int**)resMatrixI3T.values)[0][1] = 36;
	((int**)resMatrixI3T.values)[0][2] = 9;
	((int**)resMatrixI3T.values)[0][3] = -42;
	((int**)resMatrixI3T.values)[0][4] = 15;
	((int**)resMatrixI3T.values)[1][0] = 0;
	((int**)resMatrixI3T.values)[1][1] = 27;
	((int**)resMatrixI3T.values)[1][2] = -117;
	((int**)resMatrixI3T.values)[1][3] = 33;
	((int**)resMatrixI3T.values)[1][4] = 12;
	((int**)resMatrixI3T.values)[2][0] = 24;
	((int**)resMatrixI3T.values)[2][1] = 225;
	((int**)resMatrixI3T.values)[2][2] = -12;
	((int**)resMatrixI3T.values)[2][3] = 78;
	((int**)resMatrixI3T.values)[2][4] = 3;

	((int**)resMatrixI4T.values)[0][0] = 7;
	((int**)resMatrixI4T.values)[0][1] = 0;
	((int**)resMatrixI4T.values)[0][2] = 8;
	((int**)resMatrixI4T.values)[1][0] = 12;
	((int**)resMatrixI4T.values)[1][1] = 9;
	((int**)resMatrixI4T.values)[1][2] = 75;
	((int**)resMatrixI4T.values)[2][0] = 3;
	((int**)resMatrixI4T.values)[2][1] = -39;
	((int**)resMatrixI4T.values)[2][2] = -4;
	((int**)resMatrixI4T.values)[3][0] = -14;
	((int**)resMatrixI4T.values)[3][1] = 11;
	((int**)resMatrixI4T.values)[3][2] = 26;
	((int**)resMatrixI4T.values)[4][0] = 5;
	((int**)resMatrixI4T.values)[4][1] = 4;
	((int**)resMatrixI4T.values)[4][2] = 1;

	((int**)resMatrixI5T.values)[0][0] = 7;
	((int**)resMatrixI5T.values)[0][1] = 12;
	((int**)resMatrixI5T.values)[0][2] = 3;
	((int**)resMatrixI5T.values)[0][3] = -14;
	((int**)resMatrixI5T.values)[0][4] = 5;
	((int**)resMatrixI5T.values)[1][0] = 60;
	((int**)resMatrixI5T.values)[1][1] = 453;
	((int**)resMatrixI5T.values)[1][2] = -81;
	((int**)resMatrixI5T.values)[1][3] = 34;
	((int**)resMatrixI5T.values)[1][4] = 20;
	((int**)resMatrixI5T.values)[2][0] = 8;
	((int**)resMatrixI5T.values)[2][1] = 75;
	((int**)resMatrixI5T.values)[2][2] = -4;
	((int**)resMatrixI5T.values)[2][3] = 26;
	((int**)resMatrixI5T.values)[2][4] = 1;

	bool checkAdd, checkMul, checkScal, checkTrans, checkLinComb;
	checkAdd = Check(resMatrixI1, resMatrixI1T);
	checkMul = Check(resMatrixI2, resMatrixI2T);
	checkScal = Check(resMatrixI3, resMatrixI3T);
	checkTrans = Check(resMatrixI4, resMatrixI4T);
	checkLinComb = Check(resMatrixI5, resMatrixI5T);

	printf("\n");
	printf(" test of integer:\n\n");

	if (checkAdd == true)
		printf(" Test addition : succes\n");
	else 
		printf(" Test addition : fail\n");

	if (checkMul == true)
		printf(" Test multipy : succes\n");
	else
		printf(" Test multipy : fail\n");

	if (checkScal == true)
		printf(" Test scalar multipy : succes\n");
	else
		printf(" Test scalar multipy : fail\n");

	if (checkTrans == true)
		printf(" Test transponation : succes\n");
	else
		printf(" Test transponation : fail\n");

	if (checkLinComb == true)
		printf(" Test linear combination : succes\n");
	else
		printf(" Test linear combination : fail\n");


	((double**)MatrixDouble1.values)[0][0] = 7.2;
	((double**)MatrixDouble1.values)[0][1] = 12.2;
	((double**)MatrixDouble1.values)[0][2] = 3.2;
	((double**)MatrixDouble1.values)[0][3] = -14.2;
	((double**)MatrixDouble1.values)[0][4] = 5.2;
	((double**)MatrixDouble1.values)[1][0] = 0.2;
	((double**)MatrixDouble1.values)[1][1] = 9.2;
	((double**)MatrixDouble1.values)[1][2] = -39.2;
	((double**)MatrixDouble1.values)[1][3] = 11.2;
	((double**)MatrixDouble1.values)[1][4] = 4.2;
	((double**)MatrixDouble1.values)[2][0] = 8.2;
	((double**)MatrixDouble1.values)[2][1] = 75.2;
	((double**)MatrixDouble1.values)[2][2] = -4.2;
	((double**)MatrixDouble1.values)[2][3] = 26.2;
	((double**)MatrixDouble1.values)[2][4] = 1.2;

	((double**)MatrixDouble2.values)[0][0] = 3.3;
	((double**)MatrixDouble2.values)[0][1] = 7.3;
	((double**)MatrixDouble2.values)[1][0] = 9.3;
	((double**)MatrixDouble2.values)[1][1] = 5.3;
	((double**)MatrixDouble2.values)[2][0] = 4.3;
	((double**)MatrixDouble2.values)[2][1] = -1.3;
	((double**)MatrixDouble2.values)[3][0] = 2.3;
	((double**)MatrixDouble2.values)[3][1] = -2.3;
	((double**)MatrixDouble2.values)[4][0] = 7.3;
	((double**)MatrixDouble2.values)[4][1] = 8.3;

	double nD = 3.2;
	int numStrD = 1;
	double alphasD[5];
	alphasD[0] = 4.1;
	alphasD[1] = 5.1;
	alphasD[2] = 3.1;
	alphasD[3] = 1.1;
	alphasD[4] = 2.1;

	resMatrixD1 = addMat(MatrixDouble1, MatrixDouble1);
	resMatrixD2 = multipyMat(MatrixDouble1, MatrixDouble2);
	resMatrixD3 = scalMultipyMat(MatrixDouble1, nD);
	resMatrixD4 = transMat(MatrixDouble1);
	resMatrixD5 = addLinearCombMat(MatrixDouble1, numStrD, alphasD);

	((double**)resMatrixD1T.values)[0][0] = 14.4;
	((double**)resMatrixD1T.values)[0][1] = 24.4;
	((double**)resMatrixD1T.values)[0][2] = 6.4;
	((double**)resMatrixD1T.values)[0][3] = -28.4;
	((double**)resMatrixD1T.values)[0][4] = 10.4;
	((double**)resMatrixD1T.values)[1][0] = 0.4;
	((double**)resMatrixD1T.values)[1][1] = 18.4;
	((double**)resMatrixD1T.values)[1][2] = -78.4;
	((double**)resMatrixD1T.values)[1][3] = 22.4;
	((double**)resMatrixD1T.values)[1][4] = 8.4;
	((double**)resMatrixD1T.values)[2][0] = 16.4;
	((double**)resMatrixD1T.values)[2][1] = 150.4;
	((double**)resMatrixD1T.values)[2][2] = -8.4;
	((double**)resMatrixD1T.values)[2][3] = 52.4;
	((double**)resMatrixD1T.values)[2][4] = 2.4;

	((double**)resMatrixD2T.values)[0][0] = 150.98;
	((double**)resMatrixD2T.values)[0][1] = 113.06;
	((double**)resMatrixD2T.values)[1][0] = -82.34;
	((double**)resMatrixD2T.values)[1][1] = 101.18;
	((double**)resMatrixD2T.values)[2][0] = 708.36;
	((double**)resMatrixD2T.values)[2][1] = 463.88;

	((double**)resMatrixD3T.values)[0][0] = 23.04;
	((double**)resMatrixD3T.values)[0][1] = 39.04;
	((double**)resMatrixD3T.values)[0][2] = 10.24;
	((double**)resMatrixD3T.values)[0][3] = -45.44;
	((double**)resMatrixD3T.values)[0][4] = 16.64;
	((double**)resMatrixD3T.values)[1][0] = 0.64;
	((double**)resMatrixD3T.values)[1][1] = 29.44;
	((double**)resMatrixD3T.values)[1][2] = -125.44;
	((double**)resMatrixD3T.values)[1][3] = 35.84;
	((double**)resMatrixD3T.values)[1][4] = 13.44;
	((double**)resMatrixD3T.values)[2][0] = 26.24;
	((double**)resMatrixD3T.values)[2][1] = 240.64;
	((double**)resMatrixD3T.values)[2][2] = -13.44;
	((double**)resMatrixD3T.values)[2][3] = 83.84;
	((double**)resMatrixD3T.values)[2][4] = 3.84;

	((double**)resMatrixD4T.values)[0][0] = 7.2;
	((double**)resMatrixD4T.values)[0][1] = 0.2;
	((double**)resMatrixD4T.values)[0][2] = 8.2;
	((double**)resMatrixD4T.values)[1][0] = 12.2;
	((double**)resMatrixD4T.values)[1][1] = 9.2;
	((double**)resMatrixD4T.values)[1][2] = 75.2;
	((double**)resMatrixD4T.values)[2][0] = 3.2;
	((double**)resMatrixD4T.values)[2][1] = -39.2;
	((double**)resMatrixD4T.values)[2][2] = -4.2;
	((double**)resMatrixD4T.values)[3][0] = -14.2;
	((double**)resMatrixD4T.values)[3][1] = 11.2;
	((double**)resMatrixD4T.values)[3][2] = 26.2;
	((double**)resMatrixD4T.values)[4][0] = 5.2;
	((double**)resMatrixD4T.values)[4][1] = 4.2;
	((double**)resMatrixD4T.values)[4][2] = 1.2;

	((double**)resMatrixD5T.values)[0][0] = 7.2;
	((double**)resMatrixD5T.values)[0][1] = 12.2;
	((double**)resMatrixD5T.values)[0][2] = 3.2;
	((double**)resMatrixD5T.values)[0][3] = -14.2;
	((double**)resMatrixD5T.values)[0][4] = 5.2;
	((double**)resMatrixD5T.values)[1][0] = 33.82;
	((double**)resMatrixD5T.values)[1][1] = 392.72;
	((double**)resMatrixD5T.values)[1][2] = -52.22;
	((double**)resMatrixD5T.values)[1][3] = 40.02;
	((double**)resMatrixD5T.values)[1][4] = 6.72;
	((double**)resMatrixD5T.values)[2][0] = 8.20;
	((double**)resMatrixD5T.values)[2][1] = 75.2;
	((double**)resMatrixD5T.values)[2][2] = -4.2;
	((double**)resMatrixD5T.values)[2][3] = 26.2;
	((double**)resMatrixD5T.values)[2][4] = 1.2;

	bool checkAddD, checkMulD, checkScalD, checkTransD, checkLinCombD;
	checkAddD = Check(resMatrixD1, resMatrixD1T);
	checkMulD = Check(resMatrixD2, resMatrixD2T);
	checkScalD = Check(resMatrixD3, resMatrixD3T);
	checkTransD = Check(resMatrixD4, resMatrixD4T);
	checkLinCombD = Check(resMatrixD5, resMatrixD5T);

	


	printf("\n");
	printf(" Test of double:\n\n");

	if (checkAddD == true)
		printf(" Test addition : succes\n");
	else
		printf(" Test addition : fail\n");

	if (checkMulD == true)
		printf(" Test multipy : succes\n");
	else
		printf(" Test multipy : fail\n");

	if (checkScalD == true)
		printf(" Test scalar multipy : succes\n");
	else
		printf(" Test scalar multipy : fail\n");

	if (checkTransD == true)
		printf(" Test transponation : succes\n");
	else
		printf(" Test transponation : fail\n");

	if (checkLinCombD == true)
		printf(" Test linear combination : succes\n");
	else
		printf(" Test linear combination : fail\n");
}








