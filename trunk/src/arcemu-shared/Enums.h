
namespace SpellEnums
{
	enum School
	{
		SCHOOL_NORMAL = 0,
		SCHOOL_HOLY   = 1,
		SCHOOL_FIRE   = 2,
		SCHOOL_NATURE = 3,
		SCHOOL_FROST  = 4,
		SCHOOL_SHADOW = 5,
		SCHOOL_ARCANE = 6,
		SCHOOL_COUNT   
	};

	enum SpellDidHitResult
	{
		SPELL_DID_HIT_SUCCESS					= 0,
		SPELL_DID_HIT_MISS						= 1,
		SPELL_DID_HIT_RESIST					= 2,
		SPELL_DID_HIT_DODGE						= 3,
		SPELL_DID_HIT_DEFLECT					= 4,
		SPELL_DID_HIT_BLOCK						= 5,
		SPELL_DID_HIT_EVADE						= 6,
		SPELL_DID_HIT_IMMUNE					= 7,
	};

	enum SpellState
	{
		SPELL_STATE_NULL		= 0,
		SPELL_STATE_PREPARING	= 1,
		SPELL_STATE_CHANNELING	= 2,
		SPELL_STATE_FINISHED	= 3,
		SPELL_STATE_IDLE		= 4,
		SPELL_STATE_DELAYED		= 5
	};

	enum SpellCastError
	{
		SPELL_FAILED_AFFECTING_COMBAT                                = 0,
		SPELL_FAILED_ALREADY_AT_FULL_HEALTH                          = 1,
		SPELL_FAILED_ALREADY_AT_FULL_MANA                            = 2,
		SPELL_FAILED_ALREADY_AT_FULL_POWER                           = 3,
		SPELL_FAILED_ALREADY_BEING_TAMED                             = 4,
		SPELL_FAILED_ALREADY_HAVE_CHARM                              = 5,
		SPELL_FAILED_ALREADY_HAVE_SUMMON                             = 6,
		SPELL_FAILED_ALREADY_OPEN                                    = 7,
		SPELL_FAILED_AURA_BOUNCED                                    = 8,
		SPELL_FAILED_AUTOTRACK_INTERRUPTED                           = 9,
		SPELL_FAILED_BAD_IMPLICIT_TARGETS                            = 10,
		SPELL_FAILED_BAD_TARGETS                                     = 11,
		SPELL_FAILED_CANT_BE_CHARMED                                 = 12,
		SPELL_FAILED_CANT_BE_DISENCHANTED                            = 13,
		SPELL_FAILED_CANT_BE_DISENCHANTED_SKILL                      = 14,
		SPELL_FAILED_CANT_BE_PROSPECTED                              = 15,
		SPELL_FAILED_CANT_CAST_ON_TAPPED                             = 16,
		SPELL_FAILED_CANT_DUEL_WHILE_INVISIBLE                       = 17,
		SPELL_FAILED_CANT_DUEL_WHILE_STEALTHED                       = 18,
		SPELL_FAILED_CANT_STEALTH                                    = 19,
		SPELL_FAILED_CASTER_AURASTATE                                = 20,
		SPELL_FAILED_CASTER_DEAD                                     = 21,
		SPELL_FAILED_CHARMED                                         = 22,
		SPELL_FAILED_CHEST_IN_USE                                    = 23,
		SPELL_FAILED_CONFUSED                                        = 24,
		SPELL_FAILED_DONT_REPORT                                     = 25,
		SPELL_FAILED_EQUIPPED_ITEM                                   = 26,
		SPELL_FAILED_EQUIPPED_ITEM_CLASS                             = 27,
		SPELL_FAILED_EQUIPPED_ITEM_CLASS_MAINHAND                    = 28,
		SPELL_FAILED_EQUIPPED_ITEM_CLASS_OFFHAND                     = 29,
		SPELL_FAILED_ERROR                                           = 30,
		SPELL_FAILED_FIZZLE                                          = 31,
		SPELL_FAILED_FLEEING                                         = 32,
		SPELL_FAILED_FOOD_LOWLEVEL                                   = 33,
		SPELL_FAILED_HIGHLEVEL                                       = 34,
		SPELL_FAILED_HUNGER_SATIATED                                 = 35,
		SPELL_FAILED_IMMUNE                                          = 36,
		SPELL_FAILED_INTERRUPTED                                     = 37,
		SPELL_FAILED_INTERRUPTED_COMBAT                              = 38,
		SPELL_FAILED_ITEM_ALREADY_ENCHANTED                          = 39,
		SPELL_FAILED_ITEM_GONE                                       = 40,
		SPELL_FAILED_ITEM_NOT_FOUND                                  = 41,
		SPELL_FAILED_ITEM_NOT_READY                                  = 42,
		SPELL_FAILED_LEVEL_REQUIREMENT                               = 43,
		SPELL_FAILED_LINE_OF_SIGHT                                   = 44,
		SPELL_FAILED_LOWLEVEL                                        = 45,
		SPELL_FAILED_LOW_CASTLEVEL                                   = 46,
		SPELL_FAILED_MAINHAND_EMPTY                                  = 47,
		SPELL_FAILED_MOVING                                          = 48,
		SPELL_FAILED_NEED_AMMO                                       = 49,
		SPELL_FAILED_NEED_AMMO_POUCH                                 = 50,
		SPELL_FAILED_NEED_EXOTIC_AMMO                                = 51,
		SPELL_FAILED_NOPATH                                          = 52,
		SPELL_FAILED_NOT_BEHIND                                      = 53,
		SPELL_FAILED_NOT_FISHABLE                                    = 54,
		SPELL_FAILED_NOT_FLYING                                      = 55,
		SPELL_FAILED_NOT_HERE                                        = 56,
		SPELL_FAILED_NOT_INFRONT                                     = 57,
		SPELL_FAILED_NOT_IN_CONTROL                                  = 58,
		SPELL_FAILED_NOT_KNOWN                                       = 59,
		SPELL_FAILED_NOT_MOUNTED                                     = 60,
		SPELL_FAILED_NOT_ON_TAXI                                     = 61,
		SPELL_FAILED_NOT_ON_TRANSPORT                                = 62,
		SPELL_FAILED_NOT_READY                                       = 63,
		SPELL_FAILED_NOT_SHAPESHIFT                                  = 64,
		SPELL_FAILED_NOT_STANDING                                    = 65,
		SPELL_FAILED_NOT_TRADEABLE                                   = 66,
		SPELL_FAILED_NOT_TRADING                                     = 67,
		SPELL_FAILED_NOT_UNSHEATHED                                  = 68,
		SPELL_FAILED_NOT_WHILE_GHOST                                 = 69,
		SPELL_FAILED_NO_AMMO                                         = 70,
		SPELL_FAILED_NO_CHARGES_REMAIN                               = 71,
		SPELL_FAILED_NO_CHAMPION                                     = 72,
		SPELL_FAILED_NO_COMBO_POINTS                                 = 73,
		SPELL_FAILED_NO_DUELING                                      = 74,
		SPELL_FAILED_NO_ENDURANCE                                    = 75,
		SPELL_FAILED_NO_FISH                                         = 76,
		SPELL_FAILED_NO_ITEMS_WHILE_SHAPESHIFTED                     = 77,
		SPELL_FAILED_NO_MOUNTS_ALLOWED                               = 78,
		SPELL_FAILED_NO_PET                                          = 79,
		SPELL_FAILED_NO_POWER                                        = 80,
		SPELL_FAILED_NOTHING_TO_DISPEL                               = 81,
		SPELL_FAILED_NOTHING_TO_STEAL                                = 82,
		SPELL_FAILED_ONLY_ABOVEWATER                                 = 83,
		SPELL_FAILED_ONLY_DAYTIME                                    = 84,
		SPELL_FAILED_ONLY_INDOORS                                    = 85,
		SPELL_FAILED_ONLY_MOUNTED                                    = 86,
		SPELL_FAILED_ONLY_NIGHTTIME                                  = 87,
		SPELL_FAILED_ONLY_OUTDOORS                                   = 88,
		SPELL_FAILED_ONLY_SHAPESHIFT                                 = 89,
		SPELL_FAILED_ONLY_STEALTHED                                  = 90,
		SPELL_FAILED_ONLY_UNDERWATER                                 = 91,
		SPELL_FAILED_OUT_OF_RANGE                                    = 92,
		SPELL_FAILED_PACIFIED                                        = 93,
		SPELL_FAILED_POSSESSED                                       = 94,
		SPELL_FAILED_REAGENTS                                        = 95,
		SPELL_FAILED_REQUIRES_AREA                                   = 96,
		SPELL_FAILED_REQUIRES_SPELL_FOCUS                            = 97,
		SPELL_FAILED_ROOTED                                          = 98,
		SPELL_FAILED_SILENCED                                        = 99,
		SPELL_FAILED_SPELL_IN_PROGRESS                               = 100,
		SPELL_FAILED_SPELL_LEARNED                                   = 101,
		SPELL_FAILED_SPELL_UNAVAILABLE                               = 102,
		SPELL_FAILED_STUNNED                                         = 103,
		SPELL_FAILED_TARGETS_DEAD                                    = 104,
		SPELL_FAILED_TARGET_AFFECTING_COMBAT                         = 105,
		SPELL_FAILED_TARGET_AURASTATE                                = 106,
		SPELL_FAILED_TARGET_DUELING                                  = 107,
		SPELL_FAILED_TARGET_ENEMY                                    = 108,
		SPELL_FAILED_TARGET_ENRAGED                                  = 109,
		SPELL_FAILED_TARGET_FRIENDLY                                 = 110,
		SPELL_FAILED_TARGET_IN_COMBAT                                = 111,
		SPELL_FAILED_TARGET_IS_PLAYER                                = 112,
		SPELL_FAILED_TARGET_IS_PLAYER_CONTROLLED                     = 113,
		SPELL_FAILED_TARGET_NOT_DEAD                                 = 114,
		SPELL_FAILED_TARGET_NOT_IN_PARTY                             = 115,
		SPELL_FAILED_TARGET_NOT_LOOTED                               = 116,
		SPELL_FAILED_TARGET_NOT_PLAYER                               = 117,
		SPELL_FAILED_TARGET_NO_POCKETS                               = 118,
		SPELL_FAILED_TARGET_NO_WEAPONS                               = 119,
		SPELL_FAILED_TARGET_UNSKINNABLE                              = 120,
		SPELL_FAILED_THIRST_SATIATED                                 = 121,
		SPELL_FAILED_TOO_CLOSE                                       = 122,
		SPELL_FAILED_TOO_MANY_OF_ITEM                                = 123,
		SPELL_FAILED_TOTEM_CATEGORY                                  = 124,
		SPELL_FAILED_TOTEMS                                          = 125,
		SPELL_FAILED_TRAINING_POINTS                                 = 126,
		SPELL_FAILED_TRY_AGAIN                                       = 127,
		SPELL_FAILED_UNIT_NOT_BEHIND                                 = 128,
		SPELL_FAILED_UNIT_NOT_INFRONT                                = 129,
		SPELL_FAILED_WRONG_PET_FOOD                                  = 130,
		SPELL_FAILED_NOT_WHILE_FATIGUED                              = 131,
		SPELL_FAILED_TARGET_NOT_IN_INSTANCE                          = 132,
		SPELL_FAILED_NOT_WHILE_TRADING                               = 133,
		SPELL_FAILED_TARGET_NOT_IN_RAID                              = 134,
		SPELL_FAILED_DISENCHANT_WHILE_LOOTING                        = 135,
		SPELL_FAILED_PROSPECT_WHILE_LOOTING                          = 136,
		SPELL_FAILED_PROSPECT_NEED_MORE                              = 137,
		SPELL_FAILED_TARGET_FREEFORALL                               = 138,
		SPELL_FAILED_NO_EDIBLE_CORPSES                               = 139,
		SPELL_FAILED_ONLY_BATTLEGROUNDS                              = 140,
		SPELL_FAILED_TARGET_NOT_GHOST                                = 141,
		SPELL_FAILED_TOO_MANY_SKILLS                                 = 142,
		SPELL_FAILED_TRANSFORM_UNUSABLE                              = 143,
		SPELL_FAILED_WRONG_WEATHER                                   = 144,
		SPELL_FAILED_DAMAGE_IMMUNE                                   = 145,
		SPELL_FAILED_PREVENTED_BY_MECHANIC                           = 146,
		SPELL_FAILED_PLAY_TIME                                       = 147,
		SPELL_FAILED_REPUTATION                                      = 148,
		SPELL_FAILED_MIN_SKILL                                       = 149,
		SPELL_FAILED_NOT_IN_ARENA                                    = 150,
		SPELL_FAILED_NOT_ON_SHAPESHIFT                               = 151,
		SPELL_FAILED_NOT_ON_STEALTHED                                = 152,
		SPELL_FAILED_NOT_ON_DAMAGE_IMMUNE                            = 153,
		SPELL_FAILED_NOT_ON_MOUNTED                                  = 154,
		SPELL_FAILED_TOO_SHALLOW                                     = 155,
		SPELL_FAILED_TARGET_NOT_IN_SANCTUARY                         = 156,
		SPELL_FAILED_TARGET_IS_TRIVIAL                               = 157,
		SPELL_FAILED_BM_OR_INVISGOD                                  = 158,
		SPELL_FAILED_EXPERT_RIDING_REQUIREMENT                       = 159,
		SPELL_FAILED_ARTISAN_RIDING_REQUIREMENT                      = 160,
		SPELL_FAILED_NOT_IDLE                                        = 161,
		SPELL_FAILED_NOT_INACTIVE                                    = 162,
		SPELL_FAILED_PARTIAL_PLAYTIME                                = 163,
		SPELL_FAILED_NO_PLAYTIME                                     = 164,
		SPELL_FAILED_NOT_IN_BATTLEGROUND                             = 165,
		SPELL_FAILED_NOT_IN_RAID_INSTANCE							 = 166,
		SPELL_FAILED_ONLY_IN_ARENA									 = 167,
		SPELL_FAILED_TARGET_LOCKED_TO_RAID_INSTANCE                  = 168,
		SPELL_FAILED_UNKNOWN                                         = 169,
		SPELL_CANCAST_OK                                             = 255,
	};

