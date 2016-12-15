// Trying to see if I can add the posion arrows that were on the
// final exam. I'm using the flamethrower tut as a guide.
//
// Well... here goes some shit.

//#include "g_local.h"

/*
=======================
Poison Arrows
========================
*/
/*
void Fire_Think(edict_t *self)
{
	vec3_t dir, v;
	int damage;
	float points;

	if (level.time > self->delay)
	{
		self->owner->Poison--;
		G_FreeEdict(self);
		return;
	}
	if (!self->owner)
	{
		G_FreeEdict(self);
		return;
	}
	if (self->owner->waterlevel)
	{
		self->owner->Poison--;
		G_FreeEdict(self);
		return;
	}

	damage = random(1,self->PosionDamage);
	VectorAdd(self->mins, self->maxs, v);
	VectorMA(self->s.origin, 0.5, v, v);
	VectorSubtract(self->s.origin, v, v);
	points = damage - 0.5 * (VectorLength(v));
	VectorSubtract(self->owner->s.origin, self->s.origin, dir);

	if (self->PoisonDelay < level.time)
	{
		T_Damage(self->owner, self, self, dir, self->owner->s.origin, vec3_origin, damage, 0, DAMAGE_NO_KNOCKBACK, MOD_WF_POISON);
		self->PoisonDelay = level.time + 0.8;
	}
	VectorCopy(self->owner->s.origin, self->s.origin);
	self->nextthink = level.time + 0.2;
}

void poison_person(edict_t *target, edict_t *owner, int damage)
{
	edict_t *poi;
	int i;

	if (target->Poison > 1)
		return;
	target->Poison++;
	poi = G_Spawn();
	if (!poi)
		return;
	poi->movetype = MOVETYPE_NOCLIP;
	poi->clipmask = MASK_SHOT;
	poi->solid = SOLID_NOT;
	poi->s.effects |= EF_ANIM_ALLFAST|EF_BFG|EF_HYPERBLASTER;
	for (i=0; i<3; i++)
		poi->velocity[i] = target->velocity[i];

	VectorClear(poi->mins);
	VectorClear(poi->maxs);
	poi->s.modelindex = gi.modelindex("sprites/s_explod.sp2");
	poi->owner = owner;
	poi->delay = level.time + 5;
	poi->nextthink = level.time + 0.8;
	poi->PoisonDelay = level.time + 0.8;
	poi->think = Fire_Think;
	poi->PoisonDamage = damage + 2;
	poi->classname = "poison";
	poi->s.sound = gi.soundindex("weapons/bfg__l1a.wav");
	gi.linkentity(poi);

	VectorCopy(target->s.origin, poi->s.origin);
}

void poison_touch(edict_t *self, edict_t *other, cplane_t *plane, csurface_t *surf)
{
	if (other == self->owner)
		return;

	if (surf && (surf->flags & SURF_SKY)) // if you collide with the skybox
	{
		G_FreeEdict(self);
		return;
	}

	if (self->owner->client)
		PlayerNoise(self->owner, self->s.origin, PNOISE_IMPACT);
	T_Damage(other, self, self->owner, self->velocity, self->s.origin, plane->normal, 6, 0, 0, MOD_WF_POISON);

	if (other->health)
		poison_person(other, self->owner, self->PoisonDamage);

	G_FreeEdict(self);
}

void fire_poison_arrow(edict_t *self, vec3_t start, vec3_t dir, int damage, int speed, float damage_radius)
{
	edict_t *poi;

	poi = G_Spawn();
	if (!poi)
		return;
	VectorCopy(start, poi->s.origin);
	VectorCopy(dir, poi->movedir);
	vectoangles(dir, poi->s.angles);
	VectorScale(dir, speed, poi->velocity);
	poi->movetype = MOVETYPE_FLYMISSILE;
	poi->clipmask = SOLID_BBOX;
	poi->solid = SOLID_BBOX;
	poi->s.effects |= EF_ANIM_ALLFAST|EF_BFG|EF_HYPERBLASTER;
	VectorSet(poi->mins, -20, -20, -20);
	VectorSet(poi->maxs, 20, 20, 20);
	poi->s.modelindex = gi.modelindex("sprites/s_explod.sp2");
	poi->owner = self;
	poi->touch = poison_touch;
	poi->nextthink = level.time + 250/speed;
	poi->think = G_FreeEdict;
	poi->radius_dmg = damage;
	poi->PoisonDamage = damage;
	poi->dmg_radius = damage_radius;
	poi->classname = "poison";
	poi->s.sound = gi.soundindex ("weapons/bfg__l1a.wav");

	//if (self->client)
		
}

*/