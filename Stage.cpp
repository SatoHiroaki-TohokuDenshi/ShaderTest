#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Quad.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), pQuad_(nullptr)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h
    hModel_ = Model::Load("assets/BoxDefault.fbx");
    assert(hModel_ >= 0);

    pQuad_ = new Quad();
    pQuad_->Initialize("dancingAnimal.jpg");
}

//�X�V
void Stage::Update()
{
    //transform_.rotate_.y++;
}

//�`��
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

    pQuad_->Draw(transform_);
}

//�J��
void Stage::Release()
{
    pQuad_->Release();
    delete pQuad_;
}