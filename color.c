/* printtable -- A program to list the terminal char color.  
   
   This program is free software, and just a daily test when I learn
   C language and linux.  */

/* Written by Hapo<wuyichao71@126.com>  */

#include <stdio.h>
#include "color.h"

/* Print the terminal printtable normally.  */
int printtable(void)
{
  int back;
  int front;
  for (back = BACK_START; back <= BACK_END; back++)
  {
    printf("\033[%dm", back);

    for (front = FRONT_START; front <= FRONT_END; front++)
      printf("\033[%dm%d, %d ", front, back, front);

    printf("\033[0m\n");
  }
  
  return 0;
}

int getcolor()
{
  return 0;
}