	enum Attributes
	{
		ATTRIBUTES_CANNOT_BE_CAST_WHILE_SILENCED	= 0x00000001,	// 0
		ATTRIBUTES_RANGED							= 0x00000002,	// 1 All ranged abilites have this flag (pushback spells too)
		ATTRIBUTES_ON_NEXT_ATTACK_1					= 0x00000004,	// 2 on next swing
		ATTRIBUTES_UNK3								= 0x00000008,	// 3 not set in 2.4.2
		ATTRIBUTES_UNK4								= 0x00000010,	// 4
		ATTRIBUTES_UNK5								= 0x00000020,	// 5 Tradeskill recipies
		ATTRIBUTES_PASSIVE							= 0x00000040,	// 6 Passive spell
		ATTRIBUTES_NO_VISUAL_AURA					= 0x00000080,	// 7 visible?
		ATTRIBUTES_NO_CAST							= 0x00000100,	// 8 seems to be afflicts pet
		ATTRIBUTES_UNK9								= 0x00000200,	// 9 looks like temp enchants.
		ATTRIBUTES_ON_NEXT_ATTACK_2					= 0x00000400,	// 10 completely the same as ATTRIBUTE_ON_NEXT_ATTACK for class spells. So difference somewhere in mob abilities.
		ATTRIBUTES_UNK11							= 0x00000800,	// 11
		ATTRIBUTES_DAYTIME_ONLY						= 0x00001000,	// 12 only useable at daytime, not set in 2.4.2
		ATTRIBUTES_NIGHT_ONLY						= 0x00002000,	// 13 only useable at night, not set in 2.4.2
		ATTRIBUTES_INDOORS_ONLY						= 0x00004000,	// 14 only useable indoors, not set in 2.4.2
		ATTRIBUTES_ONLY_OUTDOORS					= 0x00008000,	// 15 Only useable outdoors.
		ATTRIBUTES_NOT_SHAPESHIFT					= 0x00010000,	// 16 Not while shapeshifted
		ATTRIBUTES_REQ_STEALTH						= 0x00020000,	// 17 Must be in stealth
		ATTRIBUTES_UNK18							= 0x00040000,	// 18 it's not : must be behind
		ATTRIBUTES_LEVEL_DAMAGE_CALCULATION			= 0x00080000,	// 19 spelldamage depends on caster level
		ATTRIBUTES_STOP_ATTACK						= 0x00100000,	// 20 switch off auto attack on use. Maim,Gouge,Disengage,Polymorph etc
		ATTRIBUTES_CANT_BE_DPB				    	= 0x00200000,	// 21 can't be dodged, blocked, parried
		ATTRIBUTES_UNK22							= 0x00400000,	// 22 related to ranged
		ATTRIBUTES_DEAD_CASTABLE					= 0x00800000,	// 23 castable while dead?
		ATTRIBUTES_MOUNT_CASTABLE					= 0x01000000,	// 24 castable while mounted
		ATTRIBUTES_TRIGGER_COOLDOWN			        = 0x02000000,	// 25 also requires atributes ex = 32 ?
		ATTRIBUTES_NEGATIVE							= 0x04000000,	// 26 negative spells || ATTRIBUTESEX_NEGATIVE
		ATTRIBUTES_CASTABLE_WHILE_SITTING			= 0x08000000,	// 27 castable while sitting
		ATTRIBUTES_REQ_OOC							= 0x10000000,	// 28 Cannot be used in combat
		ATTRIBUTES_IGNORE_INVULNERABILITY           = 0x20000000,	// 29 debuffs that can't be removed by any spell and spells that can't be resisted in any case
		ATTRIBUTES_UNK30							= 0x40000000,	// 30 seems like IS_DIMINISHING but some spells not there (f.e. Gouge)
		ATTRIBUTES_CANT_CANCEL						= 0x80000000,	// 31 seems like aura is not removeable by CMSG_CANCEL_AURA
	};

	enum AttributesEx
	{
		ATTRIBUTESEX_UNK0                         = 0x00000001,		// 0 pet summonings
		ATTRIBUTESEX_DRAIN_WHOLE_POWER            = 0x00000002,		// 1 use all power (Only paladin Lay of Hands and Bunyanize)
		ATTRIBUTESEX_CHANNELED_1                  = 0x00000004,		// 2 channeled 1 - object targetting spells
		ATTRIBUTESEX_UNK3                         = 0x00000008,		// 3
		ATTRIBUTESEX_UNK4                         = 0x00000010,		// 4 stealth effects but Rockbiter wtf 0_0
		ATTRIBUTESEX_NOT_BREAK_STEALTH            = 0x00000020,		// 5 Not break stealth
		ATTRIBUTESEX_CHANNELED_2				  = 0x00000040,		// 6 channeled 2 - non object targetting spells
		ATTRIBUTESEX_NEGATIVE                     = 0x00000080,		// 7 negative spells || ATTRIBUTES_NEGATIVE
		ATTRIBUTESEX_NOT_IN_COMBAT_TARGET         = 0x00000100,		// 8 Spell req target not to be in combat state
		ATTRIBUTESEX_UNK9						  = 0x00000200,		// 9
		ATTRIBUTESEX_PASSIVE_VISUAL_AURA          = 0x00000400,		// 10 Pasivni aura ktera ma visual
		ATTRIBUTESEX_UNK11                        = 0x00000800,		// 11
		ATTRIBUTESEX_UNK12                        = 0x00001000,		// 12 related to pickpocket
		ATTRIBUTESEX_UNK13                        = 0x00002000,		// 13 related to remote control
		ATTRIBUTESEX_UNK14                        = 0x00004000,		// 14
		ATTRIBUTESEX_DISPEL_AURAS_ON_IMMUNITY     = 0x00008000,		// 15 remove auras on immunity
		ATTRIBUTESEX_UNAFFECTED_BY_SCHOOL_IMMUNE  = 0x00010000,		// 16 unaffected by school immunity
		ATTRIBUTESEX_REMAIN_OOC                   = 0x00020000,		// 17
		ATTRIBUTESEX_UNK18                        = 0x00040000,		// 18
		ATTRIBUTESEX_UNK19                        = 0x00080000,		// 19
		ATTRIBUTESEX_REQ_COMBO_POINTS1            = 0x00100000,		// 20 Req combo points on target - related to "Finishing move" and "Instantly overpowers"
		ATTRIBUTESEX_UNK21                        = 0x00200000,		// 21
		ATTRIBUTESEX_REQ_COMBO_POINTS2            = 0x00400000,		// 22 Req combo points on target
		ATTRIBUTESEX_UNK23                        = 0x00800000,		// 23 related to spells like "ClearAllBuffs"
		ATTRIBUTESEX_UNK24                        = 0x01000000,		// 24 Req fishing pole?? - FISHING SPELLS
		ATTRIBUTESEX_UNK25                        = 0x02000000,		// 25 related to "Detect" spell
		ATTRIBUTESEX_UNK26                        = 0x04000000,		// 26
		ATTRIBUTESEX_UNK27                        = 0x08000000,		// 27
		ATTRIBUTESEX_UNK28                        = 0x10000000,		// 28
		ATTRIBUTESEX_UNK29                        = 0x20000000,		// 29
		ATTRIBUTESEX_UNK30                        = 0x40000000,		// 30 Overpower
		ATTRIBUTESEX_UNK31                        = 0x80000000,		// 31
	};

	enum Flags3
	{
		FLAGS3_UNK0								= 0x00000001,		// 0
		FLAGS3_UNK1								= 0x00000002,		// 1 Can be used while stealthed
		FLAGS3_UNK2								= 0x00000004,		// 2 request pet maybe
		FLAGS3_UNK3								= 0x00000008,		// 3 something todo with temp enchanted items
		FLAGS3_PARTY_EFFECTING_AURA				= 0x00000010,		// 4 Party affecting aura's
		FLAGS3_ACTIVATE_AUTO_SHOT				= 0x00000020,		// 5 spell that enable's auto shoot
		FLAGS3_UNK6								= 0x00000040,		// 6 Polymorph spells
		FLAGS3_UNK7								= 0x00000080,		// 7
		FLAGS3_UNUSED1							= 0x00000100,		// 8
		FLAGS3_UNK9								= 0x00000200,		// 9 used by 2 spells, 30421 | Nether Portal - Perseverence and  30466 | Nether Portal - Perseverence
		FLAGS3_TAME_X							= 0x00000400,		// 10 tame [creature]
		FLAGS3_FUNNEL							= 0x00000800,		// 11 only funnel spells
		FLAGS3_UNK12							= 0x00001000,		// 12 swipe / Cleave spells
		FLAGS3_ENCHANT_OWN_ONLY					= 0x00002000,		// 13 no trade window targets, BoE items get soulbound to you
		FLAGS3_SPELL_PLAYER_EVENT				= 0x00004000,		// 14 Player event's like logging in, finishing quests, triggering cinematic, being adored, Heartbroken etc
		FLAGS3_UNUSED3							= 0x00008000,		// 15
		FLAGS3_CONTROL_UNIT						= 0x00010000,		// 16 PvP Controller, RC, Creature taming, Taming Lesson
		FLAGS3_REQ_RANGED_WEAPON				= 0x00020000,		// 17 this is shit and has nothing to do with auto shot
		FLAGS3_REVIVE_PET						= 0x00040000,		// 18 actually 1 spell, revive pet
		FLAGS3_NOT_NEED_SHAPESHIFT				= 0x00080000,		// 19 does not necessarly need shapeshift - this is a group of spells that are triggered by something. (I have no clue on how to name this one)
		FLAGS3_REQ_BEHIND_TARGET				= 0x00100000,		// 20 wrong
		FLAGS3_UNK21							= 0x00200000,		// 21
		FLAGS3_UNK22							= 0x00400000,		// 22
		FLAGS3_UNK23							= 0x00800000,		// 23 Only mage Arcane Concentration have this flag
		FLAGS3_UNK24							= 0x01000000,		// 24
		FLAGS3_UNK25							= 0x02000000,		// 25
		FLAGS3_UNK26							= 0x04000000,		// 26 unaffected by school immunity
		FLAGS3_UNK27							= 0x08000000,		// 27 fishing spells and enchanting weapons
		FLAGS3_UNK28							= 0x10000000,		// 28 some secondairy spell triggers, especialy for lightning shield alike spells
		FLAGS3_CANT_CRIT						= 0x20000000,		// 29 Spell can't crit
		FLAGS3_UNK30							= 0x40000000,		// 30
		FLAGS3_UNK31							= 0x80000000,		// 31
	};

	enum Flags4
	{
		FLAGS4_UNK2									= 0x00000001,		// 0
		FLAGS4_UNK3									= 0x00000002,		// 1
		FLAGS4_UNK4									= 0x00000004,		// 2
		FLAGS4_UNK5									= 0x00000008,		// 3
		FLAGS4_UNK6									= 0x00000010,		// 4 Druid Rebirth only this spell have this flag
		FLAGS4_UNK7									= 0x00000020,		// 5
		FLAGS4_UNK8									= 0x00000040,		// 6
		FLAGS4_UNK9									= 0x00000080,		// 7
		FLAGS4_UNK10								= 0x00000100,		// 8
		FLAGS4_UNK11								= 0x00000200,		// 9
		FLAGS4_MAIN_HAND							= 0x00000400,		// 10 Main hand weapon required
		FLAGS4_BG_ONLY								= 0x00000800,		// 11 Can casted only on battleground
		FLAGS4_UNK14								= 0x00001000,		// 12
		FLAGS4_UNK15								= 0x00002000,		// 13
		FLAGS4_UNK16								= 0x00004000,		// 14 "Honorless Target" only this spells have this flag
		FLAGS4_PLAYER_RANGED_SPELLS					= 0x00008000,		// 15 Auto Shoot, Shoot, Throw,  - this is autoshot flag
		FLAGS4_UNK18								= 0x00010000,		// 16
		FLAGS4_NO_INITIAL_AGGRO						= 0x00020000,		// 17 no initial aggro
		FLAGS4_UNK20								= 0x00040000,		// 18
		FLAGS4_UNK21								= 0x00080000,		// 19
		FLAGS4_CAN_PERSIST_AND_CASTED_WHILE_DEAD	= 0x00100000,		// 20 Death persistent spells
		FLAGS4_UNK23								= 0x00200000,		// 21
		FLAGS4_PLAYER_RANGED_WAND					= 0x00400000,		// 22 Req wand
		FLAGS4_UNK25								= 0x00800000,		// 23
		FLAGS4_REQ_OFFHAND							= 0x01000000,		// 24 Req offhand weapon
		FLAGS4_UNK27								= 0x02000000,		// 25
		FLAGS4_UNK28								= 0x04000000,		// 26
		FLAGS4_UNK29								= 0x08000000,		// 27
		FLAGS4_UNK30								= 0x10000000,		// 28
		FLAGS4_UNK31								= 0x20000000,		// 29
		FLAGS4_UNK32								= 0x40000000,		// 30
		FLAGS4_UNK33								= 0x80000000,		// 31
	};

