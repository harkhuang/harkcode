
#ifndef _LINUX_SEMAPHORE_INCLUDE_
#define _LINUX_SEMAPHORE_INCLUDE_

void *CreateSemaphore(void *lpSemaphoreAttributes, // SD
                       long lInitialCount,                          // initial count
                       long lMaximumCount,                          // maximum count
                       char *lpName                               // object name
);

//If the function succeeds, the return value is nonzero.
//if the function fails, the return value is zero
int ReleaseSemaphore(
  void *hSemaphore,       // handle to semaphore
  int lReleaseCount,      // count increment amount
  int *lpPreviousCount   // previous count
);

int CloseSemaphore(void *hSemaphore);

int WaitForSingleObject(void *hHandle, int dwMilliseconds);

int WaitForMultipleObjects(
  int nCount,             // number of handles in array
  void *lpHandles,  // object-handle array
  bool fWaitAll,            // wait option
  int dwMilliseconds      // time-out interval
);

void *CreateEvent(
  void *lpEventAttributes,                 // SD
  bool bManualReset,                       // reset type
  bool bInitialState,                      // initial state
  char *lpName                             // object name
);

bool SetEvent(void *hEvent);
int CloseEvent(void *hEvent);
bool ResetEvent(void *hEvent);

#endif
