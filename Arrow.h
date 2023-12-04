#pragma once
#include "Engine/GameObject.h"

//Arrowを管理するクラス
class Arrow : public GameObject {
private:
	int hModel_;    // モデル番号
public:
	//コンストラクタ
	Arrow(GameObject* parent);

	//デストラクタ
	~Arrow();

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};