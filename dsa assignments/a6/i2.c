#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void minheapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[left]<arr[x]) x=left;
	if(right<n&&arr[right]<arr[x]) x=right;

	if(x!=i){
		int temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		minheapify(arr,n,x);
	}
}

void maxheapify(int* arr,int n,int i){
	int left=2*i+1,right=2*i+2,x=i;
	if(left<n&&arr[left]>arr[x]) x=left;
	if(right<n&&arr[right]>arr[x]) x=right;

	if(x!=i){
		int temp=arr[x];
		arr[x]=arr[i];
		arr[i]=temp;
		maxheapify(arr,n,x);
	}
}

void buildHeap(int* arr,int n,int d){
	for(int i=n/2-1;i>=0;i--){
		if(d==0) maxheapify(arr,n,i);
		else minheapify(arr,n,i);
	}
}

int main(){
	int n; scanf("%d",&n);
	int* minheap=(int*) malloc(sizeof(int)*n);
	int* maxheap=(int*) malloc(sizeof(int)*n);

	int i=0,j=0;
	for(int k=0;k<n;k++){
		int q; scanf("%d",&q);
		if(q==1){
			int x; scanf("%d",&x);
			if(i<=j){
				if(j==0||x<minheap[0]){
					maxheap[i++]=x;
					buildHeap(maxheap,i,0);
				}
				else{
					int temp=minheap[0];
					minheap[0]=x;
					minheapify(minheap,j,0);
					maxheap[i++]=temp;
					buildHeap(maxheap,i,0);
				}
			}
			else{
				if(x<maxheap[0]){
					int temp=maxheap[0];
					maxheap[0]=x;
					maxheapify(maxheap,i,0);
					minheap[j++]=temp;
					buildHeap(minheap,j,0);
				}
				else{
					minheap[j++]=x;
					buildHeap(maxheap,j,0);
				}
			}
		}
		if(q==2){
			printf("%d\n",maxheap[0]);
		}
	}
}