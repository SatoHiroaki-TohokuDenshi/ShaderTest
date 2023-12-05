#include "Stage.h"
#include "Donuts.h"

#include "MoveBall.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
	:GameObject(parent, "Stage")
{
}

//�f�X�g���N�^
Stage::~Stage() {

}

//������
void Stage::Initialize() {
	Instantiate<MoveBall>(this);
	Instantiate<Donuts>(this);
}

//�X�V
void Stage::Update() {

}

//�`��
void Stage::Draw() {

}

//�J��
void Stage::Release() {

}