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

// Property: G(a => F r)
//
// FuncTion Parameters:
// -ctl "AG{OR{set != 1}{AF{unset == 1}}}" -precondition "set == 0 && unset == 0"

int pc;
int i; int Pdolen; int num; int DName;
int lptNamei; //[5];
int dcIdi; // [5];
int Pdoi; //[5];
int PdoType; 
int status;
int dummy;

int set; 
int unset;

/* int __phi() { return CAG(CIMP(CAP(set==1),CAF(CAP(unset==1)))); } */

/* void init() { set = unset = 0; } */

// The Program
/* void ExFreePool(int a) {} */
/* void PPBlockInits() {} */
/* void PPUnblockInits() {} */
/* void RtlInitUnicodeString(int a) {} */


void main() {
  set = 1; set = 0;
  //PPBlockInits(); 
  while (1) {
    if (!(i < Pdolen)) break;
    DName = ?;
    if (DName>0) { break; } 
    //RtlInitUnicodeString(DName); 
    status = ?; pc = 1; pc = 0;
    if (1 != status) { 
      Pdoi = 0; 
      if (2 == status) { 
	//ExFreePool(DName); 
	num++; 
	//goto loc_continue; 
      } 
      break; 
    } else { 
      i++; 
    } 
  } 
  num = 0; 
  unset = 1; unset = 0;
  //PPUnblockInits();
 /* loc_continue:0; */
  while(1) { dummy=dummy; } 
    //L_return: return 0;
}

