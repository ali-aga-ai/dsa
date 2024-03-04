//half-copied and incomplete
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Pair{
	int f;
	int s;
} Pair;

void countSort(int* arr,int n,int k){
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
		outputS[count[arr[i].f]-1]=arr[i].s;
		count[arr[i].f]--;
	}

	int i=0;
	while(i<n){
		countSort(outputS+count[i],count[i+1]-count[i],n);
		i++;
	}

	for(int i=0;i<n;i++) printf("%d ",outputF[i]);
	printf("\n");
	for(int i=0;i<n;i++) printf("%d ",outputS[i]);
	printf("\n");
}

int main(){
	int n; scanf("%d",&n);
	
	int* arr = (int*)malloc(n*sizeof(int));
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);

	Pair* arr2=(Pair*) malloc(sizeof(Pair)*(n+1));


    for(int i=0;i<n;i++){
        arr2[i].f = 0;
        arr2[i].s = -1;
    }
	
	
	for(int i=0;i<n;i++) {
	    arr2[arr[i]].f++;
	    if(arr2[arr[i]].s==-1){
	        arr2[arr[i]].s=i;
	    }
	}


	sortPair(arr2,n+1);
	
	for(int i=0; i<n; i++){
	    if(arr2[i].f!=0){
	        while(arr2[i].f!=0){
	        printf("%d ",arr[arr2[i].s]);
	        arr2[i].f--;
	        }
	    }
	}
}