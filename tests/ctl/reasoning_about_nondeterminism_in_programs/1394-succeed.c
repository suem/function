// ###########################################################
//     
//         Reasoning about Nondeterminism in Programs
//     
//               Byron Cook and Eric Koskinen
//                      PLDI 2013 //     
//     
// Note: Please do not distribute without authors' consent.
// ###########################################################
#include "../ctl.h"

// Property: G(keA => F keR)
//

// -ctl "AG{OR{keA!=1}{AF{keR==1}}}" -precondition "keA==0 && keR == 0"


/* int __phi() { return CAG(CIMP(CAP(keA==1),CAF(CAP(keR==1)))); } */

int dummy;
int lock1;
int lock2;
int lock3;
int lock4;
int lock5;
int lock6;
int CancelIrql;
int irql;
int csl;
int   DeviceObject;
int             Irp;
int            ntStatus;
int   deviceExtension;
int               Irql;
int k1;
int k2;
int k3;
int k4;
int k5;
int      CromData;
int     AsyncAddressData;
int    IsochResourceData;
int      IsochDetachData;
int                   i;
int                pIrb;
int                ResourceIrp;
int               StackSize;
int  BusResetIrp;
int  prevCancel;



int keA; int keR; int ioA; int ioR;
int pc;
int __rho_1_;
int __rho_99_;
int __rho_2_;
int __rho_3_;
int __rho_4_;
int __rho_5_;
int __rho_6_;
int __rho_7_;
int __rho_8_;
int __rho_9_;
int __rho_10_;
int __rho_11_;
int __rho_12_;
int __rho_13_;

void init() {
  keA = 0;
  keR = 0;
}

/* void KeAcquireSpinLock(int * lp, int * ip) { keA = 1; keA = 0; */
/*    /1* (*lp) = 1; *1/ */
/*    /1* (*ip) = irql; *1/ */
/* } */

/* void KeReleaseSpinLock(int * lp, int i) { keR = 1; keR = 0; */
/*    /1* (*lp) = 0; *1/ */
/*    /1* irql = i; *1/ */
/* } */

/* void IoAcquireCancelSpinLock(int * ip) { ioA = 1; ioA = 0; */
/*    /1* csl = 1; *1/ */
/*    /1* (*ip) = irql; *1/ */
/* } */

/* void IoReleaseCancelSpinLock(int ip) { ioR = 1; ioR = 0; */
/*    /1* csl = 0; *1/ */
/*    /1* irql = ip; *1/ */
/* } */

/* int t1394_IsochCleanup(int a) { } */
/* int ExAllocatePool(int a, int b) { } */
/* int t1394Diag_PnpStopDevice(int a,int b) { } */
/* int t1394_SubmitIrpSynch(int a, int b) { } */
/* int IoFreeIrp(int a) { } */
/* int IoSetDeviceInterfaceState() { } */
/* int RtlZeroMemory(int a, int b) { } */
/* int KeCancelTimer() { } */
/* int IoAllocateIrp(int a, int b) { */ 
/*   __rho_99_ = nondet(); */
/*   return __rho_99_; */
/* } */
/* int IoFreeMdl() { } */
/* int IoSetCancelRoutine(int a) { } */
/* int ExFreePool0() { } */
/* int ExFreePool1(int a) { } */
/* int ExFreePool2(int a, int b) { } */
/* int IoCompleteRequest(int a) { } */

