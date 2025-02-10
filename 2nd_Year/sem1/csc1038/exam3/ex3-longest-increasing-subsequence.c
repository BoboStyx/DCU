/*
Author:Seyi Adu
Program: ex3-longest-increasing-subsequence.c
Description: Given a list of integers from command line find the longest increasing subsequence (LIS) such that all elements of the subsequence are sorted in strictly increasing order.
Input: A list of integers from command line e.g. 10 9 2 5 3 7 101 18
Output: The length of the LIS e.g 4 i.e. [2, 3, 5, 7]
Date: 18/12/24
Approach: Create a nested loop that creates lists that have an increasing order for each individual number then return the greatest length
 */


#include <stdio.h>
#include <stdlib.h>

int findGreatest(int* lists, int length, char * argv[]){
	int max = 0;
	for (int i = 0; i < length - 1; i++){
		int curr = lists[0];
		int prev = 0;
		int count = 0;
		for (int j = 0; j < length - 1; j++){
			if (curr < atoi(argv[j + 1])){
				prev = atoi(argv[j + 1]);
				count++;
			}
		}
		if (max < count){
			count = max;
		}
		}
	return max;
	}

int *createLists(int argc, char* argv[]){
	int length = argc - 1;
	int *lists = (int*)malloc( length * sizeof(int*));
	for (int i = 0; i < length - 1; i++){
		lists[i] = atoi(argv[i + 1]);
	}
	return lists;
}

int main(int argc, char* argv[]){
	int* lists = createLists(argc, argv);
	printf("%d\n", findGreatest(lists, argc, argv));
}
