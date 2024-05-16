#!/bin/bash

git clone https://github.com/microsoft/vcpkg ./scripts/vcpkg
./scripts/vcpkg/bootstrap-vcpkg.sh
./scripts/vcpkg/vcpkg install
