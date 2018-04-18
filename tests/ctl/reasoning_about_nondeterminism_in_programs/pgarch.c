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

// Property: G F wakened==1
//int __phi() { return CAG(CEF(CAP(wakend == 1))); }
//
// -ctl "AG{EF{wakend == 1}}" -precondition "wakend==1"

int dummy;
int wakend;
int pc;

/*
 * pgarch_MainLoop
 *
 * Main loop for archiver
 */
int          last_copy_time = 0;
int          curtime;
int got_SIGHUP;

int __rho_1_;
int __rho_2_;
int __rho_3_;
int __rho_4_;

/* void init() { */
/*   wakend = 1; __rho_1_ = nondet(); got_SIGHUP = __rho_2_; */
/* } */


/* void ProcessConfigFile(int a) {} */
/* int XLogArchivingActive() { */ 
/*   __rho_2_ = nondet(); */
/* return __rho_2_; */
/* } */
/* void pgarch_ArchiverCopyLoop() { } */
/* int time(int a) { return nondet(); } */
/* void pg_usleep(int a) {} */
/* #define PGARCH_AUTOWAKE_INTERVAL 1000 */
/* int PostmasterIsAlive(int a) { return nondet(); } */

void main() {

        /*
         * We run the copy loop immediately upon entry, in case there are
         * unarchived files left over from a previous database run (or maybe
         * the archiver died unexpectedly).  After that we wait for a signal
         * or timeout before doing more.
         */
        wakend = 1;

        while(1)
        {
                /* Check for config update */
                if (got_SIGHUP>0)
                {
                        got_SIGHUP = 0;
                        //ProcessConfigFile(PGC_SIGHUP);

              __rho_2_ = ?;
			int tt = __rho_2_;
			  if (tt<=0)
                                break;                  /* user wants us to shut down */
                }
                /* Do what we're here for */
                if (wakend>0)
                {
                        wakend = 0;
                        /* pgarch_ArchiverCopyLoop(); */
                        last_copy_time = ?;
                }
                /*
                 * There shouldn't be anything for the archiver to do except to
                 * wait for a signal, ... however, the archiver exists to
                 * protect our data, so she wakes up occasionally to allow
                 * herself to be proactive. In particular this avoids getting
                 * stuck if a signal arrives just before we sleep.
                 */
                if (wakend<=0)
                {
		  //pg_usleep(PGARCH_AUTOWAKE_INTERVAL * 1000000L);

                        curtime = ?;
                        if ((curtime - last_copy_time) >= 1000)
                                wakend = 1;
                }
		__rho_4_ = ?;
		dummy = __rho_4_; //  PostmasterIsAlive(true);
		if (dummy<=0) break;
        }

  while(1) { dummy=dummy; } 
    //L_return: return 0;
}