	enum Flags5
	{
		FLAGS5_UNK0							= 0x00000001,		// 0
		FLAGS5_PROCCHANCE_COMBOBASED        = 0x00000002,		// 1
		FLAGS5_UNK2							= 0x00000004,		// 2
		FLAGS5_UNK3							= 0x00000008,		// 3
		FLAGS5_UNK4							= 0x00000010,		// 4
		FLAGS5_CANNOT_BY_STOLEN_BY_MAGES	= 0x00000020,		// 5
		FLAGS5_UNK6							= 0x00000040,		// 6
		FLAGS5_UNK7							= 0x00000080,		// 7
		FLAGS5_UNK8							= 0x00000100,		// 8
		FLAGS5_UNK9							= 0x00000200,		// 9
		FLAGS5_SPELL_VS_EXTEND_COST			= 0x00000400,		// 10 Rogue Shiv have this flag
		FLAGS5_UNK11						= 0x00000800,		// 11
		FLAGS5_UNK12						= 0x00001000,		// 12
		FLAGS5_UNK13						= 0x00002000,		// 13
		FLAGS5_UNK14						= 0x00004000,		// 14
		FLAGS5_UNK15						= 0x00008000,		// 15
		FLAGS5_NOT_USABLE_IN_ARENA			= 0x00010000,		// 16 not usable in arena
		FLAGS5_USABLE_IN_ARENA				= 0x00020000,		// 17 usable in arena
		FLAGS5_UNK18						= 0x00040000,		// 18
		FLAGS5_UNK19						= 0x00080000,		// 19
		FLAGS5_UNK20						= 0x00100000,		// 20
		FLAGS5_UNK21						= 0x00200000,		// 21
		FLAGS5_UNK22						= 0x00400000,		// 22
		FLAGS5_UNK23						= 0x00800000,		// 23
		FLAGS5_UNK24						= 0x01000000,		// 24
		FLAGS5_PET_SCALING_AURA				= 0x02000000,		// 25 pet scaling auras
		FLAGS5_ONLY_IN_OUTLANDS             = 0x04000000,		// 26 Can only be used in Outland.
		FLAGS5_UNK27						= 0x08000000,		// 27
		FLAGS5_UNK28						= 0x10000000,		// 28
		FLAGS5_UNK29						= 0x20000000,		// 29
		FLAGS5_UNK30						= 0x40000000,		// 30
		FLAGS5_UNK31						= 0x80000000,		// 21
	};

	enum Flags6 
	{
		FLAGS6_UNK0							= 0x00000001,		// 0
		FLAGS6_NO_REAGENT_WHILE_PREP		= 0x00000002,		// 1 not need reagents if UNIT_FLAG_PREPARATION
		FLAGS6_UNK2							= 0x00000004,		// 2
		FLAGS6_USABLE_WHILE_STUNNED			= 0x00000008,		// 3 usable while stunned
		FLAGS6_UNK4							= 0x00000010,		// 4
		FLAGS6_SINGLE_TARGET_SPELL			= 0x00000020,		// 5 Only one target can be apply at a time
		FLAGS6_UNK6							= 0x00000040,		// 6
		FLAGS6_UNK7							= 0x00000080,		// 7
		FLAGS6_UNK8							= 0x00000100,		// 8
		FLAGS6_UNK9							= 0x00000200,		// 9
		FLAGS6_UNK10						= 0x00000400,		// 10
		FLAGS6_UNK11						= 0x00000800,		// 11
		FLAGS6_UNK12						= 0x00001000,		// 12
		FLAGS6_UNK13						= 0x00002000,		// 13
		FLAGS6_UNK14						= 0x00004000,		// 14
		FLAGS6_UNK15						= 0x00008000,		// 15
		FLAGS6_UNK16						= 0x00010000,		// 16
		FLAGS6_USABLE_WHILE_FEARED 			= 0x00020000,		// 17 usable while feared
		FLAGS6_USABLE_WHILE_CONFUSED		= 0x00040000,		// 18 usable while confused
		FLAGS6_UNK19						= 0x00080000,		// 19
		FLAGS6_UNK20						= 0x00100000,		// 20
		FLAGS6_UNK21						= 0x00200000,		// 21
		FLAGS6_UNK22						= 0x00400000,		// 22
		FLAGS6_UNK23						= 0x00800000,		// 23
		FLAGS6_UNK24						= 0x01000000,		// 24
		FLAGS6_UNK25						= 0x02000000,		// 25
		FLAGS6_UNK26						= 0x04000000,		// 26
		FLAGS6_UNK27						= 0x08000000,		// 27
		FLAGS6_UNK28						= 0x10000000,		// 28
		FLAGS6_UNK29						= 0x20000000,		// 29
		FLAGS6_UNK30						= 0x40000000,		// 30
		FLAGS6_UNK31						= 0x80000000,		// 31 Forces all nearby enemies to focus attacks caster
	};

	enum Flags7
	{
		FLAGS7_UNK0							= 0x00000001,		// 0 Only Move spell have this flag
		FLAGS7_UNUSED1						= 0x00000002,		// 1 unused 2.4.3
		FLAGS7_UNK2							= 0x00000004,		// 2
		FLAGS7_UNK3							= 0x00000008,		// 3
		FLAGS7_UNUSED2						= 0x00000010,		// 4 unused 2.4.3
		FLAGS7_UNK5							= 0x00000020,		// 5
		FLAGS7_UNK6							= 0x00000040,		// 6
		FLAGS7_UNK7							= 0x00000080,		// 7
		FLAGS7_UNK8							= 0x00000100,		// 8
		FLAGS7_UNK9							= 0x00000200,		// 9 unused 2.4.3
		FLAGS7_UNK10						= 0x00000400,		// 10
		FLAGS7_UNK11						= 0x00000800,		// 11
		FLAGS7_UNK12						= 0x00001000,		// 12 unused 2.4.3
		FLAGS7_UNK13						= 0x00002000,		// 13
		FLAGS7_UNK14						= 0x00004000,		// 14 unused 2.4.3
		FLAGS7_UNK15						= 0x00008000,		// 15 unused 2.4.3
		FLAGS7_UNK16						= 0x00010000,		// 16 unused 2.4.3 - 20-33 also unused 2.4.3
		FLAGS7_UNK17						= 0x00020000,		// 17
		FLAGS7_UNK18						= 0x00020000,		// 18
		FLAGS7_UNK19						= 0x00020000,		// 19
		FLAGS7_UNK20						= 0x00020000,		// 20
		FLAGS7_UNK21						= 0x00020000,		// 21
		FLAGS7_UNK22						= 0x00020000,		// 22
		FLAGS7_UNK23						= 0x00020000,		// 23
		FLAGS7_UNK24						= 0x00020000,		// 24
		FLAGS7_UNK25						= 0x00020000,		// 25
		FLAGS7_UNK26						= 0x00020000,		// 26
		FLAGS7_UNK27						= 0x00020000,		// 27
		FLAGS7_UNK28						= 0x00020000,		// 28
		FLAGS7_UNK29						= 0x00020000,		// 29
		FLAGS7_UNK30						= 0x00020000,		// 30
		FLAGS7_UNK31						= 0x00020000,		// 31
	};

	enum SpellEffectTarget
	{
	   EFF_TARGET_NONE										= 0,
	   EFF_TARGET_SELF										= 1,
	   EFF_TARGET_INVISIBLE_OR_HIDDEN_ENEMIES_AT_LOCATION_RADIUS		= 3,
	   EFF_TARGET_PET										= 5,
	   EFF_TARGET_SINGLE_ENEMY								= 6,
	   EFF_TARGET_SCRIPTED_TARGET							= 7,
	   EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS  = 8,
	   EFF_TARGET_HEARTSTONE_LOCATION						= 9,
	   EFF_TARGET_ALL_ENEMY_IN_AREA							= 15,
	   EFF_TARGET_ALL_ENEMY_IN_AREA_INSTANT					= 16,
	   EFF_TARGET_TELEPORT_LOCATION							= 17,
	   EFF_TARGET_LOCATION_TO_SUMMON						= 18,
	   EFF_TARGET_ALL_PARTY_AROUND_CASTER					= 20,
	   EFF_TARGET_SINGLE_FRIEND								= 21,
	   EFF_TARGET_ALL_ENEMIES_AROUND_CASTER					= 22,
	   EFF_TARGET_GAMEOBJECT								= 23,
	   EFF_TARGET_IN_FRONT_OF_CASTER						= 24,
	   EFF_TARGET_DUEL										= 25,//Dont know the real name!!!
	   EFF_TARGET_GAMEOBJECT_ITEM							= 26,
	   EFF_TARGET_PET_MASTER								= 27,
	   EFF_TARGET_ALL_ENEMY_IN_AREA_CHANNELED				= 28,
	   EFF_TARGET_ALL_PARTY_IN_AREA_CHANNELED				= 29,
	   EFF_TARGET_ALL_FRIENDLY_IN_AREA						= 30,
	   EFF_TARGET_ALL_TARGETABLE_AROUND_LOCATION_IN_RADIUS_OVER_TIME	= 31,
	   EFF_TARGET_MINION									= 32,
	   EFF_TARGET_ALL_PARTY_IN_AREA							= 33,
	   EFF_TARGET_SINGLE_PARTY								= 35,
	   EFF_TARGET_PET_SUMMON_LOCATION						= 36,
	   EFF_TARGET_ALL_PARTY									= 37,
	   EFF_TARGET_SCRIPTED_OR_SINGLE_TARGET					= 38,
	   EFF_TARGET_SELF_FISHING								= 39,
	   EFF_TARGET_SCRIPTED_GAMEOBJECT						= 40,
	   EFF_TARGET_TOTEM_EARTH								= 41,
	   EFF_TARGET_TOTEM_WATER								= 42,
	   EFF_TARGET_TOTEM_AIR									= 43,
	   EFF_TARGET_TOTEM_FIRE								= 44,
	   EFF_TARGET_CHAIN										= 45,
	   EFF_TARGET_SCIPTED_OBJECT_LOCATION					= 46,
	   EFF_TARGET_DYNAMIC_OBJECT							= 47,//not sure exactly where is used
	   EFF_TARGET_MULTIPLE_SUMMON_LOCATION					= 48,
	   EFF_TARGET_MULTIPLE_SUMMON_PET_LOCATION				= 49,
	   EFF_TARGET_SUMMON_LOCATION							= 50,
	   EFF_TARGET_CALIRI_EGS								= 51,
	   EFF_TARGET_LOCATION_NEAR_CASTER						= 52,
	   EFF_TARGET_CURRENT_SELECTION							= 53,
	   EFF_TARGET_TARGET_AT_ORIENTATION_TO_CASTER			= 54,
	   EFF_TARGET_LOCATION_INFRONT_CASTER					= 55,
	   EFF_TARGET_PARTY_MEMBER								= 57,
	   EFF_TARGET_TARGET_FOR_VISUAL_EFFECT					= 59,
	   EFF_TARGET_SCRIPTED_TARGET2							= 60,
	   EFF_TARGET_AREAEFFECT_PARTY_AND_CLASS				= 61,
	   EFF_TARGET_PRIEST_CHAMPION							= 62, //wtf ?
	   EFF_TARGET_NATURE_SUMMON_LOCATION					= 63, 
	   EFF_TARGET_BEHIND_TARGET_LOCATION					= 65, 
	   EFF_TARGET_MULTIPLE_GUARDIAN_SUMMON_LOCATION			= 72,
	   EFF_TARGET_NETHETDRAKE_SUMMON_LOCATION				= 73,
	   EFF_TARGET_SCRIPTED_LOCATION							= 74,
	   EFF_TARGET_LOCATION_INFRONT_CASTER_AT_RANGE			= 75,
	   EFF_TARGET_ENEMYS_IN_ARE_CHANNELED_WITH_EXCEPTIONS	= 76,
	   EFF_TARGET_SELECTED_ENEMY_CHANNELED					= 77,
	   EFF_TARGET_SELECTED_ENEMY_DEADLY_POISON				= 86,
		//these are custom, feel free to move them further if tageting gets extended
	   EFF_TARGET_CUSTOM_PARTY_INJURED_SINGLE				= 99,
	   EFF_TARGET_CUSTOM_PARTY_INJURED_MULTI				= 100,
	   EFF_TARGET_LIST_LENGTH_MARKER						= 101,
	};

