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
	float currentTime;
	int currentFrame;
	float length;
	vector<Frame> frames;

public:
	Animation();
	~Animation();

	void Update(float timer);
	void AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs);
	void AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs, int frameCount);
	int GetCurrentFrame();
	vector<Frame> GetFrames();
};

#endif   