#!/bin/bash

docker build -t vm-on-my-own-by-piorosen .
container_id = $(docker run --rm -it --detach vm-on-my-own-by-piorosen)
echo $(container_id)
docker cp $(container_id):/root/armnn-devenv/Output/ .
docker kill $(container_id)

