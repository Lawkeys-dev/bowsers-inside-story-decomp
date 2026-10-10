# Build environment for the decompilation.
# The toolchain (dsd, objdiff-cli, mwccarm via wibo) only ships for Windows/Linux x86-64,
# so on Apple Silicon this image runs under amd64 emulation (Rosetta/QEMU in Docker Desktop).
FROM --platform=linux/amd64 ubuntu:24.04

ENV DEBIAN_FRONTEND=noninteractive
RUN apt-get update && apt-get install -y --no-install-recommends \
        ca-certificates \
        curl \
        file \
        gcc \
        git \
        ninja-build \
        python3 \
        python3-pip \
        python3-venv \
        unzip \
    && rm -rf /var/lib/apt/lists/*

COPY tools/requirements.txt /tmp/requirements.txt
RUN python3 -m venv /opt/venv \
    && /opt/venv/bin/pip install --no-cache-dir -r /tmp/requirements.txt
ENV PATH="/opt/venv/bin:${PATH}"

WORKDIR /work
CMD ["bash"]
