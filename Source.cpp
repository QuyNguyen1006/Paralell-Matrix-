/*
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
#include<omp.h>

double LiToDouble(LARGE_INTEGER x)
{
	double result = ((double)x.HighPart) * 4.294967296E9 + (double)((x).LowPart);
	return result;
}

double GetTime()
{
	LARGE_INTEGER lpFrequency, lpPerfomanceCount;
	QueryPerformanceFrequency(&lpFrequency);
	QueryPerformanceCounter(&lpPerfomanceCount);
	return LiToDouble(lpPerfomanceCount) / LiToDouble(lpFrequency);
}

void DummyDataInitialization(double* pMatrix, double* pVector, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = 1;
		for (int j = 0; j < Size; j++)
		{
			pMatrix[i * Size + j] = i;
		}
	}
}

void RandomDataInitialization(double* pMatrix, double* pVector, int Size)
{
	srand(unsigned(clock()));
	for (int i = 0; i < Size; i++)
	{
		pVector[i] = rand() / double(1000);
		for (int j = 0; j < Size; j++)
		{
			pMatrix[i * Size + j] = rand() / double(1000);
		}
	}
}

void ProcessInitialization(double*& pMatrix, double*& pVector, double*& pResult, int& Size)
{
	do
	{
		printf("\nEnter size of the initial objects: ");
		scanf_s("%d", &Size);
		printf("\nChosen objects size= %d\n", Size);
		if (Size <= 0)
			printf("\nSize of objects must be greater than 0!\n");
	} while (Size <= 0);
	pMatrix = new double[Size * Size];
	pVector = new double[Size];
	pResult = new double[Size];
	DummyDataInitialization(pMatrix, pVector, Size);
}

void PrintMatrix(double* pMatrix, int RowCount, int ColCount)
{
	for (int i = 0; i < RowCount; i++)
	{
		for (int j = 0; j < ColCount; j++)
		{
			printf("%7.4f ", pMatrix[i * RowCount + j]);
		}
		printf("\n");
	}
}

void PrintVector(double* pVector, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		printf("%7.4f ", pVector[i]);
	}
}

void SerialResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size)
{
	for (int i = 0; i < Size; i++)
	{
		pResult[i] = 0;
		for (int j = 0; j < Size; j++)
		{
			pResult[i] += pMatrix[i * Size + j] * pVector[j];
		}
	}
}

void ParallelResultCalculation(double* pMatrix, double* pVector, double* pResult, int Size) {
	int i, j;
#pragma omp parallel for private (j)  
	for (i = 0; i < Size; i++)
	{
		pResult[i] = 0;
		for (j = 0; j < Size; j++)
			pResult[i] += pMatrix[i * Size + j] * pVector[j];
	}
}

void TestResult(double* pMatrix, double* pVector, double* pResult, int Size)
{
	double* pSerialResult;
	int equal = 0;
	pSerialResult = new double[Size];
	SerialResultCalculation(pMatrix, pVector, pSerialResult, Size);
	for (int i = 0; i < Size; i++)
	{
		if (pResult[i] != pSerialResult[i])
			equal = 1;
	}
	if (equal == 1)
		printf("\nThe results of serial and parallel algorithms are NOT identical. Check your code.");
	else
		printf("\nThe results of serial and parallel algorithms are identical.");
	delete[] pSerialResult;
}

void ProcessTermination(double* pMatrix, double* pVector, double* pResult)
{
	delete[] pMatrix;
	delete[] pVector;
	delete[] pResult;
}

int main()
{
	double* pMatrix;
	double* pVector;
	double* pResult;
	int Size;
	double Start1, Finish1, Duration1, Start2, Finish2, Duration2;
	
	printf("Da sua hehe");
	printf("Parallelmatrix-vector multiplication program\n");
	ProcessInitialization(pMatrix, pVector, pResult, Size);

	printf("Initial Matrix \n");
	PrintMatrix(pMatrix, Size, Size);
	printf("Initial Vector \n");
	PrintVector(pVector, Size);

	Start1 = GetTime();
	SerialResultCalculation(pMatrix, pVector, pResult, Size);
	Finish1 = GetTime();
	Duration1 = Finish1 - Start1;

	Start2 = GetTime();
	ParallelResultCalculation(pMatrix, pVector, pResult, Size);
	Finish2 = GetTime();
	Duration2 = Finish2 - Start2;
	TestResult(pMatrix, pVector, pResult, Size);

	printf("\nResult Vector: \n");
	PrintVector(pResult, Size);

	printf("\nTime of serial: %f\n", Duration1);
	printf("\nTime of parallel: %f\n", Duration2);

	ProcessTermination(pMatrix, pVector, pResult);
}*/
