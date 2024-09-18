include(FetchContent)

function(add_git_dependency target name repo tag mode)
    #[[
    Declare the dependency, this doesn't trigger downloads.
    Think of it like dependency metadata.

    Example, include hiredis

    FetchContent_Declare(
        hiredis
        GIT_REPOSITORY https://github.com/redis/hiredis.git
        GIT_TAG master
    )
    ]]
    FetchContent_Declare(
            ${name}
            GIT_REPOSITORY ${repo}
            GIT_TAG ${tag}
    )
    # Fetch Content Make Available downloads and configures dependencies.
    FetchContent_MakeAvailable(${name})
    #[[
    Link external dependencies. If there's an additional dependency (say
    "hiredis") then:
    target_link_libraries(${PROJECT_NAME} raylib hiredis)
    ]]
    target_link_libraries(${target} ${mode} ${name})
endfunction()
