#include <stdio.h>
#include <math.h>

double funkcja(double x){
	double y;
	y = x*x*x + 200.0;
	return y;
}

double polowienie(double A, double B){ 
	double C = (A+B)/2;
	double epsilon = 0.5;
	if (fabs(B-A) <= epsilon)
		return C; 	
	if (funkcja(C)*funkcja(A) < 0)
		{
		return polowienie(A,C);
		}
	else
		{
		return polowienie(C,B);
		}
}

int main(int argc, char*argv[]) { 	
	double A = -20.0;
	double B = 10.0;

	printf("rozwiązanie to %f.", polowienie(A,B));
	return 0;
}

