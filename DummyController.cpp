#include "DummyController.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"
#include "Player.h"

DummyController::DummyController(GameObject* parent)
	:GameObject(parent,"DummyController")
{
	
}

void DummyController::Initialize()
{
	transform_.position_ = { 0, 0, 0 };


}

void DummyController::Update()
{
	if (Input::IsKey(DIK_SPACE))
	{
		Player* player = (Player*)FindObject("Player");
		XMMATRIX mvec = player->GetRotationMatrix();
		XMVECTOR front{ 0, 0, 1, 0 };
		front = XMVector3Transform(front, mvec);
		XMVECTOR npos;
		npos = XMLoadFloat3(&transform_.position_); 
		npos = npos + 0.01 * front;
		XMStoreFloat3(&transform_.position_, npos);
	}
}

void DummyController::Draw()
{
}

void DummyController::Release()
{
}
