#include "systemInfoIarm.h"

static void systemInfo_Loop();

#ifdef ENABLE_IARM
static IARM_Result_t getCPUDetails(void *arg);
static IARM_Result_t getNumberOfCPUCores(void *arg);
static IARM_Result_t getCPUCoresDetails(void *arg);
#endif // ifdef ENABLE_IARM

int main(int argc, char *argv[])
{
#ifdef ENABLE_IARM
    IARM_Bus_RegisterCall(IARM_BUS_SYSTEMINFO_API_getCPUDetails, getCPUDetails);
    IARM_Bus_RegisterCall(IARM_BUS_SYSTEMINFO_API_getNumberOfCPUCores, getNumberOfCPUCores);
    IARM_Bus_RegisterCall(IARM_BUS_SYSTEMINFO_API_getCPUCoresDetails, getCPUCoresDetails);
#endif
#ifdef ENABLE_SD_NOTIFY
    sd_notifyf(0, "READY=1\n"
               "STATUS=systeminfo is Successfully Initialized\n"
               "MAINPID=%lu",
               (unsigned long) getpid());
#endif

    systemInfo_Loop();

}

#ifdef ENABLE_IARM
IARM_Result_t isSystemInfoAvailable(void *arg)
{
    LOG_ENTRY_EXIT;
    LOG_INFO("[%s] IARM_BUS_SYSTEMINFO_API_isAvailable is called", MODULE_NAME);
    return IARM_RESULT_SUCCESS;
}
#endif // ENABLE_IARM

#ifdef ENABLE_IARM
    err = IARM_Bus_Init(IARM_BUS_SYS_INFO_NAME);
    if(IARM_RESULT_SUCCESS != err)
    {
        //LOG("Error initializing IARM.. error code : %d\n",err);
        return err;
    }
    err = IARM_Bus_Connect();
    if(IARM_RESULT_SUCCESS != err)
    {
        //LOG("Error connecting to IARM.. error code : %d\n",err);
        return err;
    }
#endif

void systemInfo_Loop()
{
    time_t curr = 0;
    while(1)
    {
        time(&curr);
#if !defined(ENABLE_XCAM_SUPPORT) && !defined(XHB1) && !defined(XHC3)
        printf("I-ARM SYSTEM-INFO: HeartBeat at %s\r\n", ctime(&curr));
#endif
        sleep(60);
    }
}
