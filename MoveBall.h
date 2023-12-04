#pragma once
#include "Engine/GameObject.h"

//MoveBallを管理するクラス
class MoveBall : public GameObject {
private:
	int hModel_;    // モデル番号

public:
	//コンストラクタ
	MoveBall(GameObject* parent);

	//デストラクタ
	~MoveBall();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};