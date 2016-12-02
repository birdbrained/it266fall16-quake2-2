// throwup.c
// God, I hope this works too

#include "g_local.h"
#include "throwup.h"

void ThrowUpNow(edict_t *self)
{
	vec3_t forward, right, mouth_pos, spew_vector;
	float rambo;
	int i;

	// Set the spew vector based on the client's (the player's) view angle
	AngleVectors(self->client->v_angle, forward, right, NULL);

	// Make the spew start from the mouth
	VectorScale(forward, 24, mouth_pos);
	VectorAdd(mouth_pos, self->s.origin, mouth_pos);
	mouth_pos[2] += self->viewheight;

	// Make the spew come forward from the mouth
	VectorScale(forward, 24, spew_vector);

	// Make the BLOOD particle effect
	gi.WriteByte(svc_temp_entity);
	gi.WriteByte(TE_BLOOD);
	gi.WritePosition(mouth_pos);
	gi.WriteDir(spew_vector);
	gi.multicast(mouth_pos, MULTICAST_PVS);

	//============================
	// Bonus stuff the tut showed
	//============================

	// Write out to the console
	rambo = random();
	if (rambo < 0.2)
		gi.bprintf(PRINT_MEDIUM, "Hurgle blurgle\n");
	else if (rambo < 0.4)
		gi.bprintf(PRINT_MEDIUM, "...BLARHF...\n");
	else if (rambo < 0.6)
		gi.bprintf(PRINT_MEDIUM, "*vomit*\n");
	else if (rambo < 0.8)
		gi.bprintf(PRINT_MEDIUM, "There goes lunch...\n");
	else
		gi.bprintf(PRINT_MEDIUM, "BBLLZSZLSDSDFLLAARRFFFF\n");

	if (self->bloodloss > 0)
	{
		// Cough up some gibbies
		for (i = 0; i<3; i++)
		{
			ThrowVomit(self, mouth_pos, forward, right, self->velocity);
		}

		// Cough up a SUPER GIBBY every now and again
		if (random() < 0.1)
		{
			for (i = 0; i<10; i++)
			{
				ThrowVomit(self, mouth_pos, forward, right, self->velocity);
			} 
		}
		self->bloodloss -= 5;
		gi.dprintf("Barfed! New bloodloss: (%d)\n", self->bloodloss);
	}
}

