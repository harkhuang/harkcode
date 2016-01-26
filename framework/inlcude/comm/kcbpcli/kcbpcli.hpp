#ifndef _KCBPCLI_HPP
#define _KCBPCLI_HPP

#include "KCBPCli.h"

class KCBPCLI_API CKCBPCli
{
public:
	void *m_pKCBPCliBase;
public:
	CKCBPCli(void);
	~CKCBPCli();

	int GetVersion(int *pnVersion);

	int SetConnectOption(tagKCBPConnectOption stKCBPConnection);
	int GetConnectOption(tagKCBPConnectOption *pstKCBPConnection);

	int ConnectServer(char *ServerName, char *UserName, char *Password);
	int DisConnect();

	int BeginWrite();

	int CallProgramAndCommit(char *ProgramName);

	int CallProgram(char *ProgramName);
	int Commit();
	int RollBack();

	int GetValue(char *KeyName, char *Vlu, int Len = 0);
	int SetValue(char *KeyName, char *Vlu);

	/*rs*/
	int RsCreate(char *Name, int ColNum, char *pColInfo);
	int RsNewTable(char *Name, int ColNum, char *pColInfo);

	int RsAddRow();
	int RsSaveRow();
	int RsSetCol(int Col, char *Vlu);
	int RsSetCol(char *Name, char *Vlu);
	int RsSetColByName(char *Name, char *Vlu);

	int RsOpen();
	int RsMore();
	int RsClose();
	int RsGetCursorName(char *pszCursorName, int nLen);
	int RsGetColNames(char *pszInfo, int nLen);
	int RsGetColName(int nCol, char *pszName, int nLen);
	int RsFetchRow();

	int RsGetCol(int Col, char *Vlu);
	int RsGetCol(char *KeyName, char *Vlu);
	int RsGetColByName(char *KeyName, char *Vlu);

	int RsGetRowNum(int *pnRows);
	int RsGetColNum(int *pnCols);
	int RsGetTableRowNum(int nt, int *pnRows);
	int RsGetTableColNum(int nt, int *pnCols);

	/*misc*/
	int GetErr(int *pErrCode, char *ErrMsg);
	int GetErrorCode(int *pnErrno);
	int GetErrorMsg(char *szError);

	int GetCommLen(int *pnLen);
	int SetCliTimeOut(int TimeOut);

	/*SQL-Liked*/
	int SQLConnect(char *ServerName, char *UserName, char *Password);
	int SQLDisconnect();
	int SQLExecute(char *szProgramName);
	int SQLNumResultCols(int *pnresultcols);
	int SQLGetCursorName(char *pszCursorName, int nLen);
	int SQLGetColNames(char *szTableInfo, int nLen);
	int SQLGetColName(int nCol, char *szTableInfo, int nLen);
	int SQLFetch();
	int SQLMoreResults();
	int SQLCloseCursor();
	int SQLEndTran(int nType);
};
#endif
