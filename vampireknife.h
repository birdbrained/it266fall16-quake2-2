// Here's hoping to a moderatly working piece of code.
// vampireknife.h

#define VAMPIREKNIFE_NORMAL_DAMAGE 10
#define	VAMPIREKNIFE_DEATHMATCH_DAMAGE 20
#define VAMPIREKNIFE_KICK 500
#define VAMPIREKNIFE_RANGE 35

#define SELFSWORD_NORMAL_DAMAGE 10
#define SELFSWORD_DEATHMATCH_DAMAGE 10
#define SELFSWORD_KICK 5
#define SELFSWORD_RANGE 5

void fire_sword ( edict_t *self, vec3_t start, vec3_t aimdir, int damage, int kick);
void sword_attack (edict_t *ent, vec3_t g_offset, int damage);
void Weapon_Sword_Fire (edict_t *ent);
void Weapon_Sword (edict_t *ent);

void fire_selfsword(edict_t *self, vec3_t start, vec3_t aimdir, int damage, int kick);
void selfsword_attack (edict_t *ent, vec3_t g_offset, int damage);
void Weapon_SelfSword_Fire(edict_t *ent);
void Weapon_SelfSword(edict_t *ent);

