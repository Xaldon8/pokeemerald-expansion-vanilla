#include "global.h"
#include "battle_factory.h"
#include "battle_factory_screen.h"
#include "event_data.h"
#include "battle_setup.h"
#include "overworld.h"
#include "frontier_util.h"
#include "battle_tower.h"
#include "random.h"
#include "constants/species.h"
#include "constants/battle_ai.h"
#include "constants/battle_frontier.h"
#include "constants/trainers.h"
#include "constants/moves.h"

extern u8 gUnknown_03001288;
extern u16 gUnknown_03006298[];

extern const struct FacilityMon gBattleFrontierMons[];
extern const struct FacilityMon gSlateportBattleTentMons[];
extern const struct BattleFrontierTrainer gBattleFrontierTrainers[];
extern const u16 gBattleFrontierHeldItems[];

// This file's functions.
static void sub_81A5E94(void);
static void sub_81A5FA8(void);
static void sub_81A6054(void);
static void sub_81A613C(void);
static void nullsub_75(void);
static void nullsub_123(void);
static void sub_81A6188(void);
static void sub_81A6198(void);
static void sub_81A61A4(void);
static void sub_81A63CC(void);
static void sub_81A64C4(void);
static void sub_81A63B8(void);
static void sub_81A61B0(void);
static void sub_81A67EC(void);
static void sub_81A6A08(void);
static void sub_81A6AEC(void);
static void sub_81A6C1C(void);
static u16 GetMonSetId(u8 lvlMode, u8 challengeNum, bool8 arg2);
static u8 GetStyleForMove(u16 move);

// Const rom data.
static const u8 sRequiredMoveCounts[] = {3, 3, 3, 2, 2, 2, 2};

static const u16 sMoves_TotalPreparation[] =
{
    MOVE_SWORDS_DANCE, MOVE_GROWTH, MOVE_MEDITATE, MOVE_AGILITY, MOVE_DOUBLE_TEAM, MOVE_HARDEN,
    MOVE_MINIMIZE, MOVE_WITHDRAW, MOVE_DEFENSE_CURL, MOVE_BARRIER, MOVE_FOCUS_ENERGY, MOVE_AMNESIA,
    MOVE_ACID_ARMOR, MOVE_SHARPEN, MOVE_CONVERSION, MOVE_CONVERSION_2, MOVE_BELLY_DRUM, MOVE_PSYCH_UP,
    MOVE_CHARGE, MOVE_SNATCH, MOVE_TAIL_GLOW, MOVE_COSMIC_POWER, MOVE_IRON_DEFENSE, MOVE_HOWL, MOVE_BULK_UP, MOVE_CALM_MIND, MOVE_DRAGON_DANCE,
    0
};

static const u16 sMoves_ImpossibleToPredict[] =
{
    MOVE_MIMIC, MOVE_METRONOME, MOVE_MIRROR_MOVE, MOVE_TRANSFORM, MOVE_SUBSTITUTE, MOVE_SKETCH, MOVE_CURSE,
    MOVE_PRESENT, MOVE_FOLLOW_ME, MOVE_TRICK, MOVE_ROLE_PLAY, MOVE_ASSIST, MOVE_SKILL_SWAP, MOVE_CAMOUFLAGE,
    0
};

static const u16 sMoves_WeakeningTheFoe[] =
{
    MOVE_SAND_ATTACK, MOVE_TAIL_WHIP, MOVE_LEER, MOVE_GROWL, MOVE_STRING_SHOT, MOVE_SCREECH, MOVE_SMOKESCREEN, MOVE_KINESIS,
    MOVE_FLASH, MOVE_COTTON_SPORE, MOVE_SPITE, MOVE_SCARY_FACE, MOVE_CHARM, MOVE_KNOCK_OFF, MOVE_SWEET_SCENT, MOVE_FEATHER_DANCE,
    MOVE_FAKE_TEARS, MOVE_METAL_SOUND, MOVE_TICKLE,
    0
};

