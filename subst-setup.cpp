#include "MRegKey.hpp"
#include "MTextToText.hpp"

struct FONTSUBST
{
    LPCWSTR from, to;
};

// Simplified Chinese
WCHAR CSF_LocalName0[] = {0x5B8B, 0x4F53, 0};                   // SimSun
WCHAR CSF_LocalName1[] = {0x4E2D, 0x6613, 0x5B8B, 0x4F53, 0};   // SimSun
WCHAR CSF_LocalName2[] = {0x65B0, 0x5B8B, 0x4F53, 0};           // NSimSun
WCHAR CSF_LocalName3[] = {0xFC4B, 0x91CC, 0};                   // SimHei
WCHAR CSF_LocalName4[] = {'M', 'S', 0x5B8B, 0x4F53, 0};         // MS Song

// Japanese
WCHAR JF_LocalName0[] = {0xFF2D, 0xFF33, ' ', 0x660E, 0x671D, 0};                           // MS Mincho
WCHAR JF_LocalName1[] = {0xFF2D, 0xFF33, ' ', 0xFF30, 0x660E, 0x671D, 0};                   // MS PMincho
WCHAR JF_LocalName2[] = {0xFF2D, 0xFF33, ' ', 0x30B4, 0x30B7, 0x30C3, 0x30AF, 0};           // MS Gothic
WCHAR JF_LocalName3[] = {0xFF2D, 0xFF33, ' ', 0xFF30, 0x30B4, 0x30B7, 0x30C3, 0x30AF, 0};   // MS PGothic

// Korean
WCHAR KF_LocalName0[] = {0xBC14, 0xD0D5, 0};            // Batang
WCHAR KF_LocalName1[] = {0xBC14, 0xD0D5, 0xCCB4, 0};    // BatangChe
WCHAR KF_LocalName2[] = {0xAD81, 0xC11C, 0};            // Gungsuh
WCHAR KF_LocalName3[] = {0xAD81, 0xC11C, 0xCCB4, 0};    // GungsuhChe
WCHAR KF_LocalName4[] = {0xAD74, 0xB9BC, 0};            // Gulim
WCHAR KF_LocalName5[] = {0xAD74, 0xB9BC, 0xCCB4, 0};    // GulimChe

// Traditional Chinese
WCHAR CTF_LocalName0[] = {0x7D30, 0x660E, 0x9AD4, 0};                   // MingLiU
WCHAR CTF_LocalName1[] = {0x65B0, 0x7D30, 0x660E, 0x9AD4, 0};           // PMingLiU
WCHAR CTF_LocalName2[] = {0x83EF, 0x5EB7, 0x4E2D, 0x660E, 0x9AD4, 0};   // DLCMingMedium
WCHAR CTF_LocalName3[] = {0x83EF, 0x5EB7, 0x7C97, 0x660E, 0x9AD4, 0};   // DLCMingBold

static const FONTSUBST CJK_MapForInstall[] =
{
    // Simplified Chinese
    { L"SimSun",          L"WenQuanYi Zen Hei Mono" },
    { L"NSimSun",         L"WenQuanYi Zen Hei" },
    { L"SimHei",          L"Source Han Sans CN" },
    { L"MS Song",         L"WenQuanYi Zen Hei Mono" },
    { CSF_LocalName0,     L"WenQuanYi Zen Hei Mono" },  // SimSun
    { CSF_LocalName1,     L"WenQuanYi Zen Hei Mono" },  // SimSun
    { CSF_LocalName2,     L"WenQuanYi Zen Hei" },       // NSimSun
    { CSF_LocalName3,     L"WenQuanYi Zen Hei Mono" },  // SimHei
    { CSF_LocalName4,     L"Source Han Sans CN" },      // MS Song

    // Japanese
    { L"MS UI Gothic",    L"IPAPGothic" },
    { L"MS Mincho",       L"IPAMincho" },
    { L"MS PMincho",      L"IPAPMincho" },
    { L"MS Gothic",       L"IPAGothic" },
    { L"MS PGothic",      L"IPAPGothic" },
    { JF_LocalName0,      L"IPAMincho" },       // MS Mincho
    { JF_LocalName1,      L"IPAPMincho" },      // MS PMincho
    { JF_LocalName2,      L"IPAGothic" },       // MS Gothic
    { JF_LocalName3,      L"IPAPGothic" },      // MS PGothic

    // Korean
    { L"Batang",          L"Source Han Serif KR" },
    { L"BatangChe",       L"WenQuanYi Zen Hei Mono" },
    { L"Gungsuh",         L"Source Han Sans KR" },
    { L"GungsuhChe",      L"WenQuanYi Zen Hei Mono" },
    { L"Gulim",           L"Source Han Sans KR" },
    { L"GulimChe",        L"WenQuanYi Zen Hei Mono" },
    { KF_LocalName0,      L"Source Han Serif KR" },     // Batang
    { KF_LocalName1,      L"WenQuanYi Zen Hei Mono" },  // BatangChe
    { KF_LocalName2,      L"Source Han Sans KR" },      // Gungsuh
    { KF_LocalName3,      L"WenQuanYi Zen Hei Mono" },  // GungsuhChe
    { KF_LocalName4,      L"Source Han Sans KR" },      // Gulim
    { KF_LocalName5,      L"WenQuanYi Zen Hei Mono" },  // GulimChe

    // Traditional Chinese
    { L"Ming Light",      L"WenQuanYi Zen Hei Mono" },
    { L"MingLiU",         L"WenQuanYi Zen Hei Mono" },
    { L"PMingLiU",        L"Source Han Serif TW" },
    { CTF_LocalName0,     L"WenQuanYi Zen Hei Mono" },      // MingLiU
    { CTF_LocalName1,     L"Source Han Serif TW" },         // PMingLiU
    { CTF_LocalName2,     L"WenQuanYi Zen Hei Mono" },      // DLCMingMedium
    { CTF_LocalName3,     L"WenQuanYi Zen Hei Mono" },      // DLCMingBold
};

