#include "Donuts.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Donuts::Donuts(GameObject* parent)
	:GameObject(parent, "Donuts"), hModel_(-1)
{
}

//�f�X�g���N�^
Donuts::~Donuts() {

}

//������
void Donuts::Initialize() {
	// ���f���̓ǂݍ���
	hModel_ = Model::Load("Assets\\Donuts.fbx");
	assert(hModel_ >= 0);
}

//�X�V
void Donuts::Update() {

}

//�`��
void Donuts::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//�J��
void Donuts::Release() {

}