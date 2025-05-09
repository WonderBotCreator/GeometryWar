#pragma once

#include<iostream>
#include "CTransform.h"
#include "CName.h"
#include "CShape.h"
#include "CBBox.h"
#include "CCollision.h"
#include "CInput.h"
#include "CLifespan.h"
#include "CAnimation.h"
#include "CGravity.h"
#include "CState.h"

//typedef std::tuple<
//	CTransform,
//	CLifespan,
//	CInput,
//	CBBox,
//	CAnimation,
//	CGravity,
//	CState
//
//> ComponentTuple;

class Entity
{
	friend class EntityManager;

	const size_t m_id = 0;
	const std::string m_tag = "Default";
	bool m_active = true;
	//ComponentTuple m_components;



	Entity(const std::string& tag,const size_t id);

public:
	
	

	std::shared_ptr<CTransform> cTransform;
	std::shared_ptr<CAnimation> cAnimation;
	std::shared_ptr<CBBox> cBBox;
	std::shared_ptr<CGravity>cGravity;
	std::shared_ptr<CShape> cShape;
	std::shared_ptr<CCollision> cCollision;
	std::shared_ptr<CInput> cInput;
	std::shared_ptr< sf::Time> time;
	std::shared_ptr<CLifespan> cLifeSpan;
	

	float targetTime = 5.f;
	float startTime = 0.f;

	bool isActive() const;
	const std::string& tag() const;
	const size_t id() const;
	void destroy();

	//template<typename T>
	//bool hasComponent() const
	//{
	//	return getComponent<T>().has;
	//}

	//template <typename T, typename... TArgs>
	//T& addComponent(TArgs&&... mArgs)
	//{
	//	auto& component = getComponent<T>();
	//	//component = T(std::forward<TArgs>(mArgs)...);
	//	component.has = true;
	//	return component;
	//}

	//template<typename T>
	//T& getComponent()
	//{
	//	return std::get<T>(m_components);
	//}

	//template<typename T>
	//const T& getComponent() const
	//{
	//	return std::get<T>(m_components);
	//}

	//template<typename T>
	//void removeComponent()
	//{
	//	getComponent<T>() = T();
	//}
};

