#pragma once
#include "Engine/GameObject.h"

//Ball���Ǘ�����N���X
class Ball : public GameObject {
private:
    int hModel_;    // ���f���ԍ�
public:
    //�R���X�g���N�^
    Ball(GameObject* parent);

    //�f�X�g���N�^
    ~Ball();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};