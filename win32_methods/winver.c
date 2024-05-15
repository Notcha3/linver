#include "winver.h"

static VOID WINAPI fnDisplaySystemInfo(VOID) {
    DWORD dwVersion = 0; 
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0; 
    DWORD dwBuild = 0;

    dwVersion = GetVersion();
    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    if (dwVersion < 0x80000000)              
        dwBuild = (DWORD)(HIWORD(dwVersion));

    printf(
            "System version:\tWindows\t%lu.%lu\nBuild:\t(%lu)\n", 
            dwMajorVersion,
            dwMinorVersion,
            dwBuild
            );
}

static VOID WINAPI fnGetTotalMemory(VOID) {
    MEMORYSTATUSEX MemStatus;

    MemStatus.dwLength = sizeof(MemStatus);
    GlobalMemoryStatusEx(&MemStatus);

    if (MemStatus.ullTotalPhys>1000000000) printf("%s:\t%lld%s", "Total Memory", MemStatus.ullTotalPhys / (size_t)pow(10, 9), "Gb");
	
	else if (MemStatus.ullTotalPhys == 0) return;
	  
	else printf("\n%s:\t%lld%s", "Total Memory", MemStatus.ullTotalPhys / (size_t)pow(10, 6), "Mb");

}

VOID WINAPI GetSysInfoAbstract(VOID) {
    fnDisplaySystemInfo();
    fnGetTotalMemory();
}