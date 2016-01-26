#ifndef _KDDBF_STRUCT_H_
#define _KDDBF_STRUCT_H_

//Dbf����ֶ���
#define MAX_DBFFIELDNUM 64

//����Dbf����¼��
#define MAX_RECORDNUM	2000

//����Dbf�ļ����ֵ
#define MAX_DBFFILELEN	1024 * 1024 * 5    

#pragma pack(push, 1)
typedef struct 
{
	unsigned char			bId;				/* the ID.for a FoxBase+ DBF File */
	unsigned char			bYear;              // ���һ���޸����ڣ��꣩
	unsigned char			bMonth;             // ���һ���޸����ڣ��£�
	unsigned char			bDay;				// ���һ���޸����ڣ��գ�        */
	unsigned int 			dwRecNum;			// �ļ���¼������
	unsigned short			wRecOffset;         // �ļ���¼ƫ����
	unsigned short			wRecLen;            // �����ļ���¼����
	unsigned char			bReserved[20];
}DBFHEADER, *LPDBFHEADER;

typedef struct
{
	char			szName[10];                // �ֶ���
	char			cReserve1;                 // 
	char			cType;                     // �ֶ�����
	unsigned int			dwOffset;          // ���ֶ����ļ��׼�¼�еĵ�ַ
	unsigned char			bLength;           // �ֶγ���
	unsigned char			bDecLength;        // С��λ��
	unsigned char			szReserved[32-18];
}DBFFIELDINFO, *LPDBFFIELDINFO;
#pragma  pack(pop)

#endif