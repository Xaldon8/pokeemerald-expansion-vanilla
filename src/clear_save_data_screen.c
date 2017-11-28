#include "global.h"
#include "task.h"
#include "text.h"
#include "menu.h"
#include "sound.h"
#include "main.h"
#include "save.h"
#include "palette.h"
#include "gpu_regs.h"
#include "bg.h"
#include "text_window.h"
#include "songs.h"

extern u8 gText_ClearAllSaveData[];
extern u8 gText_ClearingData[];

extern u16 gUnknown_0860F074[];

static void Task_DoClearSaveDataScreenYesNo(u8);
static void Task_ClearSaveDataScreenYesNoChoice(u8);
static void Task_ClearSaveData(u8);
static bool8 SetupClearSaveDataScreen(void);
static void CB2_FadeAndDoReset(void);
static void InitClearSaveDataScreenWindows(void);

static const struct BgTemplate sClearSaveBgTemplates[2] =
{
    {
        .bg = 0,
        .charBaseIndex = 0,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0,
    },
    {
        .bg = 3,
        .charBaseIndex = 0,
        .mapBaseIndex = 30,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 1,
        .baseTile = 0,
    },
};

static const struct WindowTemplate sClearSaveTextWindow[] =
{
    {
        .priority = 0,
        .tilemapLeft = 3,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 11,
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sClearSaveYesNo[] =
{
    {
        .priority = 0,
        .tilemapLeft = 3,
        .tilemapTop = 2,
        .width = 5,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 115,
    }
};

void CB2_InitClearSaveDataScreen(void)
{
    if(SetupClearSaveDataScreen())
        CreateTask(Task_DoClearSaveDataScreenYesNo, 0);
}

static void Task_DoClearSaveDataScreenYesNo(u8 taskId)
{
    SetWindowBorderStyle(0, 0, 2, 14);
    PrintTextOnWindow(0, 1, gText_ClearAllSaveData, 0, 1, 0, 0);
    CreateYesNoMenu(sClearSaveYesNo, 2, 14, 1);
    gTasks[taskId].func = Task_ClearSaveDataScreenYesNoChoice;
}

static void Task_ClearSaveDataScreenYesNoChoice(u8 taskId)
{
    switch(sub_8198C58())
    {
        case 0:
            FillWindowPixelBuffer(0, 17);
            PrintTextOnWindow(0, 1, gText_ClearingData, 0, 1, 0, 0);
            gTasks[taskId].func = Task_ClearSaveData;
            break;
        case 1:
        case -1:
            PlaySE(SE_SELECT);
            DestroyTask(taskId);
            SetMainCallback2(CB2_FadeAndDoReset);
    }
}

static void Task_ClearSaveData(u8 taskId)
{
    ClearSaveData();
    DestroyTask(taskId);
    SetMainCallback2(CB2_FadeAndDoReset);
}

static void MainCB(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void VBlankCB(void)
{
    TransferPlttBuffer();
}

static bool8 SetupClearSaveDataScreen(void)
{
    u16 i;

    switch(gMain.state)
    {
        case 0:
        default:
            SetVBlankCallback(NULL);
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
            SetGpuReg(REG_OFFSET_BG0HOFS, 0);
            SetGpuReg(REG_OFFSET_BG0VOFS, 0);
            SetGpuReg(REG_OFFSET_BG3HOFS, 0);
            SetGpuReg(REG_OFFSET_BG3VOFS, 0);
            SetGpuReg(REG_OFFSET_WIN0H, 0);
            SetGpuReg(REG_OFFSET_WIN0V, 0);
            SetGpuReg(REG_OFFSET_WININ, 0);
            SetGpuReg(REG_OFFSET_WINOUT, 0);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            SetGpuReg(REG_OFFSET_BLDY, 0);
            DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
            DmaFill32(3, 0, (void *)OAM, OAM_SIZE);
            DmaFill16(3, 0, (void *)(PLTT + 2), PLTT_SIZE - 2);
            ResetPaletteFade();
            gPlttBufferUnfaded[0] = 0x7fff;
            gPlttBufferFaded[0] = 0x7fff;
            gPlttBufferUnfaded[1] = 0x3945;
            gPlttBufferFaded[1] = 0x3945;
            for (i = 0; i < 0x10; i++)
                ((u16 *)(VRAM + 0x20))[i] = 0x1111;

            for (i = 0; i < 0x400; i++)
                ((u16 *)(VRAM + 0xF000))[i] = 0x0001;
            ResetTasks();
            ResetSpriteData();
            ResetBgsAndClearDma3BusyFlags(0);
            InitBgsFromTemplates(0, sClearSaveBgTemplates, ARRAY_COUNT(sClearSaveBgTemplates));
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_OBJ_ON | DISPCNT_OBJ_1D_MAP);
            ShowBg(0);
            ShowBg(3);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            InitClearSaveDataScreenWindows();
            BeginNormalPaletteFade(0x0000FFFF, 0, 0x10, 0, 0xFFFF);
            EnableInterrupts(1);
            SetVBlankCallback(VBlankCB);
            gMain.state = 1;
            break;
        case 1:
            UpdatePaletteFade();
            if(!gPaletteFade.active)
            {
                SetMainCallback2(MainCB);
                return TRUE;
            }
    }
    return FALSE;
}

static void CB2_FadeAndDoReset(void)
{
    switch(gMain.state)
    {
        case 0:
        default:
            BeginNormalPaletteFade(0x0000FFFF, 0, 0, 0x10, 0xFFFF);
            gMain.state = 1;
            break;
        case 1:
            UpdatePaletteFade();
            if(!gPaletteFade.active)
            {
                FreeAllWindowBuffers();
                DoSoftReset();
            }
    }
}

static void InitClearSaveDataScreenWindows(void)
{
    InitWindows(sClearSaveTextWindow);
    DeactivateAllTextPrinters();
    FillWindowPixelBuffer(0, 0);
    sub_80987D4(0, 0, 2, 224);
    LoadPalette(gUnknown_0860F074, 0xF0, 0x20);
}