static const u16 sMoves_HighRiskHighReturn[] =
{
    MOVE_GUILLOTINE, MOVE_HORN_DRILL, MOVE_DOUBLE_EDGE, MOVE_HYPER_BEAM, MOVE_COUNTER, MOVE_FISSURE,
    MOVE_BIDE, MOVE_SELF_DESTRUCT, MOVE_SKY_ATTACK, MOVE_EXPLOSION, MOVE_FLAIL, MOVE_REVERSAL, MOVE_DESTINY_BOND,
    MOVE_PERISH_SONG, MOVE_PAIN_SPLIT, MOVE_MIRROR_COAT, MOVE_MEMENTO, MOVE_GRUDGE, MOVE_FACADE, MOVE_FOCUS_PUNCH,
    MOVE_BLAST_BURN, MOVE_HYDRO_CANNON, MOVE_OVERHEAT, MOVE_FRENZY_PLANT, MOVE_PSYCHO_BOOST, MOVE_VOLT_TACKLE,
    0
};

static const u16 sMoves_Endurance[] =
{
    MOVE_MIST, MOVE_RECOVER, MOVE_LIGHT_SCREEN, MOVE_HAZE, MOVE_REFLECT, MOVE_SOFT_BOILED, MOVE_REST, MOVE_PROTECT,
    MOVE_DETECT, MOVE_ENDURE, MOVE_MILK_DRINK, MOVE_HEAL_BELL, MOVE_SAFEGUARD, MOVE_BATON_PASS, MOVE_MORNING_SUN,
    MOVE_SYNTHESIS, MOVE_MOONLIGHT, MOVE_SWALLOW, MOVE_WISH, MOVE_INGRAIN, MOVE_MAGIC_COAT, MOVE_RECYCLE, MOVE_REFRESH,
    MOVE_MUD_SPORT, MOVE_SLACK_OFF, MOVE_AROMATHERAPY, MOVE_WATER_SPORT,
    0
};

static const u16 sMoves_SlowAndSteady[] =
{
    MOVE_SING, MOVE_SUPERSONIC, MOVE_DISABLE, MOVE_LEECH_SEED, MOVE_POISON_POWDER, MOVE_STUN_SPORE, MOVE_SLEEP_POWDER,
    MOVE_THUNDER_WAVE, MOVE_TOXIC, MOVE_HYPNOSIS, MOVE_CONFUSE_RAY, MOVE_GLARE, MOVE_POISON_GAS, MOVE_LOVELY_KISS, MOVE_SPORE,
    MOVE_SPIDER_WEB, MOVE_SWEET_KISS, MOVE_SPIKES, MOVE_SWAGGER, MOVE_MEAN_LOOK, MOVE_ATTRACT, MOVE_ENCORE, MOVE_TORMENT,
    MOVE_FLATTER, MOVE_WILL_O_WISP, MOVE_TAUNT, MOVE_YAWN, MOVE_IMPRISON, MOVE_SNATCH, MOVE_TEETER_DANCE, MOVE_GRASS_WHISTLE, MOVE_BLOCK,
    0
};

static const u16 sMoves_DependsOnTheBattlesFlow[] =
{
    MOVE_SANDSTORM, MOVE_RAIN_DANCE, MOVE_SUNNY_DAY, MOVE_HAIL, MOVE_WEATHER_BALL,
    0
};

static const u16 *const sMoveStyles[] =
{
    sMoves_TotalPreparation,
    sMoves_SlowAndSteady,
    sMoves_Endurance,
    sMoves_HighRiskHighReturn,
    sMoves_WeakeningTheFoe,
    sMoves_ImpossibleToPredict,
    sMoves_DependsOnTheBattlesFlow,
};

static void (* const gUnknown_08612120[])(void) =
{
    sub_81A5E94,
    sub_81A5FA8,
    sub_81A6054,
    sub_81A613C,
    nullsub_75,
    nullsub_123,
    sub_81A6188,
    sub_81A6198,
    sub_81A61A4,
    sub_81A63CC,
    sub_81A64C4,
    sub_81A63B8,
    sub_81A61B0,
    sub_81A67EC,
    sub_81A6A08,
    sub_81A6AEC,
    sub_81A6C1C,
};

static const u32 gUnknown_08612164[][2] =
{
    {0x100, 0x200},
    {0x1000000, 0x2000000},
};

static const u32 gUnknown_08612174[][2] =
{
    {0xfffffeff, 0xfffffdff},
    {0xfeffffff, 0xfdffffff},
};

