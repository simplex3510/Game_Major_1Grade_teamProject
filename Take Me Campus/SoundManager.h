#pragma once

//배경음 파일 추가 함수
void bgmSoundFileAdd(char file[30], int number);

//효과음 파일 추가 함수
void effectSoundFileAdd(char file[30], int number);

//사운드 기능 준비 함수
void sound_init();

//사운드 기능 종료 함수
void sound_release();

//배경음 출력 함수
void playBgmSound(int number);

//효과음 출력 함수
void playEffectSound(int number);

//사운드 갱신 - 지속적으로 호출 필요
void sound_update();

//볼륨 조절 함수
void sound_volume(double volume);