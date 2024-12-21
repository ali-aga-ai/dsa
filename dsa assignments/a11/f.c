#include <stdio.h>

int main(){

    int n, maxWeight;
    float maxValue;
    scanf("%d",&n);
    scanf("%d",&maxWeight);

    int weight[n][2];
    float perUnitValue[n];

    for(int i=0; i<n; i++){
        scanf("%d",&weight[i][0]);//stores weight
        scanf("%d",&weight[i][1]);//storesValue
        perUnitValue[i] = (float)weight[i][1] / weight[i][0]; // stores value per unit weight
    }

    while(maxWeight!=0){// there can be a condition when all weights added together still are lesser than max Weight
        int max = -1;

        for(int i=0; i<n;i++){
            if(max==-1 || perUnitValue[i]>perUnitValue[max]){
                max = i;
            }
        }

        if(weight[max][0] < maxWeight){
            maxWeight-=weight[max][0] ;
            maxValue += perUnitValue[max]*weight[max][0];
        }

        else{
            maxValue += perUnitValue[max]*maxWeight;
            break;
        }
        perUnitValue[max] = -1;

    }

    printf("max value: %f",maxValue);
    


    return 0;
}

