// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB11HASHESDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB11HASHESDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB11HASHESDLL_EXPORTS
#define LAB11HASHESDLL_API __declspec(dllexport)
#else
#define LAB11HASHESDLL_API __declspec(dllimport)
#endif

// This class is exported from the dll
class LAB11HASHESDLL_API CLab11HashesDLL {
public:
	CLab11HashesDLL(void);
	// TODO: add your methods here.
};

extern LAB11HASHESDLL_API int nLab11HashesDLL;

LAB11HASHESDLL_API int fnLab11HashesDLL(void);
