//������������������������������������������������������������������������������
 // �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D		g_texture : register(t0);	//�e�N�X�`���[
SamplerState	g_sampler : register(s0);	//�T���v���[

//������������������������������������������������������������������������������
// �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer global
{
	float4x4	matWorld;			// ���[���h�s��
	float4x4	matWVP;				// ���[���h�E�r���[�E�v���W�F�N�V�����̍����s��
	float4x4	matNormal;			// �@����ό`���邽�߂̍s��
	float4		diffuseColor;		// �}�e���A���̐F���g�U���ˌW��
	float4		eyePos;				// ���_
	float4		lightPos;			// �����̈ʒu
	bool		isTextured;			// �e�N�X�`���[���\���Ă��邩�ǂ���
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
	float4 pos  : SV_POSITION;	//�ʒu
	float2 uv	: TEXCOORD;		//UV���W
	float4 eyeDir	: POSITION;	//����
	float4 normal	: NORMAL;	//�@��
	float4 color	: COLOR;	//�F�i���邳�j
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
	//�s�N�Z���V�F�[�_�[�֓n�����
	VS_OUT outData;

	//���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
	//�X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
	outData.pos = mul(pos, matWVP);
	outData.uv = uv;

	//�@������]
	normal = mul(normal , matNormal);

	float4 light = normalize(lightPos);
	light = normalize(light);
	outData.color = clamp(dot(normal, light), 0, 1);

	//�@�����i�[
	outData.normal = normal;

	float4 posWorld = mul(pos, matWorld);
	outData.eyeDir = normalize(eyePos - posWorld);

	//�܂Ƃ߂ďo��
	return outData;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
	float4 lightSource = float4(1.0, 1.0, 1.0, 1.0);		//�����̐F
	float4 ambentSource = float4(0.2, 0.2, 0.2, 1.0);		//�����̐F

	float4 diffuse;		//�g�U���ˌ�
	float4 ambient;		//����
	float4 specular;	//���ʔ��ˌ�

	float a = 8.0;

	float4 normalLight = lightPos;
	normalLight = normalize(normalLight);
	float4 refLight = normalize(2 * inData.normal * clamp(dot(inData.normal, normalLight), 0, 1) - normalLight);

	if (isTextured) {
		//�e�N�X�`���L��
		diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
		ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambentSource;
		specular = lightSource * g_texture.Sample(g_sampler, inData.uv) * pow(clamp(dot(refLight, inData.eyeDir), 0, 1), a);
	}
	else {
		//�e�N�X�`������
		diffuse = lightSource * diffuseColor * inData.color;
		ambient = lightSource * diffuseColor * ambentSource;
		specular = lightSource * diffuseColor * pow(clamp(dot(refLight, inData.eyeDir), 0, 1), a);
	}
	return (diffuse + ambient + specular);
}
