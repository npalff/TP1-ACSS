#include "any.h"

// TODO: makes the precondition stronger (but should remain prouvable in main function) !
/*@ requires 0 <= x ;
  @ assigns \nothing;
  @ ensures \result * y <= x;
  @ ensures x - \result * y < y;
  @*/
int div(int x,int y) {
  int i=0;
  
  // TODO: fix loop annotations
  /*@ loop invariant 0; // FIX ME 
    @ loop assigns \nothing; // FIX ME
    @ loop variant 0; */ // FIX ME
  while (y <= x) {
    i++;
    x-=y;
  }
  return i;
}


int main() {
  int x=any(), y=any(), q;

  if (x < 0) x=0;
  if (y < 1) y=1;

  q=div(x,y);

  /*@ assert q*y <= x; */
  /*@ assert x-q*y < y; */

  return q;
}
