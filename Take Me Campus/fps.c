#include"fps.h"
#include "screen.h"

#pragma once
#pragma warning (disable:4996)

/* FPSData�� ����ü �����ͷ� ������ ���� **********
* 
* 1. fps�� ���� �׻� �ٲ��. ���� �������� �޸𸮸� �Ҵ��� �־�� �Ѵ�.
*
*
***************************************************/


// Call-by-Refernce
// FPS������ �ʱ�ȭ(������ �������� ����������, �ش� �����͸� ���ڷ� ���� �� ���� �����͸� ����Ͽ� ������)
void initFPSData(FPSData** fpsData)
{
    // fpsData��� ����ü �������� ��ü���� �޸� ������ ������.
    (*fpsData) = (FPSData*)malloc(sizeof(FPSData));
    // ������ �� ī��Ʈ �ʱ�ȭ
    (*fpsData)->frameCnt = 0;
    // ��� ���۸� �������� �Ҵ����
    (*fpsData)->fpsTextBuffer = (char*)malloc(sizeof(char) * 10);
    // �����Ѵ� (���ۿ�, ���ڿ��� , ī��Ʈ ���� �޾ƿͼ�)
    sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
    // ���� �ð� �ʱ�ȭ
    (*fpsData)->fpsOldTime = clock();

}

// FPS ���
void drawFPS(FPSData** fpsData)
{
    // ������ ī��Ʈ ����
    (*fpsData)->frameCnt++;
    // ���� ��� �ð� ������Ʈ
    (*fpsData)->fpsCurTime = clock();

    
    // if�� ������ 1�ʸ��� fps�� ������Ʈ �ϱ� ������.
    // (ȭ�� ��� �ð��� ���� = �ϳ��� ȭ��(����)�� �������� �ð�)�� 1��(1000)���� Ŀ����
    if (1000 <= (*fpsData)->fpsCurTime - (*fpsData)->fpsOldTime)
    {
        // �ٽ� �����Ѵ� (���ۿ�, ���ڿ��� , ī��Ʈ ���� �޾ƿͼ�)
        sprintf((*fpsData)->fpsTextBuffer, "FPS:%d", (*fpsData)->frameCnt);
        // ���� ȭ�� ��� �ð� ������Ʈ
        (*fpsData)->fpsOldTime = clock();
        // ������ ī��Ʈ�� �ٽ� �޾ƿ��� ���� 0���� �ʱ�ȭ
        (*fpsData)->frameCnt = 0;
    }
    
    // (0, 0)�� ��ǥ�� �ش� ����(���ڿ�)�� ����Ѵ�.
    screenPrint(0, 0, (*fpsData)->fpsTextBuffer);
}

// FPSData ���� �Ҵ� ����
void freeFPSData(FPSData** fpsData)
{
    free((*fpsData)->fpsTextBuffer);
    free(*fpsData);
}