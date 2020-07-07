#include<stdio.h>
#include<stdlib.h>
//I have array of pointers "goal" and i need to assign values to it dynamically all array goals have the same value

int main(void){
  int h = 0;
  char* goal[6];
  char *x; 

  for (h = 0; h < 6; h++)
  {
    goal[h] = (char*)malloc(sizeof(char*));
    x = (char*)malloc(30); 
    sprintf(x, "%s (%d)", "goal", h);
    goal[h] = x;
    printf("goal= %s\r\n", goal[h]);
  }

  for (h = 0; h < 6; h++)
  {
    printf("goal101010= %s\r\n", goal[h]);

    free (goal[h]);
  }

}

     