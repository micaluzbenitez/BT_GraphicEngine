#include "Animation.h"

Animation::Animation()
{
}

Animation::~Animation()
{
}

/*
void Animation::Update(Timer& timer)
{
	currentTime += timer.timeBetweenFrames();

	while (currentTime > length)
	{
		currentTime -= length;
	}

	float frameLength = length / frames.size();
	currentFrame = static_cast<int>(current / frameLength);
}

void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs)
{
	length = durationInSecs * 1000;

	Frame frame;

	frame.uvCoords[0].u = (frameX / textureWidth);
	frame.uvCoords[0].v = (frameY / textureHeight);

	frame.uvCoords[1].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[1].v = (frameY / textureHeight);

	frame.uvCoords[2].u = (frameX / textureWidth);
	frame.uvCoords[2].v = ((frameY + frameHeight) / textureHeight);

	frame.uvCoords[3].u = ((frameX + frameWidth) / textureWidth);
	frame.uvCoords[3].v = ((frameY + frameHeight) / textureHeight);

	frames.push_back(frame);
}

void Animation::AddFrame(float frameX, float frameY, float frameWidth, float frameHeight, float textureWidth, float textureHeight, float durationInSecs, int frameCount)
{
	length = durationInSecs * 1000;

	float frameXIndex = 0;

	for (int i = 0; i < frameCount; i++)
	{
		Frame frame;

		frame.uvCoords[0].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[0].v = (frameY / textureHeight);

		frame.uvCoords[1].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[1].v = (frameY / textureHeight);

		frame.uvCoords[2].u = ((frameX + frameXIndex) / textureWidth);
		frame.uvCoords[2].v = ((frameY + frameHeight) / textureHeight);

		frame.uvCoords[3].u = (((frameX + frameXIndex) + frameWidth) / textureWidth);
		frame.uvCoords[3].v = ((frameY + frameHeight) / textureHeight);

		frames.push_back(frame);
		frameXIndex += frameWidth;
	}
}
*/