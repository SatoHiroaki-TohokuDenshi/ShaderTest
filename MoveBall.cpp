#include "MoveBall.h"
#include "Engine/Input.h"
#include "Engine/Model.h"

//コンストラクタ
MoveBall::MoveBall(GameObject* parent)
	:GameObject(parent, "MoveBall"), hModel_(-1)
{
}

//デストラクタ
MoveBall::~MoveBall() {

}

//初期化
void MoveBall::Initialize() {
	// モデルの読み込み
	hModel_ = Model::Load("Assets/Ball.fbx");
	assert(hModel_ >= 0);
}

//更新
void MoveBall::Update() {
	const float move{ 0.1f };

	if (Input::IsKey(DIK_RIGHT))	transform_.position_.x += move;
	if (Input::IsKey(DIK_LEFT))		transform_.position_.x -= move;
	if (Input::IsKey(DIK_UP))		transform_.position_.z += move;
	if (Input::IsKey(DIK_DOWN))		transform_.position_.z -= move;

	Model::SetLightPos(hModel_, transform_.position_);
}

//描画
void MoveBall::Draw() {
	Model::SetTransform(hModel_, this->transform_);
	Model::Draw(hModel_);
}

//開放
void MoveBall::Release() {

}