@echo off

@REM docker build -t virtual-machine-created-by-myself/virtual-machine .
docker run --rm -it virtual-machine-created-by-myself/virtual-machine /virtual-machine %*
