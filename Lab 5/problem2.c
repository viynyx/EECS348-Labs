#include <stdio.h>

void findCombos(int score){ 
    //goes thru all the possible scores for TD + 2pt (8)
    //ex. 25
    //             8*0<=25 ... 8*3<=25 <- makes sure combo total isn't more than the score
    for (int i = 0; 8 * i <= score; i++) {
        //FG (7)
        for (int j = 0; 8 * i + 7 * j <= score; j++) {
            //TD (6)
            for (int k = 0; 8 * i + 7 * j + 6 * k <= score; k++) {
                //FG (3)
                for (int l = 0; 8 * i + 7 * j + 6 * k + 3 * l <= score; l++) {
                    //Safety (2)
                    //       finds how many safetys are needed to get the score
                    int m = (score - 8 * i - 7 * j - 6 * k - 3 * l) / 2;
                //makes sure m is not negative & the combo does equal the score
                    if (m >= 0 && 8 * i + 7 * j + 6 * k + 3 * l + 2 * m == score) {
                        printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety \n", i, j, k, l, m);
                    }
                }
            }
        }
    }
}

int main(){
    int score;

    while (1){ 
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        //if 0 or 1 stop program
        if (score <= 1){
            break;
        }
        printf("Possible Combinations of Scoring Play:\n");
        findCombos(score);
    }    
    return 0;
}