const struct ShadowListEntry gShadowListEntries[] =
{
    [SHADOW_LIST_NONE] =
    {
        .shadowState = 0,
        .shadowVar = 0,
        .shadowId = 0,
        .species = SPECIES_NONE,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_RUSH, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .purifyMoves = {MOVE_POUND, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 0,
        .attackIV = 0,
        .defenseIV = 0,
        .speedIV = 0,
        .spAttackIV = 0,
        .spDefenseIV = 0,
        .boostLevel = 0,
        .level = 1,
        .heartValue = 2000,
        .heartMax = 2000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Unknown")
    }, 
    
    [SHADOW_LIST_EEVEE] =
    {
        .shadowState = 1,
        .shadowVar = 1,
        .shadowId = 1,
        .species = SPECIES_EEVEE,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_WAVE, MOVE_REVERSE_MODE, MOVE_NONE, MOVE_NONE},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_CALM_MIND, MOVE_STORED_POWER},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 31,
        .attackIV = 31,
        .defenseIV = 31,
        .speedIV = 31,
        .spAttackIV = 31,
        .spDefenseIV = 31,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_VAPOREON] =
    {
        .shadowState = 1,
        .shadowVar = 2,
        .shadowId = 2,
        .species = SPECIES_VAPOREON,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_SKY, MOVE_SHADOW_STORM, MOVE_SHADOW_MIST, MOVE_SHADOW_DOWN},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_CALM_MIND, MOVE_STORED_POWER},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 16,
        .attackIV = 16,
        .defenseIV = 16,
        .speedIV = 16,
        .spAttackIV = 16,
        .spDefenseIV = 16,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_JOLTEON] =
    {
        .shadowState = 1,
        .shadowVar = 3,
        .shadowId = 3,
        .species = SPECIES_JOLTEON,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_BOLT, MOVE_SHADOW_RAVE, MOVE_SHADOW_PANIC, MOVE_SHADOW_RUSH},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_CALM_MIND, MOVE_STORED_POWER},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 16,
        .attackIV = 16,
        .defenseIV = 16,
        .speedIV = 16,
        .spAttackIV = 16,
        .spDefenseIV = 16,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_FLAREON] =
    {
        .shadowState = 1,
        .shadowVar = 4,
        .shadowId = 4,
        .species = SPECIES_FLAREON,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_FIRE, MOVE_SHADOW_HALF, MOVE_SHADOW_BLITZ, MOVE_SHADOW_END},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_BULK_UP, MOVE_POWER_TRIP},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 16,
        .attackIV = 16,
        .defenseIV = 16,
        .speedIV = 16,
        .spAttackIV = 16,
        .spDefenseIV = 16,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_LEAFEON] =
    {
        .shadowState = 1,
        .shadowVar = 5,
        .shadowId = 5,
        .species = SPECIES_LEAFEON,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_BLAST, MOVE_NONE, MOVE_NONE, MOVE_NONE},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_BULK_UP, MOVE_POWER_TRIP},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 16,
        .attackIV = 16,
        .defenseIV = 16,
        .speedIV = 16,
        .spAttackIV = 16,
        .spDefenseIV = 16,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_GLACEON] =
    {
        .shadowState = 1,
        .shadowVar = 6,
        .shadowId = 6,
        .species = SPECIES_GLACEON,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_CHILL, MOVE_SHADOW_BREAK, MOVE_SHADOW_SHED, MOVE_SHADOW_HOLD},
        .purifyMoves = {MOVE_LAST_RESORT, MOVE_REVELATION_DANCE, MOVE_CALM_MIND, MOVE_STORED_POWER},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 16,
        .attackIV = 16,
        .defenseIV = 16,
        .speedIV = 16,
        .spAttackIV = 16,
        .spDefenseIV = 16,
        .boostLevel = 3,
        .level = 10,
        .heartMax = 4000,
        .heartValue = 4000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Michael")

    },

    [SHADOW_LIST_LUGIA] =
    {
        .shadowState = 1,
        .shadowVar = 8,
        .shadowId = 137,
        .species = SPECIES_LUGIA_SHADOW,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_BLAST, MOVE_SHADOW_DOWN, MOVE_SHADOW_SHED, MOVE_SHADOW_STORM},
        .purifyMoves = {MOVE_PSYCHO_BOOST, MOVE_FEATHER_DANCE, MOVE_EARTHQUAKE, MOVE_HYDRO_PUMP},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 31,
        .attackIV = 31,
        .defenseIV = 31,
        .speedIV = 31,
        .spAttackIV = 31,
        .spDefenseIV = 31,
        .boostLevel = 3,
        .level = 50,
        .heartMax = 12000,
        .heartValue = 12000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Greevil")

    },

    [SHADOW_LIST_MEWTWO] =
    {
        .shadowState = 1,
        .shadowVar = 8,
        .shadowId = 138,
        .species = SPECIES_MEWTWO_SHADOW,
        .experience = 0,
        .shadowMoves = {MOVE_SHADOW_END, MOVE_SHADOW_STORM, MOVE_SHADOW_RAVE, MOVE_SHADOW_PANIC},
        .purifyMoves = {MOVE_ZEN_HEADBUTT, MOVE_PSYSTRIKE, MOVE_PSYWAVE, MOVE_MIRACLE_EYE},
        .hpEV = 0,
        .attackEV = 0,
        .defenseEV = 0,
        .speedEV = 0,
        .spAttackEV = 0,
        .spDefenseEV = 0,
        .hpIV = 31,
        .attackIV = 31,
        .defenseIV = 31,
        .speedIV = 31,
        .spAttackIV = 31,
        .spDefenseIV = 31,
        .boostLevel = 3,
        .level = 70,
        .heartMax = 12000,
        .heartValue = 12000,
        .personality = 0,
        .status = 0,
        .maxHP = 1,
        .hp = 1,
        .snagLocation = 0,
        .snagTrainerName = _("Anne")

    },


};
