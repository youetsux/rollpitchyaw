#include "Player.h"
#include "Engine/Model.h"
#include "Engine/Debug.h"
#include "Engine/Input.h"
#include "TestScene.h"
#include "Engine/Camera.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player"), hSilly(-1), 
	front({ 0, 0,-1, 0 })
{
	//swordDirには、初期方向として、ローカルモデルの剣の根っこから
	//先端までのベクトルとして（0,1,0)を代入しておく
	//初期位置は原点
	rpy = { 0,0,0 };
}

void Player::Initialize()
{

	hSilly = Model::Load("starship.fbx");

	transform_.matRotate_ = XMMatrixRotationRollPitchYaw(rpy.x, rpy.y, rpy.z);
	transform_.matScale_ = XMMatrixScaling(0.1, 0.1, 0.1);
	transform_.matTranslate_ = XMMatrixTranslation( 0,0,0 );
	transform_.isSetDirect = true;

}
	

void Player::Update()
{
	if (Input::IsKey(DIK_LEFT))
	{
		rpy.z -= 0.1;
	}
	if (Input::IsKey(DIK_RIGHT))
	{
		rpy.z += 0.1;
	}

	if (Input::IsKey(DIK_UP))
	{
		rpy.y += 0.1;
	}
	if (Input::IsKey(DIK_DOWN))
	{
		rpy.y -= 0.1;
	}
	if (Input::IsKey(DIK_A))
	{
		rpy.x += 0.1;
	}
	if (Input::IsKey(DIK_D))
	{
		rpy.x -= 0.1;
	}
	transform_.matRotate_ = XMMatrixRotationRollPitchYaw(rpy.y, rpy.z, rpy.x);
	transform_.matScale_ = XMMatrixScaling(0.1, 0.1, 0.1);
	transform_.matTranslate_ = XMMatrixTranslation(0, 0, 0);
	transform_.isSetDirect = true;
	//
	Camera::SetPosition({ 0, 0.5, -1 });
	Camera::SetTarget({ transform_.position_.x, transform_.position_.y, transform_.position_.z });
}

void Player::Draw()
{
		Model::SetTransform(hSilly, transform_);
		//XMMATRIX m = Model::GetMatrix(hSilly);
		
		Model::Draw(hSilly);
}


void Player::Release()
{
}


