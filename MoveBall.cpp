#include "MoveBall.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//�R���X�g���N�^
MoveBall::MoveBall(GameObject* parent)
	:GameObject(parent, "MoveBall"), hModel_(-1)
{
}

//�f�X�g���N�^
MoveBall::~MoveBall() {

}

//������
void MoveBall::Initialize() {
	// ���f���̓ǂݍ���
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void MoveBall::Update() {
	const float move{ 0.1f };

	if (Input::IsKey(DIK_RIGHT))	transform_.position_.x += move;
	if (Input::IsKey(DIK_LEFT))		transform_.position_.x -= move;
	if (Input::IsKey(DIK_UP))		transform_.position_.z += move;
	if (Input::IsKey(DIK_DOWN))		transform_.position_.z -= move;

	Model::SetLightPos(hModel_, transform_.position_);
}

//�`��
void MoveBall::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//�J��
void MoveBall::Release() {

}