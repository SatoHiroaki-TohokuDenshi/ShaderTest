#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include <vector>


#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

using std::vector;

class Texture;

class Fbx
{
	XMFLOAT4 lightPos_;

	//マテリアル
	struct MATERIAL
	{
		Texture*	pTexture;	// テクスチャ
		XMFLOAT4	ambient;	// 環境光
		XMFLOAT4	diffuse;	// 拡散反射
		XMFLOAT4	specular;	// 鏡面反射
		float		shininess;	// ハイライトの強さ
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWorld;		//ワールド行列
		XMMATRIX	matWVP;			//ワールドビュープロジェクション行列
		XMMATRIX	matNormal;		//法線を変形するための行列
		XMFLOAT4	diffuse;		//拡散反射光の色
		XMFLOAT4	ambient;		//環境光
		XMFLOAT4	specular;		//鏡面反射
		float		shininess;		//ハイライトの強度
		XMFLOAT4	eyePos;			//視線ベクトル
		XMFLOAT4	lightPos;		//光源ベクトル
		BOOL		isTextured;		//テクスチャがあるか
	};

	struct VERTEX
	{
		XMVECTOR position;//位置
		XMVECTOR uv; //テクスチャ座標
		XMVECTOR normal; //法線ベクトル
	};

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;	//マテリアルの個数

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;
	
	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
	void InitTexture(fbxsdk::FbxSurfaceMaterial* pMaterial, const int& i);
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

	void SetDifuse(XMFLOAT4 f4);
	void SetLightPos(XMFLOAT3 f3);
};