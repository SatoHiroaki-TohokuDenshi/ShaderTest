#include "Arrow.h"
#include "Engine/Model.h"

//コンストラクタ
Arrow::Arrow(GameObject* parent)
	:GameObject(parent, "Arrow"), hModel_(-1)
{
}

//デストラクタ
Arrow::~Arrow() {

}

//初期化
void Arrow::Initialize() {
	// モデルの読み込み
	hModel_ = Model::Load("Assets/Arrow.fbx");
	assert(hModel_ >= 0);
}

//更新
void Arrow::Update() {
	transform_.rotate_.y++;
}

//描画
void Arrow::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//開放
void Arrow::Release() {

}