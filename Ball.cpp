#include "Ball.h"
#include "Engine/Model.h"

//コンストラクタ
Ball::Ball(GameObject* parent)
	:GameObject(parent, "Ball"), hModel_(-1)
{
}

//デストラクタ
Ball::~Ball() {

}

//初期化
void Ball::Initialize() {
	// モデルの読み込み
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);

	transform_.rotate_.y = 180;
	transform_.scale_ = { 2.0f, 2.0f, 2.0f };
}

//更新
void Ball::Update() {
	//transform_.rotate_.y++;
}

//描画
void Ball::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//開放
void Ball::Release() {

}