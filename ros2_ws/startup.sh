#!/bin/bash

ZIP_FILE="external/libtorch.zip"  
DESTINATION_DIR="external/libtorch"  #
#TORCH_URL="https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.2.2%2Bcpu.zip" 
#TORCH_URL="https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-1.2.0.zip"
#TORCH_URL="https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-latest.zip"
TORCH_URL="https://download.pytorch.org/libtorch/cpu/libtorch-cxx11-abi-shared-with-deps-2.7.0%2Bcpu.zip"


if [ ! -f "$ZIP_FILE" ]; then
    echo "Creating external directory"
    mkdir external
    echo "Downloading libTorch ZIP..."
    wget -O "$ZIP_FILE" "$TORCH_URL"
else
    echo "libTorch ZIP already downloaded."
fi

if [ ! -d "$DESTINATION_DIR" ]; then
    echo "Unzipping libTorch..."
    unzip -q "$ZIP_FILE" -d "$DESTINATION_DIR"
else
    echo "libTorch already unzipped."
fi

rm -rf "$ZIP_FILE"
