#include "firmware_ver.h"

void GetFirmwareVerAbstract(void) {
	BIOSVendorAndRevision();
}

static void BIOSVendorAndRevision(void) {
	size_t StringSize = 0;
        FILE *BIOSVendor = fopen("/sys/class/dmi/id/bios_vendor", "r"),
	*BIOSVersion = fopen("/sys/class/dmi/id/bios_version", "r");

        if ((BIOSVendor != NULL) && (BIOSVersion != NULL)) {
                char *BIOSVenString = NULL,
		*BIOSVerString = NULL;

                getdelim(&BIOSVenString, &StringSize, 0, BIOSVendor);
		getdelim(&BIOSVerString, &StringSize, 0, BIOSVersion);
		
                printf("\nMotherboard firmware vendor:\t%s%s\t%s", BIOSVenString, "Motherboard firmware version:", BIOSVerString);
        }

        else
                puts("Motherboard firmware version:\tUnable to get");

        fclose(BIOSVendor);
	fclose(BIOSVersion);
}
