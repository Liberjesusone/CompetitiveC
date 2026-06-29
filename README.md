# Purpose

The purpose of this project is to store all the files and programs used to do competitive coding problems in different kinds of languages but starting in c++.

## Explanation of the header of each file

````c++
#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define io_boost ios_base::sync_with_stdio(0);cin.tie(0);
using ll = long long;
using ull = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;
const ll MAXN = 2e5 + 7;
ll n, m, q;
const ll oo = numeric_limits<ll>::max();
````

- The #include <bits/stdc++.h> is a header in GCC linux for competitive purposes, that allows to include a lot of useful headers for the common coding problems, but as we are not using GCC, we are just emulating it.
- The define endl is used to avoid using std::endl that clears the buffer and it's slower.
- We use long long to avoid overflows.
- The io_boost is meant to unlink c and c++ for better performance.
- The MOD is a long long const that stores the common upper limit of entries that those problems tend to have 10^9 + 7.
- The MAXN is another common upper limit.
- The oo limit represents a infinite number in some way, is the maximum capacity of a long long: 2^63 - 1.

## Explanation of the header of rust files

````rust
fn main()
{

}
````

## Explanation of the compiling process in vs code

- The process consists in several files, the first one is the **launch.json**, this is the one who leads the whole launching process after **f5** is clicked on the vs code IDE, it requests to launch the ``"${workspaceFolder}/.run/current.exe"`` file which is the **.exe** file from the file where we clicked **f5** from, but first does the preTasks **tasks.json**, and debugs it with the ``"C:/msys64/mingw64/bin/gdb.exe"`` debugger, so you must change it with your preferred one but take into account that must also debug rust.

- In the **tasks.json** it executes the command. ``powershell -NoProfile -ExecutionPolicy ByPass -ByPass -File "${workspaceFolder}/build-current.ps1" "${file}" "${fileBasenameNoExtension}" "${fileExtname}"``
  This is the command that executes the script ``"build-current.ps1"`` which is a power shell script that receives 3 parameters, the file path, the file name, and the extension and does the compiling process after enrooting it to the correct compiler according to the extension.

- In the ``build-current.ps1`` first of all we receive the parameters, and do the following actions.
  - Create the ``<root>/.run`` folder if not exists.
  - Create the target file name: ``$target = Join-Path $out "current.exe"``.
  - We redirect the compiling process to the correct compiler using a switch and the extension parameter

  - If it's ==Rust==
    - We executes the ``gen-cargo.ps1`` script which generates another \[\[bin\]\] in the **Cargo.toml** with the *name* (e.g = "coin_piles") and *path* (e.g = "problems/coin_piles.rs") for every problem we compile so the rust-analyzer can recognize it and also activates the rust intellisense.
    - After that we print in console ``"rustc -> $File"`` just as a log
    - Then we execute ``rustc --edition 2021 -g "$File" -o "$target"`` to compile.

  - If it's ==Cpp==
    - First we print in console ``Write-Host "cmake  -> target $Name"`` as a log
    - We executes ``cmake --build build --target $Name`` to compile with the **CMakeLists.txt** script that compiles all the *.cpp* files in ``/problems`` and then as it leaves the *.exe* in the build folder, we copy it with:
    - ``Copy-Item (Join-Path $PSScriptRoot "build/$Name.exe") $target -Force`` to debug it after the process.
  - Finally we print ``Write-Host "OK -> $target"`` as a log.

- Then the launch process can finally debug the **current.exe** file copied in ``/.run`` folder.
