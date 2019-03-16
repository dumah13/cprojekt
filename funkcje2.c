#include <stdio.h>
#include <math.h>

double funkcja(double x){
	double y;
	y = x*x*x - 8.0;
	return y;
}

double polowienie(double A,double B){
	return (A+B)/2;
}

int main(int argc, char*argv[]){
	double A = -10.0;
	double B = 10.0;
	double C;
	double epsi = 0.0005;

	while (fabs(B-A) > epsi) {
		C = polowienie(A, B);
		if (funkcja(A)*funkcja(C) < 0) 
		B = C;
		else
		A = C;
	}
	printf("Miejsce zerowe to %f", C);
}
