// font-setup.cpp
// This file is public domain software.
// Copyright (C) 2018-2019 Katayama Hirofumi MZ <katayama.hirofumi.mz@gmail.com>
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
WCHAR CSF_LocalName4[] = {'M','S', 0x5B8B, 0x4F53, 0};          // MS Song

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
    { L"SimSun",          L"Unifont" },                         // MUST BE MONO
    { L"NSimSun",         L"Noto Serif CJK SC" },
    { L"SimHei",          L"Unifont" },                         // MUST BE MONO
    { L"MS Song",         L"Unifont" },                         // MUST BE MONO
    { CSF_LocalName0,     L"Unifont" },                         // same as SimSun
    { CSF_LocalName1,     L"Unifont" },                         // same as SimSun
    { CSF_LocalName2,     L"Noto Serif CJK SC" },               // same as NSimSun
    { CSF_LocalName3,     L"Unifont" },                         // same as SimHei
    { CSF_LocalName4,     L"Unifont" },                         // same as MS Song

    // Japanese
    { L"MS UI Gothic",    L"Noto Sans CJK JP Regular" },
    { L"MS Mincho",       L"Noto Sans Mono CJK JP Regular" },   // MUST BE MONO
    { L"MS Gothic",       L"Noto Sans Mono CJK JP Regular" },   // MUST BE MONO
    { L"MS PMincho",      L"Noto Serif CJK JP" },
    { L"MS PGothic",      L"Noto Sans CJK JP Regular" },
    { JF_LocalName0,      L"Noto Sans Mono CJK JP Regular" },   // same as MS Mincho
    { JF_LocalName2,      L"Noto Sans Mono CJK JP Regular" },   // same as MS Gothic
    { JF_LocalName1,      L"Noto Serif CJK JP" },               // same as MS PMincho
    { JF_LocalName3,      L"Noto Sans CJK JP Regular" },        // same as MS PGothic

    // Korean
    { L"Batang",          L"Noto Serif CJK KR" },
    { L"BatangChe",       L"Noto Sans Mono CJK KR Regular" },   // MUST BE MONO
    { L"Gungsuh",         L"Noto Serif CJK KR" },
    { L"GungsuhChe",      L"Noto Sans Mono CJK KR Regular" },   // MUST BE MONO
    { L"Gulim",           L"Noto Sans CJK KR Regular" },
    { L"GulimChe",        L"Noto Sans Mono CJK KR Regular" },   // MUST BE MONO
    { KF_LocalName0,      L"Noto Serif CJK KR" },               // same as Batang
    { KF_LocalName1,      L"Noto Sans Mono CJK KR Regular" },   // same as BatangChe
    { KF_LocalName2,      L"Noto Serif CJK KR" },               // same as Gungsuh
    { KF_LocalName3,      L"Noto Sans Mono CJK KR Regular" },   // same as GungsuhChe
    { KF_LocalName4,      L"Noto Sans CJK KR Regular" },        // same as Gulim
    { KF_LocalName5,      L"Noto Sans Mono CJK KR Regular" },   // same as GulimChe

    // Traditional Chinese
    { L"MingLiU",         L"Unifont" },                         // MUST BE MONO
    { L"PMingLiU",        L"Noto Serif CJK TC" },
    { L"Ming Light",      L"Unifont" },                         // MUST BE MONO
    { CTF_LocalName0,     L"Unifont" },                         // same as MingLiU
    { CTF_LocalName1,     L"Noto Serif CJK TC" },               // same as PMingLiU
    { CTF_LocalName2,     L"Unifont" },                         // same as DLCMingMedium
    { CTF_LocalName3,     L"Unifont" },                         // same as DLCMingBold
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

