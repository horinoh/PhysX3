#pragma once

#include <PxPhysicsAPI.h>

class PX
{
public:
	PX();
	virtual ~PX();

	virtual void Initialize();
	virtual void Finalize();

	static void ExecuteVisualDebugger(HWND hWnd);
	virtual void ConnectVisualDebugger();

	virtual void OnCreate(HWND hWnd);
	virtual void OnTimer(HWND hWnd);
	virtual void OnDestroy(HWND hWnd);

protected:
	physx::PxDefaultErrorCallback DefaultErrorCallback;
	physx::PxDefaultAllocator DefaultAllocatorCallback;
	class physx::PxFoundation* Foundation = nullptr;
	class physx::PxPhysics* Physics = nullptr;
	physx::PxVisualDebuggerConnection* VisualDebuggerConnection = nullptr;
	class physx::PxScene* Scene = nullptr;
};

class AX : public PX
{
private:
	using Super = PX;

public:
	AX();
	virtual ~AX();

	virtual void Initialize();
	virtual void Finalize();

};