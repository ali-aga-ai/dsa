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
    int p =0;//p represents component number
    for(int i=0; i<q; i++){
        
        scanf("%d %d",&u,&v);
        
        if(u==v){
            printf("%d ",result);
            
        }
        
        else{
            if(component[u]==-1){// havent visited u
                if(component[v]==-1){// havent visited u or v
                    component[u] = p;
                    component[v] = p;
                    p++;
                    result--;
                    printf("%d ",result);
                }
                else{// havent visited u but visited v
                    component[u] =component[v];
                    result--;
                    printf("%d ",result);
                }
            }  
            else{//  visited u
                if(component[v]==-1){// visited u but not v
                    component[v] = component[u];
                    result--;
                    printf("%d ",result);
    
                }
                else{ 
                    if(component[u]!=component[v]){
                        result--;
                        printf("%d ",result);
                    }
                    else{
                    printf("%d ",result);
                    }
                    
                }
    
            }
            
            }
        }



    return 0;
}