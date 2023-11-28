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
	//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matWorld;		//���[���h�s��
		XMMATRIX	matWVP;			//���[���h�r���[�v���W�F�N�V�����s��
		XMMATRIX	matNormal;		//�@����ό`���邽�߂̍s��
		XMFLOAT4	diffuseColor;	//�g�U���ˌ��̐F
		XMFLOAT4	eyePos;			//�����x�N�g��
		XMFLOAT4	lightPos;		//�����x�N�g��
		BOOL		isTextured;		//�e�N�X�`�������邩
	};

	struct VERTEX
	{
		XMVECTOR position;//�ʒu
		XMVECTOR uv; //�e�N�X�`�����W
		XMVECTOR normal; //�@���x�N�g��
	};

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;
	
	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
public:

	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();

	void SetDifuse(XMFLOAT4 f4);
};