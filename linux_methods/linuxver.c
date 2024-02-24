#include "linuxver.h"

void GetSysInfoAbstract(void) {
  GetLinuxVer();
  PrintKernelArgs();
  PrintProtocol();
  GetTotalMemory();
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

	if (CmdLine != NULL) {
		char *CmdString = NULL;
	
		getdelim(&CmdString, &StringSize, 0, CmdLine);
	
		printf("Kernel boot parameters:\t%s", CmdString);
	}

	else
		puts("Kernel boot parameters:\tUnable to get");

	fclose(CmdLine);

}

static void PrintProtocol(void) {
	const char *SessionType = getenv("XDG_SESSION_TYPE");

	if (SessionType != NULL)
		printf("Session type:\t", SessionType);

	else
		puts("Session type:\tUnable to get");
}

static void GetTotalMemory(void) {
	long PhysPages = sysconf(_SC_PHYS_PAGES),
	PageSize = sysconf(_SC_PAGE_SIZE);
	
	long MemorySize = PageSize * PhysPages;
	
	if (MemorySize>1000000000)
	  printf("\n%s:\t%d%s", "Total Memory", (PhysPages * PageSize) / (int)pow(10, 9), "Gb");
	else
	  printf("\n%s:\t%d%s", "Total Memory", (PhysPages * PageSize) / (int)pow(10, 6), "Mb");
}
