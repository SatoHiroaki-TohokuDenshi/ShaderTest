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
	float4x4	matNormal;			// 法線を変形するための行列
	float4		diffuseColor;		// マテリアルの色＝拡散反射係数
	float4		eyePos;				// 視点
	float4		lightPos;			// 光源の位置
	bool		isTextured;			// テクスチャーが貼られているかどうか
};

//───────────────────────────────────────
// 頂点シェーダー出力＆ピクセルシェーダー入力データ構造体
//───────────────────────────────────────
struct VS_OUT
{
	float4 pos  : SV_POSITION;	//位置
	float2 uv	: TEXCOORD;		//UV座標
	float4 eyeDir	: POSITION;	//視線
	float4 normal	: NORMAL;	//法線
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

	//法線を回転
	normal = mul(normal , matNormal);

	float4 light = normalize(lightPos);
	light = normalize(light);
	outData.color = clamp(dot(normal, light), 0, 1);

	//法線を格納
	outData.normal = normal;

	float4 posWorld = mul(pos, matWorld);
	outData.eyeDir = normalize(eyePos - posWorld);

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

	float a = 8.0;

	float4 normalLight = lightPos;
	normalLight = normalize(normalLight);
	float4 refLight = normalize(2 * inData.normal * clamp(dot(inData.normal, normalLight), 0, 1) - normalLight);

	if (isTextured) {
		//テクスチャ有り
		diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
		ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambentSource;
		specular = lightSource * g_texture.Sample(g_sampler, inData.uv) * pow(clamp(dot(refLight, inData.eyeDir), 0, 1), a);
	}
	else {
		//テクスチャ無し
		diffuse = lightSource * diffuseColor * inData.color;
		ambient = lightSource * diffuseColor * ambentSource;
		specular = lightSource * diffuseColor * pow(clamp(dot(refLight, inData.eyeDir), 0, 1), a);
	}
	return (diffuse + ambient + specular);
}