	enum SpellEffects
	{
		SPELL_EFFECT_NULL = 0,
		SPELL_EFFECT_INSTANT_KILL,              //    1
		SPELL_EFFECT_SCHOOL_DAMAGE,             //    2
		SPELL_EFFECT_DUMMY,                     //    3
		SPELL_EFFECT_PORTAL_TELEPORT,           //    4
		SPELL_EFFECT_TELEPORT_UNITS,            //    5
		SPELL_EFFECT_APPLY_AURA,                //    6
		SPELL_EFFECT_ENVIRONMENTAL_DAMAGE,      //    7
		SPELL_EFFECT_POWER_DRAIN,               //    8
		SPELL_EFFECT_HEALTH_LEECH,              //    9
		SPELL_EFFECT_HEAL,                      //    10
		SPELL_EFFECT_BIND,                      //    11
		SPELL_EFFECT_PORTAL,                    //    12
		SPELL_EFFECT_RITUAL_BASE,               //    13
		SPELL_EFFECT_RITUAL_SPECIALIZE,         //    14
		SPELL_EFFECT_RITUAL_ACTIVATE_PORTAL,    //    15
		SPELL_EFFECT_QUEST_COMPLETE,            //    16
		SPELL_EFFECT_WEAPON_DAMAGE_NOSCHOOL,    //    17
		SPELL_EFFECT_RESURRECT,                 //    18
		SPELL_EFFECT_ADD_EXTRA_ATTACKS,         //    19
		SPELL_EFFECT_DODGE,                     //    20
		SPELL_EFFECT_EVADE,                     //    21
		SPELL_EFFECT_PARRY,                     //    22
		SPELL_EFFECT_BLOCK,                     //    23
		SPELL_EFFECT_CREATE_ITEM,               //    24
		SPELL_EFFECT_WEAPON,                    //    25
		SPELL_EFFECT_DEFENSE,                   //    26
		SPELL_EFFECT_PERSISTENT_AREA_AURA,      //    27
		SPELL_EFFECT_SUMMON,                    //    28
		SPELL_EFFECT_LEAP,                      //    29
		SPELL_EFFECT_ENERGIZE,                  //    30
		SPELL_EFFECT_WEAPON_PERCENT_DAMAGE,     //    31
		SPELL_EFFECT_TRIGGER_MISSILE,           //    32
		SPELL_EFFECT_OPEN_LOCK,                 //    33
		SPELL_EFFECT_TRANSFORM_ITEM,            //    34
		SPELL_EFFECT_APPLY_AREA_AURA,           //    35
		SPELL_EFFECT_LEARN_SPELL,               //    36
		SPELL_EFFECT_SPELL_DEFENSE,             //    37
		SPELL_EFFECT_DISPEL,                    //    38
		SPELL_EFFECT_LANGUAGE,                  //    39
		SPELL_EFFECT_DUAL_WIELD,                //    40
		SPELL_EFFECT_SUMMON_WILD,               //    41
		SPELL_EFFECT_SUMMON_GUARDIAN,           //    42
		SPELL_EFFECT_TELEPORT_UNITS_FACE_CASTER,//    43
		SPELL_EFFECT_SKILL_STEP,                //    44
		SPELL_EFFECT_UNDEFINED_45,              //    45
		SPELL_EFFECT_SPAWN,                     //    46
		SPELL_EFFECT_TRADE_SKILL,               //    47
		SPELL_EFFECT_STEALTH,                   //    48
		SPELL_EFFECT_DETECT,                    //    49
		SPELL_EFFECT_SUMMON_OBJECT,             //    50
		//SPELL_EFFECT_TRANS_DOOR,              //    50
		SPELL_EFFECT_FORCE_CRITICAL_HIT,        //    51
		SPELL_EFFECT_GUARANTEE_HIT,             //    52
		SPELL_EFFECT_ENCHANT_ITEM,              //    53
		SPELL_EFFECT_ENCHANT_ITEM_TEMPORARY,    //    54
		SPELL_EFFECT_TAMECREATURE,              //    55
		SPELL_EFFECT_SUMMON_PET,                //    56
		SPELL_EFFECT_LEARN_PET_SPELL,           //    57
		SPELL_EFFECT_WEAPON_DAMAGE,             //    58
		SPELL_EFFECT_OPEN_LOCK_ITEM,            //    59
		SPELL_EFFECT_PROFICIENCY,               //    60
		SPELL_EFFECT_SEND_EVENT,                //    61
		SPELL_EFFECT_POWER_BURN,                //    62
		SPELL_EFFECT_THREAT,                    //    63
		SPELL_EFFECT_TRIGGER_SPELL,             //    64
		SPELL_EFFECT_HEALTH_FUNNEL,             //    65
		SPELL_EFFECT_POWER_FUNNEL,              //    66
		SPELL_EFFECT_HEAL_MAX_HEALTH,           //    67
		SPELL_EFFECT_INTERRUPT_CAST,            //    68
		SPELL_EFFECT_DISTRACT,                  //    69
		SPELL_EFFECT_PULL,                      //    70
		SPELL_EFFECT_PICKPOCKET,                //    71
		SPELL_EFFECT_ADD_FARSIGHT,              //    72
		SPELL_EFFECT_SUMMON_POSSESSED,          //    73
		SPELL_EFFECT_SUMMON_TOTEM,              //    74
		SPELL_EFFECT_HEAL_MECHANICAL,           //    75
		SPELL_EFFECT_SUMMON_OBJECT_WILD,        //    76
		SPELL_EFFECT_SCRIPT_EFFECT,             //    77
		SPELL_EFFECT_ATTACK,                    //    78
		SPELL_EFFECT_SANCTUARY,                 //    79
		SPELL_EFFECT_ADD_COMBO_POINTS,          //    80
		SPELL_EFFECT_CREATE_HOUSE,              //    81
		SPELL_EFFECT_BIND_SIGHT,                //    82
		SPELL_EFFECT_DUEL,                      //    83
		SPELL_EFFECT_STUCK,                     //    84
		SPELL_EFFECT_SUMMON_PLAYER,             //    85
		SPELL_EFFECT_ACTIVATE_OBJECT,           //    86
		SPELL_EFFECT_SUMMON_TOTEM_SLOT1,        //    87
		SPELL_EFFECT_SUMMON_TOTEM_SLOT2,        //    88
		SPELL_EFFECT_SUMMON_TOTEM_SLOT3,        //    89
		SPELL_EFFECT_SUMMON_TOTEM_SLOT4,        //    90
		SPELL_EFFECT_THREAT_ALL,                //    91
		SPELL_EFFECT_ENCHANT_HELD_ITEM,         //    92
		SPELL_EFFECT_SUMMON_PHANTASM,           //    93
		SPELL_EFFECT_SELF_RESURRECT,            //    94
		SPELL_EFFECT_SKINNING,                  //    95
		SPELL_EFFECT_CHARGE,                    //    96
		SPELL_EFFECT_SUMMON_CRITTER,            //    97
		SPELL_EFFECT_KNOCK_BACK,                //    98
		SPELL_EFFECT_DISENCHANT,                //    99
		SPELL_EFFECT_INEBRIATE,                 //    100
		SPELL_EFFECT_FEED_PET,                  //    101
		SPELL_EFFECT_DISMISS_PET,               //    102
		SPELL_EFFECT_REPUTATION,                //    103
		SPELL_EFFECT_SUMMON_OBJECT_SLOT1,       //    104
		SPELL_EFFECT_SUMMON_OBJECT_SLOT2,       //    105
		SPELL_EFFECT_SUMMON_OBJECT_SLOT3,       //    106
		SPELL_EFFECT_SUMMON_OBJECT_SLOT4,       //    107
		SPELL_EFFECT_DISPEL_MECHANIC,           //    108
		SPELL_EFFECT_SUMMON_DEAD_PET,           //    109
		SPELL_EFFECT_DESTROY_ALL_TOTEMS,        //    110
		SPELL_EFFECT_DURABILITY_DAMAGE,         //    111
		SPELL_EFFECT_SUMMON_DEMON,              //    112
		SPELL_EFFECT_RESURRECT_FLAT,            //    113
		SPELL_EFFECT_ATTACK_ME,                 //    114
		SPELL_EFFECT_DURABILITY_DAMAGE_PCT,     //    115
		SPELL_EFFECT_SKIN_PLAYER_CORPSE,        //    116
		SPELL_EFFECT_SPIRIT_HEAL,               //    117
		SPELL_EFFECT_SKILL,                     //    118
		SPELL_EFFECT_APPLY_PET_AURA,            //    119
		SPELL_EFFECT_TELEPORT_GRAVEYARD,        //    120
		SPELL_EFFECT_DUMMYMELEE,                //    121
		SPELL_EFFECT_UNKNOWN1,                  //    122
		SPELL_EFFECT_FILMING,                   //    123
		SPELL_EFFECT_PLAYER_PULL,               //    124
		SPELL_EFFECT_UNKNOWN4,                  //    125
		SPELL_EFFECT_UNKNOWN5,                  //    126
		SPELL_EFFECT_PROSPECTING,               //    127
		SPELL_EFFECT_APPLY_AA_FRIENDS,			//    128
		SPELL_EFFECT_APPLY_AA_ENEMIES,			//    129
		SPELL_EFFECT_UNKNOWN9,                  //    129
		SPELL_EFFECT_UNKNOWN10,                 //    130
		SPELL_EFFECT_UNKNOWN11,                 //    131
		SPELL_EFFECT_UNKNOWN12,                 //    132
		SPELL_EFFECT_FORGET_SPECIALIZATION,     //    133
		SPELL_EFFECT_UNKNOWN14,                 //    134
		SPELL_EFFECT_UNKNOWN15,                 //    135
		SPELL_EFFECT_UNKNOWN16,                 //    136
		SPELL_EFFECT_UNKNOWN17,                 //    137
		SPELL_EFFECT_UNKNOWN18,                 //    138
		SPELL_EFFECT_UNKNOWN19,                 //    139
		SPELL_EFFECT_UNKNOWN20,                 //    140
		SPELL_EFFECT_UNKNOWN21,                 //    141
		SPELL_EFFECT_TRIGGER_SPELL_WITH_VALUE,  //    142
		SPELL_EFFECT_UNKNOWN22,                 //    143
		SPELL_EFFECT_UNKNOWN23,                 //    144
		SPELL_EFFECT_UNKNOWN24,                 //    145
		SPELL_EFFECT_UNKNOWN25,                 //    146
		SPELL_EFFECT_QUEST_FAIL,                //    147
		SPELL_EFFECT_UNKNOWN26,                 //    148
		SPELL_EFFECT_UNKNOWN27,                 //    149
		SPELL_EFFECT_UNKNOWN28,                 //    150
		SPELL_EFFECT_SUMMON_TARGET,             //    151
		SPELL_EFFECT_UNKNOWN29,                 //    152
		SPELL_EFFECT_TAME_CREATURE,             //    153
		TOTAL_SPELL_EFFECTS,                    //    154
	};

	enum SPELL_DMG_TYPE // SPELL_ENTRY_Spell_Dmg_Type
	{
		SPELL_DMG_TYPE_NONE   = 0,
		SPELL_DMG_TYPE_MAGIC  = 1,
		SPELL_DMG_TYPE_MELEE  = 2,
		SPELL_DMG_TYPE_RANGED = 3
	};

	enum SpellProcFlags
	{
		SCRIPT_ACTION									= 0x0000001,
		KILLING_TARGET_THAT_GIVES_XP					= 0x0000002,
		MELEE_ATTACK_WHITE_DAMAGE_ONLY					= 0x0000004,
		BEGIN_HIT_BY_MELEE_ATTACK_WHITE_DAMAGE_ONLY		= 0x0000008,
		MELEE_ATTACK_YELLOW_DAMAGE_ONLY					= 0x0000010,
		BEING_HIT_BY_MELEE_ATTACK_YELLOW_DAMAGE_ONLY	= 0x0000020,
		RANGED_ATTACK_WHITE_DAMAGE_ONLY					= 0x0000040,
		BEING_HIT_BY_RANGED_ATTACK_WHITE_DAMAGE_ONLY	= 0x0000080,
		RANGED_ATTACK_YELLOW_DAMAGE_ONLY				= 0x0000100,
		BEING_HIT_BY_RANGED_ATTACK_YELLOW_DAMAGE_ONLY	= 0x0000200,
		CASTING_ANY_SPELL								= 0x0000400,
		BEING_CAST_ANY_SPELL							= 0x0000800,
		DEALING_DAMAGE									= 0x0001000,
		TAKINNG_ANY_DAMAGE								= 0x0002000,
		HEALING_ANY_TARGET								= 0x0004000,
		BEING_HEALED									= 0x0008000,
		DEALING_DIRECT_MAGIC_DAMAGE						= 0x0010000,	// mimo DOT
		TAKING_DIRECT_MAGIC_DAMAGE						= 0x0020000,	// mimo DOT
		DEALING_PERIODIC_MAGIC_DAMAGE					= 0x0040000,	// DOT
		TAKING_PERIODIC_MAGIC_DAMAGE					= 0x0080000,	// DOT
		LOSING_HEALTH									= 0x0100000,
		TRAPING_TARGET									= 0x0200000,
		MELEE_ATTACK_WITH_MH_WEAPON						= 0x0400000,
		MELEE_ATTACK_WITH_OH_WEAPON						= 0x0800000,
		DEATH											= 0x1000000,
	};

	enum MECHANICS
	{
		MECHANIC_CHARMED = 1,
		MECHANIC_DISORIENTED, // 2
		MECHANIC_DISARMED, // 3
		MECHANIC_DISTRACED, // 4
		MECHANIC_FLEEING, // 5
		MECHANIC_CLUMSY, // 6
		MECHANIC_ROOTED, // 7
		MECHANIC_PACIFIED, // 8
		MECHANIC_SILENCED, // 9
		MECHANIC_ASLEEP, // 10
		MECHANIC_ENSNARED, // 11
		MECHANIC_STUNNED, // 12
		MECHANIC_FROZEN, // 13
		MECHANIC_INCAPACIPATED, // 14
		MECHANIC_BLEEDING, // 15
		MECHANIC_HEALING, // 16
		MECHANIC_POLYMORPHED, // 17
		MECHANIC_BANISHED, // 18
		MECHANIC_SHIELDED, // 19
		MECHANIC_SHACKLED, // 20
		MECHANIC_MOUNTED, // 21
		MECHANIC_SEDUCED, // 22
		MECHANIC_TURNED, // 23
		MECHANIC_HORRIFIED, // 24
		MECHANIC_INVULNARABLE, // 25
		MECHANIC_INTERRUPTED, // 26
		MECHANIC_DAZED, // 27
		MECHANIC_DISCOVERY, // 28
		MECHANIC_INVULNERABLE, // 29
		MECHANIC_SAPPED, // 30
		MECHANIC_NUM,	// 31
	};

	enum DISPEL_TYPE
	{
		DISPEL_ZGTRINKETS		= -1,
		DISPEL_NULL				= 0,
		DISPEL_MAGIC			= 1,
		DISPEL_CURSE			= 2,
		DISPEL_DISEASE			= 3,
		DISPEL_POISON			= 4,
		DISPEL_STEALTH			= 5,
		DISPEL_INVISIBILTY		= 6,
		DISPEL_ALL				= 7,
		DISPEL_SPECIAL_NPCONLY	= 8,
		DISPEL_FRENZY			= 9,
		DISPEL_NUM				= 10,
	};

