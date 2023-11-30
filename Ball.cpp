#include "Ball.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Ball::Ball(GameObject* parent)
	:GameObject(parent, "Ball"), hModel_(-1)
{
}

//�f�X�g���N�^
Ball::~Ball() {

}

//������
void Ball::Initialize() {
	// ���f���̓ǂݍ���
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);

	transform_.rotate_.y = 180;
	transform_.scale_ = { 2.0f, 2.0f, 2.0f };
}

//�X�V
void Ball::Update() {
	//transform_.rotate_.y++;
}

//�`��
void Ball::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//�J��
void Ball::Release() {

}