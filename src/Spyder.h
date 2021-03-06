#pragma once
#include "Vector3D.h"
#include "SpyderHead.h"
#include "SpyderLeg.h"
#include "SpyderTale.h"
#include "FrontLegAnimator.h"
#include "MiddleLegAnimator.h"
#include "HindLegAnimator.h"
#include "Texture.h"
#include "Material.h"
#include <vector>

class Spyder {
private:
	int angle;
	int state;
	//前脚のアニメータ
	FrontLegAnimator frontLegAni;
	//中央の脚のアニメータ
	MiddleLegAnimator middleLegAni;
	//後ろ脚のアニメータ
	HindLegAnimator hindLegAni;
	//6本脚
	SpyderLeg leg[8];
	//頭
	SpyderHead head;
	//尾
	SpyderTale tale;
	//移動用
	std::vector<int> z = { 0,-90, -90, 0,90,90,  90,  0, 0 };
	std::vector<int> x = { 0,  0,  90,90,90, 0, -90,-90, 0 };
	std::vector<float> xLerp;
	std::vector<float> zLerp;

	float mtr[4] = { 0.5, 0.25, 0.0, 1.0 };
	Texture* bodyTexture;
	Material bodyMaterial;
	MaterialParam bodyParam = {
		{0.53,0.29,0.17,1.0},
		{0.53,0.29,0.17,1.0},
		{0.0,0.0,0.0,1.0},
		{0.0,0.0,0.0,1.0},
		0
	};
	int num;
	// アニメーションの設定
	void InitAnimation();
	// クモの移動アニメーション
	void MoveAnimation();
	// デバッグ用
	void DebugDraw();
public:
	//座標
	Vector3D position;
	Spyder(int num);
	//描画関数
	void Draw();
	// 移動
	void MovePosition(float x, float y, float z);
	// 回転
	void Rotate(int angle);
	// アニメーション
	void Animation();
	// 角度取得
	int GetAngle();
};