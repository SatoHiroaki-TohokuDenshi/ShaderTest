//───────────────────────────────────────
 // テクスチャ＆サンプラーデータのグローバル変数定義
//───────────────────────────────────────
Texture2D		g_texture : register(t0);	//テクスチャー
SamplerState	g_sampler : register(s0);	//サンプラー

//───────────────────────────────────────
// コンスタントバッファ
// DirectX 側から送信されてくる、ポリゴン頂点以外の諸情報の定義
//───────────────────────────────────────
cbuffer global
{
	float4x4	matWorld;			// ワールド行列
	float4x4	matWVP;				// ワールド・ビュー・プロジェクションの合成行列
	float4x4	matNormal;			// ワールド行列を掛けた法線
	float4		diffuseColor;		// マテリアルの色＝拡散反射係数
	float4		lightDirection;		// 光源の方向
	float4		eyePos;				// 視点方向
	bool		isTextured;			// テクスチャーが貼られているかどうか
};

//───────────────────────────────────────
// 頂点シェーダー出力＆ピクセルシェーダー入力データ構造体
//───────────────────────────────────────
struct VS_OUT
{
	float4 pos  : SV_POSITION;	//位置
	float4 eyeVec	: POSITION;	//視線ベクトル
	float2 uv	: TEXCOORD;		//UV座標
	float4 color	: COLOR;	//色（明るさ）
};

//───────────────────────────────────────
// 頂点シェーダ
//───────────────────────────────────────
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
	//ピクセルシェーダーへ渡す情報
	VS_OUT outData;

	//ローカル座標に、ワールド・ビュー・プロジェクション行列をかけて
	//スクリーン座標に変換し、ピクセルシェーダーへ
	outData.pos = mul(pos, matWVP);
	outData.uv = uv;

	//視線ベクトル
	outData.eyeVec = normalize(mul(normal, matWorld));

	//法線を回転
	normal = mul(normal , matNormal);

	float4 light = float4(-1, 0, 0, 0);
	light = normalize(light);
	outData.color = clamp(dot(normal, light), 0, 1);

	//まとめて出力
	return outData;
}

//───────────────────────────────────────
// ピクセルシェーダ
//───────────────────────────────────────
float4 PS(VS_OUT inData) : SV_Target
{
	float4 lightSource = float4(1.0, 1.0, 1.0, 1.0);		//光源の色
	float4 ambentSource = float4(0.2, 0.2, 0.2, 1.0);		//環境光の色

	float4 diffuse;		//拡散反射光
	float4 ambient;		//環境光
	float4 specular;	//鏡面反射光

	if (isTextured) {
		//テクスチャ有り
		diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
		ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambentSource;
	}
	else {
		//テクスチャ無し
		diffuse = lightSource * diffuseColor * inData.color;
		ambient = lightSource * diffuseColor * ambentSource;
	}
	return (diffuse + ambient);
}
