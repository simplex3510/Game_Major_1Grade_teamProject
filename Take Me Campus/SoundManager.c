#include <stdio.h>
#include <fmod.h>
#include "SoundManager.h"

#pragma once

FMOD_SYSTEM *soundSystem; //사운드시스템
FMOD_SOUND *bgmSoundFile[10]; //배경음 파일 저장변수
FMOD_SOUND *effectSoundFile[50]; //효과음 파일 저장변수
FMOD_CHANNEL *bgmSoundChannel;
FMOD_CHANNEL *effectSoundChannel;
int bgmSoundOnOff = 0;
int effectSoundOnOff = 0;

//배경음 파일 추가 함수
void bgmSoundFileAdd(char file[30], int number)
{
	FMOD_System_CreateSound(soundSystem, file, FMOD_LOOP_NORMAL, 0, &bgmSoundFile[number]);
}

//효과음 파일 추가 함수
void effectSoundFileAdd(char file[30], int number)
{
	FMOD_System_CreateSound(soundSystem, file, FMOD_DEFAULT, 0, &effectSoundFile[number]);
}

//사운드 기능 준비 함수
void sound_init()
{
	FMOD_System_Create(&soundSystem);
	FMOD_System_Init(soundSystem, 32, FMOD_INIT_NORMAL, NULL);

	//배경음 파일 추가하는 곳 ↓ bgmSoundFileAdd("추가할 파일이름", 몇번째 배경음인지 숫자);
	bgmSoundFileAdd("01.mp3", 0); //배경음 추가 예시
	bgmSoundFileAdd("03.mp3", 1);

	//효과음 파일 추가하는 곳 ↓ effectSoundFileAdd("추가할 파일이름", 몇번째 효과음인지 숫자);
	effectSoundFileAdd("펀치 표준 게임.wav", 0); //효과음 추가 예시
}

//사운드 기능 종료 함수
void sound_release()
{
	for (int i = 0; i < 10; i++)
	{
		if (bgmSoundFile[i] == NULL)	break;
		FMOD_Sound_Release(bgmSoundFile[i]);
	}
	for (int i = 0; i < 10; i++)
	{
		if (effectSoundFile[i] == NULL)	break;
		FMOD_Sound_Release(effectSoundFile[i]);
	}
	FMOD_System_Close(soundSystem);
	FMOD_System_Release(soundSystem);
}

//배경음 출력 함수
void playBgmSound(int number)
{
	if (!bgmSoundChannel)	FMOD_Channel_IsPlaying(bgmSoundChannel, bgmSoundOnOff);
	if (!bgmSoundOnOff)		FMOD_Channel_Stop(bgmSoundChannel);
	FMOD_System_PlaySound(soundSystem, bgmSoundFile[number], 0, 0, &bgmSoundChannel);
}

//효과음 출력 함수
void playEffectSound(int number)
{
	FMOD_System_PlaySound(soundSystem, effectSoundFile[number], 0, 0, &effectSoundChannel);
}

//사운드 갱신 - 지속적으로 호출 필요
void sound_update()
{
	FMOD_System_Update(soundSystem);
}

//배경음 볼륨 조절 함수
void sound_bgmVolume(double volume)
{
	FMOD_Channel_SetVolume(bgmSoundChannel,volume);
}

//효과음 볼륨 조절 함수
void sound_effectVolume(double volume)
{
	FMOD_Channel_SetVolume(effectSoundChannel, volume);
}