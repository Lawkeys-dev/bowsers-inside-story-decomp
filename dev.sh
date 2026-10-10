#!/usr/bin/env bash
# Runs a command inside the build container, with the repository mounted at /work.
#   ./dev.sh                          -> interactive shell
#   ./dev.sh python tools/bootstrap.py
#   ./dev.sh ninja
set -euo pipefail

IMAGE="bis-decomp-dev"
cd "$(dirname "$0")"

docker build --quiet --platform linux/amd64 -t "$IMAGE" . >/dev/null

tty_flags=()
if [ -t 0 ] && [ -t 1 ]; then
    tty_flags=(-it)
fi

exec docker run --rm ${tty_flags[@]+"${tty_flags[@]}"} --platform linux/amd64 \
    -v "$PWD":/work -w /work \
    "$IMAGE" "${@:-bash}"
