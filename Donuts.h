#pragma once
#include "Engine/GameObject.h"

//Donuts���Ǘ�����N���X
class Donuts : public GameObject {
private:
	int hModel_;    // ���f���ԍ�
public:
	//�R���X�g���N�^
	Donuts(GameObject* parent);

	//�f�X�g���N�^
	~Donuts();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};