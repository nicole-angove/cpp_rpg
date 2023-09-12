#ifndef APICLIENT_H
#define APICLIENT_H

#include <memory>

#include "grpc/cpprpg.grpc.pb.h"
#include <grpcpp/grpcpp.h>

/**
 * Client interface for all users to interact with the gameboard.
 * This is the gRPC version of api.h
 * 
 * Because this is a mirror of api.h for the purpose of implementing gRPC, 
 * functions are commented in api.h
 */
class APIClient {
public:
  APIClient(std::shared_ptr<grpc::Channel> channel);

  bool useAbility(const int abilityID);

private:
  std::unique_ptr<PlayerService::Stub> _stub;
};

#endif
