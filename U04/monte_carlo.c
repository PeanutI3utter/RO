#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

double distance(double x, double y);
double monteCarlo(int numberOfPoints);

int main(){
	printf("[*] Starting test for monteCarlo accuracy\n\n\n[*] test range: from 100000 to 100000000 with step size of *= 10\n\n\n");
	double sumOfPercent = 0;
	double sumOfDiff = 0;
	int index = 0;
	for(int i = 100000; i < 100000001; i *= 10){
		double piApprox = monteCarlo(i);
		double actualDiff = piApprox - M_PI;
		sumOfDiff += abs(actualDiff);
		double relativeDiff = (piApprox - M_PI) / M_PI;
		sumOfPercent += abs(relativeDiff);
		printf("-------number of points: %d\n\napproximation of pi: %f\nabsolute difference to pi: %f\nrelative difference to pi: %f%%\n\n\n\n", i, piApprox, actualDiff, relativeDiff);
		index++;
	}
	printf("[*] average actual difference: %f\n[*] average relativeDiff: %f%%\n\n", sumOfDiff / index, sumOfPercent / index);
}

double monteCarlo(int numberOfPoints)
{
	double shifter = (double)RAND_MAX / 2;
	srand((unsigned) time(0));
	int numberOfPointsInCircle = 0;
	for(int i = 0; i < numberOfPoints; i++){
		double x = rand() / shifter - 1;
		double y = rand() / shifter - 1;
		double dist = distance(x, y);
		if(dist <= 1)
			numberOfPointsInCircle++;
	}
	return (double)numberOfPointsInCircle / numberOfPoints * 4;
}

double distance(double x, double y){
	return sqrt(x * x + y * y);
}