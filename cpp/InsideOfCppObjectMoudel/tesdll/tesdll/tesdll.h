// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� TESDLL_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// TESDLL_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef TESDLL_EXPORTS
#define TESDLL_API __declspec(dllexport)
#else
#define TESDLL_API __declspec(dllimport)
#endif

// �����Ǵ� tesdll.dll ������
class TESDLL_API Ctesdll {
public:
	Ctesdll(void);
	// TODO: �ڴ�������ķ�����
	void foo();
};

extern TESDLL_API int ntesdll;

TESDLL_API int fntesdll(void);
