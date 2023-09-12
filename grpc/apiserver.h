#ifndef APISERVER_H
#define APISERVER_H

#include <grpcpp/grpcpp.h>
#include <memory>
#include <tuple>

std::tuple<std::unique_ptr<grpc::Server>, std::unique_ptr<grpc::Service>>
RunServer();

#endif