	enum DiminishingGroup
	{
		DIMINISHING_GROUP_STUN				= 0,
		DIMINISHING_GROUP_STUN_PROC			= 1,
		DIMINISHING_GROUP_ROOT				= 2,
		DIMINISHING_GROUP_ROOT_PROC			= 3,
		DIMINISHING_GROUP_SLEEP				= 4,
		DIMINISHING_GROUP_BLIND_CYCLONE		= 5,
		DIMINISHING_GROUP_GOUGE_POLY_SAP	= 6,
		DIMINISHING_GROUP_FEAR				= 7,
		DIMINISHING_GROUP_CHARM				= 8,
		DIMINISHING_GROUP_KIDNEY_SHOT		= 9,
		DIMINISHING_GROUP_HORROR			= 10,
		DIMINISHING_GROUP_BANISH			= 11,
		DIMINISHING_GROUP_NOT_DIMINISHED	= 12,
		DIMINISHING_GROUP_DISARM			= 13,
		DIMINISHING_GROUP_NUM				= 14,
	};
};

namespace PetEnums
{
	enum PetTameFailure
	{
		PETTAME_INVALIDCREATURE			= 1,
		PETTAME_TOOMANY					= 2,
		PETTAME_CREATUREALREADYOWNED	= 3,
		PETTAME_NOTTAMEABLE				= 4,
		PETTAME_ANOTHERSUMMONACTIVE		= 5,
		PETTAME_UNITSCANTTAME			= 6,
		PETTAME_NOPETAVAILABLE			= 7,
		PETTAME_INTERNALERROR			= 8,
		PETTAME_TOOHIGHLEVEL			= 9,
		PETTAME_DEAD					= 10,
		PETTAME_NOTDEAD					= 11,
		PETTAME_UNKNOWNERROR			= 12,
	};

	/* Taken from ItemPetFood.dbc
	 * Each value is equal to a flag
	 * so 1 <<PET_FOOD_BREAD for example
	 * will result in a usable value.
	 */
	enum PET_FOOD
	{
		PET_FOOD_NONE,
		PET_FOOD_MEAT,
		PET_FOOD_FISH,
		PET_FOOD_CHEESE,
		PET_FOOD_BREAD,
		PET_FOOD_FUNGUS,
		PET_FOOD_FRUIT,
		PET_FOOD_RAW_MEAT, // not used in pet diet
		PET_FOOD_RAW_FISH  // not used in pet diet
	};

	enum PET_ACTION
	{
		PET_ACTION_STAY,
		PET_ACTION_FOLLOW,
		PET_ACTION_ATTACK,
		PET_ACTION_DISMISS,
		PET_ACTION_CASTING,
	};

	enum PET_STATE
	{
		PET_STATE_PASSIVE,
		PET_STATE_DEFENSIVE,
		PET_STATE_AGGRESSIVE
	};

	enum PET_SPELL
	{
		PET_SPELL_PASSIVE = 0x06000000,
		PET_SPELL_DEFENSIVE,
		PET_SPELL_AGRESSIVE,
		PET_SPELL_STAY = 0x07000000,
		PET_SPELL_FOLLOW,
		PET_SPELL_ATTACK
	};

	enum StableState
	{
		STABLE_STATE_NULL		= 0,
		STABLE_STATE_ACTIVE		= 1,
		STABLE_STATE_PASSIVE	= 2,
	};

	enum HappinessState
	{
		UNHAPPY		=1,
		CONTENT		=2,
		HAPPY		=3
	};

	enum LoyaltyLevel
	{
		REBELIOUS	=1,
		UNRULY		=2,
		SUBMISIVE	=3,
		DEPENDABLE	=4,
		FAITHFUL	=5,
		BEST_FRIEND	=6
	};

	enum AutoCastEvents
	{
		AUTOCAST_EVENT_NONE					= 0,
		AUTOCAST_EVENT_ATTACK				= 1,
		AUTOCAST_EVENT_ON_SPAWN				= 2,
		AUTOCAST_EVENT_OWNER_ATTACKED		= 3,
		AUTOCAST_EVENT_LEAVE_COMBAT			= 4,
		AUTOCAST_EVENT_COUNT				= 5,
	};
};

namespace TrainerEnums
{
	enum TrainerStatus
	{
		TRAINER_STATUS_LEARNABLE		= 0,
		TRAINER_STATUS_NOT_LEARNABLE	= 1,
		TRAINER_STATUS_ALREADY_HAVE		= 2,
	};

	enum TrainerServiceType
	{
		TRAINER_SERVICE_AVAILABLE		= 0x0,
		TRAINER_SERVICE_UNAVAILABLE		= 0x1,
		TRAINER_SERVICE_USED			= 0x2,
		TRAINER_SERVICE_NOT_SHOWN		= 0x3,
		TRAINER_SERVICE_NEVER			= 0x4,
		TRAINER_SERVICE_NO_PET			= 0x5,
		NUM_TRAINER_SERVICE_TYPES		= 0x6,
	};

	enum TrainerType
	{
		TRAINER_TYPE_GENERAL			 = 0x0,
		TRAINER_TYPE_TALENTS			 = 0x1,
		TRAINER_TYPE_TRADESKILLS		 = 0x2,
		TRAINER_TYPE_PET				 = 0x3,
		NUM_TRAINER_TYPES				 = 0x4,
	};
};

namespace WorldCreatorEnums
{
	enum INSTANCE_TYPE
	{
		INSTANCE_NULL,
		INSTANCE_RAID,
		INSTANCE_NONRAID,
		INSTANCE_PVP,
		INSTANCE_MULTIMODE,
	};

	enum INSTANCE_ABORT_ERROR
	{
		INSTANCE_ABORT_ERROR_ERROR					= 0x00,
		INSTANCE_ABORT_FULL							= 0x01,
		INSTANCE_ABORT_NOT_FOUND					= 0x02,
		INSTANCE_ABORT_TOO_MANY						= 0x03,
		INSTANCE_ABORT_ENCOUNTER					= 0x04,
		INSTANCE_ABORT_NON_CLIENT_TYPE				= 0x05,
		INSTANCE_ABORT_HEROIC_MODE_NOT_AVAILABLE	= 0x06,
		INSTANCE_ABORT_NOT_IN_RAID_GROUP			= 0x07,

		INSTANCE_OK									= 0x10,
	};

	enum INSTANCE_RESET_ERROR
	{
		INSTANCE_RESET_ERROR_PLAYERS_INSIDE = 0x00,
		INSTANCE_RESET_ERROR_MEMBERS_OFFLINE = 0x01,
		INSTANCE_RESET_ERROR_PLAYERS_ENTERING = 0x02
	};
};

namespace SpellAuraEnums
{
	enum ADD_AURA_RESULT
	{
		ADD_AURA_RESULT_OK						= 0,
		ADD_AURA_RESULT_TARGET_IMMUNE_TO_SCHOOL	= 1,
		ADD_AURA_RESULT_TARGET_IMMUNE_TO_MODS	= 2,
		ADD_AURA_RESULT_NOT_ADDED				= 3,
		ADD_AURA_RESULT_VISUAL_SLOT_ERR			= 4,
	};

	//! 4-bit flag
	enum AURA_FLAGS
	{
		AFLAG_EMPTY = 0x0,
		AFLAG_SET = 0x9
	};

	enum AURA_INTERNAL_USAGE_FLAGS
	{
		//if all 3 mods are resisted then we can send client as a fully resisted spell.
		//don't change the value of these !
		MOD_0_RESISTED	= 1,
		MOD_1_RESISTED	= 2,
		MOD_2_RESISTED	= 4,
	};

	enum AURA_STATE_FLAGS
	{
		AURASTATE_FLAG_DODGE_BLOCK			= 1,        //1
		AURASTATE_FLAG_HEALTH20             = 2,        //2
		AURASTATE_FLAG_BERSERK              = 4,        //3
		AURASTATE_FLAG_JUDGEMENT            = 16,       //5
		AURASTATE_FLAG_PARRY                = 64,       //7
		AURASTATE_FLAG_LASTKILLWITHHONOR    = 512,      //10
		AURASTATE_FLAG_HUNTER_CRIT			= 512,		//10
		AURASTATE_FLAG_CRITICAL             = 1024,     //11
		AURASTATE_FLAG_HEALTH35             = 4096,     //13
		AURASTATE_FLAG_IMMOLATE             = 8192,     //14
		AURASTATE_FLAG_REJUVENATE           = 16384,    //15 //where do i use this ?
		AURASTATE_FLAG_POISON               = 32768,    //16
	};

