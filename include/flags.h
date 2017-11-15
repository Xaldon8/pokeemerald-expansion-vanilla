#ifndef GUARD_FLAGS_H
#define GUARD_FLAGS_H

#define FLAG_PENDING_DAYCARE_EGG    0x86


#define FLAG_TRAINER_FLAG_START  0x500

#define TRAINERS_FLAG_NO    0x356
#define CODE_FLAGS          (FLAG_TRAINER_FLAG_START + TRAINERS_FLAG_NO + 0xA) // 0x860

// SYSTEM FLAGS

#define FLAG_SYS_POKEMON_GET     CODE_FLAGS + 0
#define FLAG_SYS_POKEDEX_GET     CODE_FLAGS + 1
#define FLAG_SYS_POKENAV_GET     CODE_FLAGS + 2
// third one appears unused
#define FLAG_SYS_GAME_CLEAR      CODE_FLAGS + 4
#define FLAG_SYS_CHAT_USED       CODE_FLAGS + 5
#define FLAG_SYS_HIPSTER_MEET    CODE_FLAGS + 6

// badges
#define FLAG_BADGE01_GET         CODE_FLAGS + 7
#define FLAG_BADGE02_GET         CODE_FLAGS + 8
#define FLAG_BADGE03_GET         CODE_FLAGS + 9
#define FLAG_BADGE04_GET         CODE_FLAGS + 0xA
#define FLAG_BADGE05_GET         CODE_FLAGS + 0xB
#define FLAG_BADGE06_GET         CODE_FLAGS + 0xC
#define FLAG_BADGE07_GET         CODE_FLAGS + 0xD
#define FLAG_BADGE08_GET         CODE_FLAGS + 0xE

// cities and towns
#define FLAG_VISITED_LITTLEROOT_TOWN  CODE_FLAGS + 0xF
#define FLAG_VISITED_OLDALE_TOWN      CODE_FLAGS + 0x10
#define FLAG_VISITED_DEWFORD_TOWN     CODE_FLAGS + 0x11
#define FLAG_VISITED_LAVARIDGE_TOWN   CODE_FLAGS + 0x12
#define FLAG_VISITED_FALLARBOR_TOWN   CODE_FLAGS + 0x13
#define FLAG_VISITED_VERDANTURF_TOWN  CODE_FLAGS + 0x14
#define FLAG_VISITED_PACIFIDLOG_TOWN  CODE_FLAGS + 0x15
#define FLAG_VISITED_PETALBURG_CITY   CODE_FLAGS + 0x16
#define FLAG_VISITED_SLATEPORT_CITY   CODE_FLAGS + 0x17
#define FLAG_VISITED_MAUVILLE_CITY    CODE_FLAGS + 0x18
#define FLAG_VISITED_RUSTBORO_CITY    CODE_FLAGS + 0x19
#define FLAG_VISITED_FORTREE_CITY     CODE_FLAGS + 0x1A
#define FLAG_VISITED_LILYCOVE_CITY    CODE_FLAGS + 0x1B
#define FLAG_VISITED_MOSSDEEP_CITY    CODE_FLAGS + 0x1C
#define FLAG_VISITED_SOOTOPOLIS_CITY  CODE_FLAGS + 0x1D
#define FLAG_VISITED_EVER_GRANDE_CITY CODE_FLAGS + 0x1E

#define FLAG_SYS_UNKNOWN_880      CODE_FLAGS + 0x20

#define FLAG_SYS_USE_FLASH        CODE_FLAGS + 0x28
#define FLAG_SYS_USE_STRENGTH     CODE_FLAGS + 0x29
#define FLAG_SYS_WEATHER_CTRL     CODE_FLAGS + 0x2A
#define FLAG_SYS_CYCLING_ROAD     CODE_FLAGS + 0x2B
#define FLAG_SYS_SAFARI_MODE      CODE_FLAGS + 0x2C
#define FLAG_SYS_CRUISE_MODE      CODE_FLAGS + 0x2D

