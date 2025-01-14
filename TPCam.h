#pragma once
#include "Engine/GameObject.h"
class TPCam :
    public GameObject
{
	XMFLOAT3 position;
	XMFLOAT3 target;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	TPCam(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

