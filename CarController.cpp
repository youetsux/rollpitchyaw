#include "CarController.h"
#include "player.h"

CarController::CarController(GameObject* parent)
	:GameObject(parent,"CarController"),frontVec({0,0, 1})
{
}

void CarController::Initialize()
{
	transform_.position_ = { -1, 0, 0 };
}

void CarController::Update()
{
	//�f�t�H���g�̃t�����g�x�N�g�����Ƃ��Ă��āA���݂̌����̕����x�N�g�������
	XMMATRIX mvec = transform_.matRotate_;
	XMVECTOR front{ frontVec.x, frontVec.y, frontVec.z };
	front = XMVector3Transform(front, mvec);
	
	//�v���C���[�̃I�u�W�F�N�g���Q�b�g
	XMFLOAT3 playerPos = ((Player *)FindObject("Player"))->GetWorldPosition();

	//�ڕW�ɂȂ�����x�N�g�����v���C���[�ƃG�l�~�[�����ԃx�N�g���i�̒P�ʃx�N�g���j
	XMVECTOR targetVec = XMVector3Normalize({ playerPos.x - transform_.position_.x,
		                                      playerPos.y - transform_.position_.y, 
		                                      playerPos.z - transform_.position_.z });
	//���݂̌����ƁA�^�[�Q�b�g�̃x�N�g���̊Ԃ̊p�x���Q�b�g
	XMVECTOR angle = XMVector3AngleBetweenVectors (targetVec, front);
	//��]�����𒲂ׂ邽�߂ɁA�O�ς��Q�b�g
	XMVECTOR rotDir = XMVector3Cross(targetVec, front);

	//�p�x�ɕϊ�
	float dig = XMConvertToDegrees(XMVectorGetX(angle));

	//��]�p�x��1�x�ȏ�Ȃ�A��
	//if (dig > 1) {
		if (XMVectorGetY(rotDir) > 0)
			transform_.rotate_.y += 0.5;
		else
			transform_.rotate_.y -= 0.5;
	//}

	transform_.Calclation();
	mvec = transform_.matRotate_;
	front = { frontVec.x, frontVec.y, frontVec.z };
	XMVECTOR nextVec = XMVector3Transform(front, mvec);
	XMVECTOR npos;
	npos = XMLoadFloat3(&transform_.position_);
	npos = npos + 0.002 * targetVec;
	XMStoreFloat3(&transform_.position_, npos);
}

void CarController::Draw()
{
}

void CarController::Release()
{
}
