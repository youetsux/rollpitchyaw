#pragma once
#include "Engine\\GameObject.h"


class CarController :
    public GameObject
{
public:
	XMFLOAT3 frontVec;
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	CarController(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