static const u8 sFixedIVTable[][2] =
{
    {3, 6},
    {6, 9},
    {9, 12},
    {12, 15},
    {15, 18},
    {21, 31},
    {31, 31},
    {31, 31},
};

static const u16 sMonsToChooseFrom[][2] =
{
    {0x006e, 0x00c7},
    {0x00a2, 0x010a},
    {0x010b, 0x0173},
    {0x0174, 0x01d3},
    {0x01d4, 0x0233},
    {0x0234, 0x0293},
    {0x0294, 0x02f3},
    {0x0174, 0x0351},
    {0x0174, 0x01d3},
    {0x01d4, 0x0233},
    {0x0234, 0x0293},
    {0x0294, 0x02f3},
    {0x0174, 0x0371},
    {0x0174, 0x0371},
    {0x0174, 0x0371},
    {0x0174, 0x0371},
};

// code
void CallBattleFactoryFunction(void)
{
    gUnknown_08612120[gSpecialVar_0x8004]();
}

static void sub_81A5E94(void)
{
    u8 i;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    gSaveBlock2Ptr->frontier.field_CA8 = 0;
    gSaveBlock2Ptr->frontier.curChallengeBattleNum = 0;
    gSaveBlock2Ptr->frontier.field_CA9_a = 0;
    gSaveBlock2Ptr->frontier.field_CA9_b = 0;
    if (!(gSaveBlock2Ptr->frontier.field_CDC & gUnknown_08612164[battleMode][lvlMode]))
    {
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = 0;
        gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = 0;
    }

    gUnknown_03001288 = 0;
    for (i = 0; i < 6; i++)
        gSaveBlock2Ptr->frontier.field_E70[i].monId |= 0xFFFF;
    for (i = 0; i < 3; i++)
        gUnknown_03006298[i] |= 0xFFFF;

    saved_warp2_set(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, -1);
    gTrainerBattleOpponent_A = 0;
}

static void sub_81A5FA8(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 1:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
        break;
    case 2:
        gSpecialVar_Result = ((gSaveBlock2Ptr->frontier.field_CDC & gUnknown_08612164[battleMode][lvlMode]) != 0);
        break;
    case 3:
        gSpecialVar_Result = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];
        break;
    }
}

static void sub_81A6054(void)
{
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);

    switch (gSpecialVar_0x8005)
    {
    case 1:
        gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] = gSpecialVar_0x8006;
        break;
    case 2:
        if (gSpecialVar_0x8006)
            gSaveBlock2Ptr->frontier.field_CDC |= gUnknown_08612164[battleMode][lvlMode];
        else
            gSaveBlock2Ptr->frontier.field_CDC &= gUnknown_08612174[battleMode][lvlMode];
        break;
    case 3:
        if (gUnknown_03001288 == 1)
        {
            gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode] = gSpecialVar_0x8006;
            gUnknown_03001288 = 0;
        }
        break;
    }
}

static void sub_81A613C(void)
{
    gSaveBlock2Ptr->frontier.field_CA8 = gSpecialVar_0x8005;
    VarSet(VAR_TEMP_0, 0);
    gSaveBlock2Ptr->frontier.field_CA9_a = 1;
    sub_81A4C30();
}

static void nullsub_75(void)
{

}

static void nullsub_123(void)
{

}

static void sub_81A6188(void)
{
    ZeroPlayerPartyMons();
    DoBattleFactorySelectScreen();
}

static void sub_81A6198(void)
{
    DoBattleFactorySwapScreen();
}

static void sub_81A61A4(void)
{
    gUnknown_03001288 = 1;
}

