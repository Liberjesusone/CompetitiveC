if (Test-Path build) { Remove-Item -Recurse -Force build }
cmake -B build -G "Ninja" `
  -DCMAKE_MAKE_PROGRAM="C:/msys64/mingw64/bin/ninja.exe" `
  -DCMAKE_CXX_COMPILER="C:/msys64/mingw64/bin/g++.exe" `
  -DCMAKE_C_COMPILER="C:/msys64/mingw64/bin/gcc.exe" `
  -DCMAKE_BUILD_TYPE=Debug
