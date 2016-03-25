# PhysX

* PhysX-3.3/
 * PhysXVisualDebugger/NVIDIA_PhysXVisualDebugger_XXXXX-x64.msi をインストール
 * PhysXSDK/Source/compiler/vc14win64/PhysX.sln を開いてビルド
  * PhysXSDK/Bin/vc14win64/*.dll ができる
  * PhysXSDK/Lib/vc14win64/*.lib ができる
 * APEXSDK/UpdatePhysXPaths.vbs を実行 - PhysXSDK フォルダを指定する
  * APEXSDK/compiler/vc14win64-PhysX_3.3/nvpath.vsprops 等が変更される
  * APEXSDK/compiler/vc14win64-PhysX_3.3/APEX.sln を開いてビルド
   * プロジェクト右クリック - Properties - Configuration Properties - C/C++ - Advanced - Disable Specific Warnings へ以下のように追加
    * APEX_Destructible, ApexCommon ... 4464
    * APEX_Clothing ... 5032
   * APEXSDK/bin/vc14win64-PhysX_3.3/*.dll ができる
   * APEXSDK/lib/vc14win64-PhysX_3.3/*.lib ができる

* 環境変数を作っておく
~~~
setx PHYSX_SDK_PATH "...\PhysX-3.3\PhysXSDK"
setx APEX_SDK_PATH "...\PhysX-3.3\APEXSDK"
~~~

* システム環境変数 PATH に DLL のパスを通しておく (管理者として実行)
~~~
setx /M PATH "%PATH%;%PHYSX_SDK_PATH%\Bin\vc14win64"
setx /M PATH "%PATH%;%APEX_SDK_PATH%\bin\vc14win64-PhysX_3.3"
~~~

