// throwup.h
// God I hope this works

// main function
void ThrowUpNow(edict_t *self);

// utility function in g_misc.c
void ThrowVomit(edict_t *ent, vec3_t mouth_pos, vec3_t forward, vec3_t right, vec3_t player_vel);
