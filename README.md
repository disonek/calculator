## Dependeny installation
I have been using WSL2 environment:
Distributor ID: Ubuntu
Description:    Ubuntu 20.04.5 LTS
Release:        20.04
Codename:       focal

If repo was not cloned with submodules:
git submodule update --init --recursive

Copied from https://gitlab.syncad.com/hive/hive/-/blob/master/doc/building.md
To install dependecies run:
./install.sh


## Building
mkdir build && cmake ..

Example of build command:
/usr/bin/cmake --build <build_directory> --config Debug --target all -j <cores> --


## Note
At the begining I have been trying to use Dockerfile however for some reasons errors occurred so I decided to use local environment
export DOCKER_BUILDKIT=0
export COMPOSE_DOCKER_CLI_BUILD=0

docker build --target=ci-base-image-5m -t registry.gitlab.syncad.com/hive/hive/ci-base-image-5m:ubuntu20.04-xxx -f Dockerfile .

Step 14/23 : FROM ${CI_REGISTRY_IMAGE}runtime$CI_IMAGE_TAG AS ci-base-image
manifest for registry.gitlab.syncad.com/hive/hive/runtime:ubuntu20.04-4 not found: manifest unknown: manifest unknown