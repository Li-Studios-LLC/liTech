project "liTechFramework"
    kind "StaticLib"
    language "C++"
    files { "**.cpp", "**.c", "**.h" }
    links { "liTechBase" }