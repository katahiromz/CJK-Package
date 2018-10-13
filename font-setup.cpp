// font-setup.cpp
// This file is public domain software.
// Copyright (C) 2018 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
#include "MRegKey.hpp"

struct FONTSUBST
{
    LPCWSTR from, to;
};

// Simplified Chinese
WCHAR CSF_LocalName0[] = {0x5B8B, 0x4F53, 0};                   // SimSun
WCHAR CSF_LocalName1[] = {0x4E2D, 0x6613, 0x5B8B, 0x4F53, 0};   // SimSun
WCHAR CSF_LocalName2[] = {0x65B0, 0x5B8B, 0x4F53, 0};           // NSimSun
WCHAR CSF_LocalName3[] = {0xFC4B, 0x91CC, 0};                   // SimHei
WCHAR CSF_LocalName4[] = {'M','S', 0x5B8B, 0x4F53, 0};         // MS Song

// Japanese
WCHAR JF_LocalName0[] = {0xFF2D, 0xFF33, ' ', 0x660E, 0x671D, 0};                           // MS Mincho
WCHAR JF_LocalName1[] = {0xFF2D, 0xFF33, ' ', 0xFF30, 0x660E, 0x671D, 0};                   // MS PMincho
WCHAR JF_LocalName2[] = {0xFF2D, 0xFF33, ' ', 0x30B4, 0x30B7, 0x30C3, 0x30AF, 0};           // MS Gothic
WCHAR JF_LocalName3[] = {0xFF2D, 0xFF33, ' ', 0xFF30, 0x30B4, 0x30B7, 0x30C3, 0x30AF, 0};   // MS PGothic
WCHAR JF_SourceMincho[] = {0x6E90, 0x30CE, 0x660E, 0x671D, 0};   // 源ノ明朝
WCHAR JF_SourceGothic[] = {0x6E90, 0x30CE, 0x89D2, 0x30B4, 0x30B7, 0x30C3, 0x30AF, ' ','R','e','g','u','l','a','r',0};   // 源ノ角ゴシック Regular
WCHAR JF_SourceGothicHW[] = {0x6E90, 0x30CE, 0x89D2, 0x30B4, 0x30B7, 0x30C3, 0x30AF, ' ', 'H','W',' ','R','e','g','u','l','a','r', 0};   // 源ノ角ゴシック HW Regular

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
    { L"SimSun",          L"Source Han Serif SC" },
    { L"NSimSun",         L"Source Han Serif SC" },
    { L"SimHei",          L"Source Han Sans SC Regular" },
    { L"MS Song",         L"Source Han Serif SC" },
    { CSF_LocalName0,     L"Source Han Serif SC" },         // SimSun
    { CSF_LocalName1,     L"Source Han Serif SC" },         // SimSun
    { CSF_LocalName2,     L"Source Han Serif SC" },         // NSimSun
    { CSF_LocalName3,     L"Source Han Sans SC Regular" },  // SimHei
    { CSF_LocalName4,     L"Source Han Serif SC" },         // MS Song

    // Japanese
    { L"MS UI Gothic",    JF_SourceGothic },
    { L"MS Mincho",       JF_SourceGothicHW },
    { L"MS PMincho",      JF_SourceMincho },
    { L"MS Gothic",       JF_SourceGothicHW },
    { L"MS PGothic",      JF_SourceGothic },
    { JF_LocalName0,      JF_SourceGothicHW },          // MS Mincho
    { JF_LocalName1,      JF_SourceMincho },            // MS PMincho
    { JF_LocalName2,      JF_SourceGothicHW },          // MS Gothic
    { JF_LocalName3,      JF_SourceGothic },            // MS PGothic

    // Korean
    { L"Batang",          L"Source Han Serif K" },
    { L"BatangChe",       L"Source Han Sans HW K Regular" },
    { L"Gungsuh",         L"Source Han Sans K Regular" },
    { L"GungsuhChe",      L"Source Han Sans HW K Regular" },
    { L"Gulim",           L"Source Han Sans K Regular" },
    { L"GulimChe",        L"Source Han Sans HW K Regular" },
    { KF_LocalName0,      L"Source Han Serif K" },              // Batang
    { KF_LocalName1,      L"Source Han Sans HW K Regular" },    // BatangChe
    { KF_LocalName2,      L"Source Han Sans K Regular" },       // Gungsuh
    { KF_LocalName3,      L"Source Han Sans HW K Regular" },    // GungsuhChe
    { KF_LocalName4,      L"Source Han Sans K Regular" },       // Gulim
    { KF_LocalName5,      L"Source Han Sans HW K Regular" },    // GulimChe

    // Traditional Chinese
    { L"MingLiU",         L"Source Han Serif TC" },
    { L"PMingLiU",        L"Source Han Serif TC" },
    { L"Ming Light",      L"Source Han Serif TC" },
    { CTF_LocalName0,     L"Source Han Serif TC" },         // MingLiU
    { CTF_LocalName1,     L"Source Han Serif TC" },         // PMingLiU
    { CTF_LocalName2,     L"Source Han Serif TC" },         // DLCMingMedium
    { CTF_LocalName3,     L"Source Han Serif TC" },         // DLCMingBold
};

