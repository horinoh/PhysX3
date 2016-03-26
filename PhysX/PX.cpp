#include "stdafx.h"

#include <cassert>
#include <vector>

#include <shellapi.h>

#include "PX.h"

#ifdef _DEBUG
#pragma comment(lib, "LowLevelDEBUG.lib")
#pragma comment(lib, "LowLevelClothDEBUG.lib")
#pragma comment(lib, "PhysX3DEBUG_x64.lib")
#pragma comment(lib, "PhysX3CharacterKinematicDEBUG_x64.lib")
#pragma comment(lib, "PhysX3CommonDEBUG_x64.lib")
#pragma comment(lib, "PhysX3CookingDEBUG_x64.lib")
#pragma comment(lib, "PhysX3ExtensionsDEBUG.lib")
#pragma comment(lib, "PhysX3VehicleDEBUG.lib")
#pragma comment(lib, "PhysXProfileSDKDEBUG.lib")
#pragma comment(lib, "PhysXVisualDebuggerSDKDEBUG.lib")
#pragma comment(lib, "PvdRuntimeDEBUG.lib")
#pragma comment(lib, "PxTaskDEBUG.lib")
#pragma comment(lib, "SceneQueryDEBUG.lib")
#pragma comment(lib, "SimulationControllerDEBUG.lib")
#else
#pragma comment(lib, "LowLevel.lib")
#pragma comment(lib, "LowLevelCloth.lib")
#pragma comment(lib, "PhysX3_x64.lib")
#pragma comment(lib, "PhysX3CharacterKinematic_x64.lib")
#pragma comment(lib, "PhysX3Common_x64.lib")
#pragma comment(lib, "PhysX3Cooking_x64.lib")
#pragma comment(lib, "PhysX3Extensions.lib")
#pragma comment(lib, "PhysX3Vehicle.lib")
#pragma comment(lib, "PhysXProfileSDK.lib")
#pragma comment(lib, "PhysXVisualDebuggerSDK.lib")
#pragma comment(lib, "PvdRuntime.lib")
#pragma comment(lib, "PxTask.lib")
#pragma comment(lib, "SceneQuery.lib")
#pragma comment(lib, "SimulationController.lib")
#endif

#ifdef _DEBUG
#pragma comment(lib, "APEX_ClothingDEBUG_x64.lib")
#pragma comment(lib, "APEX_DestructibleDEBUG_x64.lib")
#pragma comment(lib, "APEX_EmitterDEBUG.lib")
#pragma comment(lib, "APEX_LegacyDEBUG_x64.lib")
#pragma comment(lib, "APEX_LoaderDEBUG_x64.lib")
#pragma comment(lib, "ApexCommonDEBUG.lib")
#pragma comment(lib, "ApexFrameworkDEBUG_x64.lib")
#pragma comment(lib, "ApexSharedDEBUG.lib")
#else
#pragma comment(lib, "APEX_Clothing_x64.lib")
#pragma comment(lib, "APEX_Destructible_x64.lib")
#pragma comment(lib, "APEX_Emitter.lib")
#pragma comment(lib, "APEX_Legacy_x64.lib")
#pragma comment(lib, "APEX_Loader_x64.lib")
#pragma comment(lib, "ApexCommon.lib")
#pragma comment(lib, "ApexFramework_x64.lib")
#pragma comment(lib, "ApexShared.lib")
#endif

PX::PX()
{
}
PX::~PX()
{
}
void PX::Initialize()
{
	using namespace physx;

	Foundation = PxCreateFoundation(PX_PHYSICS_VERSION, DefaultAllocatorCallback, DefaultErrorCallback);
	if (nullptr != Foundation) {
		Physics = PxCreatePhysics(PX_PHYSICS_VERSION, *Foundation, PxTolerancesScale());
		if (nullptr != Physics) {
			PxSceneDesc SceneDesc(Physics->getTolerancesScale());
			SceneDesc.gravity = PxVec3(0.0f, -9.8f, 0.0f);
			SceneDesc.cpuDispatcher = PxDefaultCpuDispatcherCreate(1);
			SceneDesc.filterShader = PxDefaultSimulationFilterShader;
			Scene = Physics->createScene(SceneDesc);
		}
	}
}
void PX::Finalize()
{
	if (nullptr != VisualDebuggerConnection) { VisualDebuggerConnection->release(); VisualDebuggerConnection = nullptr; }

	if (nullptr != Scene) { Scene->release(); Scene = nullptr; }
	if (nullptr != Physics) { Physics->release(); Physics = nullptr; }
	if (nullptr != Foundation) { Foundation->release(); Foundation = nullptr; }
}
void PX::ExecuteVisualDebugger(HWND hWnd)
{
	//std::vector<char> Value(1024);
	//GetEnvironmentVariableA("PHYSX_SDK_PATH", Value.data(), static_cast<DWORD>(Value.size()));

	const auto Result = ShellExecute(hWnd, L"open", L"C:/Program Files/NVIDIA Corporation/NVIDIA PhysX Visual Debugger/PVD2.exe", nullptr, nullptr, SW_SHOWNORMAL);
	assert(reinterpret_cast<const UINT64>(Result) > 32);
}
void PX::ConnectVisualDebugger()
{
	using namespace physx;

	if (nullptr == VisualDebuggerConnection) {
		if (nullptr != Physics) {
			const auto ConnectionManager = Physics->getPvdConnectionManager();
			if (nullptr != ConnectionManager) {
				VisualDebuggerConnection = PxVisualDebuggerExt::createConnection(ConnectionManager, "127.0.0.1", 5425, 100, physx::PxVisualDebuggerExt::getAllConnectionFlags());
			}
		}
	}
}

void PX::OnCreate(HWND hWnd)
{
	ExecuteVisualDebugger(hWnd);

	Initialize();

	ConnectVisualDebugger();
}
void PX::OnTimer(HWND hWnd)
{
	if (nullptr != Scene) {
		Scene->simulate(1.0f / 60.0f);
		Scene->fetchResults(true);
	}
}
void PX::OnDestroy(HWND hWnd)
{
	Finalize();
}

AX::AX()
	: Super()
{
}
AX::~AX()
{
}
void AX::Initialize()
{
	Super::Initialize();
}
void AX::Finalize()
{
	Super::Finalize();
}
