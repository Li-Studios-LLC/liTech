project "Runner"
    kind "ConsoleApp"
    language "C++"
    files { "**.cpp", "**.h" }
    links { "opengl32", "SDL3", "liTechBase", "liTechFramework" }
