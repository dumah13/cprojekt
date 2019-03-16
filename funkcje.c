#include <stdio.h>
#include <math.h>

double funkcja(double x){
	double y;
	y = x*x*x/2 + 308.0;
	return y;
}

double polowienie(double A, double B, double epsilon){ 
	double C = (A+B)/2;
	if (fabs(B-A) <= epsilon)
		return C; 	
	if (funkcja(C)*funkcja(A) < 0)
		{
		return polowienie(A,C, epsilon);
		}
	else
		{
		return polowienie(C,B, epsilon);
		}
}

int main(int argc, char*argv[]) { 	
	double A = -20.0;
	double B = 10.0;
	double epsilon = 0.0000000005;
	
	printf("f(A) to %f, f(B) to %f.\n", funkcja(A), funkcja(B));
	
	double C = polowienie(A,B,epsilon);
	
	printf("rozwiązanie to %f.\nSprawdzenie: f(C) = %f", C, funkcja(C));
	return 0;
}