int main() {
  /* __rho_1_ = nondet(); */
   if (__rho_1_>0) {

       // haven't stopped yet, lets do so
       ntStatus = ?;
   }

   ntStatus = ?;


   // lets free up any crom data structs we've allocated...
   keA = 1; keA = 0; 
   /* KeAcquireSpinLock(lock3, Irql); */

   __rho_2_ = ?;
   k1 = __rho_2_;
   while (1) { 
     if (!(k1>0)) break;

     __rho_3_ = ?;
       CromData = __rho_3_;

       // get struct off list
       k1--;

       // need to free up everything associated with this allocate...
       if (CromData>0)
       {
	   __rho_4_ = ?;
           /* if (__rho_4_>0) */
           /*     ExFreePool0(); */

	   __rho_5_ = ?;
           /* if (__rho_5_>0) */
           /*     IoFreeMdl(); */

           // we already checked CromData
           /* ExFreePool1(CromData); */
       }
   }

   keR = 1; keR = 0; 
   /* KeReleaseSpinLock(lock3, Irql); */

   keA = 1; keA = 0;
   /* KeAcquireSpinLock(lock1, Irql); */

   __rho_6_ = ?;
   k2 = __rho_6_;
   while (1) {
     if (!(k2>0)) break;

     AsyncAddressData = ?;

       // get struct off list
       AsyncAddressData = ?;
       k2--;

       // need to free up everything associated with this allocate...

       __rho_7_ = ?;
       /* if (__rho_7_>0) */
       /*     IoFreeMdl(); */

       __rho_8_ = ?;
       /* if (__rho_8_>0) */
       /*     ExFreePool0(); */

       __rho_9_ = ?;
       /* if (__rho_9_>0) */
       /*     ExFreePool0(); */

       /* if (AsyncAddressData>0) */
       /*     ExFreePool0(); */
   }

   keR = 1; keR = 0;
   /* KeReleaseSpinLock(lock1, Irql); */

   // free up any attached isoch buffers
   while (1) {

       keA = 1; keA = 0;
       /* KeAcquireSpinLock(lock4, Irql); */

       __rho_10_ = ?;
       k3 = __rho_10_;
       if (k3>0) {

	 IsochDetachData = ?;
	 i = ?;

           IsochDetachData = ?;
           k3--;


           /* KeCancelTimer(); */
           keR = 1; keR = 0; 
           /* KeReleaseSpinLock(lock4, Irql); */


           /* t1394_IsochCleanup(IsochDetachData); */
       }
       else {

           keR = 1; keR = 0; 
           /* KeReleaseSpinLock(lock4, Irql); */
           break;
       }
   }

   // remove any isoch resource data

   __rho_11_ = ?;
   k4 = __rho_11_;
   while (1) {

       keA = 1; keA = 0; 
       /* KeAcquireSpinLock(lock5, Irql); */
       if (k4>0) {

	 __rho_12_ = ?;
           IsochResourceData = __rho_12_;
           k4--;

           keR = 1; keR = 0; 
           /* KeReleaseSpinLock(lock5, Irql); */


           if (IsochResourceData>0) {

	       pIrb = ?;
               ResourceIrp = ?;
               StackSize = ?;
               ResourceIrp = ?;

               if (ResourceIrp == 0) {

               }
               else {

                   pIrb = ?;

                   if (pIrb<=0) {

                       /* IoFreeIrp(ResourceIrp); */
                   }
                   else {

                       /* RtlZeroMemory (pIrb, 0); */

                       ntStatus = ?;


                       /* ExFreePool1(pIrb); */
                       /* IoFreeIrp(ResourceIrp); */
                   }
               }
           }
       }
       else {

           keR = 1; keR = 0;
           /* KeReleaseSpinLock(lock5, Irql); */
           break;
       }
   }

   // get rid of any pending bus reset notify requests
   keA = 1; keA = 0; 
   //KeAcquireSpinLock(lock6, Irql);

   __rho_13_ = ?;
   k5 = __rho_13_;
   while (1) {
     if (!(k5>0)) break;

       prevCancel = 0;

       // get the irp off of the list
       BusResetIrp = ?;
       k5--;


       // make this irp non-cancelable...
       prevCancel = ?;


       // and complete it...
       /* IoCompleteRequest(IO_NO_INCREMENT); */

       /* ExFreePool1(BusResetIrp); */
   }

   keR = 1; keR = 0; 
   //KeReleaseSpinLock(lock6, Irql);

   // free up the symbolic link

  while(1) { dummy=dummy; } 
   // L_return: return 0;
} // t1394Diag_PnpRemoveDevice

