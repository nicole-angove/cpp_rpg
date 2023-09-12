#include <grpcpp/grpcpp.h>

#include "grpc/apiclient.h"

std::string parseTargetAddress(int argc, char **argv) {
  std::string target_str;
  std::string arg_str("--target");

  // Read target string from command line if present
  if (argc > 1) {
    std::string arg_val = argv[1];
    size_t start_pos = arg_val.find(arg_str);
    if (start_pos != std::string::npos) {
      start_pos += arg_str.size();
      if (arg_val[start_pos] == '=') {
        target_str = arg_val.substr(start_pos + 1);
      } else {
        std::cout << "The only correct argument syntax is --target="
                  << std::endl;
        return 0;
      }
    } else {
      std::cout << "The only acceptable argument is --target=" << std::endl;
      return 0;
    }
  } else { // Otherwise, use default
    target_str = "0.0.0.0:50051";
  }

  return target_str;
}

int main(int argc, char **argv) {

  std::string target_str = parseTargetAddress(argc, argv);

  APIClient testservice(
      grpc::CreateChannel(target_str, grpc::InsecureChannelCredentials()));

  // Placeholder for actions to be performed by player
  int testValue = 1;
  bool reply = testservice.useAbility(testValue);
  std::cout << "UseAbility result: " << reply << std::endl;

  return 0;
}
