#include <stdio.h>
#include <fmod.h>
#include "SoundManager.h"

#pragma once

FMOD_SYSTEM *soundSystem; //����ý���
FMOD_SOUND *bgmSoundFile[10]; //����� ���� ���庯��
FMOD_SOUND *effectSoundFile[50]; //ȿ���� ���� ���庯��
FMOD_CHANNEL *bgmSoundChannel;
FMOD_CHANNEL *effectSoundChannel;
int bgmSoundOnOff = 0;
int effectSoundOnOff = 0;

//����� ���� �߰� �Լ�
void bgmSoundFileAdd(char file[30], int number)
{
	FMOD_System_CreateSound(soundSystem, file, FMOD_LOOP_NORMAL, 0, &bgmSoundFile[number]);
}

//ȿ���� ���� �߰� �Լ�
void effectSoundFileAdd(char file[30], int number)
{
	FMOD_System_CreateSound(soundSystem, file, FMOD_DEFAULT, 0, &effectSoundFile[number]);
}

//���� ��� �غ� �Լ�
void sound_init()
{
	FMOD_System_Create(&soundSystem);
	FMOD_System_Init(soundSystem, 32, FMOD_INIT_NORMAL, NULL);

	//����� ���� �߰��ϴ� �� �� bgmSoundFileAdd("�߰��� �����̸�", ���° ��������� ����);
	bgmSoundFileAdd("01.mp3", 0); //����� �߰� ����

	//ȿ���� ���� �߰��ϴ� �� �� effectSoundFileAdd("�߰��� �����̸�", ���° ȿ�������� ����);
	effectSoundFileAdd("��ġ ǥ�� ����.wav", 0); //ȿ���� �߰� ����
}

//���� ��� ���� �Լ�
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

//����� ��� �Լ�
void playBgmSound(int number)
{
	if (!bgmSoundChannel)	FMOD_Channel_IsPlaying(bgmSoundChannel, bgmSoundOnOff);
	if (!bgmSoundOnOff)	FMOD_Channel_Stop(bgmSoundChannel);
	FMOD_System_PlaySound(soundSystem, bgmSoundFile[number], 0, 0, &bgmSoundChannel);
}

//ȿ���� ��� �Լ�
void playEffectSound(int number)
{
	FMOD_System_PlaySound(soundSystem, effectSoundFile[number], 0, 0, &effectSoundChannel);
}

//���� ���� - ���������� ȣ�� �ʿ�
void sound_update()
{
	FMOD_System_Update(soundSystem);
}