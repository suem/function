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
// Property: c > 5 => F(resp > 5)
/* int __phi() { return COR(CAP(c<=5),CAF(CAP(resp>5))); } */

// -ctl "OR{c <= 5}{AF{resp > 5}}" -precondition "c > 0 && servers==8 && resp==0 && curr_serv == 8"


int c;
int servers ;
int resp;
int curr_serv;

int __rho_1_;
int pc;
int dummy;

/* void init() { */
/*   c = nondet(); assume(c>0); */
/*   servers = 8; */
/*   resp = 0; */
/*   curr_serv = servers; */
/* } */

int main() {
  while(1) {
    if (!(curr_serv > 0)) break;
    __rho_1_ = ?;
    if(__rho_1_>0) {
      c--; curr_serv--;
      resp++;
    } else if (c < curr_serv){
      curr_serv--;
    }
  }
  while(1) { dummy=dummy; } 
//L_return: return 0;
}


