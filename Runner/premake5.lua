project "Runner"
    kind "ConsoleApp"
    language "C++"
    files { "**.cpp", "**.h" }
    links { "SDL3", "liTechBase", "liTechFramework" }