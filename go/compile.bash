#!/usr/bin/env bash
bin=./bin

if [ ! -d $bin ]; then
	mkdir $bin
fi

ldflags="-s -w"

CGO_ENABLED=0 go build -ldflags="$ldflags" ./cmd/aos && mv ./aos $bin/aos
CGO_ENABLED=0 go build -ldflags="$ldflags" ./cmd/soa && mv ./soa $bin/soa
