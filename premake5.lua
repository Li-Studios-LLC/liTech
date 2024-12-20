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
        toolset "msc"
        architecture "x86_64"

    filter "platforms:Linux"
        system "linux"
        toolset "gcc"
        architecture "x86_64"

    filter "platforms:Web"
        system "emscripten"
        toolset "gcc"
        architecture "wasm64"
        defines { "__EMSCRIPTEN__" }

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