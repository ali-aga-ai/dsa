#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define max(a,b) ((a>b)?(a):(b))

int makeEqual(char* a,char* b){
	int l1=0,l2=0,len=0;
	while(a[l1]!='\0') l1++;
	while(b[l2]!='\0') l2++;

	len=max(l1,l2);
	char* x=(char*) malloc(sizeof(char)*100000);
	char* y=(char*) malloc(sizeof(char)*100000);
	int i=0,j=0,m=0,n=0;
	while(i<len-l1) x[i++]='0';
	while(j<len-l2) y[j++]='0';

	while(i<len) x[i++]=a[m++];
	while(j<len) y[j++]=b[n++];

	i=0,j=0;
	while(i<len) {a[i]=x[i]; i++}
	while(j<len) {b[j]=y[j]; j++}

	a[i++]='\0',b[j++]='\0';
	free(x); free(y);
	return len;
}

char* digitAdd(char* a,char* b){
	char* c=(char*) malloc(sizeof(char)*100000);
	int len=makeEqual(a,b);

	int sum=0,carry=0,i=0;
	while(len-1>=0){
		int temp=(a[len-1]-'0')+(b[len-1]-'0')+carry;
		sum=temp%10;
		carry=temp/10;
		c[i++]=sum+'0';
		len--;
	}

	if(carry>0) c[i++]=carry+'0';

	int j=0;
	//HERE I IS LENGTH OF ADDED STRING
	for(;j<i/2;j++){
		char t=c[j];
		c[j]=c[i-j-1];
		c[i-j-1]=t;
	}

	c[i++]='\0';
	return c;
}

char* sub_str(char* a,int si,int ei){
	char* r=(char*) malloc(sizeof(char)*100000);
	int m=0;
	for(int i=si;i<ei;i++){
		r[m++]=a[i];
	}
	r[m++]='\0';
	return r;
}

void appendZeroes(char* a,int zero){
	int len=0;
	while(a[len]!='\0') len++;
	int i=len;
	while(zero--) a[i++]='0'; // MULTIPLYING BY 10^ZERO
	a[i++]='\0';
	return;
}

char* trimZero(char* c){
	while(c[0]=='0' && c[1]!='0'){
		c++; ///SHIFTS POINTER BY 1
	}
	return c;
}

char* karatsuba(char* a,char* b){
	int n=makeEqual(a,b);
	if(n==1){
		char* z=(char *) malloc(sizeof(char)*100000);
		int mult=(a[0]-'0')*(b[0]-'0');
		z[1]=mult%10+'0';
		z[0]=mult/10+'0';
		z[2]='\0';
		return z;
	}

	char* a_l=sub_str(a,0,n/2); //a
	char* a_r=sub_str(a,n/2,n);	//b

	char* b_l=sub_str(b,0,n/2); //c
	char* b_r=sub_str(b,n/2,n); //d


	char* ac=karatsuba(a_l,b_l);
	char* ad=karatsuba(a_l,b_r);

	char* bc=karatsuba(a_r,b_l);
	char* bd=karatsuba(a_r,b_r);

	char* adbc=digitAdd(ad,bc);

	appendZeroes(ac,n);
	appendZeroes(adbc,n/2);

	char* p=digitAdd(ac,adbc);
	char* q=digitAdd(p,bd);

	free(ac); free(ad); free(bc); free(bd); free(adbc); free(p);

	return q;
}

int main(){
	char* a=(char *) malloc(sizeof(char)*100000);
	char* b=(char *) malloc(sizeof(char)*100000);

	scanf("%s %s",a,b);

	char* c=karatsuba(a,b);
	c=trimZero(c);
	printf("%s\n",c);
}