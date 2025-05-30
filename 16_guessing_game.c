#include <stdio.h>

int main() {
    int guess;
    int val = 42;
    
    while(scanf("%d", &guess) != EOF) {
   
        if(guess == val) {
          printf("Nice work!\n");
          break;
        }
       else if( guess > val) {
         printf("Too high - guess again\n");
       }
      else {
        printf("Too low - guess again\n");
      }
     }
}