#define FLAG_SYS_TV_HOME          CODE_FLAGS + 0x30
#define FLAG_SYS_TV_WATCH         CODE_FLAGS + 0x31
#define FLAG_SYS_TV_START         CODE_FLAGS + 0x32
#define FLAG_SYS_POPWORD_INPUT    CODE_FLAGS + 0x33
#define FLAG_SYS_MIX_RECORD       CODE_FLAGS + 0x34
#define FLAG_SYS_CLOCK_SET        CODE_FLAGS + 0x35
#define FLAG_SYS_NATIONAL_DEX     CODE_FLAGS + 0x36
#define FLAG_SYS_CAVE_SHIP        CODE_FLAGS + 0x37
#define FLAG_SYS_CAVE_WONDER      CODE_FLAGS + 0x38
#define FLAG_SYS_CAVE_BATTLE      CODE_FLAGS + 0x39
#define FLAG_SYS_SHOAL_TIDE       CODE_FLAGS + 0x3A
#define FLAG_SYS_RIBBON_GET       CODE_FLAGS + 0x3B

#define FLAG_SYS_PC_LANETTE              CODE_FLAGS + 0x4B
#define FLAG_SYS_MYSTERY_EVENT_ENABLE    CODE_FLAGS + 0x4C
#define FLAG_SYS_ENC_UP_ITEM             CODE_FLAGS + 0x4D // white flute
#define FLAG_SYS_ENC_DOWN_ITEM           CODE_FLAGS + 0x4E // black flute
#define FLAG_SYS_BRAILLE_DIG             CODE_FLAGS + 0x4F
#define FLAG_SYS_BRAILLE_STRENGTH        CODE_FLAGS + 0x50
#define FLAG_SYS_BRAILLE_WAIT            CODE_FLAGS + 0x51
#define FLAG_SYS_BRAILLE_FLY             CODE_FLAGS + 0x52
#define FLAG_SYS_HAS_EON_TICKET          CODE_FLAGS + 0x53

#define FLAG_SYS_POKEMON_LEAGUE_FLY CODE_FLAGS + 0x54

#define FLAG_SYS_TV_LATI          CODE_FLAGS + 0x5D

#define FLAG_SYS_SHOAL_ITEM       CODE_FLAGS + 0x5F
#define FLAG_SYS_B_DASH           CODE_FLAGS + 0x60 // got Running Shoes
#define FLAG_SYS_CTRL_OBJ_DELETE  CODE_FLAGS + 0x61
#define FLAG_SYS_RESET_RTC_ENABLE CODE_FLAGS + 0x62

#define FLAG_SYS_TOWER_SILVER    CODE_FLAGS + 0x64
#define FLAG_SYS_TOWER_GOLD      CODE_FLAGS + 0x65
#define FLAG_SYS_DOME_SILVER     CODE_FLAGS + 0x66
#define FLAG_SYS_DOME_GOLD       CODE_FLAGS + 0x67
#define FLAG_SYS_PALACE_SILVER   CODE_FLAGS + 0x68
#define FLAG_SYS_PALACE_GOLD     CODE_FLAGS + 0x69
#define FLAG_SYS_ARENA_SILVER    CODE_FLAGS + 0x6A
#define FLAG_SYS_ARENA_GOLD      CODE_FLAGS + 0x6B
#define FLAG_SYS_FACTORY_SILVER  CODE_FLAGS + 0x6C
#define FLAG_SYS_FACTORY_GOLD    CODE_FLAGS + 0x6D
#define FLAG_SYS_PIKE_SILVER     CODE_FLAGS + 0x6E
#define FLAG_SYS_PIKE_GOLD       CODE_FLAGS + 0x6F
#define FLAG_SYS_PYRAMID_SILVER  CODE_FLAGS + 0x70
#define FLAG_SYS_PYRAMID_GOLD    CODE_FLAGS + 0x71
#define FLAG_SYS_FRONTIER_PASS   CODE_FLAGS + 0x72

#define FLAG_SYS_STORAGE_UNKNOWN_FLAG    CODE_FLAGS + 0x77

#define FLAG_SYS_MYSTERY_GIFT_ENABLE     CODE_FLAGS + 0x7B

// SPECIAL FLAGS (unknown purpose)

#define SPECIAL_FLAG_1 0x4001

#endif // GUARD_FLAGS_H
