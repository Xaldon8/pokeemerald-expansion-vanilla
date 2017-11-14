#ifndef GUARD_LINK_RFU_H
#define GUARD_LINK_RFU_H

// Exported type declarations

// Exported RAM declarations

// Exported ROM declarations
u32 sub_800BEC0(void);
void sub_800E700(void);
void sub_800EDD4(void);
void sub_800F6FC(u8 who);
void sub_800F728(u8 who);
bool32 sub_800F7E4(void);
void sub_800F804(void);
void sub_800F850(void);
u8 sub_800FCD8(void);
bool32 sub_800FE84(const void *src, size_t size);
void Rfu_set_zero(void);
u8 sub_80104F4(void);
u8 rfu_get_multiplayer_id(void);
bool8 sub_8010100(u8 a0);
bool8 sub_8010500(void);
bool8 Rfu_IsMaster(void);
void task_add_05_task_del_08FA224_when_no_RfuFunc(void);
void sub_8010434(void);
void sub_800E604(void);
void sub_800E174(void);
void sub_800E6D0(void);
bool32 sub_8010EC0(void);
bool32 sub_8010F1C(void);
bool32 sub_800F0B8(void);
u32 sub_80124D4(void);
void RfuVSync(void);

#endif //GUARD_LINK_RFU_H
