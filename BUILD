load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")

cc_library(
  name = "board",
  srcs = [
    "board.cpp",
    "element.cpp",
    "movemap.cpp",
    "sphere.cpp",
  ],
  hdrs = [
    "board.h",
    "element.h",
    "movemap.h",
    "sphere.h",
    "move.h",
  ],
)

cc_library(
  name = "api",
  srcs = [
    "api.cpp",
  ],
  hdrs = [
    "api.h",
  ],
)

cc_library(
  name = "apiclient",
  srcs = [
    "apiclient.cpp",
  ],
  hdrs = [
    "apiclient.h",
  ],
  deps = [
    ":cpprpg_cc_proto",
  ],
)

cc_test(
  name = "hello_test",
  size = "small",
  srcs = ["hello_test.cc"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":board",
  ],
)

cc_test(
  name = "boardtest",
  size = "small",
  srcs = ["boardtest.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":board",
  ],
)

proto_library(
    name = "cpprpg_proto",
    srcs = ["cpprpg.proto"],
)

cpp_grpc_library(
    name = "cpprpg_cc_proto",
    protos = [":cpprpg_proto"],
)

cc_test(
  name = "apitest",
  size = "small",
  srcs = ["apitest.cpp"],
  deps = [
    "@com_google_googletest//:gtest_main",
    ":api",
  ],
)

cc_binary(
  name = "cpprpgserver",
  srcs = ["cpprpgserver.cpp"],
  deps = [
    ":apiserver",
  ],
)

cc_library(
  name = "apiserver",
  srcs = [
    "apiserver.cpp",
  ],
  hdrs = [
    "apiserver.h",
  ],
  deps = [
    ":cpprpg_cc_proto",
    ":api",
  ],
)

cc_binary (
  name = "cpprpgclient",
  srcs = ["cpprpgclient.cpp",],
  deps = [
    ":apiclient",
  ],
)

cc_test(
  name = "grpctest",
  size = "small",
  srcs = ["grpctest.cpp",],
  deps = [
    ":apiclient",
    ":apiserver",
    "@com_google_googletest//:gtest_main",
  ]
)
