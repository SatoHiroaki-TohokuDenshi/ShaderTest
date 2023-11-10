#include "Stage.h"
#include "Engine/Model.h"
#include "Engine/Quad.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hModel_(-1), pQuad_(nullptr)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //モデルデータのロード
    hModel_ = Model::Load("assets/BoxDefault.fbx");
    assert(hModel_ >= 0);

    pQuad_ = new Quad();
    pQuad_->Initialize("dancingAnimal.jpg");
}

//更新
void Stage::Update()
{
    //transform_.rotate_.y++;
}

//描画
void Stage::Draw()
{
    Model::SetTransform(hModel_, transform_);
    Model::Draw(hModel_);

    pQuad_->Draw(transform_);
}

//開放
void Stage::Release()
{
    pQuad_->Release();
    delete pQuad_;
}