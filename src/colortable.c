/* printtable -- A program to list the terminal char color.  
   
   This program is free software, and just a daily test when I learn
   C language and linux.  */

/* Written by Hapo<wuyichao71@126.com>  */

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

#include "color.h"
/* The offical name of this program.  */
#define PROGRAM_NAME "colortable"

/* Use YES default means when you input colortable without any suffix,
   it will print the all color table.  */
int table = YES;

/* The name that this program was run with. */
char *program_name;

/* Define the colorcode and default is 30, 40, 0.  */
colorcode code = {30, 40, 0};

static struct option const long_options[] =
{
  {"code", required_argument, NULL, 'c'},
  {"table", no_argument, NULL, 't'},
  {NULL, 0, NULL, 0}
};

/* The usage information.  */
void
usage(int status)
{
  if (status != 0)
    fprintf(stderr, "Try %s --help for more information.\n",
      program_name);
}

int
main(int argc, char **argv)
{

  int optc;
  const char *specified_color = NULL;
  
  program_name = argv[0];
  setlocale(LC_ALL, "");

 /* Parse the option.  */ 
  while ((optc = getopt_long (argc, argv, "c:t", long_options, NULL)) != -1)
    switch (optc)
    {
      case 'c':
        table = NO;
        specified_color = optarg;
        break;
      case 't':
        table = YES;
        break;
      default:
        usage(EXIT_FAILURE);
    }
    if (table)
      printtable();
    else if (specified_color)
      getcolor(specified_color);
    else
      usage(EXIT_FAILURE);
  
  exit(EXIT_SUCCESS);
}
