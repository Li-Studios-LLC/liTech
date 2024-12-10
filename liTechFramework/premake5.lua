project "liTechFramework"
    kind "SharedLib"
    language "C++"
    files { "**.cpp", "**.h" }
    links { "liTechBase" }