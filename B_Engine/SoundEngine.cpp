#include "Engine (2).h"


SoundEngine::SoundEngine(void)
{
	channel1, channel2, channel3 = 0;
	listenerFlag = true;
	listenerPos.x = 0.0f;
	listenerPos.y = 0.0f;
	listenerPos.z = 0.0f;
	running = false;
	moving = false;
	log = false;
	Rolloff = false;
	forward = false;

	Fvel.x = 0;
	Fvel.y = 0;
	Fvel.z = 0;

	Fpos.x = 0;
	Fpos.y = 0;
	Fpos.z = 0;

	Fward.x = 0;
	Fward.y = 0;
	Fward.z = 1;

}


SoundEngine::~SoundEngine(void){}


void SoundEngine::ERRCHECK(FMOD_RESULT result)
{

	    if (result != FMOD_OK)
    {
        printf("FMOD error! (%d) %s\n", result, FMOD_ErrorString(result));
        exit(-1);
    }

}

void SoundEngine::createSystemandInit()
{

	result = FMOD::System_Create(&system);
	ERRCHECK(result);

	result = system->getVersion(&version);
	ERRCHECK(result);

	 if (version < FMOD_VERSION)
    {
        printf("Error!  You are using an old version of FMOD %08x.  This program requires %08x\n", version, FMOD_VERSION);
        //return 0;
    }

	result = system->getNumDrivers(&numdrivers);
    ERRCHECK(result);


	if (numdrivers == 0)
    {
        result = system->setOutput(FMOD_OUTPUTTYPE_NOSOUND);
        ERRCHECK(result);
    }
    else
    {
        result = system->getDriverCaps(0, &caps, 0, &speakerMode);
        ERRCHECK(result);

        result = system->setSpeakerMode(speakerMode);       /* Set the user selected speaker mode. */
        ERRCHECK(result);

        if (caps & FMOD_CAPS_HARDWARE_EMULATED)             /* The user has the 'Acceleration' slider set to off!  This is really bad for latency!. */
        {                                                   /* You might want to warn the user about this. */
            result = system->setDSPBufferSize(1024, 10);
            ERRCHECK(result);
        }

        result = system->getDriverInfo(0, name, 256, 0);
        ERRCHECK(result);

        if (strstr(name, "SigmaTel"))   /* Sigmatel sound devices crackle for some reason if the format is PCM 16bit.  PCM floating point output seems to solve it. */
        {
            result = system->setSoftwareFormat(48000, FMOD_SOUND_FORMAT_PCMFLOAT, 0,0, FMOD_DSP_RESAMPLER_LINEAR);
            ERRCHECK(result);
        }
    }

    result = system->init(100, FMOD_INIT_NORMAL, 0);
    if (result == FMOD_ERR_OUTPUT_CREATEBUFFER)         /* Ok, the speaker mode selected isn't supported by this soundcard.  Switch it back to stereo... */
    {
        result = system->setSpeakerMode(FMOD_SPEAKERMODE_STEREO);
        ERRCHECK(result);
            
        result = system->init(100, FMOD_INIT_NORMAL, 0);/* ... and re-init. */
        ERRCHECK(result);
    }

}

void SoundEngine::setDistance()
{
	FMOD_VECTOR Fup = {0.0, 1.0, 0.0};

	Game soundObj;

	listenerPos.x = soundObj.currentPos.x;
	listenerPos.y = soundObj.currentPos.y + 500;
	listenerPos.z = soundObj.currentPos.z;

	result = system->set3DSettings(1.0, DISTANCEFACTOR, 1.0f);
    ERRCHECK(result);
	result = system->set3DListenerAttributes(0, &listenerPos, &Fvel, &Fward, &Fup);
	ERRCHECK(result);
}


