## Dependeny installation
I have been using WSL2 environment: <br />
Distributor ID: Ubuntu <br />
Description:    Ubuntu 20.04.5 LTS <br />
Release:        20.04 <br />
Codename:       focal <br />

If repo was not cloned with submodules: <br />
git submodule update --init --recursive <br />

Copied from https://gitlab.syncad.com/hive/hive/-/blob/master/doc/building.md <br />
To install dependecies run: <br />
./install.sh <br />


## Building
mkdir build && cmake .. <br />

Example of build command: <br />
/usr/bin/cmake --build <build_directory> --config Debug --target all -j <cores_count> -- <br />

## Tests 
I did not use any testing framework. I did basic tests based on <cassert> <br />
To run run tests perform command in project root directory:
<build_directory>/tests/visitor_tests

## Note
At the begining I have been trying to use Dockerfile however for some reasons errors occurred so I decided to use local environment <br />
export DOCKER_BUILDKIT=0 <br />
export COMPOSE_DOCKER_CLI_BUILD=0 <br />

docker build --target=ci-base-image-5m -t registry.gitlab.syncad.com/hive/hive/ci-base-image-5m:ubuntu20.04-xxx -f Dockerfile . <br />

Step 14/23 : FROM ${CI_REGISTRY_IMAGE}runtime$CI_IMAGE_TAG AS ci-base-image <br />
manifest for registry.gitlab.syncad.com/hive/hive/runtime:ubuntu20.04-4 not found: manifest unknown: manifest unknown <br />
