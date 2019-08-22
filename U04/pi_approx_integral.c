#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double approximate(int numberOfDivisions);

int main(int argc, char const *argv[])
{
	printf("[*] Starting test for pi approximation via integral accuracy\n\n\n[*] test range: from 10 to 100000000 with step size of *= 10\n\n\n");
	double sumOfPercent = 0;
	double sumOfDiff = 0;
	int index = 0;
	for(int i = 10; i < 100000001; i *= 10){
		double piApprox = approximate(i);
		double actualDiff = piApprox - M_PI;
		sumOfDiff += abs(actualDiff);
		double relativeDiff = (piApprox - M_PI) / M_PI;
		sumOfPercent += abs(relativeDiff);
		printf("-------number of points: %d\n\napproximation of pi: %f\nabsolute difference to pi: %f\nrelative difference to pi: %f%%\n\n\n\n", i, piApprox, actualDiff, relativeDiff);
		index++;
	}
	printf("[*] average actual difference: %f\n[*] average relativeDiff: %f%%\n\n", sumOfDiff / (double)index, sumOfPercent / (double)index);
	return 0;
}

double approximate(int numberOfDivisions){
	double h = 1.0 / numberOfDivisions; 
	double sum = 0;
	for(double s = 0; s < 1; s += h){
		sum += 4 / (1 + s * s) * h;
	}
	return sum;
}