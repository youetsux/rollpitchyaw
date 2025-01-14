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
	//デフォルトのフロントベクトルをとってきて、現在の向きの方向ベクトルを作る
	XMMATRIX mvec = transform_.matRotate_;
	XMVECTOR front{ frontVec.x, frontVec.y, frontVec.z };
	front = XMVector3Transform(front, mvec);
	
	//プレイヤーのオブジェクトをゲット
	XMFLOAT3 playerPos = ((Player *)FindObject("Player"))->GetWorldPosition();

	//目標になる方向ベクトル＝プレイヤーとエネミーを結ぶベクトル（の単位ベクトル）
	XMVECTOR targetVec = XMVector3Normalize({ playerPos.x - transform_.position_.x,
		                                      playerPos.y - transform_.position_.y, 
		                                      playerPos.z - transform_.position_.z });
	//現在の向きと、ターゲットのベクトルの間の角度をゲット
	XMVECTOR angle = XMVector3AngleBetweenVectors (targetVec, front);
	//回転方向を調べるために、外積をゲット
	XMVECTOR rotDir = XMVector3Cross(targetVec, front);

	//角度に変換
	float dig = XMConvertToDegrees(XMVectorGetX(angle));

	//回転角度が1度以上なら、回す
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
