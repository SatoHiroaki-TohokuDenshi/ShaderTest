#include "Stage.h"
#include "Ball.h"
#include "Ground.h"

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
	//Instantiate<Ground>(this);
	Instantiate<Ball>(this);
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