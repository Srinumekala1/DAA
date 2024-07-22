#include <stdio.h>

int main() {
   int i, n, t1 = 0, t2 = 1, nextTerm;

   printf("Enter the number of terms: ");
   scanf("%d", &n);

   if (n <= 0) {
       printf("Please enter a positive integer.\n");
       return 1;  // Exit the program with an error code
   }

   printf("Fibonacci Series: ");

   for (i = 1; i <= n; ++i) {
      printf("%d", t1);
      if (i < n) {  // Print a comma only if it's not the last term
         printf(", ");
      }
      nextTerm = t1 + t2;
      t1 = t2;
      t2 = nextTerm;
   }
   
   printf("\n");  // New line after printing the series
   return 0;
}
