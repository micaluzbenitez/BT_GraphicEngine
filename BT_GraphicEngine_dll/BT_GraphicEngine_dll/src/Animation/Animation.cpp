#include "Animation.h"
#include "Timer/Timer.h"

// ------------------------------------------- FRAME -------------------------------------------
Frame::Frame()
{
	uvCoords[0] = { 0.f, 0.f };
	uvCoords[1] = { 1.f, 0.f };
	uvCoords[2] = { 1.f, 1.f };
	uvCoords[3] = { 0.f, 1.f };
}

Frame::~Frame()
{
}

UVCords* Frame::GetUVCoords()
{
	return uvCoords;
}

// ----------------------------------------- ANIMATION -----------------------------------------
Animation::Animation()
{
	currentTime = 0;
	currentFrame = 0;
	length = 1000;
	frames = vector<Frame>();
	speed = 1.0f;
}

Animation::~Animation()
{
	frames.clear();
}

void Animation::Update()
{
	currentTime += Timer::GetDeltaTime() * speed;

	while (currentTime > length)
	{
		currentTime -= length;
	}

	float frameLength = length / frames.size();
	currentFrame = static_cast<int>(currentTime / frameLength);
}

void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs)
{
	length = durationInSecs * 1000;

	Frame frame;

	frame.GetUVCoords()[0].U = (frameX / textureWidth);
	frame.GetUVCoords()[0].V = (frameY / textureHeight);

	frame.GetUVCoords()[1].U = ((frameX + frameWidth) / textureWidth);
	frame.GetUVCoords()[1].V = (frameY / textureHeight);

	frame.GetUVCoords()[2].U = (frameX / textureWidth);
	frame.GetUVCoords()[2].V = ((frameY + frameHeight) / textureHeight);

	frame.GetUVCoords()[3].U = ((frameX + frameWidth) / textureWidth);
	frame.GetUVCoords()[3].V = ((frameY + frameHeight) / textureHeight);

	frames.push_back(frame);
}

void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs, int frameCount)
{
	length = durationInSecs * 1000; // length = durationInSecs / 1000; ???

	float frameXIndex = 0;

	for (int i = 0; i < frameCount; i++)
	{
		Frame frame;

		frame.GetUVCoords()[0].U = (frameX + frameXIndex) / textureWidth;
		frame.GetUVCoords()[0].V = frameY / textureHeight;

		frame.GetUVCoords()[1].U = ((frameX + frameXIndex) + frameWidth) / textureWidth;
		frame.GetUVCoords()[1].V = frameY / textureHeight;

		frame.GetUVCoords()[2].U = (frameX + frameXIndex) / textureWidth;
		frame.GetUVCoords()[2].V = (frameY + frameHeight) / textureHeight;

		frame.GetUVCoords()[3].U = ((frameX + frameXIndex) + frameWidth) / textureWidth;
		frame.GetUVCoords()[3].V = (frameY + frameHeight) / textureHeight;

		/*
		frame.GetUVCoords()[0].U = (frameWidth * (frameX + 1)) / textureWidth;
		frame.GetUVCoords()[0].V = (frameHeight / textureHeight) * frameY;

		frame.GetUVCoords()[1].U = (frameWidth * (frameX + 1)) / textureWidth;
		frame.GetUVCoords()[1].V = (frameHeight / textureHeight) * (frameY - 1);

		frame.GetUVCoords()[2].U = (frameWidth * frameX) / textureWidth;
		frame.GetUVCoords()[2].V = (frameHeight / textureHeight) * (frameY - 1);

		frame.GetUVCoords()[3].U = (frameWidth * frameX) / textureWidth;
		frame.GetUVCoords()[3].V = (frameHeight / textureHeight) * frameY;
		*/

		frames.push_back(frame);
		frameXIndex += frameWidth;
	}
}

int Animation::GetCurrentFrame()
{
	return currentFrame;
}

std::vector<Frame> Animation::GetFrames()
{
	return frames;
}