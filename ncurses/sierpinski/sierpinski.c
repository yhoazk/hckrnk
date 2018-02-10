/*Draw the Sierpinski triangle using ncurses*/
#include <curses.h>
#include <stdlib.h>
//#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#define ITERMAX (5000)
/* Reads /dev/random to get a random number */
int get_random_int(void)
{

  static int random_h = 0;
  if(random_h == 0)
  {
    random_h = open("/dev/random",'r');
  }

  int random_data = 0;
  (void)read(random_h, &random_data, sizeof(random_data) ); /* ignore the result of read */
  /* */
  if(random_data < 0)
  {
    random_data *=-1;
  }
  return random_data;
  /* TODO: Here we should close the device random, but we are lazy fucks */
}
/* It would be interesing to check how this works with a LFSR random generator */
int get_rand_LFSR_Galois_int(void)
{
  static unsigned short lfsr = 0xBEEF;
  unsigned lsb = lfsr & 1;   /* Get LSB (i.e., the output bit). */
  lfsr >>= 1;                /* Shift register */
  if (lsb)                   /* If the output bit is 1, apply toggle mask. */
  {
    lfsr ^= 0xB400u;
  }

  return lfsr;
}


int get_rand_LFSR_Fib_int(void)
{
  static unsigned short lfsr = 0xBEEF;

  lfsr =  ((((lfsr>>0) ^ (lfsr>>2) ^ (lfsr>>3) ^ (lfsr>>5) ) & 1) << 15) | (lfsr >> 1);

  return lfsr;
}

int main(void)
{
  long iter;
  int yi, xi;
  int y[3], x[3];
  int index;
  int maxlines, maxcols;

  /* Initialize curses */

  initscr();
  cbreak();
  noecho();
  clear();
  /* Initialize Triangle */

  maxlines = LINES - 1;
 // maxcols = COLS - 1;

  maxcols = 150;
  y[0] = 0;
  x[0] = 0;
  y[1] = maxlines;
  x[1] = maxcols / 2;

  y[2] = 0;
  x[2] = maxcols;

  mvaddch(y[0], x[0], '0');
  mvaddch(y[1], x[1], '1');
  mvaddch(y[2], x[2], '2');

  /* Init xi, yi, with rand values */

  yi = get_random_int() % maxlines;
  xi = get_random_int() % maxcols;
  mvaddch(yi,xi, '.');
  /**/
  for(iter=0; iter < ITERMAX; iter++)
  {
    #ifdef RANDOM_DEV
    index = get_random_int() % 3;
    #elif defined(RANDOM_FIB_LFSR)
    index = get_rand_LFSR_Fib_int() % 3;
    #else
    index = get_rand_LFSR_Galois_int() % 3;
    #endif
    yi = (yi + y[index]) / 2;
    xi = (xi + x[index]) / 2;

    mvaddch(yi, xi, '*');
    refresh();
  }

  mvaddstr(maxlines, 0, "key to exit");

  refresh();
  getch();
  endwin();
  exit(0);
}
