#ifndef GUARD_FIELD_EFFECTS_H
#define GUARD_FIELD_EFFECTS_H

extern const struct CompressedSpritePalette gTrainerFrontPicPaletteTable[2];
extern const struct SpritePalette gNewGameBirchObjectPaletteInfo;
extern const struct CompressedSpriteSheet gTrainerFrontPicTable[2];
extern const struct SpriteTemplate gNewGameBirchObjectTemplate;
extern const struct OamData gNewGameBirchOamAttributes;

enum FieldEffectScriptIdx
{
    FLDEFF_EXCLAMATION_MARK_ICON_1,
    FLDEFF_USE_CUT_ON_GRASS,
    FLDEFF_USE_CUT_ON_TREE,
    FLDEFF_SHADOW,
    FLDEFF_TALL_GRASS,
    FLDEFF_RIPPLE,
    FLDEFF_FIELD_MOVE_SHOW_MON,
    FLDEFF_ASH,
    FLDEFF_SURF_BLOB,
    FLDEFF_USE_SURF,
    FLDEFF_DUST,
    FLDEFF_USE_SECRET_POWER_CAVE,
    FLDEFF_JUMP_TALL_GRASS,
    FLDEFF_SAND_FOOTPRINTS,
    FLDEFF_JUMP_BIG_SPLASH,
    FLDEFF_SPLASH,
    FLDEFF_JUMP_SMALL_SPLASH,
    FLDEFF_LONG_GRASS,
    FLDEFF_JUMP_LONG_GRASS,
    FLDEFF_UNKNOWN_19,
    FLDEFF_UNKNOWN_20,
    FLDEFF_UNKNOWN_21,
    FLDEFF_UNKNOWN_22,
    FLDEFF_BERRY_TREE_GROWTH_SPARKLE,
    FLDEFF_DEEP_SAND_FOOTPRINTS,
    FLDEFF_POKECENTER_HEAL,
    FLDEFF_USE_SECRET_POWER_TREE,
    FLDEFF_USE_SECRET_POWER_SHRUB,
    FLDEFF_TREE_DISGUISE,
    FLDEFF_MOUNTAIN_DISGUISE,
    FLDEFF_NPCFLY_OUT,
    FLDEFF_USE_FLY,
    FLDEFF_FLY_IN,
    FLDEFF_EXCLAMATION_MARK_ICON_2,
    FLDEFF_FEET_IN_FLOWING_WATER,
    FLDEFF_BIKE_TIRE_TRACKS,
    FLDEFF_SAND_DISGUISE,
    FLDEFF_USE_ROCK_SMASH,
    FLDEFF_USE_DIG,
    FLDEFF_SAND_PILE,
    FLDEFF_USE_STRENGTH,
    FLDEFF_SHORT_GRASS,
    FLDEFF_HOT_SPRINGS_WATER,
    FLDEFF_USE_WATERFALL,
    FLDEFF_USE_DIVE,
    FLDEFF_POKEBALL,
    FLDEFF_HEART_ICON,
    FLDEFF_NOP_47,
    FLDEFF_NOP_48,
    FLDEFF_POP_OUT_OF_ASH,
    FLDEFF_LAVARIDGE_GYM_WARP,
    FLDEFF_SWEET_SCENT,
    FLDEFF_SAND_PILLAR,
    FLDEFF_BUBBLES,
    FLDEFF_SPARKLE,
    FLDEFF_SECRET_POWER_CAVE,
    FLDEFF_SECRET_POWER_TREE,
    FLDEFF_SECRET_POWER_SHRUB,
    FLDEFF_CUT_GRASS,
    FLDEFF_FIELD_MOVE_SHOW_MON_INIT,
    FLDEFF_USE_FLY_ANCIENT_TOMB,
    FLDEFF_PCTURN_ON,
    FLDEFF_HALL_OF_FAME_RECORD,
    FLDEFF_USE_TELEPORT
};

extern u32 gFieldEffectArguments[8];
extern void (*gUnknown_0203CEEC)(void);
extern bool8 (*gUnknown_03005DB0)(void);

u32 FieldEffectStart(u8);
bool8 FieldEffectActiveListContains(u8 id);
void sub_80B69DC(void);
u8 AddNewGameBirchObject(s16, s16, u8);
void FieldEffectStop(struct Sprite *sprite, u8 id);
u8 CreateTrainerSprite(u8 trainerSpriteID, s16 x, s16 y, u8 subpriority, u8 *buffer);
void sub_80B7FC8(void);
void FieldEffectActiveListRemove(u8 id);
void MultiplyInvertedPaletteRGBComponents(u16, u8, u8, u8);
void FieldEffectActiveListAdd(u8 id);
void FieldEffectScript_LoadTiles(u8 **script);
void FieldEffectScript_LoadFadedPalette(u8 **script);
void FieldEffectScript_LoadPalette(u8 **script);
void FieldEffectScript_CallNative(u8 **script, u32 *val);
void FieldEffectFreeTilesIfUnused(u16 tileStart);
void FieldEffectFreePaletteIfUnused(u8 paletteNum);

#endif //GUARD_FIELD_EFFECTS_H
