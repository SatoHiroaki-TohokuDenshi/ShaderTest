#pragma once
#include "Engine/GameObject.h"

//MoveBall���Ǘ�����N���X
class MoveBall : public GameObject {
private:
	int hModel_;    // ���f���ԍ�

public:
	//�R���X�g���N�^
	MoveBall(GameObject* parent);

	//�f�X�g���N�^
	~MoveBall();

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};