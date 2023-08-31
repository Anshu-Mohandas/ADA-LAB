#include <stdio.h>
#include <stdlib.h>
void swap (int *a, int *b){
    int temp = *a;
    *a= *b;
    *b = temp;
}
int main(){
    int n,i;
    int val[5], dir[5];
    printf ("Enter number of elements:\n");
    scanf("%d",&n);

    for (i=0; i<n; i++){
        val[i]=i+1;
        dir[i]=-1;
    }
    int c=0;
    while (1){
        c++;
        for (int i = 0; i < n; i++) {
            printf ("%d ",val[i]);

        }
        printf ("  %d\n",c);

        int mobileIndex = -1;
        int mobile = 0;
    
       for (int i = 0; i < n; i++) {
            if (dir[i] == -1 && i != 0) {
                if (val[i] > val[i - 1] && val[i] > mobile) {
                    mobile = val[i];
                    mobileIndex = i;
                }
            }

            if (dir[i] == 1 && i != n - 1) {
                //if the element points to right and the value is greater than its right adjacent and also its greater than the current mobile
                if (val[i] > val[i + 1] && val[i] > mobile) {
                    mobile = val[i];
                    mobileIndex = i;
                }
            }
        }

        if (mobileIndex == -1) {
            break;
        }

        if (dir[mobileIndex] == -1) { 
            swap(&val[mobileIndex], &val[mobileIndex - 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex - 1]);
        } else if (dir[mobileIndex] == 1) { //if mobile element pointing to right
            swap(&val[mobileIndex], &val[mobileIndex + 1]);
            swap(&dir[mobileIndex], &dir[mobileIndex + 1]);
        }
        for (int i = 0; i < n; i++) {
            if (val[i] > mobile) {
                dir[i] = -dir[i];
            }
        }
    }    

    return 0;
}
