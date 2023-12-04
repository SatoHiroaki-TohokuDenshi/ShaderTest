#include "Arrow.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Arrow::Arrow(GameObject* parent)
	:GameObject(parent, "Arrow"), hModel_(-1)
{
}

//�f�X�g���N�^
Arrow::~Arrow() {

}

//������
void Arrow::Initialize() {
	// ���f���̓ǂݍ���
	hModel_ = Model::Load("Assets/Arrow.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Arrow::Update() {
	transform_.rotate_.y++;
}

//�`��
void Arrow::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//�J��
void Arrow::Release() {

}