	enum MOD_TYPES
	{
		SPELL_AURA_NONE = 0,                                // None
		SPELL_AURA_BIND_SIGHT = 1,                          // Bind Sight
		SPELL_AURA_MOD_POSSESS = 2,                         // Mod Possess
		SPELL_AURA_PERIODIC_DAMAGE = 3,                     // Periodic Damage
		SPELL_AURA_DUMMY = 4,                               // Script Aura
		SPELL_AURA_MOD_CONFUSE = 5,                         // Mod Confuse
		SPELL_AURA_MOD_CHARM = 6,                           // Mod Charm
		SPELL_AURA_MOD_FEAR = 7,                            // Mod Fear
		SPELL_AURA_PERIODIC_HEAL = 8,                       // Periodic Heal
		SPELL_AURA_MOD_ATTACKSPEED = 9,                     // Mod Attack Speed
		SPELL_AURA_MOD_THREAT = 10,                         // Mod Threat
		SPELL_AURA_MOD_TAUNT = 11,                          // Taunt
		SPELL_AURA_MOD_STUN = 12,                           // Stun
		SPELL_AURA_MOD_DAMAGE_DONE = 13,                    // Mod Damage Done
		SPELL_AURA_MOD_DAMAGE_TAKEN = 14,                   // Mod Damage Taken
		SPELL_AURA_DAMAGE_SHIELD = 15,                      // Damage Shield
		SPELL_AURA_MOD_STEALTH = 16,                        // Mod Stealth
		SPELL_AURA_MOD_DETECT = 17,                         // Mod Detect
		SPELL_AURA_MOD_INVISIBILITY = 18,                   // Mod Invisibility
		SPELL_AURA_MOD_INVISIBILITY_DETECTION = 19,         // Mod Invisibility Detection
		SPELL_AURA_MOD_TOTAL_HEALTH_REGEN_PCT = 20,
		SPELL_AURA_MOD_TOTAL_MANA_REGEN_PCT = 21,
		SPELL_AURA_MOD_RESISTANCE = 22,                     // Mod Resistance
		SPELL_AURA_PERIODIC_TRIGGER_SPELL = 23,             // Periodic Trigger
		SPELL_AURA_PERIODIC_ENERGIZE = 24,                  // Periodic Energize
		SPELL_AURA_MOD_PACIFY = 25,                         // Pacify
		SPELL_AURA_MOD_ROOT = 26,                           // Root
		SPELL_AURA_MOD_SILENCE = 27,                        // Silence
		SPELL_AURA_REFLECT_SPELLS = 28,                     // Reflect Spells %
		SPELL_AURA_MOD_STAT = 29,                           // Mod Stat
		SPELL_AURA_MOD_SKILL = 30,                          // Mod Skill
		SPELL_AURA_MOD_INCREASE_SPEED = 31,                 // Mod Speed
		SPELL_AURA_MOD_INCREASE_MOUNTED_SPEED = 32,         // Mod Speed Mounted
		SPELL_AURA_MOD_DECREASE_SPEED = 33,                 // Mod Speed Slow
		SPELL_AURA_MOD_INCREASE_HEALTH = 34,                // Mod Increase Health
		SPELL_AURA_MOD_INCREASE_ENERGY = 35,                // Mod Increase Energy
		SPELL_AURA_MOD_SHAPESHIFT = 36,                     // Shapeshift
		SPELL_AURA_EFFECT_IMMUNITY = 37,                    // Immune Effect
		SPELL_AURA_STATE_IMMUNITY = 38,                     // Immune State
		SPELL_AURA_SCHOOL_IMMUNITY = 39,                    // Immune School    
		SPELL_AURA_DAMAGE_IMMUNITY = 40,                    // Immune Damage
		SPELL_AURA_DISPEL_IMMUNITY = 41,                    // Immune Dispel Type
		SPELL_AURA_PROC_TRIGGER_SPELL = 42,                 // Proc Trigger Spell
		SPELL_AURA_PROC_TRIGGER_DAMAGE = 43,                // Proc Trigger Damage
		SPELL_AURA_TRACK_CREATURES = 44,                    // Track Creatures
		SPELL_AURA_TRACK_RESOURCES = 45,                    // Track Resources
		SPELL_AURA_MOD_PARRY_SKILL = 46,                    // Mod Parry Skill
		SPELL_AURA_MOD_PARRY_PERCENT = 47,                  // Mod Parry Percent
		SPELL_AURA_MOD_DODGE_SKILL = 48,                    // Mod Dodge Skill
		SPELL_AURA_MOD_DODGE_PERCENT = 49,                  // Mod Dodge Percent  
		SPELL_AURA_MOD_BLOCK_SKILL = 50,                    // Mod Block Skill
		SPELL_AURA_MOD_BLOCK_PERCENT = 51,                  // Mod Block Percent
		SPELL_AURA_MOD_CRIT_PERCENT = 52,                   // Mod Crit Percent
		SPELL_AURA_PERIODIC_LEECH = 53,                     // Periodic Leech
		SPELL_AURA_MOD_HIT_CHANCE = 54,                     // Mod Hit Chance
		SPELL_AURA_MOD_SPELL_HIT_CHANCE = 55,               // Mod Spell Hit Chance
		SPELL_AURA_TRANSFORM = 56,                          // Transform
		SPELL_AURA_MOD_SPELL_CRIT_CHANCE = 57,              // Mod Spell Crit Chance
		SPELL_AURA_MOD_INCREASE_SWIM_SPEED = 58,            // Mod Speed Swim
		SPELL_AURA_MOD_DAMAGE_DONE_CREATURE = 59,           // Mod Creature Dmg Done   
		SPELL_AURA_MOD_PACIFY_SILENCE = 60,                 // Pacify & Silence
		SPELL_AURA_MOD_SCALE = 61,                          // Mod Scale
		SPELL_AURA_PERIODIC_HEALTH_FUNNEL = 62,             // Periodic Health Funnel
		SPELL_AURA_PERIODIC_MANA_FUNNEL = 63,               // Periodic Mana Funnel
		SPELL_AURA_PERIODIC_MANA_LEECH = 64,                // Periodic Mana Leech
		SPELL_AURA_MOD_CASTING_SPEED = 65,                  // Haste - Spells
		SPELL_AURA_FEIGN_DEATH = 66,                        // Feign Death
		SPELL_AURA_MOD_DISARM = 67,                         // Disarm
		SPELL_AURA_MOD_STALKED = 68,                        // Mod Stalked
		SPELL_AURA_SCHOOL_ABSORB = 69,                      // School Absorb    
		SPELL_AURA_EXTRA_ATTACKS = 70,                      // Extra Attacks
		SPELL_AURA_MOD_SPELL_CRIT_CHANCE_SCHOOL = 71,       // Mod School Spell Crit Chance
		SPELL_AURA_MOD_POWER_COST = 72,                     // Mod Power Cost
		SPELL_AURA_MOD_POWER_COST_SCHOOL = 73,              // Mod School Power Cost
		SPELL_AURA_REFLECT_SPELLS_SCHOOL = 74,              // Reflect School Spells %
		SPELL_AURA_MOD_LANGUAGE = 75,                       // Mod Language
		SPELL_AURA_FAR_SIGHT = 76,                          // Far Sight
		SPELL_AURA_MECHANIC_IMMUNITY = 77,                  // Immune Mechanic
		SPELL_AURA_MOUNTED = 78,                            // Mounted
		SPELL_AURA_MOD_DAMAGE_PERCENT_DONE = 79,            // Mod Dmg %   
		SPELL_AURA_MOD_PERCENT_STAT = 80,                   // Mod Stat %
		SPELL_AURA_SPLIT_DAMAGE = 81,                       // Split Damage
		SPELL_AURA_WATER_BREATHING = 82,                    // Water Breathing
		SPELL_AURA_MOD_BASE_RESISTANCE = 83,                // Mod Base Resistance
		SPELL_AURA_MOD_REGEN = 84,                          // Mod Health Regen
		SPELL_AURA_MOD_POWER_REGEN = 85,                    // Mod Power Regen
		SPELL_AURA_CHANNEL_DEATH_ITEM = 86,                 // Create Death Item
		SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN = 87,           // Mod Dmg % Taken
		SPELL_AURA_MOD_PERCENT_REGEN = 88,                  // Mod Health Regen Percent
		SPELL_AURA_PERIODIC_DAMAGE_PERCENT = 89,            // Periodic Damage Percent   
		SPELL_AURA_MOD_RESIST_CHANCE = 90,                  // Mod Resist Chance
		SPELL_AURA_MOD_DETECT_RANGE = 91,                   // Mod Detect Range
		SPELL_AURA_PREVENTS_FLEEING = 92,                   // Prevent Fleeing
		SPELL_AURA_MOD_UNATTACKABLE = 93,                   // Mod Uninteractible
		SPELL_AURA_INTERRUPT_REGEN = 94,                    // Interrupt Regen
		SPELL_AURA_GHOST = 95,                              // Ghost
		SPELL_AURA_SPELL_MAGNET = 96,                       // Spell Magnet
		SPELL_AURA_MANA_SHIELD = 97,                        // Mana Shield
		SPELL_AURA_MOD_SKILL_TALENT = 98,                   // Mod Skill Talent
		SPELL_AURA_MOD_ATTACK_POWER = 99,                   // Mod Attack Power
		SPELL_AURA_AURAS_VISIBLE = 100,                     // Auras Visible
		SPELL_AURA_MOD_RESISTANCE_PCT = 101,                // Mod Resistance %
		SPELL_AURA_MOD_CREATURE_ATTACK_POWER = 102,         // Mod Creature Attack Power
		SPELL_AURA_MOD_TOTAL_THREAT = 103,                  // Mod Total Threat (Fade)
		SPELL_AURA_WATER_WALK = 104,                        // Water Walk
		SPELL_AURA_FEATHER_FALL = 105,                      // Feather Fall
		SPELL_AURA_HOVER = 106,                             // Hover
		SPELL_AURA_ADD_FLAT_MODIFIER = 107,                 // Add Flat Modifier
		SPELL_AURA_ADD_PCT_MODIFIER = 108,                  // Add % Modifier
		SPELL_AURA_ADD_TARGET_TRIGGER = 109,                // Add Class Target Trigger    
		SPELL_AURA_MOD_POWER_REGEN_PERCENT = 110,           // Mod Power Regen %
		SPELL_AURA_ADD_CASTER_HIT_TRIGGER = 111,            // Add Class Caster Hit Trigger
		SPELL_AURA_OVERRIDE_CLASS_SCRIPTS = 112,            // Override Class Scripts
		SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN = 113,           // Mod Ranged Dmg Taken
		SPELL_AURA_MOD_RANGED_DAMAGE_TAKEN_PCT = 114,       // Mod Ranged % Dmg Taken
		SPELL_AURA_MOD_HEALING = 115,                       // Mod Healing
		SPELL_AURA_IGNORE_REGEN_INTERRUPT = 116,            // Regen During Combat
		SPELL_AURA_MOD_MECHANIC_RESISTANCE = 117,           // Mod Mechanic Resistance
		SPELL_AURA_MOD_HEALING_PCT = 118,                   // Mod Healing %
		SPELL_AURA_SHARE_PET_TRACKING = 119,                // Share Pet Tracking    
		SPELL_AURA_UNTRACKABLE = 120,                       // Untrackable
		SPELL_AURA_EMPATHY = 121,                           // Empathy (Lore, whatever)
		SPELL_AURA_MOD_OFFHAND_DAMAGE_PCT = 122,            // Mod Offhand Dmg %
		SPELL_AURA_MOD_POWER_COST_PCT = 123,                // Mod Power Cost % --> armor penetration & spell penetration
		SPELL_AURA_MOD_RANGED_ATTACK_POWER = 124,           // Mod Ranged Attack Power
		SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN = 125,            // Mod Melee Dmg Taken
		SPELL_AURA_MOD_MELEE_DAMAGE_TAKEN_PCT = 126,        // Mod Melee % Dmg Taken
		SPELL_AURA_RANGED_ATTACK_POWER_ATTACKER_BONUS = 127,// Rngd Atk Pwr Attckr Bonus
		SPELL_AURA_MOD_POSSESS_PET = 128,                   // Mod Possess Pet
		SPELL_AURA_MOD_INCREASE_SPEED_ALWAYS = 129,         // Mod Speed Always   
		SPELL_AURA_MOD_MOUNTED_SPEED_ALWAYS = 130,          // Mod Mounted Speed Always
		SPELL_AURA_MOD_CREATURE_RANGED_ATTACK_POWER = 131,  // Mod Creature Ranged Attack Power
		SPELL_AURA_MOD_INCREASE_ENERGY_PERCENT = 132,       // Mod Increase Energy %
		SPELL_AURA_MOD_INCREASE_HEALTH_PERCENT = 133,       // Mod Max Health %
		SPELL_AURA_MOD_MANA_REGEN_INTERRUPT = 134,          // Mod Interrupted Mana Regen
		SPELL_AURA_MOD_HEALING_DONE = 135,                  // Mod Healing Done
		SPELL_AURA_MOD_HEALING_DONE_PERCENT = 136,          // Mod Healing Done %
		SPELL_AURA_MOD_TOTAL_STAT_PERCENTAGE = 137,         // Mod Total Stat %
		SPELL_AURA_MOD_HASTE = 138,                         // Haste - Melee
		SPELL_AURA_FORCE_REACTION = 139,                    // Force Reaction    
		SPELL_AURA_MOD_RANGED_HASTE = 140,                  // Haste - Ranged
		SPELL_AURA_MOD_RANGED_AMMO_HASTE = 141,             // Haste - Ranged (Ammo Only)
		SPELL_AURA_MOD_BASE_RESISTANCE_PCT = 142,           // Mod Base Resistance %
		SPELL_AURA_MOD_RESISTANCE_EXCLUSIVE = 143,          // Mod Resistance Exclusive
		SPELL_AURA_SAFE_FALL = 144,                         // Safe Fall
		SPELL_AURA_CHARISMA = 145,                          // Charisma
		SPELL_AURA_PERSUADED = 146,                         // Persuaded
		SPELL_AURA_ADD_CREATURE_IMMUNITY = 147,             // Add Creature Immunity
		SPELL_AURA_RETAIN_COMBO_POINTS = 148,               // Retain Combo Points
		SPELL_AURA_RESIST_PUSHBACK = 149,                   // Resist Pushback
		SPELL_AURA_MOD_SHIELD_BLOCK_PCT = 150,              // Mod Shield Block %
		SPELL_AURA_TRACK_STEALTHED = 151,                   // Track Stealthed
		SPELL_AURA_MOD_DETECTED_RANGE = 152,                // Mod Detected Range
		SPELL_AURA_SPLIT_DAMAGE_FLAT = 153,                 // Split Damage Flat
		SPELL_AURA_MOD_STEALTH_LEVEL = 154,                 // Stealth Level Modifier
		SPELL_AURA_MOD_WATER_BREATHING = 155,               // Mod Water Breathing
		SPELL_AURA_MOD_REPUTATION_ADJUST = 156,             // Mod Reputation Gain
		SPELL_AURA_PET_DAMAGE_MULTI = 157,                  // Mod Pet Damage
		SPELL_AURA_MOD_SHIELD_BLOCK = 158,                  // Mod Shield Block
		SPELL_AURA_NO_PVP_CREDIT = 159,                     // No PVP Credit 
		SPELL_AURA_MOD_SIDE_REAR_PDAE_DAMAGE_TAKEN = 160,   // Mod Side/Rear PBAE Damage Taken 
		SPELL_AURA_MOD_HEALTH_REGEN_IN_COMBAT = 161,        // Mod Health Regen In Combat
		SPELL_AURA_POWER_BURN = 162,                        // Power Burn 
		SPELL_AURA_MOD_CRIT_DAMAGE_BONUS_MELEE = 163,       // Mod Critical Damage Bonus (Physical)
		SPELL_AURA_MELEE_ATTACK_POWER_ATTACKER_BONUS = 165, // Melee AP Attacker Bonus
		SPELL_AURA_MOD_ATTACK_POWER_PCT = 166,              // Mod Attack Power
		SPELL_AURA_MOD_RANGED_ATTACK_POWER_PCT = 167,       // Mod Ranged Attack Power %
		SPELL_AURA_INCREASE_DAMAGE = 168,                   // Increase Damage Type
		SPELL_AURA_INCREASE_CRITICAL = 169,                 // Increase Critical Type
		SPELL_AURA_DETECT_AMORE = 170,                      // Detect Amore
		SPELL_AURA_INCREASE_MOVEMENT_AND_MOUNTED_SPEED = 172,// Increase Movement and Mounted Speed (Non-Stacking)
		SPELL_AURA_INCREASE_SPELL_DAMAGE_PCT = 174,         // Increase Spell Damage by % status
		SPELL_AURA_INCREASE_SPELL_HEALING_PCT = 175,        // Increase Spell Healing by % status
		SPELL_AURA_SPIRIT_OF_REDEMPTION = 176,              // Spirit of Redemption Auras
		SPELL_AURA_AREA_CHARM = 177,                        // Area Charm 
		SPELL_AURA_INCREASE_ATTACKER_SPELL_CRIT = 179,      // Increase Attacker Spell Crit Type
		SPELL_AURA_INCREASE_SPELL_DAMAGE_VS_TYPE = 180,     // Increase Spell Damage Type
		SPELL_AURA_INCREASE_ARMOR_BASED_ON_INTELLECT_PCT = 182, // Increase Armor based on Intellect
		SPELL_AURA_DECREASE_CRIT_THREAT = 183,              // Decrease Critical Threat by
		SPELL_AURA_DECREASE_ATTACKER_CHANCE_TO_HIT_MELEE = 184,//Reduces Attacker Chance to Hit with Melee
		SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_RANGED = 185,// Reduces Attacker Chance to Hit with Ranged 
		SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_HIT_SPELLS = 186,// Reduces Attacker Chance to Hit with Spells
		SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_MELEE = 187,// Reduces Attacker Chance to Crit with Melee (Ranged?)
		SPELL_AURA_DECREASE_ATTACKER_CHANGE_TO_CRIT_RANGED = 188,// Reduces Attacker Chance to Crit with Ranged (Melee?)
		SPELL_AURA_INCREASE_REPUTATION = 190,               // Increases reputation from killed creatures
		SPELL_AURA_SPEED_LIMIT = 191,                       // speed limit
		SPELL_AURA_MELEE_SLOW_PCT = 192,
		SPELL_AURA_INCREASE_TIME_BETWEEN_ATTACKS = 193,
		SPELL_AURA_INREASE_SPELL_DAMAGE_PCT_OF_INTELLECT = 194,  // NOT USED ANYMORE - 174 used instead
		SPELL_AURA_INCREASE_HEALING_PCT_OF_INTELLECT = 195,		// NOT USED ANYMORE - 175 used instead
		SPELL_AURA_MOD_ALL_WEAPON_SKILLS = 196,
		SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_CHANCE_PCT = 197,
		SPELL_AURA_INCREASE_SPELL_HIT_PCT = 199,
		SPELL_AURA_CANNOT_BE_DODGED = 201,
		SPELL_AURA_FINISHING_MOVES_CANNOT_BE_DODGED = 202,
		SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_MELEE_PCT = 203,
		SPELL_AURA_REDUCE_ATTACKER_CRICTICAL_HIT_DAMAGE_RANGED_PCT = 204,
		SPELL_AURA_INCREASE_RANGED_ATTACK_POWER_PCT_OF_INTELLECT = 212,
		SPELL_AURA_INCREASE_RAGE_FROM_DAMAGE_DEALT_PCT = 213,
		SPELL_AURA_INCREASE_CASTING_TIME_PCT = 216,
		SPELL_AURA_REGEN_MANA_STAT_PCT=219,
		SPELL_AURA_HEALING_STAT_PCT=220,
		SPELL_AURA_INCREASE_MAX_HEALTH=230,//Used by Commanding Shout
		SPELL_AURA_MOD_SCALE_2 = 239,
		SPELL_AURA_MODIFY_AXE_SKILL=240,
		SPELL_AURA_241 = 241,
		SPELL_AURA_MOD_SPELL_DAMAGE_FROM_HEALING = 242,
		SPELL_AURA_243 = 243,
		SPELL_AURA_244 = 244,
		SPELL_AURA_MOD_DURATION_OF_MAGIC_EFFECTS = 245,
		SPELL_AURA_246 = 246,
		SPELL_AURA_247 = 247,
		SPELL_AURA_MOD_COMBAT_RESULT_CHANCE = 248,
		SPELL_AURA_249 = 249,
		SPELL_AURA_MOD_INCREASE_HEALTH_2 = 250,
		SPELL_AURA_MOD_ENEMY_DODGE = 251,
		TOTAL_SPELL_AURAS = 252
	};

