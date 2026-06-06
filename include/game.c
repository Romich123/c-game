#include <stdint.h>
#include <stdlib.h>

typedef enum HeroStatKey {
    STAT_ARMOR,
    STAT_BASE_DAMAGE,
    STAT_LUCK,

    HeroStatKey_Count
} HeroStatKey;

typedef struct Stat {
    uint64_t base;
    double multiplier;
} Stat;

uint64_t Stat_ToNumber(Stat stat) {
    return stat.base * stat.multiplier;
}

Stat Stat_Add(const Stat *a, const Stat *b) {
    return (Stat){
        .base = a->base + b->base,
        .multiplier = a->multiplier * b->multiplier};
}

typedef struct Stats {
    Stat values[HeroStatKey_Count];
} Stats;

Stats Stats_Empty() {
    return (Stats){.values = {0}};
}

Stats Stats_Add(const Stats *a, const Stats *b) {
    Stats result;

    for (uint64_t i = 0; i < HeroStatKey_Count; i++) {
        result.values[i] = Stat_Add(&a->values[i], &b->values[i]);
    }

    return result;
}

typedef struct ItemBase {
    char *name;
    char *description;

    Stats stats;
} ItemBase;

typedef struct ItemInstance {
    ItemBase *base;

    // self is attacker
    void (*onAttack)(Entity *self, Entity *attacked, GameState *gameState);
    // self is attacked
    void (*onBeingAttacked)(Entity *self, Entity *attacker, GameState *gameState);
    // self is attacked
    void (*onSpellCast)(Entity *self, Entity *attacker, GameState *gameState);

    Stats addedStats;
} ItemInstance;

typedef struct Entity {
    Stats baseStats;

    ItemInstance *items;
    uint64_t itemsCount;
    uint64_t itemsCapacity;

    // it is used in actual gameplay
    // it should not be modified directly
    // it is calculated every once in a while
    // so it is mostly just a cache of actual stats
    Stats stats;
} Entity;

// side effect: changes entity->stats
Stats Entity_GetActualStats(Entity *entity) {
    Stats result = entity->baseStats;

    for (uint64_t itemIndex = 0; itemIndex < entity->itemsCount; itemIndex++) {
        result = Stats_Add(&result, &entity->items[itemIndex].base->stats);
        result = Stats_Add(&result, &entity->items[itemIndex].addedStats);
    }

    entity->stats = result;

    return result;
}

typedef enum FightGround {
    FIELD_CLOSE
} FightGround;

typedef struct FightState {
    Entity playerTeam[12];

    Entity enemyTeam[12];
} FightState;

typedef struct GameState {
} GameState;
