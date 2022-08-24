#include "Math/MathUtils.h"
#include "PhysicsSystem.h" 

namespace towr
{
	const float PhysicsSystem::pixelsPerUnit = 48.0f;

	void PhysicsSystem::Initialize(){
		b2Vec2 gravity{ 0, 10 };
		m_world = std::make_unique<b2World>(gravity);
	}

	void PhysicsSystem::Shutdown(){

	}

	void PhysicsSystem::Update() {
		m_world->Step(1.0f / 60, 8, 3);
	}

	b2Body* PhysicsSystem::CreateBody(const Vector2& position, float angle, const RigidBodyData& data)
	{
		Vector2 worldPosition = ScreenToWorld(position);

		b2BodyDef bodyDef;
		bodyDef.type = (data.isDynamic) ? b2_dynamicBody : b2_staticBody;
		bodyDef.position = *((b2Vec2*)(&worldPosition));
		bodyDef.angle = math::DegToRad(angle);
		bodyDef.fixedRotation = data.constrainAngle;
		b2Body* body = m_world->CreateBody(&bodyDef);

		return body;
	}

	void PhysicsSystem::DestroyBody(b2Body* body){
		if (m_world) {
			m_world->DestroyBody(body); //big boy error to be fixed   
			//I think my probbems are being caused by an overflow error. but i do not know whats causeing it.
			//i also think the reason my character dosn't move is caused by this overflow error. it seams that 
			//it is haveing difficulty reading memory
		}
	}

	void PhysicsSystem::SetCollisionBox(b2Body* body, const CollisionData& data, class Actor* actor)
	{
		b2PolygonShape shape;
		Vector2 worldSize = PhysicsSystem::ScreenToWorld(data.size * 0.5f);
		shape.SetAsBox(worldSize.x, worldSize.y);

		b2FixtureDef fixtureDef;
		fixtureDef.density = data.density;
		fixtureDef.friction = data.friction;
		fixtureDef.restitution = data.restitution;
		fixtureDef.isSensor = data.isTrigger;
		fixtureDef.shape = &shape;
		fixtureDef.userData.pointer = reinterpret_cast<uintptr_t>(actor);

		body->CreateFixture(&fixtureDef);
	}
}