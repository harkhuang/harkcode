#ifndef _KDDBF_STRUCT_H_
#define _KDDBF_STRUCT_H_

//Dbf最大字段数
#define MAX_DBFFIELDNUM 64

//定义Dbf最大记录数
#define MAX_RECORDNUM	2000

//定义Dbf文件最大值
#define MAX_DBFFILELEN	1024 * 1024 * 5    

#pragma pack(push, 1)
typedef struct 
{
	unsigned char			bId;				/* the ID.for a FoxBase+ DBF File */
	unsigned char			bYear;              // 最后一次修改日期（年）
	unsigned char			bMonth;             // 最后一次修改日期（月）
	unsigned char			bDay;				// 最后一次修改日期（日）        */
	unsigned int 			dwRecNum;			// 文件记录总条数
	unsigned short			wRecOffset;         // 文件记录偏移量
	unsigned short			wRecLen;            // 单条文件记录长度
	unsigned char			bReserved[20];
}DBFHEADER, *LPDBFHEADER;

typedef struct
{
	char			szName[10];                // 字段名
	char			cReserve1;                 // 
	char			cType;                     // 字段类型
	unsigned int			dwOffset;          // 该字段在文件首记录中的地址
	unsigned char			bLength;           // 字段长度
	unsigned char			bDecLength;        // 小数位数
	unsigned char			szReserved[32-18];
}DBFFIELDINFO, *LPDBFFIELDINFO;
#pragma  pack(pop)

#endif