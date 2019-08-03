//
// COMP 371 Assignment Framework
//
// Created by Nicolas Bergeron on 8/7/14.
// Updated by Gary Chang on 14/1/15
//
// Copyright (c) 2014-2019 Concordia University. All rights reserved.
//

#pragma once


#include "ParsingHelper.h"
#include <vector>
#include <glm/glm.hpp>

class Camera;
class Model;
class Animation;
class AnimationKey;
class BSpline;
using namespace glm;

class World
{
public:
	World();
	~World();
	
    static World* GetInstance();

	void Update(float dt);
	void Draw();

	void LoadScene(const char * scene_path);
    Animation* FindAnimation(ci_string animName);
    AnimationKey* FindAnimationKey(ci_string keyName);

    const Camera* GetCurrentCamera() const;
    
private:
    static World* instance;
    
	std::vector<Model*> mModel;
    std::vector<Animation*> mAnimation;
    std::vector<AnimationKey*> mAnimationKey;
	std::vector<Camera*> mCamera;
    std::vector<BSpline*> mSpline;
	unsigned int mCurrentCamera;


	//Adding light properties from assignment 2

	float ambientSphere;
	float diffuseSphere;
	float specularSphere;
	float exponentSphere;

	float kc;
	float kl;
	float kq;

	glm::vec3 lightColor;
	glm::vec4 lightPosition;
};