// map for uninstall 
static const FONTSUBST CJK_MapForUninstall[] =
{
    // Simplified Chinese
    { L"SimSun",          L"Droid Sans Fallback" },
    { L"NSimSun",         L"Droid Sans Fallback" },
    { L"SimHei",          L"Droid Sans Fallback" },
    { L"MS Song",         L"Droid Sans Fallback" },
    { CSF_LocalName0,     L"Droid Sans Fallback" },
    { CSF_LocalName1,     L"Droid Sans Fallback" },
    { CSF_LocalName2,     L"Droid Sans Fallback" },
    { CSF_LocalName3,     L"Droid Sans Fallback" },
    { CSF_LocalName4,     L"Droid Sans Fallback" },

    // Japanese
    { L"MS UI Gothic",    L"Droid Sans Fallback" },
    { L"MS Mincho",       L"Droid Sans Fallback" },
    { L"MS PMincho",      L"Droid Sans Fallback" },
    { L"MS Gothic",       L"Droid Sans Fallback" },
    { L"MS PGothic",      L"Droid Sans Fallback" },
    { JF_LocalName0,      L"Droid Sans Fallback" },
    { JF_LocalName1,      L"Droid Sans Fallback" },
    { JF_LocalName2,      L"Droid Sans Fallback" },
    { JF_LocalName3,      L"Droid Sans Fallback" },

    // Korean
    { L"Batang",          L"Droid Sans Fallback" },
    { L"BatangChe",       L"Droid Sans Fallback" },
    { L"Gungsuh",         L"Droid Sans Fallback" },
    { L"GungsuhChe",      L"Droid Sans Fallback" },
    { L"Gulim",           L"Droid Sans Fallback" },
    { L"GulimChe",        L"Droid Sans Fallback" },
    { KF_LocalName0,      L"Droid Sans Fallback" },
    { KF_LocalName1,      L"Droid Sans Fallback" },
    { KF_LocalName2,      L"Droid Sans Fallback" },
    { KF_LocalName3,      L"Droid Sans Fallback" },
    { KF_LocalName4,      L"Droid Sans Fallback" },
    { KF_LocalName5,      L"Droid Sans Fallback" },

    // Traditional Chinese
    { L"Ming Light",      L"Droid Sans Fallback" },
    { L"MingLiU",         L"Droid Sans Fallback" },
    { L"PMingLiU",        L"Droid Sans Fallback" },
    { CTF_LocalName0,     L"Droid Sans Fallback" },
    { CTF_LocalName1,     L"Droid Sans Fallback" },
    { CTF_LocalName2,     L"Droid Sans Fallback" },
    { CTF_LocalName3,     L"Droid Sans Fallback" },
};

LONG DoSubst(MRegKey& key, const FONTSUBST *subst)
{
    return key.SetSz(MWideToText(CP_ACP, subst->from).c_str(),
                     MWideToText(CP_ACP, subst->to).c_str());
}

LONG DoOpenKey(MRegKey& key)
{
    return key.RegOpenKeyEx(
        HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontSubstitutes"),
        0, KEY_READ | KEY_WRITE);
}

LONG DoInstallSubst(void)
{
    MRegKey key;
    LONG nError = DoOpenKey(key);
    if (nError)
        return nError;

    size_t count = _countof(CJK_MapForInstall);
    for (size_t i = 0; i < count; ++i)
    {
        const FONTSUBST& mapping = CJK_MapForInstall[i];
        LONG nError = DoSubst(key, &mapping);
        if (nError)
        {
            return nError;
        }
    }
    return 0;
}

LONG DoUninstallSubst(void)
{
    MRegKey key;

    LONG nError = DoOpenKey(key);
    if (nError)
        return nError;

    size_t count = _countof(CJK_MapForUninstall);
    for (size_t i = 0; i < count; ++i)
    {
        const FONTSUBST& mapping = CJK_MapForUninstall[i];
        LONG nError = DoSubst(key, &mapping);
        if (nError)
        {
            return nError;
        }
    }
    return 0;
}

extern "C"
INT WINAPI
WinMain(HINSTANCE   hInstance,
        HINSTANCE   hPrevInstance,
        LPSTR       lpCmdLine,
        INT         nCmdShow)
{
    LONG nError = 0;
    if (lstrcmpiA(lpCmdLine, "-i") == 0)
    {
        nError = DoInstallSubst();
    }
    if (lstrcmpiA(lpCmdLine, "-u") == 0)
    {
        nError = DoUninstallSubst();
    }
    if (nError)
    {
        TCHAR szMsg[256];
        wsprintf(szMsg, TEXT("Error in Font Substitution Setup.\r\n\r\nError Code: %ld"), nError);
        MessageBox(NULL, szMsg, NULL, MB_ICONERROR);
    }
    return nError;
}
