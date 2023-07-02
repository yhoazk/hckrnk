
# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_binary
cc_binary(
    name = "solar_doomsday",
    srcs = ["solar_doomsday.cpp"],
    copts = [],
    deps = [
        ":solar_doom",
        "@com_github_google_googletest//:gtest",
   #     "@gtest//:gtest_main"
            ],
)

# https://docs.bazel.build/versions/master/be/c-cpp.html#cc_library
cc_library(
    name = "solar_doom",
    hdrs = ["solar_doomsday.h"],
    visibility = ["//visibility:public"]
)