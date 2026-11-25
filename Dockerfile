FROM ros:lyrical-ros-base AS build

RUN apt-get update \
    && apt-get install --no-install-recommends -y \
        build-essential \
        cmake \
        libboost-program-options-dev \
        libboost-system-dev \
    && rm -rf /var/lib/apt/lists/*

WORKDIR /workspace
COPY src/ ./src/

RUN . /opt/ros/lyrical/setup.sh \
    && cmake -S src -B build -DCMAKE_BUILD_TYPE=Release \
    && cmake --build build --parallel

FROM ros:lyrical-ros-base AS runtime

RUN apt-get update \
    && apt-get install --no-install-recommends -y \
        libboost-program-options-dev \
        libboost-system-dev \
    && rm -rf /var/lib/apt/lists/*

COPY --from=build /workspace/build/DGPSBaseStation /usr/local/bin/DGPSBaseStation

ENTRYPOINT ["/ros_entrypoint.sh", "/usr/local/bin/DGPSBaseStation"]
