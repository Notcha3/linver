#include "linuxver.h"

static void GetLinuxVer(void);
static void PrintKernelArgs(void);
static void PrintProtocol(void);
static void GetTotalMemory(void);
static void GetRootFSstat(void);


void GetSysInfoAbstract(void) {
  GetLinuxVer();
  PrintKernelArgs();
  PrintProtocol();
  GetTotalMemory();
  GetRootFSstat();
}

static void GetLinuxVer(void) {
struct utsname Uname;
 if (uname(&Uname) < 0) {
   exit(EXIT_FAILURE);
 }

 printf("%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n%s\t%s\n",
	"System Name:",
	Uname.sysname,
	"Node name:",
	Uname.nodename,
	"Release:",
	Uname.release,
	"Version:",
	Uname.version,
	"Machine:",
	Uname.machine
	);

}

static void PrintKernelArgs(void) {
	size_t StringSize = 0;
	FILE *CmdLine = NULL;
	CmdLine = fopen("/proc/cmdline", "r");

	if ((CmdLine != NULL)) {
		char *CmdString = NULL;
	
		getdelim(&CmdString, &StringSize, 0, CmdLine);
	
		printf("Kernel boot parameters:\t%s", CmdString);
		fclose(CmdLine);
	}

}

static void PrintProtocol(void) {

 const char *EnvironmentList[8][2] = {{"Protocol\0", "XDG_SESSION_TYPE\0"},
				 {"WM\0", "WINDOW_MANAGER\0"},
				 {"DE\0", "DESKTOP_SESSION\0"},
				 {"Terminal\0", "TERM_PROGRAM\0"},
				 {"Shell\0","SHELL\0"},
				 {"Username\0", "USER\0"},
				 {"Locale\0", "LANG\0"},
				 {"Home directory\0", "HOME\0"}};
 char *TmpString = NULL;
  
 for(int a = 0; a<7; a++) {
   TmpString = getenv(EnvironmentList[a][1]);
		      
    if(TmpString != NULL)
     printf("%s:\t%s\n", EnvironmentList[a][0], TmpString);
 }

  
}

static void GetTotalMemory(void) {
	long PhysPages = sysconf(_SC_PHYS_PAGES),
	PageSize = sysconf(_SC_PAGE_SIZE);
	
	long MemorySize = PageSize * PhysPages;
	
	if (MemorySize>1000000000)
	  printf("%s:\t%zu%s", "Total Memory", (PhysPages * PageSize) / (size_t)pow(10, 9), "Gb");
	
	else if (MemorySize == 0) return;
	  
	else
	  printf("\n%s:\t%zu%s", "Total Memory", (PhysPages * PageSize) / (size_t)pow(10, 6), "Mb");
}

static void GetRootFSstat(void) {
  
}