static void sub_81A61B0(void)
{
    s32 i, j, k;
    u16 species[3];
    u16 heldItems[3];
    s32 firstMonId = 0;
    u16 trainerId = 0;
    u32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u32 winStreak = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode];
    u32 challengeNum = winStreak / 7;
    gFacilityTrainers = gBattleFrontierTrainers;

    do
    {
        trainerId = sub_8162548(challengeNum, gSaveBlock2Ptr->frontier.curChallengeBattleNum);
        for (i = 0; i < gSaveBlock2Ptr->frontier.curChallengeBattleNum; i++)
        {
            if (gSaveBlock2Ptr->frontier.field_CB4[i] == trainerId)
                break;
        }
    } while (i != gSaveBlock2Ptr->frontier.curChallengeBattleNum);

    gTrainerBattleOpponent_A = trainerId;
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum < 6)
        gSaveBlock2Ptr->frontier.field_CB4[gSaveBlock2Ptr->frontier.curChallengeBattleNum] = trainerId;

    i = 0;
    while (i != 3)
    {
        u16 monSetId = GetMonSetId(lvlMode, challengeNum, FALSE);
        if (gFacilityTrainerMons[monSetId].species == SPECIES_UNOWN)
            continue;

        for (j = 0; j < 6; j++)
        {
            if (gFacilityTrainerMons[monSetId].species == gFacilityTrainerMons[gSaveBlock2Ptr->frontier.field_E70[j].monId].species)
                break;
        }
        if (j != 6)
            continue;

        if (lvlMode == FRONTIER_LVL_50 && monSetId > 849)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monSetId].species)
                break;
        }
        if (k != firstMonId + i)
            continue;

        for (k = firstMonId; k < firstMonId + i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
                break;
        }
        if (k != firstMonId + i)
            continue;

        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        gUnknown_03006298[i] = monSetId;
        i++;
    }
}

static void sub_81A63B8(void)
{
    SetBattleFacilityTrainerGfxId(gTrainerBattleOpponent_A, 0);
}

static void sub_81A63CC(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < 3; i++)
    {
        gSaveBlock2Ptr->frontier.field_E70[i + 3].monId = gUnknown_03006298[i];
        gSaveBlock2Ptr->frontier.field_E70[i + 3].ivs = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ATK_IV, NULL);
        gSaveBlock2Ptr->frontier.field_E70[i + 3].personality = GetMonData(&gEnemyParty[i], MON_DATA_PERSONALITY, NULL);
        gSaveBlock2Ptr->frontier.field_E70[i + 3].abilityBit = GetBoxMonData(&gEnemyParty[i].box, MON_DATA_ALT_ABILITY, NULL);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[gUnknown_03006298[i]].itemTableId]);
    }
}

static void sub_81A64C4(void)
{
    s32 i, j, k;
    s32 count = 0;
    u8 bits = 0;
    u8 monLevel;
    u16 monSetId;
    u16 evs;
    u8 ivs;
    u8 friendship;

    if (gSaveBlock2Ptr->frontier.lvlMode == FRONTIER_LVL_TENT)
    {
        gFacilityTrainerMons = gSlateportBattleTentMons;
        monLevel = 30;
    }
    else
    {
        gFacilityTrainerMons = gBattleFrontierMons;
        if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
            monLevel = 100;
        else
            monLevel = 50;
    }

    if (gSpecialVar_0x8005 < 2)
    {
        ZeroPlayerPartyMons();
        for (i = 0; i < 3; i++)
        {
            monSetId = gSaveBlock2Ptr->frontier.field_E70[i].monId;
            ivs = gSaveBlock2Ptr->frontier.field_E70[i].ivs;
            CreateMon(&gPlayerParty[i],
                      gFacilityTrainerMons[monSetId].species,
                      monLevel,
                      ivs,
                      TRUE, gSaveBlock2Ptr->frontier.field_E70[i].personality,
                      0, 0);

            count = 0;
            bits = gFacilityTrainerMons[monSetId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monSetId].evSpread & bits)
                    SetMonData(&gPlayerParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gPlayerParty[i]);
            friendship = 0;
            for (k = 0; k < 4; k++)
                SetMonMoveAvoidReturn(&gPlayerParty[i], gFacilityTrainerMons[monSetId].moves[k], k);
            SetMonData(&gPlayerParty[i], MON_DATA_FRIENDSHIP, &friendship);
            SetMonData(&gPlayerParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
            SetMonData(&gPlayerParty[i], MON_DATA_ALT_ABILITY, &gSaveBlock2Ptr->frontier.field_E70[i].abilityBit);
        }
    }

    switch (gSpecialVar_0x8005)
    {
    case 0:
    case 2:
        for (i = 0; i < 3; i++)
        {
            monSetId = gSaveBlock2Ptr->frontier.field_E70[i + 3].monId;
            ivs = gSaveBlock2Ptr->frontier.field_E70[i + 3].ivs;
            CreateMon(&gEnemyParty[i],
                      gFacilityTrainerMons[monSetId].species,
                      monLevel,
                      ivs,
                      TRUE, gSaveBlock2Ptr->frontier.field_E70[i + 3].personality,
                      0, 0);

            count = 0;
            bits = gFacilityTrainerMons[monSetId].evSpread;
            for (j = 0; j < NUM_STATS; bits >>= 1, j++)
            {
                if (bits & 1)
                    count++;
            }

            evs = MAX_TOTAL_EVS / count;
            bits = 1;
            for (j = 0; j < NUM_STATS; bits <<= 1, j++)
            {
                if (gFacilityTrainerMons[monSetId].evSpread & bits)
                    SetMonData(&gEnemyParty[i], MON_DATA_HP_EV + j, &evs);
            }

            CalculateMonStats(&gEnemyParty[i]);
            for (k = 0; k < 4; k++)
                SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monSetId].moves[k], k);
            SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
            SetMonData(&gEnemyParty[i], MON_DATA_ALT_ABILITY, &gSaveBlock2Ptr->frontier.field_E70[i + 3].abilityBit);
        }
        break;
    }
}