	enum AuraTickFlags
	{
		FLAG_PERIODIC_DAMAGE            = 2,
		FLAG_PERIODIC_TRIGGER_SPELL     = 4,
		FLAG_PERIODIC_HEAL              = 8,
		FLAG_PERIODIC_LEECH             = 16,
		FLAG_PERIODIC_ENERGIZE          = 32,
	};

	enum AuraInterruptFlags
	{
		AURA_INTERRUPT_NULL                       = 0x00000000,
		AURA_INTERRUPT_ON_HOSTILE_SPELL_INFLICTED = 0x00000001,		// 0    removed when getting hit by a negative spell?
		AURA_INTERRUPT_ON_ANY_DAMAGE_TAKEN        = 0x00000002,		// 1    removed by any damage
		AURA_INTERRUPT_ON_UNK1                    = 0x00000004,		// 2
		AURA_INTERRUPT_ON_MOVEMENT                = 0x00000008,		// 3    removed by any movement
		AURA_INTERRUPT_ON_TURNING                 = 0x00000010,		// 4    removed by any turning
		AURA_INTERRUPT_ON_ENTER_COMBAT            = 0x00000020,		// 5    removed by entering combat
		AURA_INTERRUPT_ON_NOT_MOUNTED             = 0x00000040,		// 6    removed by unmounting
		AURA_INTERRUPT_ON_SLOWED                  = 0x00000080,		// 7    removed by entering water
		AURA_INTERRUPT_ON_LEAVE_WATER             = 0x00000100,		// 8    removed by leaving water
		AURA_INTERRUPT_ON_NOT_SHEATHED            = 0x00000200,		// 9    removed by unsheathing
		AURA_INTERRUPT_ON_UNK4                    = 0x00000400,		// 10
		AURA_INTERRUPT_ON_UNK5                    = 0x00000800,		// 11
		AURA_INTERRUPT_ON_START_ATTACK            = 0x00001000,		// 12	removed by attack?
		AURA_INTERRUPT_ON_UNK6                    = 0x00002000,		// 13
		AURA_INTERRUPT_ON_UNUSED3                 = 0x00004000,		// 14
		AURA_INTERRUPT_ON_CAST_SPELL              = 0x00008000,		// 15	removed by casting a spell?
		AURA_INTERRUPT_ON_UNK7                    = 0x00010000,		// 16
		AURA_INTERRUPT_ON_MOUNT                   = 0x00020000,		// 17	removed by mounting
		AURA_INTERRUPT_ON_STAND_UP                = 0x00040000,		// 18	removed by standing up
		AURA_INTERRUPT_ON_LEAVE_AREA              = 0x00080000,		// 19	leaving map/getting teleported
		AURA_INTERRUPT_ON_INVINCIBLE              = 0x00100000,		// 20
		AURA_INTERRUPT_ON_STEALTH                 = 0x00200000,		// 21
		AURA_INTERRUPT_ON_UNK8                    = 0x00400000,		// 22
		AURA_INTERRUPT_ON_ENTER_PVP_COMBAT		  = 0x00800000,		// 23   removed by entering pvp combat
		AURA_INTERRUPT_ON_DIRECT_DAMAGE			  = 0x01000000,		// 24   removed by any direct damage

		AURA_INTERRUPT_ON_AFTER_CAST_SPELL        = 0x80000000,
	};
};

namespace AIInterfaceEnums
{
	enum AiEvents
	{
		EVENT_ENTERCOMBAT,
		EVENT_LEAVECOMBAT,
		EVENT_DAMAGETAKEN,
		EVENT_FEAR,
		EVENT_UNFEAR,
		EVENT_FOLLOWOWNER,
		EVENT_WANDER,
		EVENT_UNWANDER,
		EVENT_UNITDIED,
	};

	enum AiSpellEvents
	{
		SPELL_EVENT_NULL = 0,
		SPELL_EVENT_ON_SPAWN = 1,
		SPELL_EVENT_ON_COMBAT_START = 2,
		SPELL_EVENT_ON_COMBAT_STOP = 3,
		SPELL_EVENT_ON_DAMAGE_TAKEN = 4,
		SPELL_EVENT_ON_DIE = 5,
		SPELL_EVENT_ON_COMBAT_UPDATE = 6,
	};

	enum AiTargetFlags
	{
		TARGET_FLAG_NULL = 0,
		TARGET_FLAG_RANDOM_ANY = 1,
		TARGET_FLAG_RANDOM_IN_SHORTRANGE = 2,
		TARGET_FLAG_RANDOM_IN_MIDRANGE = 3,
		TARGET_FLAG_RANDOM_IN_LONGRANGE = 4,
		TARGET_FLAG_RANDOM_WITH_MANA = 5,
		TARGET_FLAG_RANDOM_WITH_ENERGY = 6,
		TARGET_FLAG_RANDOM_WITH_RAGE = 7,
		TARGET_FLAG_RANDOM_NOT_MAINTANK = 8,
		TARGET_FLAG_RANDOM_FRIEND = 9,
	};

	enum AI_SpellTargetType
	{
		TTYPE_NULL = 0,
		TTYPE_SINGLETARGET = 1,
		TTYPE_DESTINATION = 2,
		TTYPE_SOURCE = 3,
		TTYPE_CASTER = 4,
		TTYPE_OWNER = 5,
		TTYPE_HIGHEST_AGGRO = 6,
		TTYPE_RANDOM_NOT_HIGGEST_AGGRO = 7,
		TTYPE_RANDOM = 8,
		TTYPE_SECOND_AGGRO = 9,
		TTYPE_BY_TARGET_FLAGS = 10,
		TTYPE_RANDOM_DESTINATION = 11,
	};

	enum AiTargetType
	{
		AI_TARGET_TYPE_NULL = 0,
		AI_TARGET_TYPE_UNIT = 3,
		AI_TARGET_TYPE_PLAYER = 4,
	};

	enum TerrainType
	{
		ALL_TYPES = 0,
		WATER_ONLY,
		GROUND_ONLY,
	};
};

namespace CreatureEnums
{
	enum CreatureAISpellFlags
	{
		CREATURE_AI_FLAG_NONE				= 0x00,
		CREATURE_AI_FLAG_RANDOMCAST			= 0x01,
		CREATURE_AI_FLAG_CASTOUTOFCOMBAT	= 0x02,
		CREATURE_AI_FLAG_PLAYERGCD			= 0x04
	};

	enum CritUncapable
	{
		CRIT_UNCAPABLE_NONE			= 0,
		CRIT_UNCAPABLE_MELEE		= 2,
		CRIT_UNCAPABLE_SPELL		= 4,
		CRIT_UNCAPABLE_CRUSHING		= 8,
		CRIT_UNCAPABLE_ALL			= 16,
	};
	   
	enum UNIT_TYPE
	{
		NOUNITTYPE			= 0,
		BEAST				= 1,
		DRAGONSKIN			= 2,
		DEMON				= 3,
		ELEMENTAL			= 4,
		GIANT				= 5,
		UNDEAD				= 6,
		HUMANOID			= 7,
		CRITTER				= 8,
		MECHANICAL			= 9,
		UNIT_TYPE_MISC		= 10,
		TOTEM				= 11,
		NON_COMBAT_PET		= 12,
		GAS_CLOUD			= 13,
		UNIT_TYPE_NUM		= 14,
	};

	enum FAMILY
	{
		FAMILY_WOLF = 1,
		FAMILY_CAT,
		FAMILY_SPIDER,
		FAMILY_BEAR,
		FAMILY_BOAR,
		FAMILY_CROCILISK,
		FAMILY_CARRION_BIRD,
		FAMILY_CRAB,
		FAMILY_GORILLA,
		FAMILY_RAPTOR = 11,
		FAMILY_TALLSTRIDER ,
		FAMILY_FELHUNTER = 15,
		FAMILY_VOIDWALKER,
		FAMILY_SUCCUBUS,
		FAMILY_DOOMGUARD = 19,
		FAMILY_SCORPID,
		FAMILY_TURTLE, 
		FAMILY_IMP = 23,
		FAMILY_BAT,
		FAMILY_HYENA,
		FAMILY_OWL,
		FAMILY_WIND_SERPENT,
		FAMILY_REMOTE_CONTROL,
		FAMILY_FELGUARD,
		FAMILY_DRAGONHAWK,
		FAMILY_RAVAGER,
		FAMILY_WARP_STALKER,
		FAMILY_SPOREBAT,
		FAMILY_NETHER_RAY,
		FAMILY_SERPENT
	};

	enum ELITE
	{
		ELITE_NORMAL = 0,
		ELITE_ELITE,
		ELITE_RAREELITE,
		ELITE_WORLDBOSS,
		ELITE_RARE
	};

	enum TIME_REMOVE_CORPSE
	{
		TIME_CREATURE_REMOVE_CORPSE = 180000,
		TIME_CREATURE_REMOVE_RARECORPSE = 180000*5,
		TIME_CREATURE_REMOVE_BOSSCORPSE = 180000*10,
	};

	enum CreatureTypeFlags
	{
		CREATURE_TYPEFLAGS_TAMEABLE         = 0x000001,         // Tameable by any hunter
		CREATURE_TYPEFLAGS_GHOST            = 0x000002,         // Creature are also visible for not alive player. Allow gossip interaction if npcflag allow?
		CREATURE_TYPEFLAGS_UNK3             = 0x000004,
		CREATURE_TYPEFLAGS_UNK4             = 0x000008,
		CREATURE_TYPEFLAGS_UNK5             = 0x000010,
		CREATURE_TYPEFLAGS_UNK6             = 0x000020,
		CREATURE_TYPEFLAGS_UNK7             = 0x000040,
		CREATURE_TYPEFLAGS_UNK8             = 0x000080,
		CREATURE_TYPEFLAGS_HERBLOOT         = 0x000100,         // Can be looted by herbalist
		CREATURE_TYPEFLAGS_MININGLOOT       = 0x000200,         // Can be looted by miner
		CREATURE_TYPEFLAGS_UNK11            = 0x000400,
		CREATURE_TYPEFLAGS_UNK12            = 0x000800,         // ? Related to mounts in some way. If mounted, fight mounted, mount appear as independant when rider dies?
		CREATURE_TYPEFLAGS_UNK13            = 0x001000,         // ? Can aid any player in combat if in range?
		CREATURE_TYPEFLAGS_UNK14            = 0x002000,
		CREATURE_TYPEFLAGS_UNK15            = 0x004000,         // ? Possibly not in use
		CREATURE_TYPEFLAGS_ENGINEERLOOT     = 0x008000,         // Can be looted by engineer
		CREATURE_TYPEFLAGS_EXOTIC           = 0x010000,         // Can be tamed by hunter as exotic pet
		CREATURE_TYPEFLAGS_UNK18            = 0x020000,         // ? Related to vehicles/pvp?
		CREATURE_TYPEFLAGS_UNK19            = 0x040000,         // ? Related to vehicle/siege weapons?
		CREATURE_TYPEFLAGS_UNK20            = 0x080000,
		CREATURE_TYPEFLAGS_UNK21            = 0x100000,
		CREATURE_TYPEFLAGS_UNK22            = 0x200000,
		CREATURE_TYPEFLAGS_UNK23            = 0x400000,
		CREATURE_TYPEFLAGS_UNK24            = 0x800000          // ? First seen in 3.2.2. Related to banner/backpack of creature/companion?
	};
};

namespace StatEnums
{
	enum Stats
	{
		STAT_STRENGTH,
		STAT_AGILITY,
		STAT_STAMINA,
		STAT_INTELLECT,
		STAT_SPIRIT,
		STAT_NUM,
	};

