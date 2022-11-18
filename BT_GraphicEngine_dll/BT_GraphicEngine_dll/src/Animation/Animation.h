#ifndef ANIMATION_H
#define ANIMATION_H

#include <glew.h>
#include <glfw3.h>
#include <iostream>
#include <vector>
#include "Export.h"
using namespace std;

struct UVCords
{
	float U;
	float V;
};

class DllApi Frame
{
public:
	Frame();
	~Frame();
	UVCords* GetUVCoords();

private:
	UVCords uvCoords[4];
};

class DllApi Animation
{
private:
	int currentFrame;
	float currentTime;
	float speed;
	float length;
	vector<Frame> frames;

public:
	Animation();
	~Animation();

	void Update();
	void AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs);
	void SetSpeed(float newSpeed);
	int GetCurrentFrame();
	vector<Frame> GetFrames();
};

#endif   