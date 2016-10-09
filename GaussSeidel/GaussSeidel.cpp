// GaussSeidel.cpp : Defines the entry point for the console application.
// Dimas Dwi Adiguna - 20916005

#include "stdafx.h"
#include <cmath>
#include <iostream>
using namespace std;

int main()
{
	double a[8][8] = 
	{
		{-1,0,0,0.70711,1,0,0,0},
		{0,-1,0,0.70711,0,0,0,0},
		{0,0,-1,0,0,0,0.5,0},
		{0,0,0,-0.70711,0,-1,-0.5,0},
		{0,0,0,0,-1,0,0,1},
		{0,0,0,0,0,1,0,0},
		{0,0,0,-0.70711,0,0,0.86602,0},
		{0,0,0,0,0,0,-0.86602,-1}
	};
	double b[8] = { 0,0,0,0,0,10000,0,0 };			//Matriks hasil
	double xs[8] = {1,1,1,1,1,1,1,1};				//Matriks tebakan
	int isNearTol = 0;								//Penanda apakah seluruh x sudah mencapai batas toleransi
	double sum;										//Variabel penampung sum sementara
	int k = 0;
	int N = 100;									//Iterasi maksimum
	double tol = 0.00001;							//Toleransi selisih antara hasil dengan tebakan

	while (k<N && isNearTol<=8) {					//Looping dilakukan selama belum iterasi maksimum & semua x belum mencapai batas toleransi
		k += 1;
													//cout << "\nCount : " << k;
		for (int i = 0;i < 8;i++) {					//Penyusuran setiap baris
			sum = b[i];
													//cout << "\n- Baris : " << i;
													//cout << "\n- Sum update : ";
			for (int j = 0; j < 8; j++) {
				if (i != j) {						//Mengecek apakah ini adalah nilai diagonalnya (a[i][i])
					sum = sum - (a[i][j] * xs[j]);	//Selain nilai diagonalnya, nilai b akan dikurangi a*xs;
													//cout << "~" << sum;
				}
				else {
													//cout << "~SKIP";
				}
			}
			double xtemp = sum / a[i][i];			//Nilai xs sementara dihitung
			double cekTol = abs((xtemp - xs[i]) / xs[i]);//Mengecek toleransi
													//cout << "\n- X" << i << " : " << xtemp << ". Toleransi : " << cekTol;
			if (cekTol >= tol) {
													//cout << "\n-- Perlu iterasi lagi. x" << i << " akan diupdate : " << xtemp;
				isNearTol = 0;						//Jika nilai xs masih belum mencapai toleransi, isNearTol di-nol-kan kembali
				xs[i] = xtemp;						//Update nilai xs terbaru
			}
			else {
				isNearTol += 1;
													//cout << "\n--!! TOL REACHED";
			}
		}
	}
	//Display hasil iterasi Gauss Seidel
	cout << "Result Gauss-Seidel : ";
	for (int u = 0;u < 8;u++) {
		cout << "\nX" << u << " : " << xs[u];
	}
	cout << "\n";
	return 0;
}