	enum Resistance
	{
		RESISTANCE_ARMOR,
		RESISTANCE_HOLY,
		RESISTANCE_FIRE,
		RESISTANCE_NATURE,
		RESISTANCE_FROST,
		RESISTANCE_SHADOW,
		RESISTANCE_ARCANE,
		RESISTANCE_NUM,
	};
};

namespace PlayerEnums
{
	enum PlayerTeam
	{
		NULL_TEAM	= -1,
		ALLIANCE	= 0,
		HORDE		= 1,
		TEAM_COUNT,
	};

	enum ShapeshiftForm
	{
		FORM_NORMAL             = 0,
		FORM_CAT                = 1,
		FORM_TREE               = 2,
		FORM_TRAVEL             = 3,
		FORM_AQUA               = 4,
		FORM_BEAR               = 5,
		FORM_AMBIENT            = 6,
		FORM_GHOUL              = 7,
		FORM_DIREBEAR           = 8,
		FORM_CREATUREBEAR       = 14,
		FORM_GHOSTWOLF          = 16,
		FORM_BATTLESTANCE       = 17,
		FORM_DEFENSIVESTANCE    = 18,
		FORM_BERSERKERSTANCE    = 19,
		FORM_SWIFT              = 27,
		FORM_SHADOW             = 28,
		FORM_FLIGHT             = 29,
		FORM_STEALTH            = 30,
		FORM_MOONKIN            = 31,
		FORM_SPIRITOFREDEMPTION = 32,
	};

	enum PlayerSpeedType
	{
		RUN	            = 1,
		RUNBACK         = 2,
		SWIM	        = 3,
		SWIMBACK        = 4,
		WALK	        = 5,
		FLY	            = 6,
	};

	enum PlayerMovementType
	{
		MOVE_ROOT	    = 1,
		MOVE_UNROOT	    = 2,
		MOVE_WATER_WALK = 3,
		MOVE_LAND_WALK  = 4,
	};
};

namespace MapMgrEnums
{
	enum MapMgrActions
	{
		CALL_INSTANCE_EXPIRE = 0,
		BEGIN_INSTANCE_EXPIRE_COUTDOWN = 1,
	};
};

namespace GroupEnums
{
	enum PartyErrors
	{
		ERR_PARTY_NO_ERROR					= 0,
		ERR_PARTY_CANNOT_FIND				= 1,
		ERR_PARTY_IS_NOT_IN_YOUR_PARTY		= 2,
		ERR_PARTY_OTHER_INSTANCE			= 3,
		ERR_PARTY_IS_FULL					= 4,
		ERR_PARTY_ALREADY_IN_GROUP			= 5,
		ERR_PARTY_YOU_ARENT_IN_A_PARTY		= 6,
		ERR_PARTY_YOU_ARE_NOT_LEADER		= 7,
		ERR_PARTY_WRONG_FACTION				= 8,
		ERR_PARTY_IS_IGNORING_YOU			= 9,
	};

	enum GroupTypes
	{
	   GROUP_TYPE_PARTY               = 0x00,
	   GROUP_TYPE_BG                  = 0x01,
	   GROUP_TYPE_RAID                = 0x02,
	   GROUP_TYPE_BGRAID              = GROUP_TYPE_BG | GROUP_TYPE_RAID,		// mask
	   GROUP_TYPE_LFD                 = 0x08,									// dunno if this is also on wotlk, i think not :P
	};

	enum MaxGroupCount
	{
		MAX_GROUP_SIZE_PARTY				= 5,
		MAX_GROUP_SIZE_RAID					= 40,
	};

	enum QuickGroupUpdateFlags
	{
		PARTY_UPDATE_FLAG_POSITION			= 1,
		PARTY_UPDATE_FLAG_ZONEID			= 2,
	};

	enum PartyUpdateFlags
	{
		GROUP_UPDATE_FLAG_NONE						= 0,		// 0x00000000
		GROUP_UPDATE_FLAG_ONLINE					= 1,		// 0x00000001  uint8
		GROUP_UPDATE_FLAG_HEALTH					= 2,		// 0x00000002  uint16
		GROUP_UPDATE_FLAG_MAXHEALTH					= 4,		// 0x00000004  uint16
		GROUP_UPDATE_FLAG_POWER_TYPE				= 8,		// 0x00000008  uint16
		GROUP_UPDATE_FLAG_POWER						= 16,		// 0x00000010  uint16
		GROUP_UPDATE_FLAG_MAXPOWER					= 32,		// 0x00000020  uint16
		GROUP_UPDATE_FLAG_LEVEL						= 64,		// 0x00000040  uint16
		GROUP_UPDATE_FLAG_ZONEID					= 128,		// 0x00000080  uint16
		GROUP_UPDATE_FLAG_POSITION					= 256,		// 0x00000100  uint16, uint16
		GROUP_UPDATE_FLAG_PLAYER_AURAS				= 512,		// 0x00000200  uint64, uint16 for each uint64
		GROUP_UPDATE_FLAG_PET_GUID					= 1024,		// 0x00000400  uint64
		GROUP_UPDATE_FLAG_PET_NAME					= 2048,		// 0x00000800  string
		GROUP_UPDATE_FLAG_PET_DISPLAYID				= 4096,		// 0x00001000  uint16
		GROUP_UPDATE_FLAG_PET_HEALTH				= 8192,		// 0x00002000  uint16
		GROUP_UPDATE_FLAG_PET_MAXHEALTH				= 16384,	// 0x00004000  uint16
		GROUP_UPDATE_FLAG_PET_POWER_TYPE			= 32768,	// 0x00008000  uint8
		GROUP_UPDATE_FLAG_PET_POWER					= 65535,	// 0x00010000  uint16
		GROUP_UPDATE_FLAG_PET_MAXPOWER				= 131070,	// 0x00020000  uint16
		GROUP_UPDATE_FLAG_PET_AURAS					= 262144,	// 0x00040000  uint64, uint16 for each uint64
	};

	enum PartyUpdateFlagGroups
	{
		GROUP_UPDATE_TYPE_FULL_CREATE				=	GROUP_UPDATE_FLAG_ONLINE | GROUP_UPDATE_FLAG_HEALTH | GROUP_UPDATE_FLAG_MAXHEALTH |
														GROUP_UPDATE_FLAG_POWER | GROUP_UPDATE_FLAG_LEVEL |
														GROUP_UPDATE_FLAG_ZONEID | GROUP_UPDATE_FLAG_MAXPOWER | GROUP_UPDATE_FLAG_POSITION,
		GROUP_UPDATE_TYPE_FULL_REQUEST_REPLY		=   0x7FFC0BFF,
	};
	enum PartyOperation
	{
		PARTY_OPERATION_INVITE		= 0,	//Used also as default action when not doing any from the list
		PARTY_OPERATION_UNINVITE	= 1,
		PARTY_OPERATION_LEAVE		= 2,
		PARTY_OPERATION_CONVERT		= 4,
	};
};

namespace BattleGroundEnums
{
	enum BattleGroundTypes
	{
		BATTLEGROUND_NONE = 0,
		BATTLEGROUND_ALTERAC_VALLEY = 1,
		BATTLEGROUND_WARSONG_GULCH	= 2,
		BATTLEGROUND_ARATHI_BASIN	= 3,
		BATTLEGROUND_ARENA_2V2		= 4,
		BATTLEGROUND_ARENA_3V3		= 5,
		BATTLEGROUND_ARENA_5V5		= 6,
		BATTLEGROUND_EYE_OF_THE_STORM=7,
		BATTLEGROUND_NUM_TYPES		 =8,
	};

	enum BattlefieldStatuses
	{
		BF_STATUS_NONE = 0,
		BF_STATUS_IN_QUEUE = 1,
		BF_STATUS_READY_TO_JOIN = 2,
		BF_STATUS_IN_PROGRESS = 3,
		BF_STATUS_ENDED = 4
	};
};

namespace ProcEnums
{
	enum ProcCondHandlerRes
	{
		PROCCOND_CONTINUE_EXECUTION		= 1,	//we meet conditions and should cast this spell
		PROCCOND_BREAK_EXECUTION		= 2,	//it is not time to take further actions
		PROCCOND_FATAL_EXIT				= 3,	//should not happen
	};

	enum procFlags
	{
		PROC_NULL							= 0x00000000,
		PROC_ON_ANY_HOSTILE_ACTION			= 0x00000001,
		PROC_ON_GAIN_EXPIERIENCE			= 0x00000002,
		PROC_ON_MELEE_ATTACK				= 0x00000004,
		PROC_ON_CRIT_HIT_VICTIM				= 0x00000008,
		PROC_ON_CAST_SPELL					= 0x00000010,
		PROC_ON_PHYSICAL_ATTACK_VICTIM		= 0x00000020,
		PROC_ON_RANGED_ATTACK				= 0x00000040,
		PROC_ON_RANGED_CRIT_ATTACK			= 0x00000080,
		PROC_ON_PHYSICAL_ATTACK				= 0x00000100,
		PROC_ON_MELEE_ATTACK_VICTIM			= 0x00000200,
		PROC_ON_SPELL_HIT					= 0x00000400,
		PROC_ON_RANGED_CRIT_ATTACK_VICTIM	= 0x00000800,
		PROC_ON_CRIT_ATTACK					= 0x00001000,
		PROC_ON_RANGED_ATTACK_VICTIM		= 0x00002000,
		PROC_ON_PRE_DISPELL_AURA_VICTIM		= 0x00004000,
		PROC_ON_SPELL_LAND_VICTIM			= 0x00008000,
		PROC_ON_CAST_SPECIFIC_SPELL			= 0x00010000,
		PROC_ON_SPELL_HIT_VICTIM			= 0x00020000,
		PROC_ON_SPELL_CRIT_HIT_VICTIM		= 0x00040000,
		PROC_ON_TARGET_DIE					= 0x00080000,
		PROC_ON_ANY_DAMAGE_VICTIM			= 0x00100000,
		PROC_ON_TRAP_TRIGGER				= 0x00200000, //triggers on trap activation)
		PROC_ON_AUTO_SHOT_HIT				= 0x00400000,
		PROC_ON_ABSORB						= 0x00800000,
		PROC_ON_RESIST_VICTIM				= 0x01000000,
		PROC_ON_DODGE_VICTIM				= 0x02000000,
		PROC_ON_DIE							= 0x04000000,
		PROC_REMOVEONUSE					= 0x08000000,//remove prochcharge only when it is used
		PROC_MISC							= 0x10000000,//our custom flag to decide if proc dmg or shield
		PROC_ON_BLOCK_VICTIM				= 0x20000000,
		PROC_ON_SPELL_CRIT_HIT				= 0x40000000,
		PROC_TARGET_SELF					= 0x80000000,//our custom flag to decide if proc target is self or victim
	};
};

namespace GameObjectEnums
{
	enum GAMEOBJECT_TYPES
	{
		GAMEOBJECT_TYPE_DOOR				= 0,
		GAMEOBJECT_TYPE_BUTTON				= 1,
		GAMEOBJECT_TYPE_QUESTGIVER			= 2,
		GAMEOBJECT_TYPE_CHEST				= 3,
		GAMEOBJECT_TYPE_BINDER				= 4,
		GAMEOBJECT_TYPE_GENERIC				= 5,
		GAMEOBJECT_TYPE_TRAP				= 6,
		GAMEOBJECT_TYPE_CHAIR				= 7,
		GAMEOBJECT_TYPE_SPELL_FOCUS			= 8,
		GAMEOBJECT_TYPE_TEXT				= 9,
		GAMEOBJECT_TYPE_GOOBER				= 10,
		GAMEOBJECT_TYPE_TRANSPORT			= 11,
		GAMEOBJECT_TYPE_AREADAMAGE			= 12,
		GAMEOBJECT_TYPE_CAMERA				= 13,
		GAMEOBJECT_TYPE_MAP_OBJECT			= 14,
		GAMEOBJECT_TYPE_MO_TRANSPORT		= 15,
		GAMEOBJECT_TYPE_DUEL_ARBITER		= 16,
		GAMEOBJECT_TYPE_FISHINGNODE			= 17,
		GAMEOBJECT_TYPE_RITUAL				= 18,
		GAMEOBJECT_TYPE_MAILBOX				= 19,
		GAMEOBJECT_TYPE_AUCTIONHOUSE		= 20,
		GAMEOBJECT_TYPE_GUARDPOST			= 21,
		GAMEOBJECT_TYPE_SPELLCASTER			= 22,
		GAMEOBJECT_TYPE_MEETINGSTONE		= 23,
		GAMEOBJECT_TYPE_FLAGSTAND			= 24,
		GAMEOBJECT_TYPE_FISHINGHOLE			= 25,
		GAMEOBJECT_TYPE_FLAGDROP			= 26,
	};

	enum GameObjectFlags
	{
		GO_FLAG_IN_USE          = 0x01,                         //disables interaction while animated
		GO_FLAG_LOCKED          = 0x02,                         //require key, spell, event, etc to be opened. Makes "Locked" appear in tooltip
		GO_FLAG_INTERACT_COND   = 0x04,                         //cannot interact (condition to interact)
		GO_FLAG_TRANSPORT       = 0x08,                         //any kind of transport? Object can transport (elevator, boat, car)
		GO_FLAG_UNK1            = 0x10,                         //
		GO_FLAG_NODESPAWN       = 0x20,                         //never despawn, typically for doors, they just change state
		GO_FLAG_TRIGGERED       = 0x40,                         //typically, summoned objects. Triggered by spell or other events
	};

	enum GameObjectDynFlags
	{
		GO_DYNFLAG_QUEST		= 0x09,
	};
};