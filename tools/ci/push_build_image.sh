#!/usr/bin/env bash
# Builds the private CI image from your extracted ROM and pushes it to GitHub Container Registry.
# Requirements: `./dev.sh python tools/bootstrap.py` done, and `docker login ghcr.io` with a token that has `write:packages`.
# The package must stay private: never make it public, it contains game data.
set -euo pipefail

IMAGE="ghcr.io/istornz/bowsers-inside-story-decomp-build:main"
VERSION="usa"
cd "$(dirname "$0")/../.."

if [ ! -f "extract/$VERSION/config.yaml" ]; then
    echo "extract/$VERSION/ not found, run ./dev.sh python tools/bootstrap.py first" >&2
    exit 1
fi

context="$(mktemp -d)"
trap 'rm -rf "$context"' EXIT
mkdir -p "$context/extract"
cp tools/requirements.txt "$context/"
cp -R "extract/$VERSION" "$context/extract/$VERSION"

docker build --platform linux/amd64 -f tools/ci/build-image.Dockerfile -t "$IMAGE" "$context"
docker push "$IMAGE"
echo "Pushed $IMAGE. Check that the package is private and that the repository has access to it (see docs/ci.md)."
