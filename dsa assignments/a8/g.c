// HORRIBLE, JUST GONNA DO SLIDING
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>

#define MAX 100

struct Q{
    int first;//index of first element
    int last;//index pointing to an element after the last element in queue
    int a[MAX];
};

void push(struct Q *q, int element){
    if(q->a[q->first]!=0){
    q->a[(q->last)] = element;
    
    q->last++;}
    else{
        q->a[q->first] = element;
        
    }
    
}

int pop(struct Q *q){
    
    int x = q->a[q->first];
    
    q->first++;
    
    return x;
    
}

void print(struct Q *q){
    
    for(int i= q->first; i<q->last; i++){
        printf("%d ",q->a[i]);
    }
    printf("\n");
    
}

int main() {
    
    struct Q *q = malloc(sizeof(struct Q));
    //allocating memory for a Queue and hacving its locn specified by q
    
    int n,k,a;
    int max, min;
    q->first =0;
    q->last = 1;
    
    scanf("%d",&n);
    scanf("%d",&k);
    
    int sum =0;
    
    for(int i= 0; i<n; i++){
        scanf("%d",&a);
        
        if(i==0){
            min = a;
            max = a;
            push(q,a);
        }
        else{
            
            if(a>max){
                
                max = a;
                
                if(max-min<=k){
                    push(q,a);
                    sum++;
                    print(q);
                }
                else{//changing the max value brought change in max-min
                    while(q->first!=min){
                        pop(q);
                    }
                    if(q->first == min){
                        pop(q);
                        min =1000;//change this to max val
                        for(int j = q->first; j <q->last; q++){
                            
                            if(q->a[j]<min){
                                
                                min = q->a[j];
                                
                            }
                        }
                    }
                    
                    if(max-min<=k){
                        sum++;
                        print(q);
                    }
                    else{
                        q->first = q->last -1;
                        sum++;
                        print(q);
                    }
                }
            }
            else if(a<min){
                
                min = a;
                
                if(max-min<=k){
                    push(q,a);
                    sum++;
                    print(q);
                }
                else{
                    while(q->first!=max){
                        pop(q);
                    }
                    if(q->first == max){
                        pop(q);
                        max =0;//change this to max val
                        for(int j = q->first; j <q->last; q++){
                            
                            if(q->a[j]>max){
                                
                                max = q->a[j];
                                
                            }
                        }
                    }
                }
                
                if(max-min<=k){
                        sum++;
                        print(q);
                    }
                    else{
                        q->first = q->last -1;
                        sum++;
                        print(q);
                    }
                
            }
            else{
                push(q,a);
                sum++;
                print(q);
            }
            
            
            
        }
        
        
    }
    
    printf("%d",sum);
    
    
    
    
    
    return 0;
}