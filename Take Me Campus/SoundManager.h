#pragma once

//����� ���� �߰� �Լ�
void bgmSoundFileAdd(char file[30], int number);

//ȿ���� ���� �߰� �Լ�
void effectSoundFileAdd(char file[30], int number);

//���� ��� �غ� �Լ�
void sound_init();

//���� ��� ���� �Լ�
void sound_release();

//����� ��� �Լ�
void playBgmSound(int number);

//ȿ���� ��� �Լ�
void playEffectSound(int number);

//���� ���� - ���������� ȣ�� �ʿ�
void sound_update();
