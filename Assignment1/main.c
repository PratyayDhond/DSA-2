#include "bt.h"
#include "bst.h"
#include<limits.h>
void insertRandomNumbersIntoFile(char* filename, int noOfRecords, int maxValue){
	// printf("%s, %d, %d",filename, noOfRecords, maxValue);
	FILE *fptr;
	fptr = fopen(filename, "w+"); // use a+ for append and read | w+ indicates write and read
	int num = noOfRecords;
	while(num--){
		fprintf(fptr,"%d ",rand() % maxValue);
	}
	fclose(fptr);
	printf("Insertion of %d random values into \'%s\' successful.\n",noOfRecords,filename);
	return;
}

int getNumber(char* str){
	char *p = str;
	int n = 0;
	while(*p != '\0'){
		n = n * 10 + *p - '0';
		p++;
	}
	return n;
}

int main(int charc, char* argv[]){
	char * filename = argv[1];
	srand(time(0));
//	printf("%d", charc);
if(charc == 4){	
	int numberOfRecords = getNumber(argv[2]);
	int maxValue= getNumber(argv[3]);
	insertRandomNumbersIntoFile(filename, numberOfRecords, maxValue);
}else if(charc == 3){
	// input -> ./a.out filename key_to_search(int)
	BT t;
	BinarySearchTree bst;
	initBT(&t);
	initBst(&bst);
	FILE *fptr;
	fptr = fopen(filename, "r+");
	int no;
	int max = INT_MIN;
	while(fscanf(fptr,"%d",&no)){
	//	printf("%d ", no);
		if(feof(fptr)) 
        	break ;
		insertBT(&t,no);
		insertBst(&bst,no);
		if(no > max)
			max = no;
		
	}
	int key = getNumber(argv[2]);
	int BtComparisonCount = 0;
	int BstComparisonCount = 0;
	int n = key;
	int avgBTComparisons = 0;
	int avgBSTComparisons = 0;
	int gotDataFlag = 0;
	for(int i = 0; i < n ; i++){
		key = rand() % max;
		searchBT(t, key, &BtComparisonCount, &gotDataFlag);
		getSearchCountBst(t, key, &BstComparisonCount);
		avgBTComparisons += BtComparisonCount;
		avgBSTComparisons += BstComparisonCount;
		BtComparisonCount = 0;
		BstComparisonCount = 0;
	}
		
	avgBTComparisons /= n;
	avgBSTComparisons /= n;
	
	
	printf("Binary Tree Comparisons :  %d\n",avgBTComparisons);
	printf("Bianry Search Tree Comparisons:  %d\n",avgBSTComparisons);	
	
}
//	numberOfRecords, maxValue

}
