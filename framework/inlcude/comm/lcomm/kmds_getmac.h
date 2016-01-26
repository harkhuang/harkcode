
#include <stdio.h>
#include <stdlib.h>
#if defined(_WIN32) || defined(_WIN64)
#include <Windows.h>
#include <time.h>
#pragma comment(lib,"netapi32.lib")
#else
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <net/if.h>
#include <string.h>
#include <unistd.h>
#endif
#include <lcomm/macro_ldef.h>


int GetMacInfo(char *pszMac, int nSize)
{
    int nRet = -1;
    if (pszMac == NULL || nSize <= 0)
    {
        return -2;
    }
    *pszMac = 0x00;

    int nFlag = 0;
#if defined(_WIN32) || defined(_WIN64)
typedef struct _ASTAT_
{
    ADAPTER_STATUS adapt;
    NAME_BUFFER    NameBuff[30];
}ASTAT, *PSATAT;

    ASTAT Adapetr;
    NCB Ncb;
    UCHAR uRetCode;
    LANA_ENUM lenum;
    int i = 0;

    memset(&Ncb, 0, sizeof(Ncb));
    Ncb.ncb_command = NCBENUM;
    Ncb.ncb_buffer = (UCHAR *)&lenum;
    Ncb.ncb_length = sizeof(lenum);
    uRetCode = Netbios(&Ncb);
    for (i = 0; i < lenum.length; i++)
    {
        memset(&Ncb, 0, sizeof(Ncb));
        Ncb.ncb_command = NCBRESET;
        Ncb.ncb_lana_num = lenum.lana[i];
        uRetCode = Netbios(&Ncb);

        memset(&Ncb, 0, sizeof(Ncb));
        Ncb.ncb_command = NCBASTAT;
        Ncb.ncb_lana_num = lenum.lana[i];
        strcpy((char *)Ncb.ncb_callname, "*");
        Ncb.ncb_buffer = (unsigned char *)&Adapetr;
        Ncb.ncb_length = sizeof(Adapetr);
        uRetCode = Netbios(&Ncb);
        if (uRetCode == 0)
        {
            _snprintf(pszMac, nSize,
                "%02X%02X%02X%02X%02X%02X",
                Adapetr.adapt.adapter_address[0],
                Adapetr.adapt.adapter_address[1],
                Adapetr.adapt.adapter_address[2],
                Adapetr.adapt.adapter_address[3],
                Adapetr.adapt.adapter_address[4],
                Adapetr.adapt.adapter_address[5]);
            pszMac[nSize] = 0;
            nFlag = 1;
            break;
        }
    }
#else
   	int fd, intrface;
   	struct ifreq buf[1024];
   	struct ifconf ifc;
   	if ((fd = socket (AF_INET, SOCK_DGRAM, 0)) >= 0)
   	{
      	ifc.ifc_len = sizeof(buf);
      	ifc.ifc_buf = (caddr_t) buf;
      	if (!ioctl (fd, SIOCGIFCONF, (char *) &ifc))
      	{
         	intrface = ifc.ifc_len / sizeof (struct ifreq);
         	while (intrface-- > 0)
         	{
              	if (!(ioctl (fd, SIOCGIFHWADDR, (char *) &buf[intrface])))
              	{
					if (!buf[intrface].ifr_hwaddr.sa_data[0]
					    && !buf[intrface].ifr_hwaddr.sa_data[1]
					    && !buf[intrface].ifr_hwaddr.sa_data[2]
					    && !buf[intrface].ifr_hwaddr.sa_data[3]
					    && !buf[intrface].ifr_hwaddr.sa_data[4]
					    && !buf[intrface].ifr_hwaddr.sa_data[5])
					{
					    continue;
					}
                    snprintf(pszMac, nSize,
                             "%02X%02X%02X%02X%02X%02X",
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[0],
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[1],
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[2],
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[3],
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[4],
		                     (unsigned char)buf[intrface].ifr_hwaddr.sa_data[5]);
                    pszMac[nSize] = 0;
                    nFlag = 1;
		            break;
              	}
	          	else
	          	{
                    nRet = -3;
	          	}
          	}
      	}
		else
		{
            nRet = -4;
		}
    }
	else
	{
        return -5;
	}
    close (fd);
#endif

    if (nFlag == 1)
    {
        nRet = 0;
    }
    return nRet;
}
