load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_library")

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
    "//api:api",
  ],
  visibility = ["//visibility:public"]
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
  visibility = ["//visibility:public"]
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

proto_library(
    name = "cpprpg_proto",
    srcs = ["cpprpg.proto"],
)

cpp_grpc_library(
    name = "cpprpg_cc_proto",
    protos = [":cpprpg_proto"],
)
