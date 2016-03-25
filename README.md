# PhysX

* PhysX-3.3/
 * PhysXVisualDebugger/NVIDIA_PhysXVisualDebugger_XXXXX-x64.msi ���C���X�g�[��
 * PhysXSDK/Source/compiler/vc14win64/PhysX.sln ���J���ăr���h
  * PhysXSDK/Bin/vc14win64/*.dll ���ł���
  * PhysXSDK/Lib/vc14win64/*.lib ���ł���
 * APEXSDK/UpdatePhysXPaths.vbs �����s - PhysXSDK �t�H���_���w�肷��
  * APEXSDK/compiler/vc14win64-PhysX_3.3/nvpath.vsprops �����ύX�����
  * APEXSDK/compiler/vc14win64-PhysX_3.3/APEX.sln ���J���ăr���h
   * �v���W�F�N�g�E�N���b�N - Properties - Configuration Properties - C/C++ - Advanced - Disable Specific Warnings �ֈȉ��̂悤�ɒǉ�
    * APEX_Destructible, ApexCommon ... 4464
    * APEX_Clothing ... 5032
   * APEXSDK/bin/vc14win64-PhysX_3.3/*.dll ���ł���
   * APEXSDK/lib/vc14win64-PhysX_3.3/*.lib ���ł���

* ���ϐ�������Ă���
~~~
setx PHYSX_SDK_PATH "...\PhysX-3.3\PhysXSDK"
setx APEX_SDK_PATH "...\PhysX-3.3\APEXSDK"
~~~

* �V�X�e�����ϐ� PATH �� DLL �̃p�X��ʂ��Ă��� (�Ǘ��҂Ƃ��Ď��s)
~~~
setx /M PATH "%PATH%;%PHYSX_SDK_PATH%\Bin\vc14win64"
setx /M PATH "%PATH%;%APEX_SDK_PATH%\bin\vc14win64-PhysX_3.3"
~~~

