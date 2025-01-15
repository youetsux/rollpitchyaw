#include "TestScene.h"
#include "Player.h"
#include "DummyController.h"
#include "TPCam.h"
#include "Ground.h"
#include "CarTest.h"
#include "CarController.h"

//�R���X�g���N�^
TestScene::TestScene(GameObject * parent)
	: GameObject(parent, "TestScene")
{
}

//������
void TestScene::Initialize()
{	
	//pWp = Instantiate<Weapon>(this);
	//Instantiate<CarTest>(Instantiate<CarController>(this));
	Instantiate<Ground>(this);
	Instantiate <Player>(Instantiate<DummyController>(this));
	//Instantiate <TPCam>(Instantiate<DummyController>(this));

}

//�X�V
void TestScene::Update()
{
}

//�`��
void TestScene::Draw()
{
}

//�J��
void TestScene::Release()
{
}