static void sub_81A67EC(void)
{
    s32 i, j;
    u8 firstMonId;
    u8 battleMode;
    u8 lvlMode;
    u8 challengeNum;
    u8 factoryLvlMode;
    u8 factoryBattleMode;
    u8 var_40;
    u16 monSetId;
    u16 currSpecies;
    u16 species[PARTY_SIZE];
    u16 monIds[PARTY_SIZE];
    u16 heldItems[PARTY_SIZE];

    gFacilityTrainers = gBattleFrontierTrainers;
    for (i = 0; i < PARTY_SIZE; i++)
    {
        species[i] = 0;
        monIds[i] = 0;
        heldItems[i] = 0;
    }
    lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
    if (VarGet(VAR_FRONTIER_BATTLE_MODE) == FRONTIER_MODE_DOUBLES)
        factoryBattleMode = FRONTIER_MODE_DOUBLES;
    else
        factoryBattleMode = FRONTIER_MODE_SINGLES;

    gFacilityTrainerMons = gBattleFrontierMons;
    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_50)
    {
        factoryLvlMode = FRONTIER_LVL_OPEN;
        firstMonId = 0;
    }
    else
    {
        factoryLvlMode = FRONTIER_LVL_50;
        firstMonId = 0;
    }
    var_40 = sub_81A6F70(factoryBattleMode, factoryLvlMode);

    currSpecies = 0;
    i = 0;
    while (i != PARTY_SIZE)
    {
        if (i < var_40)
            monSetId = GetMonSetId(factoryLvlMode, challengeNum, TRUE);
        else
            monSetId = GetMonSetId(factoryLvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monSetId].species == SPECIES_UNOWN)
            continue;

        // Cannot have two pokemon of the same species.
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            u16 monId = monIds[j];
            if (monId == monSetId)
                break;
            if (species[j] == gFacilityTrainerMons[monSetId].species)
            {
                if (currSpecies == 0)
                    currSpecies = gFacilityTrainerMons[monSetId].species;
                else
                    break;
            }
        }
        if (j != firstMonId + i)
            continue;

        // Cannot have two same held items.
        for (j = firstMonId; j < firstMonId + i; j++)
        {
            if (heldItems[j] != 0 && heldItems[j] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
            {
                if (gFacilityTrainerMons[monSetId].species == currSpecies)
                    currSpecies = 0;
                break;
            }
        }
        if (j != firstMonId + i)
            continue;

        gSaveBlock2Ptr->frontier.field_E70[i].monId = monSetId;
        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        monIds[i] = monSetId;
        i++;
    }
}

