#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int sumTest(int sum);

#define MILLION 1000000

int main() {
   
   int num[6],temp[6],lott[6],win[6];
   int i=0,j=0,testnum=1,b;
   int sum,sort,sort2,cnt = 1,cnt2 = 1,num2,num3;

   while (testnum == 1) { //While loop that confirms whether the sum is less than 50.
	  
	  printf("\n\nSum of numbers entered must be less than or equal to 50!\n\n");
	  //A series of do while loops that takes user input and confirms that
	  //the number falls within the correct range.
	  do {
		 printf("Please input a number from 1 to 5, inclusive: ");
		 scanf("%i",&num[0]);
	  } while(num[0] < 1 || num[0] > 5);
	  
	  do {
		 printf("\nPlease input a number from 1 to 10, inclusive: ");
		 scanf("%i",&num[1]);
	  } while(num[1] < 1 || num[1] > 10);
	  
	  do {
		 printf("\nPlease input another number from 1 to 10, inclusive: ");
		 scanf("%i",&num[2]);
	  } while(num[2] < 1 || num[2] > 10);
	  
	  do {
		 printf("\nPlease input a number from 10 to 12, inclusive: ");
		 scanf("%i",&num[3]);
	  } while(num[3] < 10 || num[3] > 12);
	  
	  do {
		 printf("\nPlease input a number from 8 to 15, inclusive: ");
		 scanf("%i",&num[4]);
	  } while(num[4] < 8 || num[4] > 15);
	  
	  do {
		 printf("\nPlease input another number from 8 to 15, inclusive: ");
		 scanf("%i",&num[5]);
	  } while(num[5] < 8 || num[5] > 15);

	  //Adds up the values into variable "sum".
	  printf("\n");
	  sum = num[0] + num[1] + num[2] + num[3] + num[4] + num[5];
	  
	  //Calls function that tests the sum and saves test var in var "k".
	  testnum = sumTest(sum);
   }
   
   //Nested for loops that sort the array of delta numbers in ascending order.
   for (i = 0; i < 5; i++) {
	  for (j = 0; j < (5-i); j++) {
		 if (num[j] > num[j+1]) {
			sort = num[j];
			num[j] = num[j+1];
			num[j+1] = sort;
		 }
	  }
   }
   
   //Delta numbers are printed out using for loop.
   printf("Your delta numbers are: ");
   for (i = 0; i < 6; i++) {
	  printf("%i ",num[i]);
   }

   printf("\n");
   
   //rand function is seeded using the current time
   srand (time(NULL));
   
   //A for loop is used to go through the delta number array
   for (i = 0; i < 6; i++) {
	  
	  //rand function produces a number between 0 and 5 that reference that
	  //place in the array. It will then swap that place with the place
	  //referenced in the for loop.
	  b = rand() % 6;
	  temp[i] = num[i];
	  num[i] = num[b];
	  num[b] = temp[i];
   }
   
   //The final delta numbers are printed out here
   printf("Your final delta numbers are: ");
   for (i = 0; i < 6; i++) {
	  printf("%i ",num[i]);
   }
   
   //Lottery numbers are created using equation that does successive additon.
   //A for loop is used for the majority this process.
   lott[0] = num[0];
   for (i = 0; i < 5; i++) {
	  lott[i+1] = num[i+1] + lott[i];
   }
   
   //Lottery numbers are printed.
   printf("\n");
   printf("Your lottery numbers are: ");
   for (i = 0; i < 6; i++) {
	  printf("%i ",lott[i]);
   }
   
   //While loop that compares user's numbers to randomly generated set of
   //numbers. Unless the user wins, this will run 1 million times.
   while (cnt <= MILLION) {
	  
	  //6 numbers are randomly generated between 1 and 50 and saved in an array
	  for (i = 0; i < 6; i++) {
		 num2 = (rand() % 50) + 1;
		 win[i] = num2;

	  }

	  //Nested for loop that will go through the array to compare each slot
	  //of the array with every other slot. This entire process makes sure
	  //that there are no repeating numbers in the winning lottery numbers.
	  for (i = 0; i < 6; i++) {
		 for (j = 0; j < 6; j++) {
			
			//This while loop compares each two slots and and if the numbers
			//are the same, another number will be randomly generated until
			//those two numbers are different.
			while (win[i] == win[j]  && j != i) {
			   num3 = (rand() % 50) + 1;
			   win[j] = num3;
			}
		 }
	  }

	  //Using nested for loops, the winning lottery numbers are sorted in
	  //ascending order. This makes the winning numbers mreo likely to line
	  //up with the user's numbers.
	  for (i = 0; i < 5; i++) {
		 for(j = 0; j < (5-i); j++) {
			if (win[j] > win[j+1]) {
			   sort2 = win[j];
			   win[j] = win[j+1];
			   win[j+1] = sort2;
			}
		 }
	  }

	  //This conditional prints out the winning lottery numbers every 10000
	  //tries as well as the attempt number.
	  if (cnt2 % 10000 == 0) { 
	  printf("\n\nWinning Numbers are: ");
	  for (i = 0; i < 6; i++) {
		 printf("%i ",win[i]);
	  }
	  printf("\nAttempt # %i",cnt);
	  }

	  //This conditional compares the user's lottery numbers to the winning
	  //numbers.
	  if (lott[0]==win[0] && lott[1]==win[1] && lott[2]==win[2] && 
			lott[3]==win[3] && lott[4]==win[4] && lott[5]==win[5]) {
		 
		 //If the numbers match up, the program prints out the winning message
		 //along with the attempt number.
		 printf("\n\nYou won after %i tries! Winning numbers are: ",cnt);
		 for (i = 0; i < 6; i++) {
			printf("%i ",win[i]);
		 }
		 
		 //The cnt variable is updated to break the initial while loop.
		 cnt = MILLION + 1;
	  }
	  else {
		 //If the numbers do not line up, the program continues on. Once cnt
		 //reaches 1 million, the final losing message appears.
		 if (cnt == MILLION) {
			printf("\n\nAfter playing 1000000 times, your numbers did not win.");
		 }
	  }
	  cnt++; //Counter variables are updated here
	  cnt2++;
   }
   
   printf("\n\n");
   return 0;
}

//Function to test if t he sum of the user delta numbers is less than 50
int sumTest(int sum) {
   int g; //Local variables initialized

   //If the sum is less than or equal to 50, the variable will equal 0.
   //This will break the while loop in main, allowing the program to continue.
   if (sum <= 50) {
	  g = 0;
   }
   else {
	  //If it is larger than 50, the variable will stay 1, meaning that the 
	  //user must enter the numbers again.
	  g = 1;
   }

   return g; //This variable is returned to main
}