// language-specific
static const FONTSUBST CJK_MapForInstallSimplifiedChinese[] =
{
    { L"MS Sans Serif",   L"Noto Serif CJK SC" },
    { L"MS Shell Dlg",    L"Noto Serif CJK SC" },
    { L"Tahoma",          L"Noto Serif CJK SC" },
    { L"System",          L"Noto Serif CJK SC" },
    { L"Lucida Console",  L"Noto Sans Mono CJK SC Regular" },
    { L"Terminal",        L"Noto Sans Mono CJK SC Regular" },
    { L"Microsoft Sans Serif",   L"Noto Sans CJK SC Regular" },
};
static const FONTSUBST CJK_MapForInstallJapanese[] =
{
    { L"MS Sans Serif",   L"Noto Sans CJK JP Regular" },
    { L"MS Shell Dlg",    L"Noto Sans CJK JP Regular" },
    { L"Tahoma",          L"Noto Sans CJK JP Regular" },
    { L"System",          L"Noto Sans CJK JP Regular" },
    { L"Lucida Console",  L"Noto Sans Mono CJK JP Regular" },
    { L"Terminal",        L"Noto Sans Mono CJK JP Regular" },
    { L"Microsoft Sans Serif",   L"Noto Sans CJK JP Regular" },
};
static const FONTSUBST CJK_MapForInstallKorean[] =
{
    { L"MS Sans Serif",   L"Noto Serif CJK KR" },
    { L"MS Shell Dlg",    L"Noto Serif CJK KR" },
    { L"Tahoma",          L"Noto Serif CJK KR" },
    { L"System",          L"Noto Serif CJK KR" },
    { L"Lucida Console",  L"Noto Sans Mono CJK KR Regular" },
    { L"Terminal",        L"Noto Sans Mono CJK KR Regular" },
    { L"Microsoft Sans Serif",   L"Noto Sans CJK KR Regular" },
};
static const FONTSUBST CJK_MapForInstallTraditionalChinese[] =
{
    { L"MS Sans Serif",   L"Noto Serif CJK TC" },
    { L"MS Shell Dlg",    L"Noto Serif CJK TC" },
    { L"Tahoma",          L"Noto Serif CJK TC" },
    { L"System",          L"Noto Serif CJK TC" },
    { L"Lucida Console",  L"Noto Sans Mono CJK TC Regular" },
    { L"Terminal",        L"Noto Sans Mono CJK TC Regular" },
    { L"Microsoft Sans Serif",   L"Noto Sans CJK TC Regular" },
};
static const FONTSUBST CJK_MapForInstallNonCJK[] =
{
    { L"MS Sans Serif",   L"Tahoma" },
    { L"MS Shell Dlg",    L"Tahoma" },
    { L"Tahoma",          L"Tahoma" },
    { L"System",          L"FreeSans" },
    { L"Lucida Console",  L"DejaVu Sans Mono" },
    { L"Terminal",        L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",   L"Tahoma" },
};

static const FONTSUBST CJK_MapForUninstallSimplifiedChinese[] =
{
    { L"MS Sans Serif",   L"Droid Sans Fallback" },
    { L"MS Shell Dlg",    L"Droid Sans Fallback" },
    { L"Tahoma",          L"Droid Sans Fallback" },
    { L"System",          L"Droid Sans Fallback" },
    { L"Lucida Console",  L"DejaVu Sans Mono" },
    { L"Terminal",        L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",  L"Droid Sans Fallback" },
};
static const FONTSUBST CJK_MapForUninstallJapanese[] =
{
    { L"MS Sans Serif",   L"Droid Sans Fallback" },
    { L"MS Shell Dlg",    L"Droid Sans Fallback" },
    { L"Tahoma",          L"Droid Sans Fallback" },
    { L"System",          L"Droid Sans Fallback" },
    { L"Lucida Console",  L"DejaVu Sans Mono" },
    { L"Terminal",        L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",  L"Droid Sans Fallback" },
};
static const FONTSUBST CJK_MapForUninstallKorean[] =
{
    { L"MS Sans Serif",   L"Droid Sans Fallback" },
    { L"MS Shell Dlg",    L"Droid Sans Fallback" },
    { L"Tahoma",          L"Droid Sans Fallback" },
    { L"System",          L"Droid Sans Fallback" },
    { L"Lucida Console",  L"DejaVu Sans Mono" },
    { L"Terminal",        L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",  L"Droid Sans Fallback" },
};
static const FONTSUBST CJK_MapForUninstallTraditionalChinese[] =
{
    { L"MS Sans Serif",   L"Droid Sans Fallback" },
    { L"MS Shell Dlg",    L"Droid Sans Fallback" },
    { L"Tahoma",          L"Droid Sans Fallback" },
    { L"System",          L"Droid Sans Fallback" },
    { L"Lucida Console",  L"DejaVu Sans Mono" },
    { L"Terminal",        L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",  L"Droid Sans Fallback" },
};
static const FONTSUBST CJK_MapForUninstallNonCJK[] =
{
    { L"MS Sans Serif",         L"Tahoma" },
    { L"MS Shell Dlg",          L"Tahoma" },
    { L"Tahoma",                L"Tahoma" },
    { L"System",                L"FreeSans" },
    { L"Lucida Console",        L"DejaVu Sans Mono" },
    { L"Terminal",              L"DejaVu Sans Mono" },
    { L"Microsoft Sans Serif",  L"Tahoma" },
};

// the list of all font files
static const LPCWSTR FontFiles[] =
{
    L"NotoSerifCJK-Regular.ttc",
    L"NotoSansCJK-Regular.ttc",
    L"unifont-12.0.01.ttf"
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

LONG DoOpenKeyForSubst(MRegKey& key)
{
    return key.RegOpenKeyEx(
        HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\FontSubstitutes"),
        0, KEY_READ | KEY_WRITE);
}

LONG DoSetupSubst(const FONTSUBST *map, size_t count)
{
    MRegKey key;
    LONG nError = DoOpenKeyForSubst(key);
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
            return DoSetupSubst(CJK_MapForInstallSimplifiedChinese, _countof(CJK_MapForInstallSimplifiedChinese));
        }
        if (SUBLANGID(wLangID) == SUBLANG_CHINESE_TRADITIONAL)
        {
            return DoSetupSubst(CJK_MapForInstallTraditionalChinese, _countof(CJK_MapForInstallTraditionalChinese));
        }
        // FALL THROUGH
    default:
        return DoSetupSubst(CJK_MapForInstallNonCJK, _countof(CJK_MapForInstallNonCJK));
    case LANG_JAPANESE:
        return DoSetupSubst(CJK_MapForInstallJapanese, _countof(CJK_MapForInstallJapanese));
    case LANG_KOREAN:
        return DoSetupSubst(CJK_MapForInstallKorean, _countof(CJK_MapForInstallKorean));
    }
    return -1;
}

LONG DoUninstallSubst(void)
{
    MRegKey key;

    LONG nError = DoOpenKeyForSubst(key);
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

LONG DoUninstallLanguageSpecificSubst(void)
{
    WORD wLangID = GetUserDefaultLangID();
    switch (PRIMARYLANGID(wLangID))
    {
    case LANG_CHINESE:
        if (SUBLANGID(wLangID) == SUBLANG_CHINESE_SIMPLIFIED)
        {
            return DoSetupSubst(CJK_MapForUninstallSimplifiedChinese, _countof(CJK_MapForUninstallSimplifiedChinese));
        }
        if (SUBLANGID(wLangID) == SUBLANG_CHINESE_TRADITIONAL)
        {
            return DoSetupSubst(CJK_MapForUninstallTraditionalChinese, _countof(CJK_MapForUninstallTraditionalChinese));
        }
        // FALL THROUGH
    default:
        return DoSetupSubst(CJK_MapForUninstallNonCJK, _countof(CJK_MapForUninstallNonCJK));
    case LANG_JAPANESE:
        return DoSetupSubst(CJK_MapForUninstallJapanese, _countof(CJK_MapForUninstallJapanese));
    case LANG_KOREAN:
        return DoSetupSubst(CJK_MapForUninstallKorean, _countof(CJK_MapForUninstallKorean));
    }
    return -1;
}

LONG DoOpenKeyForConsole(MRegKey& key)
{
    return key.RegOpenKeyEx(
        HKEY_LOCAL_MACHINE,
        TEXT("SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion\\Console\\TrueTypeFont"),
        0, KEY_READ | KEY_WRITE);
}

LONG DoInstallConsoleFont(void)
{
    MRegKey key;
    LONG ret = DoOpenKeyForConsole(key);
    if (ret)
        return ret;

    key.SetSz(L"936", L"Unifont");
    key.SetSz(L"950", L"Unifont");
    key.SetSz(L"932", L"MS Gothic");
    key.SetSz(L"949", L"GulimChe");
    return ERROR_SUCCESS;
}

LONG DoUninstallConsoleFont(void)
{
    MRegKey key;
    LONG ret = DoOpenKeyForConsole(key);
    if (ret)
        return ret;

    key.RegDeleteValue(L"936");
    key.RegDeleteValue(L"950");
    key.RegDeleteValue(L"932");
    key.RegDeleteValue(L"949");
    return ERROR_SUCCESS;
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
        nError = DoSetupSubst(CJK_MapForInstall, _countof(CJK_MapForInstall));
        if (nError == 0)
            nError = DoInstallLanguageSpecificSubst();
        if (nError == 0)
            nError = DoInstallConsoleFont();
    }
    if (lstrcmpiA(lpCmdLine, "-u") == 0)
    {
        nError = DoSetupSubst(CJK_MapForUninstall, _countof(CJK_MapForUninstall));
        if (nError == 0)
            nError = DoUninstallLanguageSpecificSubst();
        if (nError == 0)
            nError = DoUninstallConsoleFont();
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
