#pragma once
#include "Engine/GameObject.h"
class DummyController :
    public GameObject
{
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	DummyController(GameObject* parent);
	

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
	void RotateR();
	void RotateL();
};

