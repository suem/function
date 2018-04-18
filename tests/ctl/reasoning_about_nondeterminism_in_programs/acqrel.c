// ###########################################################
//     
//         Reasoning about Nondeterminism in Programs
//     
//               Byron Cook and Eric Koskinen
//                      PLDI 2013
//     
//     
// Note: Please do not distribute without authors' consent.
// ###########################################################
#include "../ctl.h"

/* int __phi() { return CAG(CIMP(CAP(A==1),CAF(CAP(R==1)))); } */

/* int init() { A=0; R=0; } */

// -ctl AG{OR{A!=1}{AF{R==1}}}" 

// cant handle nondet assignment that affects controllflow

int dobreak;
int dummy;
int n; int A; int R;
int pc;


int main() { 
    A = 0;
    R = 0;
  dobreak = ?;
  while(1) {
    if (dobreak > 0) break;
    A = 1;
    A = 0;
    n = ?;
    while(1) {
      if (!(n>0)) break;
      /*  ((n___old2 > loc_n)&&(loc_n>=0)) */
      n--;
    }
    R = 1;
    R=0;
    dobreak = ?;
  }
  while(1) { dummy=dummy; } L_return: return 0;
}
