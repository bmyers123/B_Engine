#ifndef SOUND_ENGINE_H
#define SOUND_ENGINE_H


#define DISTANCEFACTOR 1.0f


#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <math.h>

#include "FMod/fmod.hpp"
#include "FMod/fmod_errors.h"


class SoundEngine 
{

public:

	SoundEngine(void);
	~SoundEngine(void);

	FMOD_VECTOR Fpos;
	FMOD_VECTOR Fvel;
	FMOD_VECTOR Fward;

	FMOD::System	*system;
    FMOD::Channel *channel1, *channel2, *channel3;
	FMOD::Channel *channel4, *channel5, *channel6, *channel7;
    FMOD_RESULT      result;
    int              key, numdrivers, numchannels;

    bool             listenerFlag;
    FMOD_VECTOR      listenerPos;
    unsigned int     version;
    FMOD_SPEAKERMODE speakerMode;
    FMOD_CAPS        caps;
    char             name[256];
	bool running, moving, log, Rolloff, forward;
	int input;

	//const float DISTANCEFACTOR = 1.0f;
	/*const int   INTERFACE_UPDATETIME = 50;*/


	void createSystemandInit();
	void ERRCHECK(FMOD_RESULT result);
	void setDistance();
	void updateSoundPos(unsigned int input, Vec3 pos, Vec3 vel);
	void updateSoundRolloff(bool logCheck);

	//Sounds
	FMOD::Sound		*sound1, *sound2, *sound3, *sound4, *sound5, *sound6, *sound7;
	
	void loadSounds(int name);
	void playSounds(int name, Vec3 pos, Vec3 vel);
	void displayHelp();

	void start()
	{
	running = true;
	}
	void stop()
	{
	running = false;
	}

};


#endif
