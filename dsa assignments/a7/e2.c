//half copies

//step1 : sort based on first
//sytep2: count sort each based on second
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Pair{
	int f;
	int s;
} Pair;

void countSort(int* arr,int n,int k){//k is range of values arr can take

	int count[k+1];
	for(int i=0;i<=k;i++) count[i]=0;

	for(int i=0;i<n;i++) count[arr[i]]++;

	for(int i=1;i<=k;i++) count[i]+=count[i-1];

	int output[n];
	for(int i=n-1;i>=0;i--){
		output[count[arr[i]]-1]=arr[i];
		count[arr[i]]--;
	}

	for(int i=0;i<n;i++) arr[i]=output[i];
}

void sortPair(Pair* arr,int n){
	int count[n+1];
	for(int i=0;i<=n;i++) count[i]=0;

	for(int i=0;i<n;i++) count[arr[i].f]++;

	for(int i=1;i<=n;i++) count[i]+=count[i-1];

	int outputF[n],outputS[n];
	for(int i=n-1;i>=0;i--){
		outputF[count[arr[i].f]-1]=arr[i].f;
		outputS[count[arr[i].f]-1]=arr[i].s;//first arranging the second one in accordance with first one
		count[arr[i].f]--;
	}

	int i=0;
	while(i<n){
		countSort(outputS+count[i],count[i+1]-count[i],n);//count[i+1]-count[i] suggests number of times i occurs in final list
		i++;
	}

	for(int i=0;i<n;i++) printf("%d ",outputF[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",outputS[i]);
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	Pair* arr=(Pair*) malloc(sizeof(Pair)*n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].f);
	for(int i=0;i<n;i++) scanf("%d",&arr[i].s);

	sortPair(arr,n);
}