#include "Stage.h"
#include "Ball.h"
#include "Ground.h"

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
	//Instantiate<Ground>(this);
	Instantiate<Ball>(this);
	Instantiate<MoveBall>(this);
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