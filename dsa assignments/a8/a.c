//The topmost element of the stack is the index of the topmost element in the array and NOT the topmost element
//havent figured same nesting level

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE  100

struct Stack{
  
  int top;//index of top element
  
  char a[MAX_SIZE]; // each stack object has a corresponding array
    
};

void push(char c, struct Stack *stack){
     //the reason i am passing stack pointer is because, if no pointer, it would be like passing a value, and hence no changes wpuldve been made to the stack i was passing
     
    stack-> top +=1;//not considering max_size
    
    stack->a[stack->top] = c;
    
    printf("%c was pushed at %d \n",c,stack->top);
    
}

char pop(struct Stack *stack){
    
    char element = stack->a[stack->top];
    stack->top-=1;
    
    return element;
    
    
}


int main() {
    
    struct Stack *stack = malloc(sizeof(struct Stack));
    //allocating memory for a stack object
    //we use malloc generally with a pointer (not sure)
    
    stack->top =-1;
    char c;
    int a[3];//a is the parentheses count
    int b[3]; //b is the parenthesis open indicator if it is 1
    for(int i =0;i<3;i++){
        a[i]=0;
        b[i]=0;
    }
    
    while(true){
 
        
        scanf("%c",&c);
        if(c==' ' || c=='\n'){//condition for encountering either whitespace
            break;
        }
        
    push(c,stack);
        
    }
    
    
    while(stack->top!=-1){
        c = pop(stack);
        if(c==')'){
            a[0]++;
        }
        else if(c=='(' ){
            if(a[0]>0 ){
                a[0]--;
            }
            else{
                printf("NO");
                return 0;
            }
        }
        if(c=='}'){
                a[1]++;
            }
            else if(c=='{'){
                if(a[1]>0){
                    a[1]--;
                }
                else{
                    printf("NO");
                    return 0;
                }
            }
            
        if(c==']'){
            a[2]++;
        }
        else if(c=='['){
            if(a[2]>0){
                a[2]--;
            }
            else{
                printf("NO");
                return 0;
            }
        }    
    }
    printf("YES");
    
    free(stack);
    
    return 0;
}