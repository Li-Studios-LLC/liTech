project "Runner"
    language "C++"
    files { "**.cpp", "**.h" }
    links { "SDL3", "liTechBase", "liTechFramework" }
    filter "configurations:Debug"
        kind "ConsoleApp"
    filter "configurations:Release"
        kind "WindowedApp"
    filter "platforms:Win64"
        links { "opengl32" }