static void sub_81A6A08(void)
{
    u8 i;
    u8 typesCount[18];
    u8 usedType[2];

    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < NUMBER_OF_MON_TYPES; i++)
        typesCount[i] = 0;
    for (i = 0; i < 3; i++)
    {
        u32 species = gFacilityTrainerMons[gUnknown_03006298[i]].species;

        typesCount[gBaseStats[species].type1]++;
        if (gBaseStats[species].type1 != gBaseStats[species].type2)
            typesCount[gBaseStats[species].type2]++;
    }

    usedType[0] = 0;
    usedType[1] = 0;
    for (i = 1; i < NUMBER_OF_MON_TYPES; i++)
    {
        if (typesCount[usedType[0]] < typesCount[i])
            usedType[0] = i;
        else if (typesCount[usedType[0]] == typesCount[i])
            usedType[1] = i;
    }

    gSpecialVar_Result = gSpecialVar_Result; // Needed to match. Don't ask me why.
    if (typesCount[usedType[0]] != 0 && (typesCount[usedType[0]] > typesCount[usedType[1]] || usedType[0] == usedType[1]))
        gSpecialVar_Result = usedType[0];
    else
        gSpecialVar_Result = NUMBER_OF_MON_TYPES;
}

static void sub_81A6AEC(void)
{
    u8 i, j, count;
    u8 stylePoints[8];

    count = 0;
    gFacilityTrainerMons = gBattleFrontierMons;
    for (i = 0; i < 8; i++)
        stylePoints[i] = 0;
    for (i = 0; i < 3; i++)
    {
        u16 monSetId = gUnknown_03006298[i];
        for (j = 0; j < 4; j++)
        {
            u8 id = GetStyleForMove(gFacilityTrainerMons[monSetId].moves[j]);
            stylePoints[id]++;
        }
    }

    gSpecialVar_Result = 0;
    for (i = 1; i < 8; i++)
    {
        if (stylePoints[i] >= sRequiredMoveCounts[i - 1])
        {
            gSpecialVar_Result = i;
            count++;
        }
    }
    if (count > 2)
        gSpecialVar_Result = 8;
}

static u8 GetStyleForMove(u16 move)
{
    const u16 *moves;
    u8 i, j;

    for (i = 0; i < ARRAY_COUNT(sMoveStyles); i++)
    {
        for (j = 0, moves = sMoveStyles[i]; moves[j] != 0; j++)
        {
            if (moves[j] == move)
                return i + 1;
        }
    }
    return 0;
}

bool8 sub_81A6BF4(void)
{
    return (gMapHeader.mapLayoutId == 347 || gMapHeader.mapLayoutId == 348);
}

static void sub_81A6C1C(void)
{
    u8 i;

    if (gSaveBlock2Ptr->frontier.lvlMode != FRONTIER_LVL_TENT)
        gFacilityTrainerMons = gBattleFrontierMons;
    else
        gFacilityTrainerMons = gSlateportBattleTentMons;

    for (i = 0; i < 3; i++)
    {
        SetMonData(&gPlayerParty[i],
                   MON_DATA_HELD_ITEM,
                   &gBattleFrontierHeldItems[gFacilityTrainerMons[gSaveBlock2Ptr->frontier.field_E70[i].monId].itemTableId]);
    }
}

u8 GetFactoryMonFixedIV(u8 arg0, u8 arg1)
{
    u8 a1;
    u8 a2 = (arg1 != 0) ? 1 : 0;

    if (arg0 > 8)
        a1 = 7;
    else
        a1 = arg0;

    return sFixedIVTable[a1][a2];
}

