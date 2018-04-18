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

int n; int A; int R;
unsigned int pc;
int __phi() { return CAG(CIMP(CAP(A==1),CAF(CAP(R==1)))); }

int init() { A=0; R=0; }
int dobreak;

int body() {
  dobreak = nondet();
  while(1) {
    if (dobreak > 0) break;
    A = 1;
    A = 0;
    n = nondet();
    while(1) {
      if (!(n>0)) break;
      /*  ((n___old2 > loc_n)&&(loc_n>=0)) */
      n--;
    }
    R = 1;
    R=0;
    dobreak = nondet();
  }
  while(1) { dummy=dummy; } L_return: return 0;
}

int main() { }
