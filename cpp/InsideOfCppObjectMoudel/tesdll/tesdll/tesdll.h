// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TESDLL_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TESDLL_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef TESDLL_EXPORTS
#define TESDLL_API __declspec(dllexport)
#else
#define TESDLL_API __declspec(dllimport)
#endif

// 此类是从 tesdll.dll 导出的
class TESDLL_API Ctesdll {
public:
	Ctesdll(void);
	// TODO: 在此添加您的方法。
	void foo();
};

extern TESDLL_API int ntesdll;

TESDLL_API int fntesdll(void);
