project "Runner"
    language "C++"
    files { "**.cpp", "**.h" }
    links { "opengl32", "SDL3", "liTechBase", "liTechFramework" }
    filter "configurations:Debug"
        kind "ConsoleApp"
    filter "configurations:Release"
        kind "WindowedApp"