// map for uninstall 
static const FONTSUBST CJK_MapForUninstall[] =
{
    { L"MS Sans Serif",   L"Droid Sans Fallback" },
    { L"MS Shell Dlg",    L"Droid Sans Fallback" },
    { L"Tahoma",          L"Droid Sans Fallback" },
    { L"System",          L"Droid Sans Fallback" },

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

// language-specific
static const FONTSUBST CJK_MapForInstallSimplifiedChinese[] =
{
    { L"MS Sans Serif",   L"Source Han Serif SC" },
    { L"MS Shell Dlg",    L"Source Han Serif SC" },
    { L"Tahoma",          L"Source Han Serif SC" },
    { L"System",          L"Source Han Serif SC" },
};
static const FONTSUBST CJK_MapForInstallJapanese[] =
{
    { L"MS Sans Serif",   L"JF_SourceGothic" },
    { L"MS Shell Dlg",    L"JF_SourceGothic" },
    { L"Tahoma",          L"JF_SourceGothic" },
    { L"System",          L"JF_SourceGothic" },
};
static const FONTSUBST CJK_MapForInstallKorean[] =
{
    { L"MS Sans Serif",   L"Source Han Serif K" },
    { L"MS Shell Dlg",    L"Source Han Serif K" },
    { L"Tahoma",          L"Source Han Serif K" },
    { L"System",          L"Source Han Serif K" },
};
static const FONTSUBST CJK_MapForInstallTraditionalChinese[] =
{
    { L"MS Sans Serif",   L"Source Han Serif SC" },
    { L"MS Shell Dlg",    L"Source Han Serif SC" },
    { L"Tahoma",          L"Source Han Serif SC" },
    { L"System",          L"Source Han Serif SC" },
};

// the list of all font files
static const LPCWSTR FontFiles[] =
{
    L"SourceHanSerif-Regular.ttc",
    L"SourceHanSans-Regular.ttc"
};

BOOL DoFont(LPCWSTR pszName, BOOL bUninstall)
{
    WCHAR szPath[MAX_PATH];
    GetWindowsDirectoryW(szPath, _countof(szPath));
    lstrcatW(szPath, L"\\Fonts\\");
    lstrcatW(szPath, pszName);
    if (bUninstall)
        return RemoveFontResource(szPath) != 0;
    else
        return AddFontResource(szPath) != 0;
}

LONG DoInstallFonts(void)
{
    size_t count = _countof(FontFiles);
    for (size_t i = 0; i < count; ++i)
    {
        if (!DoFont(FontFiles[i], FALSE))
        {
            return 1;
        }
    }
    return 0;
}

LONG DoUninstallFonts(void)
{
    size_t count = _countof(FontFiles);
    for (size_t i = 0; i < count; ++i)
    {
        if (!DoFont(FontFiles[i], TRUE))
        {
            return 1;
        }
    }
    return 0;
}

LONG DoSubst(MRegKey& key, const FONTSUBST *subst)
{
    return key.SetSz(subst->from, subst->to);
}

LONG DoOpenKey(MRegKey& key)
{
    return key.RegOpenKeyEx(
        HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontSubstitutes"),
        0, KEY_READ | KEY_WRITE);
}

LONG DoInstallSubst(const FONTSUBST *map, size_t count)
{
    MRegKey key;
    LONG nError = DoOpenKey(key);
    if (nError)
        return nError;

    for (size_t i = 0; i < count; ++i)
    {
        const FONTSUBST& mapping = map[i];
        LONG nError = DoSubst(key, &mapping);
        if (nError)
        {
            return nError;
        }
    }
    return 0;
}

LONG DoInstallLanguageSpecificSubst(void)
{
    WORD wLangID = GetUserDefaultLangID();
    switch (PRIMARYLANGID(wLangID))
    {
    case LANG_CHINESE:
        if (SUBLANGID(wLangID) == SUBLANG_CHINESE_SIMPLIFIED)
        {
            return DoInstallSubst(CJK_MapForInstallSimplifiedChinese, _countof(CJK_MapForInstallSimplifiedChinese));
        }
        if (SUBLANGID(wLangID) == SUBLANG_CHINESE_TRADITIONAL)
        {
            return DoInstallSubst(CJK_MapForInstallTraditionalChinese, _countof(CJK_MapForInstallTraditionalChinese));
        }
        break;
    case LANG_JAPANESE:
        return DoInstallSubst(CJK_MapForInstallJapanese, _countof(CJK_MapForInstallJapanese));
    case LANG_KOREAN:
        return DoInstallSubst(CJK_MapForInstallKorean, _countof(CJK_MapForInstallKorean));
    }
    return -1;
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
        nError = DoInstallFonts();
    }
    if (lstrcmpiA(lpCmdLine, "-u") == 0)
    {
        nError = DoUninstallFonts();
    }
    if (nError)
    {
        TCHAR szMsg[256];
        wsprintf(szMsg, TEXT("Error in Font Setup.\r\n\r\nError Code: %ld"), nError);
        MessageBox(NULL, szMsg, NULL, MB_ICONERROR);
        return nError;
    }

    if (lstrcmpiA(lpCmdLine, "-i") == 0)
    {
        nError = DoInstallSubst(CJK_MapForInstall, _countof(CJK_MapForInstall));
        if (nError == 0)
            nError = DoInstallLanguageSpecificSubst();
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
        return nError;
    }

    return 0;
}
