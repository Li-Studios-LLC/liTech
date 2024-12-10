workspace "liTech"
    configurations { "Debug", "Release" }
    platforms { "Win64" }
    location "Build"
    cppdialect "C++20"
    startproject "Runner"
    editorintegration "On"
    flags { "MultiProcessorCompile" }
    defines { "_CRT_SECURE_NO_WARNINGS" }
    includedirs { "liTech-dependencies/Inc", _WORKING_DIR }
    libdirs { "liTech-dependencies/Libs" }

    filter "platforms:Win64"
        system "Windows"
        architecture "x86_64"

    filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

    filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"

group "Engine"
    include "liTechBase"
    include "liTechFramework"

group "Applications"
    include "Runner"