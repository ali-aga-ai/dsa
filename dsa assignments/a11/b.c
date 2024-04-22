#include <stdio.h>
//better optimisatioin would be to use a bst (unordered_set in cpp) as components;

//wrong, but works for some test cases


int main(){

    int n,q,u,v;

    scanf("%d %d",&n,&q);    

    int component[n+1];

    for(int i=0; i<n+1; i++){
        component[i] = -1;    
    }
    
    int result = n;

    for(int i=0; i<q; i++){
        
        scanf("%d %d",&u,&v);
        
        if(u==v){
            printf("%d ",result);
            
        }
        
        else{
            if(component[u]==-1){// havent visited u
                if(component[v]==-1){// havent visited u or v
                    component[u] = 1;
                    component[v] = 1;
                    result--;
                    printf("%d ",result);
                }
                else{// havent visited u but visited v
                    component[u] =1;
                    result--;
                    printf("%d ",result);
                }
            }  
            else{//  visited u
                if(component[v]==-1){// visited u but not v
                    component[v] =1;
                    result--;
                    printf("%d ",result);
    
                }
                else{              //visited both already here is where code goes WRONG because what if u are joining two separate components      
                    printf("%d ",result);
                    
                }
    
            }
            
            }
        }



    return 0;
}