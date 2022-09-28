## Dependency installation
I have been using WSL2 environment: <br />
Distributor ID: Ubuntu <br />
Description:    Ubuntu 20.04.5 LTS <br />
Release:        20.04 <br />
Codename:       focal <br />

Clone with submodules:
git clone --recurse-submodules -j10 https://github.com/disonek/calculator.git

If repo was not cloned with submodules: <br />
git submodule update --init --recursive <br />

Copied from https://gitlab.syncad.com/hive/hive/-/blob/master/doc/building.md <br />
To install dependecies run script: <br />
./install.sh <br />


## Building
mkdir build && cd build  <br />
cmake .. <br />

To build main application/program:  <br />
make -j10 calculator <br />

To build tests:  <br />
make -j10 visitor_tests <br />



## Example of usage of app/program
Help prompt:  <br />
~ ./calculator/build/calculator -h <br />

One time run: <br />
~ ./calculator/build/calculator 3 + 6 <br />
calculated by static visitor: 9 <br />
calculated by abstract visitor: 9 <br />

Interactive mode run: <br />
~ ./calculator/build/calculator -i <br />
123 + 777 <br />
calculated by static visitor: 900 <br />
calculated by abstract visitor: 900 <br />
900 - 1 <br />
calculated by static visitor: 899 <br />
calculated by abstract visitor: 899 <br />
q <br />

## Tests 
I did not use any testing framework. I did basic tests based on asserts <br />
To run tests perform command in project root directory: <br />
./calculator/build/tests/visitor_tests <br /> 

## Side Note
At the begining I have been trying to use Dockerfile however for some reasons errors occurred so I decided to use local environment <br />
export DOCKER_BUILDKIT=0 <br />
export COMPOSE_DOCKER_CLI_BUILD=0 <br />

docker build --target=ci-base-image-5m -t registry.gitlab.syncad.com/hive/hive/ci-base-image-5m:ubuntu20.04-xxx -f Dockerfile . <br />

Step 14/23 : FROM ${CI_REGISTRY_IMAGE}runtime$CI_IMAGE_TAG AS ci-base-image <br />
manifest for registry.gitlab.syncad.com/hive/hive/runtime:ubuntu20.04-4 not found: manifest unknown: manifest unknown <br />
