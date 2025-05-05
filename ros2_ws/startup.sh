#!/bin/bash

ZIP_FILE="external/libtorch.zip"  
DESTINATION_DIR="external/libtorch"  #
TORCH_URL="https://download.pytorch.org/libtorch/cpu/libtorch-shared-with-deps-2.2.2%2Bcpu.zip" 

if [ ! -f "$ZIP_FILE" ]; then
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
