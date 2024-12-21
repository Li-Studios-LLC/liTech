require("liTech-dependencies/PremakeModules/emscripten")

workspace "liTech"
    configurations { "Debug", "Release" }
    platforms { "Win64", "Linux", "Web" }
    location "Build"
    cppdialect "C++20"
    startproject "Runner"
    editorintegration "On"
    flags { "MultiProcessorCompile" }
    defines { "_CRT_SECURE_NO_WARNINGS" }
    includedirs { "liTech-dependencies/Inc", _WORKING_DIR }
    libdirs { "liTech-dependencies/Libs" }

    filter "platforms:Win64"
        system "windows"
        architecture "x86_64"

    filter "platforms:Linux"
        system "linux"
        architecture "x86_64"

    filter "platforms:Web"
        system "emscripten"
        architecture "wasm64"
        defines { "__EMSCRIPTEN__" }

    filter "configurations:Debug"
        defines { "_DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "_NDEBUG" }
        optimize "On"

group "Engine"
    include "liTechBase"
    include "liTechFramework"

group "Applications"
    include "Runner"