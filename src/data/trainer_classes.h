#define DEFAULT_MONEY 5
#define DEFAULT_BALL ITEM_POKE_BALL

#define TRAINER_CLASS(trainerClass, trainerName, trainerMoney, trainerBall) \
    [TRAINER_CLASS_##trainerClass] =                                        \
    {                                                                       \
        .name = trainerName,                                                \
        .money = trainerMoney,                                              \
        .ball = trainerBall,                                                \
    }

const struct TrainerClass gTrainerClasses[TRAINER_CLASS_COUNT] =
{
    TRAINER_CLASS(PKMN_TRAINER_1, _("{PKMN} TRAINER"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(PKMN_TRAINER_2, _("{PKMN} TRAINER"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(HIKER, _("HIKER"), 10, DEFAULT_BALL),
    TRAINER_CLASS(TEAM_AQUA, _("TEAM AQUA"), 5, DEFAULT_BALL),
    TRAINER_CLASS(PKMN_BREEDER, _("{PKMN} BREEDER"), 10, (B_TRAINER_CLASS_POKE_BALLS >= GEN_8) ? ITEM_HEAL_BALL : ITEM_FRIEND_BALL),
    TRAINER_CLASS(COOLTRAINER, _("COOLTRAINER"), 12, ITEM_ULTRA_BALL),
    TRAINER_CLASS(BIRD_KEEPER, _("BIRD KEEPER"), 8, DEFAULT_BALL),
    TRAINER_CLASS(COLLECTOR, _("COLLECTOR"), 15, ITEM_PREMIER_BALL),
    TRAINER_CLASS(SWIMMER_M, _("SWIMMER♂"), 2, ITEM_DIVE_BALL),
    TRAINER_CLASS(TEAM_MAGMA, _("TEAM MAGMA"), 5, DEFAULT_BALL),
    TRAINER_CLASS(EXPERT, _("EXPERT"), 10, DEFAULT_BALL),
    TRAINER_CLASS(AQUA_ADMIN, _("AQUA ADMIN"), 10, DEFAULT_BALL),
    TRAINER_CLASS(BLACK_BELT, _("BLACK BELT"), 8, ITEM_ULTRA_BALL),
    TRAINER_CLASS(AQUA_LEADER, _("AQUA LEADER"), 20, ITEM_MASTER_BALL),
    TRAINER_CLASS(HEX_MANIAC, _("HEX MANIAC"), 6, DEFAULT_BALL),
    TRAINER_CLASS(AROMA_LADY, _("AROMA LADY"), 10, DEFAULT_BALL),
    TRAINER_CLASS(RUIN_MANIAC, _("RUIN MANIAC"), 15, DEFAULT_BALL),
    TRAINER_CLASS(INTERVIEWER, _("INTERVIEWER"), 12, DEFAULT_BALL),
    TRAINER_CLASS(TUBER_F, _("TUBER"), 1, DEFAULT_BALL),
    TRAINER_CLASS(TUBER_M, _("TUBER"), 1, DEFAULT_BALL),
    TRAINER_CLASS(LADY, _("LADY"), 50, DEFAULT_BALL),
    TRAINER_CLASS(BEAUTY, _("BEAUTY"), 20, DEFAULT_BALL),
    TRAINER_CLASS(RICH_BOY, _("RICH BOY"), 50, DEFAULT_BALL),
    TRAINER_CLASS(POKEMANIAC, _("POKéMANIAC"), 15, DEFAULT_BALL),
    TRAINER_CLASS(GUITARIST, _("GUITARIST"), 8, DEFAULT_BALL),
    TRAINER_CLASS(KINDLER, _("KINDLER"), 8, DEFAULT_BALL),
    TRAINER_CLASS(CAMPER, _("CAMPER"), 4, DEFAULT_BALL),
    TRAINER_CLASS(PICNICKER, _("PICNICKER"), 4, DEFAULT_BALL),
    TRAINER_CLASS(BUG_MANIAC, _("BUG MANIAC"), 15, DEFAULT_BALL),
    TRAINER_CLASS(PSYCHIC, _("PSYCHIC"), 6, DEFAULT_BALL),
    TRAINER_CLASS(GENTLEMAN, _("GENTLEMAN"), 20, ITEM_LUXURY_BALL),
    TRAINER_CLASS(ELITE_FOUR, _("ELITE FOUR"), 25, ITEM_ULTRA_BALL),
    TRAINER_CLASS(LEADER, _("LEADER"), 25, DEFAULT_BALL),
    TRAINER_CLASS(SCHOOL_KID, _("SCHOOL KID"), 5, DEFAULT_BALL),
    TRAINER_CLASS(SR_AND_JR, _("SR. AND JR."), 4, DEFAULT_BALL),
    TRAINER_CLASS(WINSTRATE, _("WINSTRATE"), 10, DEFAULT_BALL),
    TRAINER_CLASS(POKEFAN, _("POKéFAN"), 20, DEFAULT_BALL),
    TRAINER_CLASS(YOUNGSTER, _("YOUNGSTER"), 4, DEFAULT_BALL),
    TRAINER_CLASS(CHAMPION, _("CHAMPION"), 50, DEFAULT_BALL),
    TRAINER_CLASS(FISHERMAN, _("FISHERMAN"), 10, (B_TRAINER_CLASS_POKE_BALLS >= GEN_8) ? ITEM_DIVE_BALL : ITEM_LURE_BALL),
    TRAINER_CLASS(TRIATHLETE, _("TRIATHLETE"), 10, DEFAULT_BALL),
    TRAINER_CLASS(DRAGON_TAMER, _("DRAGON TAMER"), 12, DEFAULT_BALL),
    TRAINER_CLASS(NINJA_BOY, _("NINJA BOY"), 3, DEFAULT_BALL),
    TRAINER_CLASS(BATTLE_GIRL, _("BATTLE GIRL"), 6, DEFAULT_BALL),
    TRAINER_CLASS(PARASOL_LADY, _("PARASOL LADY"), 10, DEFAULT_BALL),
    TRAINER_CLASS(SWIMMER_F, _("SWIMMER♀"), 2, ITEM_DIVE_BALL),
    TRAINER_CLASS(TWINS, _("TWINS"), 3, DEFAULT_BALL),
    TRAINER_CLASS(SAILOR, _("SAILOR"), 8, DEFAULT_BALL),
    TRAINER_CLASS(COOLTRAINER_2, _("COOLTRAINER"), DEFAULT_MONEY, ITEM_ULTRA_BALL),
    TRAINER_CLASS(MAGMA_ADMIN, _("MAGMA ADMIN"), 10, DEFAULT_BALL),
    TRAINER_CLASS(RIVAL, _("{PKMN} TRAINER"), 15, DEFAULT_BALL),
    TRAINER_CLASS(BUG_CATCHER, _("BUG CATCHER"), 4, DEFAULT_BALL),
    TRAINER_CLASS(PKMN_RANGER, _("{PKMN} RANGER"), 12, DEFAULT_BALL),
    TRAINER_CLASS(MAGMA_LEADER, _("MAGMA LEADER"), 20, ITEM_MASTER_BALL),
    TRAINER_CLASS(LASS, _("LASS"), 4, DEFAULT_BALL),
    TRAINER_CLASS(YOUNG_COUPLE, _("YOUNG COUPLE"), 8, DEFAULT_BALL),
    TRAINER_CLASS(OLD_COUPLE, _("OLD COUPLE"), 10, DEFAULT_BALL),
    TRAINER_CLASS(SIS_AND_BRO, _("SIS AND BRO"), 3, DEFAULT_BALL),
    TRAINER_CLASS(SALON_MAIDEN, _("SALON MAIDEN"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(DOME_ACE, _("DOME ACE"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(PALACE_MAVEN, _("PALACE MAVEN"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(ARENA_TYCOON, _("ARENA TYCOON"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(FACTORY_HEAD, _("FACTORY HEAD"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(PIKE_QUEEN, _("PIKE QUEEN"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(PYRAMID_KING, _("PYRAMID KING"), DEFAULT_MONEY, DEFAULT_BALL),
    TRAINER_CLASS(RS_PROTAG, _("{PKMN} TRAINER"), DEFAULT_MONEY, DEFAULT_BALL),
};
