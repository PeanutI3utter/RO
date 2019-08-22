#include <stdio.h>

int arraySorted(int *array, int length);
char* convertBoolToString(int bool);

int main(int argc, char const *argv[])
{
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int array2[10] = {1, 2, 4, 3, 5, 6, 7, 8, 9, 10};
	int array3[10] = {-1, 0, 0, 4, 100, 234, 1024, 10000, 90999, 100001};
	printf("%s\n%s\n%s\n", convertBoolToString(arraySorted(array, 10)), convertBoolToString(arraySorted(array2, 10)), convertBoolToString(arraySorted(array3, 10)));
	return 0;
}

char* convertBoolToString(int bool){
	if(bool)
		return "True";
	return "False";
}

int arraySorted(int *array, int length){
	for(int i = 0; i < length - 1; i++){
		if(array[i] > array[i + 1])
			return 0;
	}
	return 1;
}