void SoundEngine::loadSounds(int name)
{

	//If Drum Sound is chosen
	if(name == 1)
	{
		result = system->createSound("sounds/oceanSounds.wav", FMOD_3D, 0, &sound1);
		ERRCHECK(result);
		result = sound1->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 20 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound1->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

	//If Jaguar Sound is chosen
	else if(name == 2)
	{
		result = system->createSound("sounds/Shantay2.mp3", FMOD_3D, 0, &sound2);
		ERRCHECK(result);
		result = sound2->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 5 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound2->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

	//If Swish Sound is chosen
	else if(name == 3)
	{
		result = system->createSound("sounds/SpiritCarnage.mp3", FMOD_3D, 0, &sound3);
		ERRCHECK(result);
		result = sound3->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 30 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound3->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

	//If Swish Sound is chosen
	else if(name == 4)
	{
		result = system->createSound("sounds/se_maoudamashii_explosion03.ogg", FMOD_3D, 0, &sound4);
		ERRCHECK(result);
		result = sound4->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 15 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound4->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

		else if(name == 5)
	{
		result = system->createSound("sounds/clickSound.mp3", FMOD_3D, 0, &sound5);
		ERRCHECK(result);
		result = sound5->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 5 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound5->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}


		else if(name == 6)
	{
		result = system->createSound("sounds/gullSound.ogg", FMOD_3D, 0, &sound6);
		ERRCHECK(result);
		result = sound6->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 10 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound6->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}


		else if(name == 7)
	{
		result = system->createSound("sounds/CHARGE.wav", FMOD_3D, 0, &sound7);
		ERRCHECK(result);
		result = sound7->set3DMinMaxDistance(1.0f * DISTANCEFACTOR, 5 * DISTANCEFACTOR);
		ERRCHECK(result);
		result = sound7->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);
	}

}

void SoundEngine::playSounds(int name, Vec3 pos, Vec3 vel)
{

	Fpos.x = pos.x;
	Fpos.y = pos.y;
	Fpos.z = pos.z;

    Fvel.x = vel.x;
	Fvel.y = vel.y;
	Fvel.z = vel.z;


	if(name == 1)
	{
		result = system->playSound(FMOD_CHANNEL_FREE, sound1, true, &channel1);
		ERRCHECK(result);
		result = channel1->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel1->setPaused(false);
		ERRCHECK(result);
	}

	else if(name == 2)
	{
		result = system->playSound(FMOD_CHANNEL_FREE, sound2, true, &channel2);
		ERRCHECK(result);
		result = channel2->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel2->setPaused(false);
		ERRCHECK(result);
	}


	else if(name == 3)
	{
		result = system->playSound(FMOD_CHANNEL_FREE, sound3, true, &channel3);
		ERRCHECK(result);
		result = channel3->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel3->setPaused(false);
		ERRCHECK(result);
	}


		else if(name == 4)
	{
		result = system->playSound(FMOD_CHANNEL_FREE, sound4, true, &channel4);
		ERRCHECK(result);
		result = channel4->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel4->setPaused(false);
		ERRCHECK(result);
	}


		else if(name == 5)
	{
		
		result = system->playSound(FMOD_CHANNEL_FREE, sound5, true, &channel5);
		ERRCHECK(result);
		result = channel5->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel5->setPaused(false);
		ERRCHECK(result);
	}

			else if(name == 6)
	{
		
		result = system->playSound(FMOD_CHANNEL_FREE, sound6, true, &channel6);
		ERRCHECK(result);
		result = channel6->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel6->setPaused(false);
		ERRCHECK(result);
	}

			else if(name == 7)
	{
		
		result = system->playSound(FMOD_CHANNEL_FREE, sound7, true, &channel7);
		ERRCHECK(result);
		result = channel7->set3DAttributes(&Fpos, &Fvel);
		ERRCHECK(result);
		result = channel7->setPaused(false);
		ERRCHECK(result);
	}

}

void SoundEngine::displayHelp()
{

	result = system->getHardwareChannels(&numchannels);
    ERRCHECK(result);
    
    printf("Hardware channels : %d\n", numchannels);

}

void SoundEngine::updateSoundPos(unsigned int input, Vec3 pos, Vec3 vel)
{
	FMOD_VECTOR tempPos = {pos.x, pos.y, pos.z};
	FMOD_VECTOR tempVel = {vel.x, vel.y, vel.z};

	if(input == 1)
	{
		result = channel1->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);
	}

	else if(input == 2)
	{
		result = channel2->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);
	}
	
	else if(input == 3)
	{
		result = channel3->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);

	}

	else if(input == 4)
	{
		result = channel4->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);

	}

	else if(input == 5)
	{
		result = channel4->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);

	}

	else if(input == 6)
	{
		result = channel6->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);

	}

	else if(input == 7)
	{
		result = channel7->set3DAttributes(&tempPos, &tempVel);
		ERRCHECK(result);

	}

}

void SoundEngine::updateSoundRolloff(bool logCheck)
{

	if(logCheck == true)
	{
		result = sound1->setMode(FMOD_LOOP_NORMAL);
		ERRCHECK(result);

	//	result = sound2->setMode(FMOD_LOOP_NORMAL);
		//ERRCHECK(result);

		//result = sound3->setMode(FMOD_LOOP_NORMAL);
		//ERRCHECK(result);
	}

	else if(logCheck == false)
	{
		result = sound1->setMode(FMOD_3D_LINEARROLLOFF);
		ERRCHECK(result);

		//result = sound2->setMode(FMOD_3D_LINEARROLLOFF);
		//ERRCHECK(result);

		//result = sound3->setMode(FMOD_3D_LINEARROLLOFF);
		//ERRCHECK(result);
	}

}