void FillFactoryBrainParty(void)
{
    s32 i, j, k;
    u16 species[3];
    u16 heldItems[3];
    u8 friendship;
    s32 monLevel;
    u8 fixedIV;
    u32 otId;

    u8 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;
    u8 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
    u8 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;
    fixedIV = GetFactoryMonFixedIV(challengeNum + 2, 0);
    monLevel = SetFacilityPtrsGetLevel();
    i = 0;
    otId = T1_READ_32(gSaveBlock2Ptr->playerTrainerId);

    while (i != 3)
    {
        u16 monSetId = GetMonSetId(lvlMode, challengeNum, FALSE);

        if (gFacilityTrainerMons[monSetId].species == SPECIES_UNOWN)
            continue;
        if (monLevel == 50 && monSetId > 849)
            continue;

        for (j = 0; j < 6; j++)
        {
            if (monSetId == gSaveBlock2Ptr->frontier.field_E70[j].monId)
                break;
        }
        if (j != 6)
            continue;

        for (k = 0; k < i; k++)
        {
            if (species[k] == gFacilityTrainerMons[monSetId].species)
                break;
        }
        if (k != i)
            continue;

        for (k = 0; k < i; k++)
        {
            if (heldItems[k] != 0 && heldItems[k] == gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId])
                break;
        }
        if (k != i)
            continue;

        species[i] = gFacilityTrainerMons[monSetId].species;
        heldItems[i] = gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId];
        CreateMonWithEVSpreadNatureOTID(&gEnemyParty[i],
                                             gFacilityTrainerMons[monSetId].species,
                                             monLevel,
                                             gFacilityTrainerMons[monSetId].nature,
                                             fixedIV,
                                             gFacilityTrainerMons[monSetId].evSpread,
                                             otId);

        friendship = 0;
        for (k = 0; k < 4; k++)
            SetMonMoveAvoidReturn(&gEnemyParty[i], gFacilityTrainerMons[monSetId].moves[k], k);
        SetMonData(&gEnemyParty[i], MON_DATA_FRIENDSHIP, &friendship);
        SetMonData(&gEnemyParty[i], MON_DATA_HELD_ITEM, &gBattleFrontierHeldItems[gFacilityTrainerMons[monSetId].itemTableId]);
        i++;
    }
}

static u16 GetMonSetId(u8 lvlMode, u8 challengeNum, bool8 arg2)
{
    u16 range, ret;
    u16 adder;

    if (lvlMode == FRONTIER_LVL_50)
        adder = 0;
    else
        adder = 8;

    if (challengeNum < 7)
    {
        if (arg2)
        {
            range = (sMonsToChooseFrom[adder + challengeNum + 1][1] - sMonsToChooseFrom[adder + challengeNum + 1][0]) + 1;
            ret = Random() % range;
            ret += sMonsToChooseFrom[adder + challengeNum + 1][0];
        }
        else
        {
            range = (sMonsToChooseFrom[adder + challengeNum][1] - sMonsToChooseFrom[adder + challengeNum][0]) + 1;
            ret = Random() % range;
            ret += sMonsToChooseFrom[adder + challengeNum][0];
        }
    }
    else
    {
        u16 num = challengeNum;
        if (num != 7)
            num = 7;
        range = (sMonsToChooseFrom[adder + num][1] - sMonsToChooseFrom[adder + num][0]) + 1;
        ret = Random() % range;
        ret += sMonsToChooseFrom[adder + num][0];
    }

    return ret;
}

u8 sub_81A6F70(u8 battleMode, u8 lvlMode)
{
    u8 ret;
    u8 rents = gSaveBlock2Ptr->frontier.factoryRentsCount[battleMode][lvlMode];

    if (rents < 15)
        ret = 0;
    else if (rents < 22)
        ret = 1;
    else if (rents < 29)
        ret = 2;
    else if (rents < 36)
        ret = 3;
    else if (rents < 43)
        ret = 4;
    else
        ret = 5;

    return ret;
}

u32 GetAiScriptsInBattleFactory(void)
{
    s32 lvlMode = gSaveBlock2Ptr->frontier.lvlMode;

    if (lvlMode == FRONTIER_LVL_TENT)
    {
        return 0;
    }
    else
    {
        s32 battleMode = VarGet(VAR_FRONTIER_BATTLE_MODE);
        s32 challengeNum = gSaveBlock2Ptr->frontier.factoryWinStreaks[battleMode][lvlMode] / 7;

        if (gTrainerBattleOpponent_A == TRAINER_FRONTIER_BRAIN)
            return AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY;
        else if (challengeNum < 2)
            return 0;
        else if (challengeNum < 4)
            return AI_SCRIPT_CHECK_BAD_MOVE;
        else
            return AI_SCRIPT_CHECK_BAD_MOVE | AI_SCRIPT_TRY_TO_FAINT | AI_SCRIPT_CHECK_VIABILITY;
    }
}

void SetMonMoveAvoidReturn(struct Pokemon *mon, u16 moveArg, u8 moveSlot)
{
    u16 move = moveArg;
    if (moveArg == MOVE_RETURN)
        move = MOVE_FRUSTRATION;
    SetMonMoveSlot(mon, move, moveSlot);
}
