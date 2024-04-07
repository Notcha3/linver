#include "firmware_ver.h"

static void BIOSVendorAndRevision(void);

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
		
		fclose(BIOSVendor);
		fclose(BIOSVersion);
        }

}
